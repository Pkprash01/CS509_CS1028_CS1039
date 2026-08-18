#include "../src/gradient_descent.hpp"
#include <iostream>
#include <iomanip>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <test_file_path>\n";
        return 1;
    }

    std::string filepath = argv[1];
    
    // Call the gradient descent algorithm (timing handled internally inside the solver)
    GDResult res = run_gradient_descent(filepath);

    // Print expected output format for Gradient Descent
    std::cout << "Algorithm: Gradient Descent\n";
    std::cout << "Degree: " << res.degree << "\n";
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Final x: " << res.final_x << "\n";
    std::cout << "Final f(x): " << res.final_fx << "\n";
    std::cout << "Iterations: " << res.iterations << "\n";
    std::cout << "Converged: " << (res.converged ? "true" : "false") << "\n";
    std::cout << "Execution time: " << res.execution_time_ms << " ms\n";

    return 0;
}