#include "bfs_dfs_algo.hpp"
#include <chrono>

BFSResult run_bfs(const CSRGraph& graph, int source) {
    BFSResult res;
    int V = graph.V;

    res.distances = new int[V];
    res.traversal = new int[V];
    res.num_vertices = V;

    int* queue = new int[V];

    for (int i = 0; i < V; ++i) {
        res.distances[i] = -1;
    }

    int head = 0;
    int tail = 0;
    int traversal_count = 0;

    //TIMING STARTS HERE
    auto start = std::chrono::high_resolution_clock::now();

    res.distances[source] = 0;
    queue[tail++] = source;

    while (head < tail) {
        int u = queue[head++];
        res.traversal[traversal_count++] = u;

        int start_idx = graph.row_ptr[u];
        int end_idx = graph.row_ptr[u + 1];

        for (int i = start_idx; i < end_idx; ++i) {
            int v = graph.col_idx[i];
            if (res.distances[v] == -1) {
                res.distances[v] = res.distances[u] + 1;
                queue[tail++] = v;
            }
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    //TIMING ENDS HERE

    res.execution_time_ms = std::chrono::duration<double, std::milli>(end - start).count();
    res.traversal_size = traversal_count;

    delete[] queue;
    return res;
}

DFSResult run_dfs(const CSRGraph& graph, int source) {
    DFSResult res;
    int V = graph.V; // <-- Updated from graph.num_vertices to graph.V

    res.traversal = new int[V];
    bool* visited = new bool[V];
    int* stack = new int[V];

    for (int i = 0; i < V; ++i) {
        visited[i] = false;
    }

    int top = 0;
    int traversal_count = 0;

    //TIMING STARTS HERE
    auto start = std::chrono::high_resolution_clock::now();

    stack[top++] = source;

    while (top > 0) {
        int u = stack[--top];

        if (!visited[u]) {
            visited[u] = true;
            res.traversal[traversal_count++] = u;

            int start_idx = graph.row_ptr[u];
            int end_idx = graph.row_ptr[u + 1];

            // Traverse neighbors in reverse order so lower indexed neighbors are visited first
            for (int i = end_idx - 1; i >= start_idx; --i) {
                int v = graph.col_idx[i];
                if (!visited[v]) {
                    stack[top++] = v;
                }
            }
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    //TIMING ENDS HERE

    res.execution_time_ms = std::chrono::duration<double, std::milli>(end - start).count();
    res.traversal_size = traversal_count;

    delete[] visited;
    delete[] stack;

    return res;
}

void free_bfs_result(BFSResult& res) {
    delete[] res.traversal;
    delete[] res.distances;
}

void free_dfs_result(DFSResult& res) {
    delete[] res.traversal;
}