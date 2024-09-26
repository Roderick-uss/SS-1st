#include <assert.h>
#include <stdio.h>

#include "commoner.h"
#include "sorter.h"

void bubble_sort(void* base, size_t size, size_t el_size, cmp_t cmp) {
    assert(base);

    for (size_t last_pos = size - 2; last_pos >= 1; --last_pos) {
        for(size_t i = 0; i <= last_pos; ++i) {
            void* a = (char*)base + el_size * i;
            void* b = (char*)base + el_size * (i + 1);

            if (cmp(a, b) > 0) {
                swap_memory(a, b, el_size);
            }
        }
    }

    return;
}

void quic_sort(void* base, size_t size, size_t el_size, cmp_t cmp) {
    assert(base);

    if (size <= 1) return;

    void* left  = (char*)base - el_size;
    void* right = (char*)base + el_size * (size - 1);
    void* pivot = right;

    while ((char*)left + el_size < (char*)right) {
        left  = (char*)left + el_size;
        if (cmp(left, pivot) > 0) {
            do {
                right = (char*)right - el_size;
            } while (cmp(right, pivot) > 0 && right != left);

            swap_memory_2(left, right, el_size);
        }
    }

    swap_memory_2(pivot, right, el_size);
    size_t left_size = ((char*)right - (char*)base) / el_size;
    right = (char*)right + el_size;

    quic_sort(base,  left_size,            el_size, cmp);
    quic_sort(right, size - left_size - 1, el_size, cmp);

    return;
}
