#include <iostream>
#include <chrono>
#include <iomanip>
#include "../../buddy_csr.hpp"
#include "../src/triangle_counting.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <test_file_path>\n";
        return 1;
    }

    std::string test_file = argv[1];
    int source_vertex = 0;

    CSRGraph graph = load_unweighted_csr(test_file, source_vertex);
    if (graph.V == 0) {
        std::cerr << "Error loading graph for Triangle Counting.\n";
        return 1;
    }

    std::cout << "Algorithm: Triangle Counting\n";

    // Enable listing for small graph sizes (e.g., if V <= 100)
    bool should_list = (graph.V <= 100);

    // Call count_triangles; if should_list is true, it prints the triangles directly inside
    // Note: Per timing rules, setup/printing isn't strictly core algorithm runtime, but 
    // direct printing avoids any STL vector allocation overhead.
    TriangleResult result = count_triangles(graph, should_list);

    std::cout << "Total triangles: " << result.total_triangles << "\n";
    std::cout << "Triangles found:\n";
    if (!should_list) {
        std::cout << "(Optional/Skipped for large graph scale)\n";
    }

    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Execution time: " << result.execution_time_ms << " ms\n";

    free_csr_graph(graph);
    return 0;
}