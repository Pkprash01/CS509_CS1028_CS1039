# CS509 Laboratory Repository — Buddy Tasks

## Repository Overview

This repository contains the **Buddy Programming Assignments for CS509 — M.Tech CSE Laboratory**.

This section documents the **Buddy Tasks for Assignment 02**, which focuses on three fundamental graph algorithms:

1. **Triangle Counting (TC)**
2. **Betweenness Centrality (BC)**
3. **Connected Components (CC)**

The implementations are written in **C++17** and operate on graphs represented using the **Compressed Sparse Row (CSR)** format.

---

## Student Details

| Field               | Details        |
| ------------------- | -------------- |
| **Student 1**       | Prashant Kumar |
| **Entry No.**       | 2026CSM1028    |
| **Student 2**       | Vikram Gurjar  |
| **Entry No.**       | 2026CSM1039    |
| **Program**         | M.Tech CSE     |
| **Course**          | CS509          |
| **Assignment**      | Assignment 02  |
| **Assignment Mode** | Buddy          |
| **Language**        | C++17          |

---

# Language and Environment

| Component                | Configuration                        |
| ------------------------ | ------------------------------------ |
| **Programming Language** | C++                                  |
| **C++ Standard**         | C++17                                |
| **Compiler**             | GCC / g++ / MinGW-w64                |
| **Operating Systems**    | Windows 11 / Linux                   |
| **Graph Representation** | Compressed Sparse Row (CSR)          |
| **Timing Method**        | `std::chrono::high_resolution_clock` |
| **Timing Unit**          | Milliseconds (`ms`)                  |
| **Output Precision**     | Fixed-point floating-point precision |

The CSR loader reads the number of vertices and edges from the input and constructs the `row_ptr` and `col_idx` arrays used by the graph algorithms.

---

# Directory Structure

```text
CS509_CS1028_CS1039/
│
├── README.md
├── wrapper.cpp
├── wrapper.exe
├── .gitignore
├── Makefile
├── buddy_csr.cpp
├── buddy_csr.hpp
│
└── Assignment_02/
    │
    ├── src/
    │   ├── triangle_counting.cpp
    │   ├── triangle_counting.hpp
    │   ├── betweenness_centrality.cpp
    │   ├── betweenness_centrality.hpp
    │   ├── connected_components.cpp
    │   └── connected_components.hpp
    │
    ├── driver/
    │   ├── tc_driver.cpp
    │   ├── bc_driver.cpp
    │   └── cc_driver.cpp
    │
    ├── tests/
    │   ├── tc_1.txt
    │   ├── tc_10.txt
    │   ├── tc_100.txt
    │   ├── tc_1000.txt
    │   ├── tc_10000.txt
    │   ├── bc_1.txt
    │   ├── bc_10.txt
    │   ├── bc_100.txt
    │   ├── bc_1000.txt
    │   ├── bc_5000.txt
    │   ├── bc_10000.txt
    │   ├── cc_1.txt
    │   ├── cc_10.txt
    │   ├── cc_100.txt
    │   ├── cc_1000.txt
    │   └── cc_10000.txt
    │
    └── outputs/
        ├── tc_1_out.txt
        ├── tc_10_out.txt
        ├── tc_100_out.txt
        ├── tc_1000_out.txt
        ├── tc_10000_out.txt
        ├── bc_1_out.txt
        ├── bc_10_out.txt
        ├── bc_100_out.txt
        ├── bc_1000_out.txt
        ├── bc_5000_out.txt
        ├── bc_10000_out.txt
        ├── cc_1_out.txt
        ├── cc_10_out.txt
        ├── cc_100_out.txt
        ├── cc_1000_out.txt
        └── cc_10000_out.txt
```

---

# Assignment 02 — Algorithms

## 1. Triangle Counting (TC)

Triangle Counting computes the total number of unique triangles present in an undirected graph.

The implementation traverses CSR adjacency lists and uses a two-pointer intersection technique to identify common neighbors. A triangle is counted only when the vertex ordering satisfies `u < v < w`, avoiding duplicate counting.

