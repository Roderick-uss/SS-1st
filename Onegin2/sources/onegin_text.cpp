#include <assert.h>
#include <stdio.h>
#include <sys\stat.h>

#include "commoner.h"
#include "loger.h"
#include "onegin_text.h"

static const char* const ONEGIN_READ  = "text_files/proc_onegin.txt";
static const char* const ONEGIN_WRITE = "text_files/ency_onegin.txt";

void text_assert(const Text* const text) {
    assert(text);
    assert(text->lines);
    assert(text->buffer);

    return;
}

static void print_log_line(const Text * const text, size_t i_line) {
    open_log_stream();
    text_assert(text);

    FILE* log_stream = get_log_stream();

//    LOG_FATAL("make log print(onegin_text)\n");

    const char* line  = text->lines[i_line].begin;
    size_t size = text->lines[i_line].size;

    fprintf(log_stream, "line N: %llu\n", i_line + 1);
    fprintf(log_stream, "%p %llu\r\n", line, size);
    fwrite(line, sizeof(char), size, log_stream);
    fwrite("\r\n\r\n", sizeof(char), 4, log_stream);

    close_log_stream();
    return;
}


static void repare_text(Text *text) {
    assert(text);
    assert(text->buffer);

    if (text->buffer[text->buffer_size - 4] != '\n') {

        text->buffer[text->buffer_size - 3]  = '\r';
        text->buffer[text->buffer_size - 2]  = '\n';
        LOG_CERR("FIXED\n");
    }
}

static size_t get_n_lines(char* buffer) {
    assert(buffer);

    size_t line_cnt = 0;

    while(*buffer) line_cnt += int(*(buffer++) == '\n');

    return line_cnt;
}

static int fill_buffer(Text *text) {
    assert(text);

    struct stat text_info = {};
    stat(ONEGIN_READ, &text_info);

    FILE* read_stream = fopen(ONEGIN_READ, "rb");
    if (!read_stream) return 1;

    text->buffer_size = (size_t)text_info.st_size + 3;

    text->buffer = (char*) calloc(text->buffer_size + 1, sizeof(char));
    assert(text->buffer);

    *text->buffer = '\n';
    text->buffer++;

    fread(text->buffer, sizeof(char), text->buffer_size, read_stream);
    repare_text(text);

    LOG_CERR("%p\n", text->buffer);

    fclose(read_stream);

    return 0;
}

static int get_line_buff(Text* text, size_t i_line, char* curr_pos) {
    text_assert(text);
    assert(curr_pos);

    if (!*curr_pos)
        return 0;

    STRING_t* line = &text->lines[i_line];
    char* start_pos = curr_pos;

    while (*curr_pos != '\r') curr_pos++;

    line->begin = start_pos;
    line->size  = curr_pos - start_pos;

    return 1;
}

static void fill_lines(Text* text) {
    assert(text);
    assert(text->buffer);

    text->n_lines = get_n_lines(text->buffer);

    LOG_CERR("Result of get_n_lines: %llu\n\n", text->n_lines);

    text->lines = (STRING_t*)calloc(text->n_lines, sizeof(STRING_t));
    assert(text->lines);

    size_t i_line = 0;
    char*  curr_pos  = text->buffer;

    while(get_line_buff(text, i_line, curr_pos)) {
        curr_pos += text->lines[i_line++].size + 2;
    }
    return;
}


int read_onegin(Text* text) {
    assert(text);

    if (fill_buffer(text)) return 1;

    fill_lines(text);

    return 0;
}

void print_onegin(const Text* const text) {
    text_assert(text);

    FILE* write_stream = fopen(ONEGIN_WRITE, "ab");
    assert(write_stream);

    fprintf(write_stream, "\r\nONEGIN\r\n");

    for(size_t i = 0; i < text->n_lines; ++i) {
        print_log_line(text, i);
        fwrite(text->lines[i].begin, sizeof(char), text->lines[i].size + 2, write_stream);
    }

    fclose(write_stream);
    return;
}

void print_clean_onegin(const Text* const text) {
    text_assert(text);

    FILE* write_stream = fopen(ONEGIN_WRITE, "ab");
    assert(write_stream);

    fprintf(write_stream, "ONEGIN\r\n\r\n");
    fwrite(text->buffer, sizeof(char), text->buffer_size, write_stream);

    fclose(write_stream);
    return;
}

void free_onegin(Text* text) {
    text_assert(text);
    text->buffer--;

    FREE(text->buffer);
    FREE(text->lines);

    text->buffer_size = 0;
    text->n_lines = 0;

    return;
}
