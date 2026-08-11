#include "betweenness_centrality.hpp"
#include <chrono>
#include <iostream>

CentralityResult compute_betweenness_centrality(const CSRGraph& graph) {
    int V = graph.V;
    
    // Allocate raw memory arrays (no STL)
    double* centrality = new double[V];
    for (int i = 0; i < V; ++i) {
        centrality[i] = 0.0;
    }

    // Allocate working memory for Brandes' algorithm
    int* queue = new int[V];
    int* stack = new int[V];
    int* dist = new int[V];
    long long* sigma = new long long[V];
    double* delta = new double[V];
    int* pred_count = new int[V];
    int** predecessors = new int*[V];
    for (int i = 0; i < V; ++i) {
        predecessors[i] = new int[V];
    }

    // Start timer (excluding CSR preprocessing setup)[cite: 7]
    auto start_time = std::chrono::high_resolution_clock::now();

    // Brandes' algorithm: run BFS from every vertex
    for (int s = 0; s < V; ++s) {
        int q_head = 0, q_tail = 0;
        int stack_top = 0;

        for (int i = 0; i < V; ++i) {
            dist[i] = -1;
            sigma[i] = 0;
            delta[i] = 0.0;
            pred_count[i] = 0;
        }

        dist[s] = 0;
        sigma[s] = 1;
        queue[q_tail++] = s;

        while (q_head < q_tail) {
            int v = queue[q_head++];
            stack[stack_top++] = v;

            int start = graph.row_ptr[v];
            int end = graph.row_ptr[v + 1];

            for (int i = start; i < end; ++i) {
                int w = graph.col_idx[i];

                // Found w for the first time?
                if (dist[w] < 0) {
                    dist[w] = dist[v] + 1;
                    queue[q_tail++] = w;
                }

                // Shortest path to w via v?
                if (dist[w] == dist[v] + 1) {
                    sigma[w] += sigma[v];
                    predecessors[w][pred_count[w]++] = v;
                }
            }
        }

        // Back-propagation of dependencies
        while (stack_top > 0) {
            int w = stack[--stack_top];
            for (int i = 0; i < pred_count[w]; ++i) {
                int v = predecessors[w][i];
                double fraction = (static_cast<double>(sigma[v]) / sigma[w]) * (1.0 + delta[w]);
                delta[v] += fraction;
            }
            if (w != s) {
                centrality[w] += delta[w];
            }
        }
    }

    // For undirected graphs, Brandes counts each shortest path pair twice; divide by 2
    for (int i = 0; i < V; ++i) {
        centrality[i] /= 2.0;
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end_time - start_time;

    // Clean up auxiliary memory arrays
    delete[] queue;
    delete[] stack;
    delete[] dist;
    delete[] sigma;
    delete[] delta;
    delete[] pred_count;
    for (int i = 0; i < V; ++i) {
        delete[] predecessors[i];
    }
    delete[] predecessors;

    return {centrality, duration.count()};
}

void free_centrality_result(CentralityResult& result) {
    if (result.centrality_scores != nullptr) {
        delete[] result.centrality_scores;
        result.centrality_scores = nullptr;
    }
    result.execution_time_ms = 0.0;
}