For smaller graphs, the driver can additionally print the individual triangles. For larger graphs, triangle listing is skipped while the total count and execution time are reported.

### Output

The driver reports:

* Algorithm name
* Total number of triangles
* Individual triangles for small graphs
* Execution time in milliseconds

---

## 2. Betweenness Centrality (BC)

Betweenness Centrality measures the importance of vertices based on their participation in shortest paths.

The implementation follows the structure of **Brandes' algorithm**. It performs a BFS from every source vertex, maintains shortest-path counts and predecessor information, and then performs dependency back-propagation.
For undirected graphs, the resulting centrality values are divided by two because shortest paths are counted from both directions.

### Output

The driver reports:

* Algorithm name
* Centrality score for each vertex
* Execution time in milliseconds

---

## 3. Connected Components (CC)

Connected Components identifies and labels the connected subgraphs present in an input graph.

The implementation uses **Breadth-First Search (BFS)**. Whenever an unvisited vertex is encountered, a new component is started and all reachable vertices are assigned the same component ID.

### Output

The driver reports:

* Algorithm name
* Total number of connected components
* Component ID assigned to each vertex
* Execution time in milliseconds

---

# CSR Graph Representation

The algorithms use a common **Compressed Sparse Row (CSR)** graph representation.

The unweighted CSR loader stores:

* `V` — number of vertices
* `E` — number of edges
* `row_ptr` — offsets identifying each vertex's adjacency range
* `col_idx` — adjacency-list vertex indices
* `values` — unused for unweighted graphs

## The loader reads the graph header and constructs the CSR arrays before passing the graph to the selected algorithm.

# Drivers

Each algorithm has a dedicated driver responsible for:

1. Reading the input test-file path.
2. Loading the graph into CSR format.
3. Invoking the corresponding algorithm.
4. Printing the algorithm result.
5. Reporting execution time.
6. Releasing allocated memory.

### Triangle Counting Driver

```text
Assignment_02/driver/tc_driver.cpp
```

The driver loads the CSR graph, determines whether triangle listing should be enabled for small graphs, invokes `count_triangles()`, and prints the resulting triangle count and execution time.

### Betweenness Centrality Driver

```text
Assignment_02/driver/bc_driver.cpp
```

The driver invokes `compute_betweenness_centrality()` and prints the centrality score of every vertex together with the execution time.

### Connected Components Driver

```text
Assignment_02/driver/cc_driver.cpp
```

The driver invokes `find_connected_components()` and prints the number of components, component ID of every vertex, and execution time.

---

# Benchmark Results

## 1. Triangle Counting (TC)

| Test File      | Vertices (V) | Edges (E) | Expected Output | Actual Output | Time (ms) | Status   |
| -------------- | -----------: | --------: | --------------- | ------------- | --------: | -------- |
| `tc_1.txt`     |            1 |         0 | Valid Count     | Matches       |    0.0000 | **Pass** |
| `tc_10.txt`    |           10 |        20 | Valid Count     | Matches       |    0.0000 | **Pass** |
| `tc_100.txt`   |          100 |       300 | Valid Count     | Matches       |    0.0000 | **Pass** |
| `tc_1000.txt`  |        1,000 |     3,000 | Valid Count     | Matches       |    0.0000 | **Pass** |
| `tc_10000.txt` |       10,000 |    30,000 | Valid Count     | Matches       |    4.5320 | **Pass** |

---

## 2. Betweenness Centrality (BC)

| Test File      | Vertices (V) | Edges (E) | Expected Output  | Actual Output | Time (ms) | Status   |
| -------------- | -----------: | --------: | ---------------- | ------------- | --------: | -------- |
| `bc_1.txt`     |            1 |         0 | Centrality Array | Matches       |    0.0000 | **Pass** |
| `bc_10.txt`    |           10 |        20 | Centrality Array | Matches       |    0.0000 | **Pass** |
| `bc_100.txt`   |          100 |       300 | Centrality Array | Matches       |    0.0000 | **Pass** |
| `bc_1000.txt`  |        1,000 |     3,000 | Centrality Array | Matches       |    8.6360 | **Pass** |
| `bc_5000.txt`  |        5,000 |    15,000 | Centrality Array | Matches       |  682.4450 | **Pass** |
| `bc_10000.txt` |       10,000 |    30,000 | Centrality Array | Matches       | 3200.5520 | **Pass** |

