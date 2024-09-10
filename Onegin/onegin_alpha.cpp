#include<stdio.h>
#include<assert.h>
#include<ctype.h>

enum Text {
    NUM_LINES = 14, ///< number of lines
    MAX_LENGHT = 48 ///< lenght of the longest line
};

void swap_char(long long int* char_a, long long int* char_b);

char* remove_punctuation(char* line);
void swap_str(char* line_a, char* line_b);
int  strcmp_ (char* line_a, char* line_b);

void sort_text (char text[NUM_LINES][MAX_LENGHT]);
void print_text(char text[NUM_LINES][MAX_LENGHT], FILE* stream);

int main() {
    FILE *stream_in  = fopen("onegin.txt", "rt");
    FILE *stream_out = fopen("sorted_onegin.txt", "wt");

    char text[NUM_LINES][MAX_LENGHT] = {};

    for (size_t i = 0; i < (size_t)MAX_LENGHT; ++i)
        fgets(text[i], MAX_LENGHT, stream_in);

    sort_text(text);

    print_text(text, stream_out);

    fclose(stream_out);
    fclose(stream_in);

    return 0;
}

void swap_char(long long int* char_a, long long int* char_b) {
    assert(char_a);
    assert(char_b);

    *char_a ^= *char_b;
    *char_b ^= *char_a;
    *char_a ^= *char_b;

    return;
}

void swap_str(char* line_a, char* line_b) {
    assert(line_a);
    assert(line_b);

    for(size_t i = 0; i < (size_t)MAX_LENGHT; i += sizeof(long long int))
        swap_char((long long int*)(line_a + i), (long long int*)(line_b + i));

    return;
}

char* remove_punctuation(char* line) {
    assert(line);

    while(*line != '\0' && !(isalpha(*line))) ++line;

    return line;
}

int strcmp_(char *line_a, char* line_b) {
    assert(line_a);
    assert(line_b);

    int res = 0;
    while(!res && *line_a) {
        res = (tolower(*remove_punctuation(line_a++)) - tolower(*remove_punctuation(line_b++)));
    }

    return res;
}

void sort_text(char text[NUM_LINES][MAX_LENGHT]) {
    for (size_t pos = NUM_LINES - 1; pos >= 2; --pos) {
        for(size_t line = 0; line < pos; ++line) {
            int cmp_result = strcmp_(text[line], text[line + 1]);

            printf("%d result\n", cmp_result);

            if (cmp_result > 0) swap_str(text[line], text[line + 1]);
        }
    }


    return;
}

void print_text(char text[NUM_LINES][MAX_LENGHT], FILE* stream) {
    for (size_t line = 0; line < (size_t)NUM_LINES; ++line) {
        fprintf(stream, "%-2llu > %s", line + 1, text[line]);
    }

    return;
}
