#include "../src/kmeans.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <input> <output>\n";
        return 1;
    }

    KMeansResult result = run_kmeans(argv[1], argv[2]);

    std::cout << "Algorithm: K-Means Clustering\n";
    std::cout << "WCSS: " << result.wcss << "\n";
    std::cout << "Iterations completed.\n";
    std::cout << "Execution time: " << result.execution_time_ms << " ms\n";

    return 0;
}