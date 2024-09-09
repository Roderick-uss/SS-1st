#include <math.h>

#include "adj_list.h"

int main() {
    Graph graph = input_graph();
    print_graph(graph);
    bfs(graph, 0);
    clear_graph(graph);
    return 0;
}
