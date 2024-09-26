#ifndef  ONEGIN_TEXT
#define  ONEGIN_TEXT

#include "commoner.h"

struct Text {
    char* buffer;       ///< buffer asdfadsf
    size_t buffer_size;
    STRING_t* lines;
    size_t n_lines;
};

int  read_onegin(Text* text);
void free_onegin(Text* text);
void print_onegin(const Text* const text);
void print_clean_onegin(const Text* const text);
void text_assert(const Text* const text);

#endif// ONEGIN_TEXT
