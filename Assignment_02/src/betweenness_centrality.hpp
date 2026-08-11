#ifndef BETWEENNESS_CENTRALITY_HPP
#define BETWEENNESS_CENTRALITY_HPP

#include "../../buddy_csr.hpp"

struct CentralityResult {
    double* centrality_scores; // Dynamically allocated array for V vertices
    double execution_time_ms;
};

CentralityResult compute_betweenness_centrality(const CSRGraph& graph);
void free_centrality_result(CentralityResult& result);

#endif