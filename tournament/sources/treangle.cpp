#include <malloc.h>
#include <math.h>

#include "commoner.h"
#include "io.h"
#include "list_base.h"
#include "tournament.h"
#include "treangle.h"

static size_t get_size(size_t num) {
    return num * (num - 1) / 2;
}

static void mem_set(TOURNAMENT* data, TOURNAMENT element, size_t num_of_elements) {
    for (size_t i = 0; i < num_of_elements; ++i) *(data + i) = element;
}

void game_res(TOURNAMENT* data, size_t x_size, int game_num, game g) {
    if (g.p1 > g.p2) {
        swap(&g.p1, &g.p2);
        g.res = res_swap(g.res);
    }

    size_t pos = get_size(g.p2 - 1) + g.p1 - 1;

    if (g.p1 == g.p2 ||  g.p1 > x_size || g.p2 > x_size) {
        if (g.p1 == g.p2)                  run_game_error(game_num, g.p1, "Simmular players"     );
        if (g.p1 > x_size)                 run_game_error(game_num, g.p1, "Player is out of list");
        if (g.p1 != g.p2 && g.p2 > x_size) run_game_error(game_num, g.p2, "Player is out of list");
        endl();
        return;
    }

    *(TOURNAMENT*)(get_1d((void*)data, pos, get_size(x_size), sizeof(TOURNAMENT))) = g.res;

    return;
}

void clear_treangle(TOURNAMENT* data) {
    FREE(data);

    return;
}

TOURNAMENT* create_treangle(size_t x_size) {
    size_t size = get_size(x_size);

    TOURNAMENT* data = (TOURNAMENT*)calloc(size, sizeof(TOURNAMENT));
    mem_set(data, SPACE, size);

    return data;
}

static void print_tour_line(TOURNAMENT* data1, size_t size1, TOURNAMENT*data2, size_t size2) {
    for (size_t i = 0; i < size1; ++i) print_cell(*(data1 + i));

    print_cell(SPACE);

    for (size_t i = size2; i > 0; --i) print_cell(res_swap(*(data2 + (i - 1))));
}

void print_tournament(TOURNAMENT* data, size_t x_size) {
    for (size_t part = 0; part <= x_size; part++) print_cell_num((int)part);
    endl();
    for (size_t i = 0; i <= x_size; i++)          print_cell_num(-1);
    endl();

    size_t opp_part;

    for (size_t part = 0; part < x_size; ++part) {
        opp_part = x_size - part - 1;
        print_cell_num((int)part + 1);
        print_tour_line(data + get_size(part), part, data + (get_size(opp_part)), opp_part);
        endl();
    }

    return;
}

TOURNAMENT* go_tournament(size_t* x_size) {
    size_t game_num = NULL;
    game* g = enter_games_file(x_size, &game_num);
    game* game_now = NULL;
    TOURNAMENT* tour = create_treangle(*x_size);

    for (size_t curr_game = 0; curr_game < game_num; ++curr_game) {
        game_now = (game*)get_1d((void*)g, curr_game, game_num, sizeof(game));

        game_res(tour, *x_size, (int)curr_game, *game_now);
    }

    FREE(g);

    return tour;
}
