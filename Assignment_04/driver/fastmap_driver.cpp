#include "../src/fastmap.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <input> <output>\n";
        return 1;
    }

    FastMapResult result = run_fastmap(argv[1], argv[2]);

    std::cout << "Algorithm: FastMap\n";
    std::cout << "Execution time: " << result.execution_time_ms << " ms\n";

    return 0;
}