#ifndef ADJ_LIST
#define ADJ_LIST

#include <math.h>

struct edge{
    int node;
    int weight;
};

struct graph{
    size_t size;
    size_t* sizes;
    edge** self;
};

void  bfs(graph g, int root);
void  clear_graph(graph g);
void  print_graph(graph g);
graph create_graph(size_t size, size_t* sizes);
graph input_graph();

#endif // ADJ_LIST
