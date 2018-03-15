#ifndef INCIDENCEMATRIX_H
#define INCIDENCEMATRIX_H

#include <stdbool.h>

#define MAX_VERTICES 20
#define MAX_EDGES 20

typedef const unsigned int index;

// Representation as a 2D array
typedef struct matrix {
    unsigned int *unused_edges;
    unsigned int lines, columns, nb_unused;
    float **values;
} matrix;

matrix *load(FILE * const inf);
void save(FILE * const outf, const matrix * const m);

bool adjacent(const matrix * const m, index v1, index v2);
index *neighbours(const matrix * const m, index v);

index add_vertex(matrix * const m);
void remove_vertex(matrix * const m, index v);

void add_edge(matrix * const m, index v1, index v2, float value);
void remove_edge(matrix * const m, index v1, index v2);

float get_edge_value(const matrix * const m, index v1, index v2);
void set_edge_value(const matrix * const m, index v1, index v2);

#endif
