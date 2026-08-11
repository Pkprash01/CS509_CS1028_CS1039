#include "connected_components.hpp"
#include <chrono>

ComponentResult find_connected_components(const CSRGraph& graph) {
    int V = graph.V;
    int* component_ids = new int[V];
    bool* visited = new bool[V];
    int* queue = new int[V];

    for (int i = 0; i < V; ++i) {
        component_ids[i] = -1;
        visited[i] = false;
    }

    int component_count = 0;

    // Start timer (excluding CSR preprocessing setup)[cite: 3, 4]
    auto start_time = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            // Start a new BFS traversal for this component
            int q_head = 0, q_tail = 0;
            visited[i] = true;
            component_ids[i] = component_count;
            queue[q_tail++] = i;

            while (q_head < q_tail) {
                int u = queue[q_head++];

                int start = graph.row_ptr[u];
                int end = graph.row_ptr[u + 1];

                for (int j = start; j < end; ++j) {
                    int neighbor = graph.col_idx[j];
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        component_ids[neighbor] = component_count;
                        queue[q_tail++] = neighbor;
                    }
                }
            }
            component_count++;
        }
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end_time - start_time;

    delete[] visited;
    delete[] queue;

    return {component_count, component_ids, duration.count()};
}

void free_component_result(ComponentResult& result) {
    if (result.component_ids != nullptr) {
        delete[] result.component_ids;
        result.component_ids = nullptr;
    }
    result.num_components = 0;
    result.execution_time_ms = 0.0;
}