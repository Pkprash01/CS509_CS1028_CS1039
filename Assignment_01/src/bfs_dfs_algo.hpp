#ifndef BFS_DFS_ALGO_HPP
#define BFS_DFS_ALGO_HPP

#include "csr_graph.hpp"

struct BFSResult {
    int* distances;
    int* traversal;
    int num_vertices;
    int traversal_size;
    double execution_time_ms;
};

struct DFSResult {
    int* traversal;
    int traversal_size;
    double execution_time_ms;
};

BFSResult run_bfs(const CSRGraph& graph, int source);
DFSResult run_dfs(const CSRGraph& graph, int source);

void free_bfs_result(BFSResult& res);
void free_dfs_result(DFSResult& res);

#endif // BFS_DFS_ALGO_HPP