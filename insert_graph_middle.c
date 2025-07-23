#include <stdio.h>
#include <stdlib.h>

// Graph node structure (adjacency list)
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Graph structure
typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;

// Create a node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Create a graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = (Node**)malloc(vertices * sizeof(Node*));
    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;
    return graph;
}

// Insert edge at the middle of adjacency list
void insertEdgeMiddle(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);

    Node* head = graph->adjLists[src];
    if (head == NULL) {
        graph->adjLists[src] = newNode;
        return;
    }

    // Count nodes
    int count = 0;
    Node* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }

    int mid = count / 2;
    temp = head;
    for (int i = 0; i < mid - 1; i++)
        temp = temp->next;

    if (mid == 0) {
        newNode->next = head->next;
        head->next = newNode;
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Print graph
void printGraph(Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        Node* temp = graph->adjLists[v];
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
    int V = 5;
    Graph* graph = createGraph(V);

    insertEdgeMiddle(graph, 0, 1);
    insertEdgeMiddle(graph, 0, 2);
    insertEdgeMiddle(graph, 0, 3); // Insert in middle
    insertEdgeMiddle(graph, 0, 4); // Insert in middle

    printGraph(graph);

    // Free memory (not shown for brevity)
    return 0;
}