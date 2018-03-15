#include "adjacencymatrix.h"


graph *init_graph_with_weights(size_t nb_vertices, double **weights) {
    
    unsigned int i, j;
    graph *g = (graph *) malloc(sizeof(graph));
    g->nb_vertices = nb_vertices;
    g->weights = (double **) malloc(sizeof(double *) * nb_vertices);
    for (i = 0; i < nb_vertices; i += 1) {
        g->weights[i] = (double *) malloc(sizeof(double) * nb_vertices);
        for (j = 0; j < nb_vertices; j += 1) {
            g->weights[i][j] = weights[i][j];
        }
    }
    return g;

}

graph *init_graph(size_t nb_vertices) {

    unsigned int i, j;
    graph *g = (graph *) malloc(sizeof(graph));
    g->nb_vertices = nb_vertices;
    g->weights = (double **) malloc(sizeof(double *) * nb_vertices);
    for (i = 0; i < nb_vertices; i += 1) {
        g->weights[i] = (double *) malloc(sizeof(double) * nb_vertices); 
        for (j = 0; j < nb_vertices; j += 1) {
            g->weights[i][j] = 0.0;
        }
    }
    return g;

}

void add_edge(graph * const g, unsigned int v1, unsigned int v2, double weight) {
    if (v1 < g->nb_vertices && v2 < g->nb_vertices) {
        g->weights[v1][v2] = weight;
    }
}

void remove_edge(graph * const g, unsigned int v1, unsigned int v2) {
    add_edge(g, v1, v2, 0.0);
}


void print_graph(const graph * const g) {

    unsigned int i, j;
    for (i = 0; i < g->nb_vertices; i+= 1) {
        for (j = 0; j < g->nb_vertices; j += 1) {
            printf("\t%lf", g->weights[i][j]);
        }
        printf("\n");
    }

}
