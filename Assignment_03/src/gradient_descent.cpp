#include "gradient_descent.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <chrono>

GDResult run_gradient_descent(const std::string& filepath) {
    std::ifstream infile(filepath.c_str());
    if (!infile.is_open()) {
        std::cerr << "[GD ERROR] Cannot open file: " << filepath << std::endl;
        return {0, 0, 0, 0, false, 0.0};
    }

    std::string line;
    int degree = 0;
    int max_iterations = 0;
    double initial_x = 0.0;
    double learning_rate = 0.0;
    double tolerance = 0.0;
    double* coeffs = nullptr;

    while (std::getline(infile, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        std::string key;
        ss >> key;
        if (key == "DEGREE") {
            ss >> degree;
            coeffs = new double[degree + 1];
        } else if (key == "COEFFICIENTS") {
            for (int i = 0; i <= degree; ++i) {
                ss >> coeffs[i];
            }
        } else if (key == "INITIAL_X") {
            ss >> initial_x;
        } else if (key == "LEARNING_RATE") {
            ss >> learning_rate;
        } else if (key == "TOLERANCE") {
            ss >> tolerance;
        } else if (key == "MAX_ITERATIONS") {
            ss >> max_iterations;
        }
    }
    infile.close();

    auto start_time = std::chrono::high_resolution_clock::now();

    double x = initial_x;
    int iter = 0;
    bool converged = false;

    for (iter = 0; iter < max_iterations; ++iter) {
        // Evaluate derivative f'(x) = c1 + 2*c2*x + 3*c3*x^2 + ... + d*cd*x^(d-1)
        double df_dx = 0.0;
        for (int i = 1; i <= degree; ++i) {
            double term = i * coeffs[i];
            for (int p = 0; p < i - 1; ++p) {
                term *= x;
            }
            df_dx += term;
        }

        if (std::abs(df_dx) <= tolerance) {
            converged = true;
            break;
        }

        x = x - learning_rate * df_dx;
    }

    // Evaluate final f(x) = c0 + c1*x + c2*x^2 + ... + cd*x^d
    double fx = 0.0;
    double x_pow = 1.0;
    for (int i = 0; i <= degree; ++i) {
        fx += coeffs[i] * x_pow;
        x_pow *= x;
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end_time - start_time;

    delete[] coeffs;

    return {degree, x, fx, iter, converged, elapsed.count()};
}