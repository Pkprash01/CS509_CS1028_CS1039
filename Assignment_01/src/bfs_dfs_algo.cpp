#include "bfs_dfs_algo.hpp"
#include "csr_graph.hpp"
#include <chrono>

BFSResult run_bfs(const CSRGraph& graph, int source) {
    BFSResult res;
    int V = graph.V;

    res.distances = new int[V];
    res.traversal = new int[V];
    res.num_vertices = V;

    int* q = new int[V];

    for (int i = 0; i < V; ++i) {
        res.distances[i] = -1;
    }

    int head = 0;
    int tail = 0;
    int count = 0;

    auto start_time = std::chrono::high_resolution_clock::now();

    res.distances[source] = 0;
    q[tail++] = source;

    while (head < tail) {
        int u = q[head++];
        res.traversal[count++] = u;

        int row_start = graph.row_ptr[u];
        int row_end = graph.row_ptr[u + 1];

        for (int i = row_start; i < row_end; ++i) {
            int v = graph.col_idx[i];
            if (res.distances[v] == -1) {
                res.distances[v] = res.distances[u] + 1;
                q[tail++] = v;
            }
        }
    }

    auto end_time = std::chrono::high_resolution_clock::now();

    auto duration_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
    res.execution_time_ms = static_cast<double>(duration_ns) / 1000.0; // Microseconds (us)
    res.traversal_size = count;

    delete[] q;
    return res;
}

DFSResult run_dfs(const CSRGraph& graph, int source) {
    DFSResult res;
    int V = graph.V;

    res.traversal = new int[V];
    bool* visited = new bool[V];

    int stack_capacity = (graph.E > V) ? graph.E : V;
    int* st = new int[stack_capacity];

    for (int i = 0; i < V; ++i) {
        visited[i] = false;
    }

    int top = 0;
    int count = 0;

    auto start_time = std::chrono::high_resolution_clock::now();

    st[top++] = source;

    while (top > 0) {
        int u = st[--top];

        if (!visited[u]) {
            visited[u] = true;
            res.traversal[count++] = u;

            int row_start = graph.row_ptr[u];
            int row_end = graph.row_ptr[u + 1];

            for (int i = row_end - 1; i >= row_start; --i) {
                int v = graph.col_idx[i];
                if (!visited[v]) {
                    st[top++] = v;
                }
            }
        }
    }

    auto end_time = std::chrono::high_resolution_clock::now();

    auto duration_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
    res.execution_time_ms = static_cast<double>(duration_ns) / 1000.0; // Microseconds (us)
    res.traversal_size = count;

    delete[] visited;
    delete[] st;

    return res;
}

void free_bfs_result(BFSResult& res) {
    delete[] res.traversal;
    delete[] res.distances;
}

void free_dfs_result(DFSResult& res) {
    delete[] res.traversal;
}