#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int dest;
    struct Node *next;
} Node;

typedef struct AdjList {
    Node *head;
} AdjList;

typedef struct Graph {
    int V;
    AdjList *array;
} Graph;

Node *newNode(int dest) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->dest = dest;
    node->next = NULL;
    return node;
}

Graph *createGraph(int V) {
    Graph *graph = (Graph *) malloc(sizeof(Graph));
    graph->V = V;

    graph->array = (AdjList *) malloc(V * sizeof(AdjList));

    int i;
    for (i = 0; i < V; i += 1) {
        graph->array[i].head = NULL;
    }

    return graph;
}

void addEdge(Graph *graph, int src, int dest) {
    Node *node = newNode(dest);
    node->next = graph->array[src].head;
    graph->array[src].head = node;

    node = newNode(src);
    node->next = graph->array[dest].head;
    graph->array[dest].head = node;
}

void printGraph(Graph *graph) {
    int v;
    for (v = 0; v < graph->V; v += 1) {
        Node *pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl) {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

int main(void) {
    int V = 5;
    Graph *graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);
    return 0;
}
