#ifndef IO
#define IO

#include <math.h>

#include "tournament.h"

void print_line(void* data, size_t size);
void endl();
int enter_one_number(const char* const intro);
Game* enter_games_file(size_t* x_size, size_t* game_num);


#endif // IO
