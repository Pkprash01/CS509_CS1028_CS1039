#ifndef GRADIENT_DESCENT_HPP
#define GRADIENT_DESCENT_HPP

#include <string>

struct GDResult {
    int degree;
    double final_x;
    double final_fx;
    int iterations;
    bool converged;
    double execution_time_ms;
};

GDResult run_gradient_descent(const std::string& filepath);

#endif