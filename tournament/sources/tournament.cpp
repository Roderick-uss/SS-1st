#include "tournament.h"

TOURNAMENT res_swap(TOURNAMENT res) {
    switch(res) {
        case VICT:
            res = LOSS;
            break;
        case LOSS:
            res = VICT;
            break;
        case DRAW:
            break;
        case SPACE:
            break;
        default:
            break;
    }
    return res;
}
