#include<assert.h>
#include<math.h>

#include "list_base.h"

/*
    @brief get element from list
    @param data - list
    @param i - index of element
    @param size - size of list
    returns address of element
    @errors - out of list
*/

void* get_1d(void* data, size_t index, size_t num_of_elemenst, size_t size_of_elements) {
    assert(index < num_of_elemenst);
    return (void*)((size_t)data + index * size_of_elements);
}

void* get_2d(void* data, size_t i, size_t j, size_t height, size_t width, size_t size_of_elements) {
    //* return get_1d(get_1d(data, i * width, width * height), j, width);
    assert(i < height);
    assert(j < width);
    return (void*)((size_t)data + i * width * size_of_elements + j * size_of_elements);
    //* (void*)((size_t)data + i * width * sizeof(int) + j * sizeof(int));
}
