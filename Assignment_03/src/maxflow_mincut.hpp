#ifndef MAXFLOW_MINCUT_HPP
#define MAXFLOW_MINCUT_HPP

#include <string>

struct CutResult {
    int max_flow;
    int min_cut_capacity;
    double execution_time_ms;
};

CutResult run_maxflow_mincut(const std::string& filepath, const std::string& output_filepath);

#endif