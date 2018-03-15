#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "incidence_matrix.h"

// Private prototypes
int check_edge(const matrix * const m, index v1, index v2);

// Interface implementation

matrix *load(FILE * const inf) {
    
    // Check input argument
    if (inf == NULL) return NULL;

    // Allocate matrix struct and helper variables
    matrix *m = (matrix *) malloc(sizeof(matrix));
    unsigned int i, j, v1, v2, nb_vertices, nb_edges;
    float tmp;

    // Read first line of the file as number of vertices and edges
    fscanf(inf, "%u %u", &nb_vertices, &nb_edges);
    if (nb_vertices > MAX_VERTICES || nb_edges > MAX_EDGES) return NULL;

    // Set up matrix structure
    m->lines = nb_vertices;
    m->columns = nb_edges;
    m->values = (float **) malloc(sizeof(float *));
    for (i = 0; i < nb_vertices; i += 1) {
        m->values[i] = (float *) malloc(sizeof(float) * nb_edges);
        //memset(m->values[i], 0.0f, nb_edges * sizeof(float));
    }
    m->unused_edges = NULL;
    m->nb_unused = 0;

    // Set up matrix values
    for (i = 0; i < nb_edges; i += 1) {
        fscanf(inf, "%u %u %f", &v1, &v2, &tmp);
        m->values[v1][i] = m->values[v2][i] = tmp;
        for (j = 0; j < nb_vertices; j += 1) {
            if (j != v1 && j != v2) {
                m->values[j][i] = 0.0;
            }
        }
    }

    return m;

}

void save(FILE * const outf, const matrix * const m) {

    // Check output file
    if (outf == NULL) return;

    // Helper variables
    unsigned int i, v1 = 0, v2;

    // Print first line as number of vertices and number of edges
    fprintf(outf, "%u\t%u\n", m->lines, m->columns);

    // Print all (vertex1, vertex2, value) triples
    for (i = 0; i < m->columns; i += 1) {
        while (v1 < m->lines && m->values[v1][i] == 0.0) v1 += 1;
        // Case of an unused edge entry
        if (v1 == m->lines) continue;
        v2 = v1 + 1;
        while (m->values[v2][i] == 0.0) v2 += 1;
        fprintf(outf, "%u\t%u\t%f\n", v1, v2, m->values[v1][i]); 
        fprintf(outf, "%u\t%u\t%f\n", v2, v1, m->values[v2][i]); 
    }
}


bool adjacent(const matrix * const m, index v1, index v2) {
    
    unsigned int i = 0;
    int found = 0, v1_found = 0;
    while (!found) {
        while (i < m->columns && !m->values[v1][i]) i += 1;
        if (i < m->columns && m->values[v2][i] != 0.0) {
            found = 1;
        } else if (i >= m->columns) {
            found = -1;
        }
    }

    return (found == 1 ? true : false);
    
}

index add_vertex(matrix * const m) {

    m->lines += 1;
    m->values = (float **) realloc(m->values, m->lines * sizeof(float *));

    return m->lines - 1;

}

void remove_vertex(matrix * const m, index vertex) {

    // Remove all edges from/to the vertex to remove
    
    // Swap last vertex with vertex to remove

    // Truncate matrix
    
}

void add_edge(matrix * const m, index v1, index v2, float value) {
    if (!check_edge(m, v1, v2) || adjacent(m, v1, v2)) return;
    
    unsigned int i;

    if (m->unused_edges == NULL) {
        m->columns += 1;
        for (i = 0; i < m->lines; i += 1) {
            m->values[i] = (float *) realloc(m->values[i], m->columns * sizeof(float));
            m->values[i][m->columns - 1] = 0.0f;
        }
    } else {
        m->nb_unused -= 1;
        m->values[v1][m->unused_edges[m->nb_unused]] = value;
        m->values[v2][m->unused_edges[m->nb_unused]] = value;
        if (m->nb_unused == 0) {
            free(m->unused_edges);
        } else {
            m->unused_edges = (unsigned int *) realloc(m->unused_edges, m->nb_unused * sizeof(unsigned int));
        }
   }

}

void remove_edge(matrix * const m, index v1, index v2) {
    if (!check_edge(m, v1, v2)) return;
}


int check_edge(const matrix * const m, index v1, index v2) {
    return v1 >= m->lines && v2 >= m->lines;
}

