#include <stdio.h>
#include <stdlib.h>

// Structure for adjacency list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Structure for graph
typedef struct Graph {
    int vertices;
    Node** adjList;
} Graph;

// Create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Create a graph with given vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->adjList = (Node**)malloc(vertices * sizeof(Node*));
    for (int i = 0; i < vertices; i++)
        graph->adjList[i] = NULL;
    return graph;
}

// Insert edge at the end of adjacency list
void insertEdgeEnding(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    if (graph->adjList[src] == NULL) {
        graph->adjList[src] = newNode;
    } else {
        Node* temp = graph->adjList[src];
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Print the graph
void printGraph(Graph* graph) {
    for (int v = 0; v < graph->vertices; v++) {
        Node* temp = graph->adjList[v];
        printf("Adjacency list of vertex %d: ", v);
        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Example usage
int main() {
    int vertices = 5;
    Graph* graph = createGraph(vertices);

    insertEdgeEnding(graph, 0, 1);
    insertEdgeEnding(graph, 0, 4);
    insertEdgeEnding(graph, 1, 2);
    insertEdgeEnding(graph, 1, 3);
    insertEdgeEnding(graph, 1, 4);
    insertEdgeEnding(graph, 2, 3);
    insertEdgeEnding(graph, 3, 4);

    printGraph(graph);

    // Free memory (not shown for brevity)
    return 0;
}