---

## 3. Connected Components (CC)

| Test File      | Vertices (V) | Edges (E) | Expected Output | Actual Output | Time (ms) | Status   |
| -------------- | -----------: | --------: | --------------- | ------------- | --------: | -------- |
| `cc_1.txt`     |            1 |         0 | Component ID    | Matches       |    0.0000 | **Pass** |
| `cc_10.txt`    |           10 |        20 | Component ID    | Matches       |    0.0000 | **Pass** |
| `cc_100.txt`   |          100 |       300 | Component ID    | Matches       |    0.0000 | **Pass** |
| `cc_1000.txt`  |        1,000 |     3,000 | Component ID    | Matches       |    0.0000 | **Pass** |
| `cc_10000.txt` |       10,000 |    30,000 | Component ID    | Matches       |    0.0000 | **Pass** |

---

# Performance Observations

### Triangle Counting

Triangle Counting performs efficiently on the provided benchmark graphs. The largest tested graph contains **10,000 vertices and 30,000 edges**, with an observed execution time of **4.5320 ms**.

The implementation uses CSR adjacency lists and sorted-neighbor intersection to identify triangles efficiently.

### Betweenness Centrality

Betweenness Centrality is computationally more expensive than the other two algorithms.

The measured execution time increases significantly with graph size:

```text
1,000 vertices   →      8.6360 ms
5,000 vertices   →    682.4450 ms
10,000 vertices  →   3200.5520 ms
```

This behavior is consistent with the implementation performing a BFS-based Brandes computation from **every vertex**.

### Connected Components

Connected Components remains highly efficient for the provided benchmark set. The implementation performs BFS traversals over the CSR representation and records a component ID for each vertex.

---

# Memory Management

The implementations explicitly allocate and release the arrays used during computation.

For example, the Betweenness Centrality implementation allocates working arrays for the BFS queue, stack, distances, shortest-path counts, dependencies, and predecessor information, and releases them after computation.
Similarly, Connected Components releases its traversal arrays and provides a dedicated result cleanup function.

The CSR graph also provides explicit cleanup for `row_ptr`, `col_idx`, and `values`.

---

# Input and Output

Each driver accepts the test-file path as a command-line argument.

### Example

```bash
./tc_driver <input_file_path>
```

```bash
./bc_driver <input_file_path>
```

```bash
./cc_driver <input_file_path>
```

## The drivers validate the input graph and report an error if the CSR graph cannot be loaded successfully.

# `.gitignore`

Generated executables and build outputs are excluded from version control. The current ignore configuration includes:

```text
*.exe
*.out
*.o
Assignment_01/driver/*_exec
Assignment_02/driver/*_exec
```

---

# References

* **CS509 Assignment 02 Specification Document**
* **CS509 M.Tech CSE Laboratory Work Guidelines**
* **C++17 Standard Library — `std::chrono`**

---

# Authors

| Name               | Entry Number |
| ------------------ | ------------ |
| **Prashant Kumar** | 2026CSM1028  |
| **Vikram Gurjar**  | 2026CSM1039  |

**Program:** M.Tech CSE
**Course:** CS509
**Assignment:** Assignment 02
**Mode:** Buddy Programming

---

## Summary

This assignment implements and benchmarks three graph-processing algorithms using a common CSR graph representation:

| Algorithm                  | Purpose                      | Approach                   |
| -------------------------- | ---------------------------- | -------------------------- |
| **Triangle Counting**      | Count unique triangles       | CSR adjacency intersection |
| **Betweenness Centrality** | Measure vertex importance    | Brandes-style BFS          |
| **Connected Components**   | Identify connected subgraphs | BFS traversal              |

All provided benchmark cases are reported as **passing**, with Betweenness Centrality showing the highest computational cost as graph size increases.
