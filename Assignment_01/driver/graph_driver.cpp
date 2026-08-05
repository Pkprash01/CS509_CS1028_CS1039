#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> // Needed for std::fixed and std::setprecision
#include "../src/csr_graph.hpp"
#include "../src/bfs_dfs_algo.hpp"

// Unified print function targeting any stream
void print_bfs_results(std::ostream& os, int source, const BFSResult& res) {
    os << "Algorithm: BFS\n";
    os << "Source: " << source << "\n";
    os << "Traversal: ";
    for (int i = 0; i < res.traversal_size; ++i) {
        os << res.traversal[i] << (i + 1 == res.traversal_size ? "" : " ");
    }
    os << "\nDistances:\n";
    for (int i = 0; i < res.num_vertices; ++i) {
        if (res.distances[i] == -1)
            os << i << " INF\n";
        else
            os << i << " " << res.distances[i] << "\n";
    }
    // Formats execution time to 4 decimal places (e.g., 0.0035 ms)
    os << std::fixed << std::setprecision(4);
    os << "Execution time: " << res.execution_time_ms << " ms\n";
}

void print_dfs_results(std::ostream& os, int source, const DFSResult& res) {
    os << "Algorithm: DFS\n";
    os << "Source: " << source << "\n";
    os << "Traversal: ";
    for (int i = 0; i < res.traversal_size; ++i) {
        os << res.traversal[i] << (i + 1 == res.traversal_size ? "" : " ");
    }
    // Formats execution time to 4 decimal places (e.g., 0.0028 ms)
    os << std::fixed << std::setprecision(4);
    os << "\nExecution time: " << res.execution_time_ms << " ms\n";
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "Usage: " << argv[0] << " <algo: bfs|dfs|sssp> <input_file_path> [output_file_path]" << std::endl;
        return 1;
    }

    std::string algo = argv[1];
    std::string filepath = argv[2];
    std::string out_filepath = (argc >= 4) ? argv[3] : "";

    int source_vertex = 0;

    if (algo == "bfs") {
        CSRGraph csr = load_unweighted_csr(filepath, source_vertex);
        if (csr.row_ptr == NULL) {
            std::cerr << "Error: Failed to load graph from " << filepath << std::endl;
            return 1;
        }

        BFSResult bfs_res = run_bfs(csr, source_vertex);

        // CONTROL LOGIC: Write to File OR Terminal
        if (!out_filepath.empty()) {
            std::ofstream outfile(out_filepath.c_str());
            if (outfile.is_open()) {
                print_bfs_results(outfile, source_vertex, bfs_res);
                outfile.close();
                std::cout << "[Success] Results saved to " << out_filepath << std::endl;
            } else {
                std::cerr << "Error: Could not open output file " << out_filepath << std::endl;
            }
        } else {
            print_bfs_results(std::cout, source_vertex, bfs_res);
        }

        free_bfs_result(bfs_res);
        free_csr_graph(csr);

    } else if (algo == "dfs") {
        CSRGraph csr = load_unweighted_csr(filepath, source_vertex);
        if (csr.row_ptr == NULL) {
            std::cerr << "Error: Failed to load graph from " << filepath << std::endl;
            return 1;
        }

        DFSResult dfs_res = run_dfs(csr, source_vertex);

        // CONTROL LOGIC: Write to File OR Terminal
        if (!out_filepath.empty()) {
            std::ofstream outfile(out_filepath.c_str());
            if (outfile.is_open()) {
                print_dfs_results(outfile, source_vertex, dfs_res);
                outfile.close();
                std::cout << "[Success] Results saved to " << out_filepath << std::endl;
            } else {
                std::cerr << "Error: Could not open output file " << out_filepath << std::endl;
            }
        } else {
            print_dfs_results(std::cout, source_vertex, dfs_res);
        }

        free_dfs_result(dfs_res);
        free_csr_graph(csr);

    } else if (algo == "sssp") {
        std::cout << "SSSP implementation goes here!" << std::endl;
    } else {
        std::cerr << "Invalid algorithm choice! Choose 'bfs', 'dfs', or 'sssp'." << std::endl;
        return 1;
    }

    return 0;
}