#ifndef ADJ_LIST
#define ADJ_LIST

#include <math.h>

struct Edge{
    int node;
    int weight;
};

struct Graph{
    size_t size;
    size_t* sizes;
    Edge** self;
};

void  bfs(Graph graph, int root);
void  clear_graph(Graph graph);
void  print_graph(Graph graph);
Graph create_graph(size_t size, size_t* sizes);
Graph input_graph();

#endif // ADJ_LIST
