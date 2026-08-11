#include "triangle_counting.hpp"
#include <chrono>
#include <iostream>

TriangleResult count_triangles(const CSRGraph& graph, bool list_triangles) {
    long long triangle_count = 0;

    auto start_time = std::chrono::high_resolution_clock::now();

    for (int u = 0; u < graph.V; ++u) {
        int u_start = graph.row_ptr[u];
        int u_end = graph.row_ptr[u + 1];

        for (int i = u_start; i < u_end; ++i) {
            int v = graph.col_idx[i];
            
            if (v > u) {
                int v_start = graph.row_ptr[v];
                int v_end = graph.row_ptr[v + 1];

                int p1 = u_start;
                int p2 = v_start;

                while (p1 < u_end && p2 < v_end) {
                    int neighbor_u = graph.col_idx[p1];
                    int neighbor_v = graph.col_idx[p2];

                    if (neighbor_u == neighbor_v) {
                        int w = neighbor_u;
                        if (w > v) { 
                            triangle_count++;
                            if (list_triangles) {
                                std::cout << "(" << u << ", " << v << ", " << w << ")\n";
                            }
                        }
                        p1++;
                        p2++;
                    } else if (neighbor_u < neighbor_v) {
                        p1++;
                    } else {
                        p2++;
                    }
                }
            }
        }
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end_time - start_time;

    TriangleResult result;
    result.total_triangles = triangle_count;
    result.execution_time_ms = duration.count();
    return result;
}