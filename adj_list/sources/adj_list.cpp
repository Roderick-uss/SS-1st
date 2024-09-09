#include <assert.h>
#include <math.h>
#include <malloc.h>
#include <stdio.h>

#include "adj_list.h"
#include "commoner.h"
#include "io.h"
#include "run_error.h"
#include "queue.h"

static void graph_assert(Graph graph) {
    assert(graph.size);
    assert(graph.sizes);
    assert(graph.self);
}

static void add_edge(Edge* pos, Edge edge) {
    assert(pos);

    *pos = edge;
    return;
}

Graph create_graph(size_t size, size_t* sizes) {
    assert(sizes);
    assert(size);

    Graph graph = {};
    graph.size = size;
    graph.sizes = sizes;
    graph.self = (Edge**)calloc(size, sizeof(Edge*));

    for (size_t i = 0; i < size; ++i) {
        assert(i < size);

        graph.self[i] = (Edge*)calloc(sizes[i], sizeof(Edge));

        if (!graph.self[i]) run_memory_error(sizes[i] * sizeof(Edge));
    }

    return graph;
}

void clear_graph(Graph graph) {
    graph_assert(graph);

    for (size_t i = 0; i < graph.size; ++i) {
        assert(i < graph.size);

        FREE(graph.self[i]);
    }
    FREE(graph.self);
    FREE(graph.sizes);
    graph.size = 0;
    return;
}

void bfs(Graph graph, int root) {
    graph_assert(graph);

    bool* is_vert_used  = (bool*)calloc(graph.size, sizeof(bool));
    int*  vert_deep  = (int* )calloc(graph.size, sizeof(int ));
    queue order = que_init(graph.size);

    if(!is_vert_used) run_memory_error(1);
    if(!vert_deep) run_memory_error(1);

    push_back(&order, root);
    int curr_vert = 0;
    Edge now_edge = {};
    is_vert_used[root] = 1;

    while(!empty(&order)) {
        curr_vert = pop_front(&order);

        for (size_t i = 0; i < graph.sizes[curr_vert]; ++i) {
            now_edge = graph.self[curr_vert][i];

            if (!is_vert_used[now_edge.node]) {
                is_vert_used[now_edge.node] = 1;
                vert_deep[now_edge.node] = vert_deep[curr_vert] + 1;
                push_back(&order,now_edge.node);
            }
        }
    }

    FREE(is_vert_used);
    que_clear(&order);

    printf("\n");
    for(size_t i = 0; i < graph.size; ++i) LOG_INFO("%2llu ", i + 1);
    printf("\n");
    for(size_t i = 0; i < graph.size; ++i) printf("%2d ", vert_deep[i]);
    printf("\n");
    return;

    FREE(vert_deep);

    return;
}

Graph input_graph() {
    struct edge_in {
        int node1, node2, weight;
    };

    size_t size   = (size_t)enter_one_int("Enter the number of nodes");
    size_t n_edge = (size_t)enter_one_int("Enter the number of edges");
    size_t* node_i = (size_t*)  calloc(size,   sizeof(size_t));
    size_t*  sizes = (size_t*)  calloc(size,   sizeof(size_t));
    edge_in* edges = (edge_in*) calloc(n_edge, sizeof(edge_in));

    if(!node_i) run_memory_error(size   * sizeof(size_t));
    if(!sizes)  run_memory_error(size   * sizeof(size_t));
    if(!edges)  run_memory_error(n_edge * sizeof(edge_in));

    edge_in* now = NULL;

    LOG_INFO("Enter edges in order node node weith\n");

    for (size_t i = 0; i < n_edge; ++i) {
        now = &edges[i];

        enter_edge(&(now->node1 ),
                   &(now->node2 ),
                   &(now->weight));

        sizes[--(now->node1)]++;
        sizes[--(now->node2)]++;
    }

    Graph graph = create_graph(size, sizes);

    for (size_t i = 0; i < n_edge; ++i) {
        assert(i < n_edge);
        now = &edges[i];

        add_edge(graph.self[now->node1] + node_i[now->node1]++, {now->node2, now->weight});
        add_edge(graph.self[now->node2] + node_i[now->node2]++, {now->node1, now->weight});
    }

    FREE(node_i);
    FREE(edges);

    return graph;
}

void print_graph(Graph graph) {
    graph_assert(graph);
    LOG_INFO("\nNodes and their edges\n\n");
    Edge now = {};

    for(size_t i = 0; i < graph.size; ++i) {
        LOG_INFO("%llu ]", i + 1);
        assert(i < graph.size);
        for (size_t j = 0; j < graph.sizes[i]; ++j) {
            assert(j < graph.sizes[i]);
            now = graph.self[i][j];
            printf(" -(%d)> %d |", now.weight, now.node + 1);
        }
        printf("\n");
    }
    printf("\n");
}
