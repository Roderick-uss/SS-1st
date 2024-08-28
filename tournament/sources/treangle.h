#ifndef TREANGLE
#define TREANGLE

#include<math.h>

#include "tournament.h"

void clear_treangle(TOURNAMENT* data);
void game_res(TOURNAMENT* data, size_t x_size, int game_num, game g);
TOURNAMENT* create_treangle(size_t x_size);
void print_tournament(TOURNAMENT* data, size_t x_size);
TOURNAMENT* go_tournament(size_t* x_size);

#endif // TREANGLE
