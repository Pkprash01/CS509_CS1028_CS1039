#ifndef BFS_DFS_ALGO_HPP
#define BFS_DFS_ALGO_HPP

#include "csr_graph.hpp"

//Container for BFS results using raw pointers
struct BFSResult {
    int* traversal;
    int* distances;      //-1 for unreachable vertices
    int traversal_size;
    int num_vertices;
    double execution_time_ms;
};

//Container for DFS results using raw pointers
struct DFSResult {
    int* traversal;
    int traversal_size;
    double execution_time_ms;
};

//BFS implementation
BFSResult run_bfs(const CSRGraph& graph, int source);

//DFS implementation
DFSResult run_dfs(const CSRGraph& graph, int source);

//Helper functions to cleanup allocated result memory
void free_bfs_result(BFSResult& res);
void free_dfs_result(DFSResult& res);

#endif //BFS_DFS_ALGO_HPP