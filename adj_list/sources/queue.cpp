#include <math.h>
#include <malloc.h>

#include "queue.h"
#include "commoner.h"
#include "run_error.h"

queue que_init(size_t size) {
    queue que = {};
    que.begin = (int*)calloc(size + 1, sizeof(int));

    if (!que.begin) {
        run_memory_error((size + 1) * sizeof(int));
        return que;
    }

    que.back = que.begin + 1;
    que.front = que.begin;
    return que;
}

void que_clear(queue* que) {
    FREE(que->begin);
    que->back = NULL;
    que->front = NULL;

    return;

}
void push_back(queue* que, int num) {
    *(que->back++) = num;
    return;
}
// todo realloc
int pop_front(queue* que) {
    return *(que->front++);
}

bool empty(queue* que) {
    return que->front + 1 == que->back;
}
