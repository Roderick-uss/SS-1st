#include<math.h>

#include "tournament.h"
#include "treangle.h"

int main() {
//    size_t x_size = (size_t)enter_one_number("Enter the number of participants:");
//    TOURNAMENT* tour = create_treangle(x_size);
/*
    print_tournament(tour, x_size);
    endl();
    game_res(tour, x_size, 1, 1, 2, VICT);
    game_res(tour, x_size, 2, 4, 2, DRAW);
    game_res(tour, x_size, 3, 3, 2, LOSS);
    game_res(tour, x_size, 4, 3, 1, LOSS);
    game_res(tour, x_size, 5, 1, 4, DRAW);
    game_res(tour, x_size, 6, 4, 3, LOSS);
*/
    size_t x_size = 0;
    TOURNAMENT* tour = go_tournament(&x_size);
    print_tournament(tour, x_size);
    clear_treangle(tour);
    return 0;
}
