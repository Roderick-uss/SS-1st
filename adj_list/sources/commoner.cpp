#include <assert.h>
#include <math.h>
#include <stdint.h>

#include "commoner.h"

void swap(void* x1, void* x2) {
    uint64_t* a = (uint64_t*)x1;
    uint64_t* b = (uint64_t*)x2;
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
    return;
}

void* get(void* data, size_t index, size_t num_of_elemenst, size_t size_of_elements) {
    assert(index < num_of_elemenst);
    return (void*)((size_t)data + index * size_of_elements);
}

