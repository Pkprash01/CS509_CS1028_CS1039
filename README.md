# CS509 Software Laboratory Repository

## Repository Overview

This repository contains **Assignment 01** for the **CS509_PGSoftwareLab** course. The project demonstrates graph processing algorithms using different graph representations and traversal techniques.

The assignment includes the implementation of:

- Breadth First Search (BFS)
- Depth First Search (DFS)
- Single Source Shortest Path (SSSP)
- Compressed Sparse Row (CSR) Graph Representation

The project also compares the execution time of different graph algorithms using multiple input datasets.

---

# Student Details

| Name | Roll Number |
|------|-------------|
| Vikram Gurjar | 2026CSM1039 |
| Prashant Kumar | 2026CSM1028 |

**Course:** CS509_PGSoftwareLab

**Assignment:** Assignment 01

**Type:** Buddy Assignment

---

# Programming Language

- C++
- Compiler : g++
- Standard : C++17

---

# Development Environment

- Windows 11
- MinGW g++
- GNU Make
- Command Prompt / PowerShell
- Visual Studio Code (Code Editing Only)

---

# Repository Structure

```
CS509_CS1028_CS1039/

│── README.md
│
├── common_wrapper/
│      wrapper.cpp
│
├── Assignment_01/
│
│   ├── driver/
│   │      main.cpp
│   │      graph_driver.cpp
│   │
│   ├── src/
│   │      bfs_dfs_algo.cpp
│   │      bfs_dfs_algo.hpp
│   │      csr_graph.cpp
│   │      csr_graph.hpp
│   │      sssp.cpp
│   │      sssp.hpp
│   │
│   ├── tests/
│   │      graph_input.txt
│   │      graph_10.txt
│   │      graph_100.txt
│   │      graph_1000.txt
│   │      graph_10000.txt
│   │      graph_50000.txt
│   │      graph_100000.txt
│   │
│   ├── outputs/
│   │      bfs_output.txt
│   │      dfs_output.txt
│   │      output_sssp.txt
│   │
│   └── Makefile
```

---

# Project Objectives

The objectives of this assignment are:

- Construct graphs using the Compressed Sparse Row (CSR) representation.
- Perform graph traversal using BFS.
- Perform graph traversal using DFS.
- Compute shortest paths using Single Source Shortest Path (SSSP).
- Measure and compare execution time for different graph sizes.

---

# Algorithms Implemented

## 1. Breadth First Search (BFS)

Breadth First Search explores all neighboring vertices before moving to the next level.

### Features

- Level-order graph traversal
- Computes shortest distance in unweighted graphs
- Stores traversal order
- Measures execution time

### Time Complexity

```
O(V + E)
```

---

## 2. Depth First Search (DFS)

Depth First Search explores each branch completely before backtracking.

### Features

- Depth-first traversal
- Stack-based implementation
- Stores traversal order
- Measures execution time

### Time Complexity

```
O(V + E)
```

---

## 3. Single Source Shortest Path (SSSP)

The project implements Dijkstra's algorithm to compute the shortest distance from a source vertex to all other vertices in a weighted graph.

### Features

- Computes minimum path cost
- Supports weighted graphs
- Displays shortest distances
- Measures execution time

### Time Complexity

```
O(V²)
```

---

# CSR (Compressed Sparse Row)

The graph is represented using the Compressed Sparse Row (CSR) format.

The CSR representation stores the graph using:

- Row Pointer Array
- Column Index Array

This representation reduces memory usage for sparse graphs and enables efficient traversal.

---

# Input Format

```
Number_of_Vertices Number_of_Edges

Vertex Degree AdjacentVertices

...

SOURCE SourceVertex
```

Example

```
10 11

0 2 1 2
1 2 0 3
2 3 0 3 4
3 2 1 2
4 2 2 5
5 2 4 6
6 2 5 7
7 2 6 8
8 2 7 9
9 1 8

SOURCE 0
```

---

# Output

## BFS

Displays

- Traversal Order
- Distance of every vertex
- Execution Time

---

## DFS

Displays

- Traversal Order
- Execution Time

---

## SSSP

Displays

- Source Vertex
- Distance of every vertex
- Execution Time

---

# Test Files

The repository contains graph datasets of different sizes.

```
graph_10.txt

graph_100.txt

graph_1000.txt

graph_10000.txt

graph_50000.txt

graph_100000.txt
```

These datasets are used to evaluate algorithm performance.

---

# Output Files

Generated outputs are stored inside:

```
outputs/

bfs_output.txt

dfs_output.txt

output_sssp.txt
```

---

# Compilation

Compile the project using:

```bash
make
```

or

```bash
g++ driver/main.cpp driver/graph_driver.cpp src/*.cpp common_wrapper/wrapper.cpp -o graph_app
```

---

# Running the Project

Run BFS

```bash
graph_app bfs tests/graph_100.txt outputs/bfs_output.txt
```

Run DFS

```bash
graph_app dfs tests/graph_100.txt outputs/dfs_output.txt
```

Run SSSP

```bash
graph_app sssp tests/graph_input.txt outputs/output_sssp.txt
```

---

# Performance Measurement

Execution time is measured using

```cpp
std::chrono::high_resolution_clock
```

The timing includes only algorithm execution. File reading and output generation are excluded.

---

# Complexity Analysis

| Algorithm | Time Complexity | Space Complexity |
|------------|----------------|------------------|
| BFS | O(V + E) | O(V) |
| DFS | O(V + E) | O(V) |
| SSSP (Dijkstra) | O(V²) | O(V) |
| CSR Construction | O(V + E) | O(V + E) |

---

# References

- CS509 Software Laboratory Assignment Guidelines
- GNU GCC Documentation
- C++ Reference Documentation
- Course Notes

---

# Authors

**Vikram Gurjar**  
Roll Number: **2026CSM1039**

**Prashant Kumar**  
Roll Number: **2026CSM1028**

**Course:** CS509_PGSoftwareLab
