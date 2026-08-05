#ifndef SSSP_H
#define SSSP_H

// Node for weighted adjacency list
struct AdjListNode {
    int dest;
    int weight;
    struct AdjListNode* next;
};

// Graph structure
struct Graph {
    int numVertices;
    struct AdjListNode** head;
};

// Function prototypes
struct Graph* createGraph(int numVertices);
void addEdge(struct Graph* graph, int src, int dest, int weight);
void freeGraph(struct Graph* graph);
int* runSSSP(struct Graph* graph, int startNode);

#endif // SSSP_H