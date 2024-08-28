#ifndef COMMONER
#define COMMONER

#include "colors.h"

#define LOG_FATAL(str, ...) printf(RED str WHITE __VA_OPT__(,) __VA_ARGS__)
#define LOG_INFO(str,  ...) printf(GREEN str WHITE __VA_OPT__(,) __VA_ARGS__)
#define LOG_CERR(str, ...)   fprintf(stderr, YELLOW str WHITE __VA_OPT__(,) __VA_ARGS__)

#define FREE(data) {free(data); data = NULL;}

void swap(void* a, void* b);

#endif // COMMONER
