#include <math.h>

#include "adjacency_list.h"

int main() {
    graph g = input_graph();
    print_graph(g);
    bfs(g, 0);
    clear_graph(g);
    return 0;
}
