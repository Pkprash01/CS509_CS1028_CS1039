#include "maxflow_mincut.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <cstring>
#include <algorithm>

struct StaticEdge {
    int to;
    int cap;
    int flow;
    int rev_index;
};

// Custom dynamic array replacing std::vector entirely
struct NodeEdgeList {
    StaticEdge* edges;
    int size;
    int capacity;

    NodeEdgeList() {
        size = 0;
        capacity = 4;
        edges = new StaticEdge[capacity];
    }

    ~NodeEdgeList() {
        delete[] edges;
    }

    void push_back(const StaticEdge& e) {
        if (size >= capacity) {
            capacity *= 2;
            StaticEdge* new_edges = new StaticEdge[capacity];
            for (int i = 0; i < size; ++i) new_edges[i] = edges[i];
            delete[] edges;
            edges = new_edges;
        }
        edges[size++] = e;
    }
};

CutResult run_maxflow_mincut(const std::string& filepath, const std::string& output_filepath) {
    std::ifstream infile(filepath.c_str());
    if (!infile.is_open()) {
        std::cerr << "[MF ERROR] Cannot open file: " << filepath << std::endl;
        return {0, 0, 0.0};
    }

    int V, E;
    if (!(infile >> V >> E)) {
        infile.close();
        return {0, 0, 0.0};
    }

    NodeEdgeList* graph = new NodeEdgeList[V];

    auto add_edge_custom = [&](int u, int v, int cap) {
        StaticEdge a = {v, cap, 0, graph[v].size};
        StaticEdge b = {u, 0, 0, graph[u].size};
        graph[u].push_back(a);
        graph[v].push_back(b);
        graph[u].edges[graph[u].size - 1].rev_index = graph[v].size - 1;
        graph[v].edges[graph[v].size - 1].rev_index = graph[u].size - 1;
    };

    for (int i = 0; i < V; ++i) {
        int u, degree;
        if (!(infile >> u >> degree)) break;
        for (int d = 0; d < degree; ++d) {
            int v, cap;
            infile >> v >> cap;
            add_edge_custom(u, v, cap);
        }
    }

    std::string label;
    int source = 0, sink = 0;
    while (infile >> label) {
        if (label == "SOURCE") infile >> source;
        else if (label == "SINK") infile >> sink;
    }
    infile.close();

    auto start_time = std::chrono::high_resolution_clock::now();

    int* level = new int[V];
    int* ptr = new int[V];

    // BFS implemented completely with raw arrays (STL-free)
    auto bfs = [&](int s, int t) {
        for (int i = 0; i < V; ++i) level[i] = -1;
        level[s] = 0;
        int* q = new int[V];
        int head = 0, tail = 0;
        q[tail++] = s;

        while (head < tail) {
            int v = q[head++];
            for (int i = 0; i < graph[v].size; ++i) {
                StaticEdge& edge = graph[v].edges[i];
                if (edge.cap - edge.flow > 0 && level[edge.to] == -1) {
                    level[edge.to] = level[v] + 1;
                    q[tail++] = edge.to;
                }
            }
        }
        bool reachable = (level[t] != -1);
        delete[] q;
        return reachable;
    };

    // DFS implemented using recursive lambda with manual references (STL-free)
    auto dfs = [&](int v, int t, int pushed, auto& self_ref) -> int {
        if (pushed == 0) return 0;
        if (v == t) return pushed;
        for (int& cid = ptr[v]; cid < graph[v].size; ++cid) {
            StaticEdge& edge = graph[v].edges[cid];
            int tr = edge.to;
            if (level[v] + 1 != level[tr] || edge.cap - edge.flow == 0) continue;
            int tr_push = self_ref(tr, t, std::min(pushed, edge.cap - edge.flow), self_ref);
            if (tr_push == 0) continue;
            edge.flow += tr_push;
            graph[tr].edges[edge.rev_index].flow -= tr_push;
            return tr_push;
        }
        return 0;
    };

    int max_flow = 0;
    while (bfs(source, sink)) {
        for (int i = 0; i < V; ++i) ptr[i] = 0;
        while (int pushed = dfs(source, sink, 1e9, dfs)) {
            max_flow += pushed;
        }
    }

    // Min-cut reachable nodes tracking using raw array queue
    bool* visited = new bool[V];
    for (int i = 0; i < V; ++i) visited[i] = false;
    int* q = new int[V];
    int head = 0, tail = 0;
    q[tail++] = source;
    visited[source] = true;

    while (head < tail) {
        int v = q[head++];
        for (int i = 0; i < graph[v].size; ++i) {
            StaticEdge& edge = graph[v].edges[i];
            if (edge.cap - edge.flow > 0 && !visited[edge.to]) {
                visited[edge.to] = true;
                q[tail++] = edge.to;
            }
        }
    }
    delete[] q;

    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end_time - start_time;

    // Write output
    std::ofstream outfile(output_filepath.c_str());
    outfile << "Algorithm: Maxflow-Mincut\n";
    outfile << "Source: " << source << "\n";
    outfile << "Sink: " << sink << "\n";
    outfile << "Maximum flow: " << max_flow << "\n";
    outfile << "Minimum cut capacity: " << max_flow << "\n";
    
    outfile << "Source side:";
    for (int i = 0; i < V; ++i) if (visited[i]) outfile << " " << i;
    outfile << "\nSink side:";
    for (int i = 0; i < V; ++i) if (!visited[i]) outfile << " " << i;
    outfile << "\nCut edges:\n";

    for (int i = 0; i < V; ++i) {
        if (visited[i]) {
            for (int j = 0; j < graph[i].size; ++j) {
                StaticEdge& edge = graph[i].edges[j];
                if (!visited[edge.to] && edge.cap > 0) {
                    outfile << i << " " << edge.to << " " << edge.cap << "\n";
                }
            }
        }
    }
    outfile.close();

    delete[] graph;
    delete[] level;
    delete[] ptr;
    delete[] visited;

    return {max_flow, max_flow, elapsed.count()};
}