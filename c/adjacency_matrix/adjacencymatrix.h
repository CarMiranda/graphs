#ifndef ADJACENCY_MATRIX_H
#define ADJACENCY_MATRIX_H

typedef struct graph {
    size_t nb_vertices;
    double **weights;
} graph;

graph *init_graph_with_weights(size_t nb_vertices, double **weights);
graph *init_graph(size_t nb_vertices);
void add_edge(graph * const g, unsigned int v1, unsigned int v2, double weight);
void remove_edge(graph * const g, unsigned int v1, unsigned v2);
void print_graph(const graph * const g);

#endif
