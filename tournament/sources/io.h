#ifndef IO11
#define IO11

#include <math.h>

#include "tournament.h"

void print_line(void* data, size_t size);
void print_cell_num(int num);
void print_cell (TOURNAMENT res);
void endl();
void run_game_error(int game, size_t p, const char* const error);
int enter_one_number(const char* const intro);
game* enter_games_file(size_t* x_size, size_t* game_num);


#endif //IO
