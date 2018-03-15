#include <stdio.h>
#include <stdlib.h>

Node *newNode(int dest) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->dest = dest;
    node->next = NULL;
    return node;
}

graph *create_graph(int V) {
    graph *graph = (graph *) malloc(sizeof(graph));
    graph->V = V;

    graph->array = (AdjList *) malloc(V * sizeof(AdjList));

    int i;
    for (i = 0; i < V; i += 1) {
        graph->array[i].head = NULL;
    }

    return graph;
}

void add_edge(graph *graph, int src, int dest) {
    Node *node = newNode(dest);
    node->next = graph->array[src].head;
    graph->array[src].head = node;

    node = newNode(src);
    node->next = graph->array[dest].head;
    graph->array[dest].head = node;
}

void print_graph(graph *g) {
    int i;
    for (i = 0; i < g->nb_vertices; i += 1) {
        node *pcrawl = graph->list[i].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl) {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

int main(void) {
    int nb_vertices = 5;

    graph *g = create_graph(nb_vertices);

    add_edge(g, 0, 1);
    add_edge(g, 0, 4);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 1, 4);
    add_edge(g, 2, 3);
    add_edge(g, 3, 4);

    print_graph(g);
    return 0;
}
