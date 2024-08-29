#ifndef IO11
#define IO11

#include <math.h>
#include <stdio.h>

void  endl();
void  print_line(void* data, size_t size);
int   enter_edge(int* node, int* node2, int* weight);
int   enter_one_int(const char* const intro);
FILE* enter_file_name(const char* const file_content);


#endif //IO
