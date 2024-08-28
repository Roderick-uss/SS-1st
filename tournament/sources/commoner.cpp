#include<math.h>
#include<stdint.h>

#include "commoner.h"

void swap(void* x1, void* x2) {
    uint64_t* a = (uint64_t*)x1;
    uint64_t* b = (uint64_t*)x2;
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
    return;
}
