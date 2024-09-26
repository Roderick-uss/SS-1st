#ifndef COMMON
#define COMMON

#include "colors.h"

#define LOG_CERR( str, ...) fprintf(stderr, YELLOW str WHITE __VA_OPT__(,) __VA_ARGS__)
#define LOG_INFO( str, ...) fprintf(stderr, GREEN str WHITE __VA_OPT__(,) __VA_ARGS__)
#define LOG_FATAL(str, ...) fprintf(stderr, RED str WHITE __VA_OPT__(,) __VA_ARGS__)

#define FREE(data) {free(data); (data) = NULL;}

struct STRING_t {
    const char* begin;
    size_t size;
};

void* get_i(void* data, size_t index, size_t num_of_elemenst, size_t size_of_elements);
void swap_memory(void* x1, void* x2, size_t size);
void swap_memory_2(void* x1, void* x2, size_t size);
void swap_1b(void * x1, void* x2);
void swap_2b(void * x1, void* x2);
void swap_4b(void * x1, void* x2);
void swap_8b(void * x1, void* x2);

#endif // COMMON
