#ifndef TOUR
#define TOUR

#include <math.h>

enum TOURNAMENT {
    SPACE = -1,
    LOSS = 0,
    VICT = 2,
    DRAW = 1,
};

struct Game {
    size_t p1, p2;
    TOURNAMENT res;
};


TOURNAMENT res_swap(TOURNAMENT res);

#endif // TOUR
