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
        case SPACE:
        default:
            break;
    }
    return res;
}
