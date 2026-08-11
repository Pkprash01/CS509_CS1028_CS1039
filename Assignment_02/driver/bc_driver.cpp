#include <iostream>
#include <iomanip>
#include <string>
#include "../src/betweenness_centrality.hpp"
#include "../../buddy_csr.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: ./bc_driver <input_file_path>" << std::endl;
        return 1;
    }

    std::string filepath = argv[1];
    int source_vertex = 0;

    CSRGraph graph = load_unweighted_csr(filepath, source_vertex);
    if (graph.V == 0) {
        std::cerr << "Error loading graph for Betweenness Centrality." << std::endl;
        return 1;
    }

    CentralityResult result = compute_betweenness_centrality(graph);

    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Algorithm: Betweenness Centrality\n";
    std::cout << "Vertex Centrality\n";
    for (int i = 0; i < graph.V; ++i) {
        std::cout << i << " " << std::fixed << std::setprecision(2) << result.centrality_scores[i] << "\n";
    }
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Execution time: " << result.execution_time_ms << " ms\n";

    free_centrality_result(result);
    free_csr_graph(graph);
    return 0;
}