#ifndef COMMON
#define COMMON

#include "colors.h"

#define LOG_CERR( str, ...) fprintf(stderr, YELLOW str WHITE __VA_OPT__(,) __VA_ARGS__)
#define LOG_INFO( str, ...) printf(GREEN str WHITE __VA_OPT__(,) __VA_ARGS__)
#define LOG_FATAL(str, ...) fprintf(stderr, RED str WHITE __VA_OPT__(,) __VA_ARGS__)

#define FREE(data) {free(data); (data) = NULL;}

void* get(void* data, size_t index, size_t num_of_elemenst, size_t size_of_elements);
void swap(void* a, void* b);

#endif // COMMON
