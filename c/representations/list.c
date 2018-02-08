#include "list.h"

typedef struct Vertex {
    char label;
    int value;
    Edge *edges;
} Vertex;

typedef struct Edge {
    Vertex *head;
    Vertex *tail;
    int weight;
} Edge;


typedef struct Graph {
    Vertex *vertices;
    Edge *edges;
} Graph;

Graph *create_graph(int nb_vertices, int nb_edges) {
    Graph *graph = (Graph *) malloc(sizeof(Graph));
    graph->vertices = (Vertex *) malloc(sizeof(Vertex) * nb_vertices);
    graph->edges = (Edge *) malloc(sizeof(Edge) * nb_edges);
    return graph;
}

void addVertex(const Graph *graph, int value) {
    
}

void destroy_graph(const Graph *graph) {
    free(graph->vertices);
    free(graph->edges);
    free(graph);
}

int main(int argc, char *argv[]) {

    

    return 0;

}
