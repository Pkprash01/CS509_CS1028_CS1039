#include "sssp.hpp"
#include <cstdlib>
#include <climits>

// Function to initialize and create graph memory
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    // Allocate memory for array of pointers
    graph->head = (struct AdjListNode**)malloc(numVertices * sizeof(struct AdjListNode*));

    // Set all head pointers to NULL initially
    for (int i = 0; i < numVertices; i++) {
        graph->head[i] = NULL;
    }

    return graph;
}

// Function to add a directed edge from src to dest
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    // Create new node
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;

    // Insert new node at beginning of linked list for 'src'
    newNode->next = graph->head[src];
    graph->head[src] = newNode;
}

// Function to free all allocated graph memory
void freeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct AdjListNode* current = graph->head[i];
        while (current != NULL) {
            struct AdjListNode* temp = current;
            current = current->next;
            free(temp); // Free node
        }
    }
    free(graph->head); // Free array of heads
    free(graph);       // Free graph structure
}

// Dijkstra's Single Source Shortest Path Algorithm
int* runSSSP(struct Graph* graph, int startNode) {
    int V = graph->numVertices;

    // Allocate dynamic arrays for output distances and visited state
    int* dist = (int*)malloc(V * sizeof(int));
    bool* visited = (bool*)malloc(V * sizeof(bool));

    // Initialize all distances to INFINITY and visited array to false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    // Distance to starting node is always 0
    dist[startNode] = 0;

    // Loop through all vertices
    for (int count = 0; count < V - 1; count++) {
        int minDistance = INT_MAX;
        int minIndex = -1;

        // Step 1: Pick vertex with minimum distance from unvisited nodes
        for (int v = 0; v < V; v++) {
            if (!visited[v] && dist[v] <= minDistance) {
                minDistance = dist[v];
                minIndex = v;
            }
        }

        // If no vertex is reachable, break loop early
        if (minIndex == -1) {
            break;
        }

        int u = minIndex;
        visited[u] = true; // Mark node as processed

        // Step 2: Update distances of adjacent vertices of current node 'u'
        struct AdjListNode* crawler = graph->head[u];
        while (crawler != NULL) {
            int v = crawler->dest;
            int weight = crawler->weight;

            // Relaxation condition check
            if (!visited[v] && dist[u] != INT_MAX && (dist[u] + weight < dist[v])) {
                dist[v] = dist[u] + weight;
            }
            crawler = crawler->next; // Move to next neighbor
        }
    }

    // Clean up temporary boolean array
    free(visited);

    return dist; // Return dynamically allocated shortest path distance array
}