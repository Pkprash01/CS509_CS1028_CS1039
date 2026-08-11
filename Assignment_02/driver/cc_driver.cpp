#include <iostream>
#include <iomanip>
#include <string>
#include "../src/connected_components.hpp"
#include "../../buddy_csr.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: ./cc_driver <input_file_path>" << std::endl;
        return 1;
    }

    std::string filepath = argv[1];
    int source_vertex = 0;

    CSRGraph graph = load_unweighted_csr(filepath, source_vertex);
    if (graph.V == 0) {
        std::cerr << "Error loading graph for Connected Components." << std::endl;
        return 1;
    }

    ComponentResult result = find_connected_components(graph);

    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Algorithm: Connected Components\n";
    std::cout << "Number of components: " << result.num_components << "\n";
    std::cout << "Vertex Component\n";
    for (int i = 0; i < graph.V; ++i) {
        std::cout << i << " " << result.component_ids[i] << "\n";
    }
    std::cout << "Execution time: " << result.execution_time_ms << " ms\n";

    free_component_result(result);
    free_csr_graph(graph);
    return 0;
}