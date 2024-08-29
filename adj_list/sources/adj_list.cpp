#include <assert.h>
#include <math.h>
#include <malloc.h>
#include <stdio.h>

#include "adj_list.h"
#include "commoner.h"
#include "io.h"
#include "run_error.h"
#include "queue.h"

static void add_edge(edge* pos, edge e) {
    *pos = e;
    return;
}

graph create_graph(size_t size, size_t* sizes) {
    graph g = {};
    g.size = size;
    g.sizes = sizes;
    g.self = (edge**)calloc(size, sizeof(edge*));

    for (size_t i = 0; i < size; ++i) {
        assert(i < size);
        g.self[i] = (edge*)calloc(sizes[i], sizeof(edge));

        if (!g.self[i]) {
            run_memory_error(sizes[i] * sizeof(edge));
            return {};
        }
    }

    return g;
}

void clear_graph(graph g) {
    for (size_t i = 0; i < g.size; ++i) {
        assert(i < g.size);
        FREE(g.self[i]);
    }
    FREE(g.self);
    FREE(g.sizes);
    g.size = 0;
    return;
}

void bfs(graph g, int root) {
    bool* used  = (bool*)calloc(g.size, sizeof(bool));
    int*  deep  = (int* )calloc(g.size, sizeof(int ));
    queue order = que_init(g.size);

    if(!used) run_memory_error(1);
    if(!deep) run_memory_error(1);

    push_back(&order, root);
    int now = 0;
    edge now_edge = {};
    used[root] = 1;

    while(!empty(&order)) {
        now = pop_front(&order);

        for (size_t i = 0; i < g.sizes[now]; ++i) {
            now_edge = g.self[now][i];

            if (!used[now_edge.node]) {
                used[now_edge.node] = 1;
                deep[now_edge.node] = deep[now] + 1;
                push_back(&order,now_edge.node);
            }
        }
    }

    FREE(used);
    que_clear(&order);

    endl();
    print_line(deep, g.size);

    FREE(deep);

    return;
}

graph input_graph() {
    struct edge_in {
        int node1, node2, weight;
    };

    size_t size   = (size_t)enter_one_int("Enter the number of nodes");
    size_t n_edge = (size_t)enter_one_int("Enter the number of edges");
    size_t* node_i = (size_t*)  calloc(size,   sizeof(size_t));
    size_t*  sizes = (size_t*)  calloc(size,   sizeof(size_t));
    edge_in* edges = (edge_in*) calloc(n_edge, sizeof(edge_in));

    if(!node_i) run_memory_error(1);
    if(!sizes)  run_memory_error(1);
    if(!edges)  run_memory_error(1);

    edge_in* now;

    LOG_INFO("Enter edges in order node node weith\n");

    for (size_t i = 0; i < n_edge; ++i) {
        now = &edges[i];

        enter_edge(&(now->node1 ),
                   &(now->node2 ),
                   &(now->weight));

        sizes[--(now->node1)]++;
        sizes[--(now->node2)]++;
    }

    graph g = create_graph(size, sizes);

    for (size_t i = 0; i < n_edge; ++i) {
        now = &edges[i];

        add_edge(g.self[now->node1] + node_i[now->node1]++, {now->node2, now->weight});
        add_edge(g.self[now->node2] + node_i[now->node2]++, {now->node1, now->weight});
    }

    FREE(node_i);
    FREE(edges);

    return g;
}

void print_graph(graph g) {
    LOG_INFO("\nNodes and their edges\n\n");
    edge now;

    for(size_t i = 0; i < g.size; ++i) {
        LOG_INFO("%llu ]", i + 1);
        for (size_t j = 0; j < g.sizes[i]; ++j) {
            now = g.self[i][j];
            printf(" -(%d)> %d |", now.weight, now.node + 1);
        }
        endl();
    }
    endl();
}
