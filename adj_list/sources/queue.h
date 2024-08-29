#ifndef  QUEUE
#define  QUEUE

#include <math.h>

struct queue {
    int* begin, * back, * front;
};

queue que_init(size_t size);
void  push_back(queue* que, int num);
void  que_clear(queue* que);
bool  empty(queue* que);
int   pop_front(queue* que);

#endif //QUEUE
