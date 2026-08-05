#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <climits>
#include <iomanip>
#include "sssp.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    // Check if test file path is provided as argument
    if (argc < 2) {
        cout << "Error: Please provide a test file path." << endl;
        cout << "Usage: ./driver_app <test_file>" << endl;
        return 1;
    }

    string inputPath = argv[1];
    ifstream fin(inputPath);

    if (!fin.is_open()) {
        cout << "Could not open input file: " << inputPath << endl;
        return 1;
    }

    // Read graph specifications
    int total_nodes, total_edges;
    fin >> total_nodes >> total_edges;

    struct Graph* g = createGraph(total_nodes);

    // Read adjacency list line by line
    for (int i = 0; i < total_nodes; i++) {
        int node, degree;
        fin >> node >> degree;
        
        for (int k = 0; k < degree; k++) {
            int adj_node, w;
            fin >> adj_node >> w;
            addEdge(g, node, adj_node, w);
        }
    }

    // Read source vertex at the end of the file
    string tag;
    int src = 0;
    while (fin >> tag) {
        if (tag == "SOURCE") {
            fin >> src;
            break;
        }
    }
    fin.close();

    // Prepare output file stream
    string outputPath = "outputs/output_sssp.txt";
    ofstream fout(outputPath);

    // Timer starts: Track algorithm execution time only
    auto t_start = chrono::high_resolution_clock::now();

    int* shortest_dist = runSSSP(g, src);

    auto t_end = chrono::high_resolution_clock::now();
    // Timer ends

    // Calculate execution time in milliseconds
    double duration_ns = chrono::duration_cast<chrono::nanoseconds>(t_end - t_start).count();
    double time_in_ms = duration_ns / 1000000.0;

    // Display formatted output on terminal
    cout << "Algorithm: SSSP" << endl;
    cout << "Source: " << src << endl;
    cout << "Vertex\tDistance" << endl;
    for (int node_id = 0; node_id < total_nodes; node_id++) {
        cout << node_id << "\t";
        if (shortest_dist[node_id] == INT_MAX) {
            cout << "INF" << endl;
        } else {
            cout << shortest_dist[node_id] << endl;
        }
    }

    cout << fixed << setprecision(6);
    cout << "Execution time: " << time_in_ms << " ms" << endl;

    // Write formatted output into outputs/ directory
    if (fout.is_open()) {
        fout << "Algorithm: SSSP" << endl;
        fout << "Source: " << src << endl;
        fout << "Vertex\tDistance" << endl;
        
        for (int node_id = 0; node_id < total_nodes; node_id++) {
            fout << node_id << "\t";
            if (shortest_dist[node_id] == INT_MAX) {
                fout << "INF" << endl;
            } else {
                fout << shortest_dist[node_id] << endl;
            }
        }
        
        fout << fixed << setprecision(6);
        fout << "Execution time: " << time_in_ms << " ms" << endl;
        fout.close();
        
        cout << "\nOutput saved in: " << outputPath << endl;
    }

    // Free memory allocations
    free(shortest_dist);
    freeGraph(g);

    return 0;
}