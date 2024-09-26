#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "commoner.h"

#define BASE_INPUT_FILE  "text_files/full_onegin.txt"
#define BASE_OUTPUT_FILE "text_files/proc_onegin.txt"
#define MAX_LINE 500

int remove_rome_number(char* str);
int remove_bad_prefix(char* str);
int is_chapter(const char* a);
int is_valid(const char* a);
int is_rome   (const char  a);

int main(int argc, const char* argv[]) {
    const char* input_file  = argc > 1 ? argv[1] : (const char*)BASE_INPUT_FILE;
    const char* output_file = BASE_OUTPUT_FILE;

    FILE* read_stream = fopen(input_file, "r");

    if (!read_stream) {
        LOG_FATAL("FILE ");
        fprintf(stderr, "%s ", input_file);
        LOG_FATAL("NOT EXIST\n");

        return 1;
    }

    FILE* write_stream = fopen(output_file, "w");
    assert(write_stream);

    char* curr_str = (char*)calloc(MAX_LINE, sizeof(char));
    int is_fictitious = 0;

    while(fgets(curr_str, MAX_LINE, read_stream)) {
        remove_rome_number(curr_str);
        remove_bad_prefix(curr_str);

        is_fictitious = 0;
        is_fictitious |= is_chapter(curr_str);
        is_fictitious |= !is_valid(curr_str);

        if (!is_fictitious)  fputs(curr_str, write_stream);
        else if (curr_str[1]) puts(curr_str);
    }

    fclose(read_stream);
    fclose(write_stream);
    return 0;
}

int is_chapter(const char* str) {
    assert(str);

    static const char CHAP_1[8] = "Chapter";
    static const char CHAP_2[14] = "Eugene Onegin";

    return !strncmp(str, CHAP_1, sizeof(CHAP_1) - 1) || \
           !strncmp(str, CHAP_2, sizeof(CHAP_2) - 1);
}

int is_valid (const char* a) {
    assert(a);

    int cnt_upper = 0;
    int cnt_lower = 0;

    while (*a) {
        if (isalpha(*a)) {
            cnt_lower += !islower(*a);
            cnt_upper += !isupper(*a);
        }
        a++;
    }

    return cnt_lower && cnt_upper;
}

int is_rome(const char a) {
    static const char* const ROME_NUMS = "cxvil";
    int a_is_rome = 0;
    for(int i = 0; i < 6; ++i) a_is_rome |= ROME_NUMS[i] == tolower(a);

    return a_is_rome;
}

int remove_rome_number(char* str) {
    assert(str);

    int i = 0;
    int all_is_rome = 1;

    if (str[0] == 'I') i++;

    if (!isalpha(str[i]) || str[1] == '.') return 1;

    while (isalpha(str[i]) && all_is_rome) all_is_rome &= is_rome(str[i++]);

    if (all_is_rome) {
        *str = str[i];
        while(str[i] != 0) {
            str++;
            *str = str[i];
        }
    }

    return 1;
}

int remove_bad_prefix(char* str) {
    assert(str);

    int i = 0;

    while (isdigit(str[i]) || str[i] == ' ') i++;

    *str = str[i];
    while(str[i] != 0) {
        str++;
        *str = str[i];
    }

    return 1;
}
