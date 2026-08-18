#include "../src/maxflow_mincut.hpp"
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <test_file_path> <output_file_path>\n";
        return 1;
    }

    std::string filepath = argv[1];
    std::string outpath = argv[2];
    
    // 1. Run the core algorithm (this handles writing everything up to 'Cut edges' to the file)
    CutResult res = run_maxflow_mincut(filepath.c_str(), outpath.c_str());

    // 2. Append the execution time to the output file to perfectly match the PDF format!
    std::ofstream outfile(outpath.c_str(), std::ios::app);
    if (outfile.is_open()) {
        outfile << "Execution time: " << res.execution_time_ms << " ms\n";
        outfile.close();
    }

    // 3. Print only a clean, minimal summary to the terminal
    std::cout << "Algorithm: Maxflow-Mincut\n";
    std::cout << "Maximum flow: " << res.max_flow << "\n";
    std::cout << "Minimum cut capacity: " << res.min_cut_capacity << "\n";
    std::cout << "Execution time: " << res.execution_time_ms << " ms\n";
    std::cout << "Detailed results successfully written to: " << outpath << "\n";

    return 0;
}