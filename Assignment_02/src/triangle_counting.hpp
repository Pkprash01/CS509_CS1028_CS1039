#ifndef TRIANGLE_COUNTING_HPP
#define TRIANGLE_COUNTING_HPP

#include "../../buddy_csr.hpp"

struct TriangleResult {
    long long total_triangles;
    double execution_time_ms;
};

TriangleResult count_triangles(const CSRGraph& graph, bool list_triangles);

#endif