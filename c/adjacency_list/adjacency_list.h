#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H

#include "../common/linked_list.h"

typedef struct graph {
    size_t nb_vertices;
    linked_list *vertices;
} graph;

graph *create_graph(size_t);
void destroy_graph(graph *);

label add_vertex(graph *, vertex_val);
void add_edge(graph *, unsigned int, unsigned int);
void print_graph(graph *);

#endif
