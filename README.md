# CS509 Software Laboratory

## Buddy Assignment Repository

This repository contains the Buddy Assignment work for the **CS509 Software Laboratory** course.

The repository contains two assignments:

- **Assignment 01** - BFS, DFS, SSSP and CSR
- **Assignment 02** - Triangle Counting, Betweenness Centrality and Connected Components

The project is written in **C++17** and uses **CSR (Compressed Sparse Row)** for graph representation.

---

## 1. Student Details

| Student | Entry Number | 
|---|---|
| Prashant Kumar | 2026CSM1028 | 
| Vikram Gurjar | 2026CSM1039 | 

| Item | Details |
|---|---|
| Course | CS509 Software Laboratory |
| Program | M.Tech CSE |
| Language | C++ |
| Standard | C++17 |
| Compiler | g++ |
| Build Tool | GNU Make |
| Graph Representation | CSR |
| Assignment Type | Buddy Assignment |

---

## 2. Repository Overview

| Assignment | Main Topic | Algorithms |
|---|---|---|
| Assignment 01 | Basic Graph Algorithms | BFS, DFS, SSSP, CSR |
| Assignment 02 | Graph Processing | Triangle Counting, Betweenness Centrality, Connected Components |

---

## 3. Repository Structure

```text
CS509_CS1028_CS1039/
│
├── README.md
├── Makefile
├── wrapper.cpp
├── buddy_csr.cpp
├── buddy_csr.hpp
├── .gitignore
│
├── Assignment_01/
│   ├── README.md
│   ├── src/
│   ├── driver/
│   ├── tests/
│   └── outputs/
│
└── Assignment_02/
    ├── README.md
    ├── src/
    ├── driver/
    ├── tests/
    └── outputs/
```

---

## 4. Root Files

| File | Purpose |
|---|---|
| `README.md` | Main repository documentation |
| `Makefile` | Builds, runs and cleans the project |
| `wrapper.cpp` | Common menu for both assignments |
| `buddy_csr.cpp` | Common CSR implementation |
| `buddy_csr.hpp` | Common CSR declarations |
| `.gitignore` | Git ignored files |

---

## 5. Programming Language and Tools

| Tool | Details |
|---|---|
| Language | C++ |
| Standard | C++17 |
| Compiler | g++ |
| Optimization | `-O3` |
| Build Tool | GNU Make |
| Graph Representation | CSR |
| Timing | `std::chrono` |
| Time Unit | milliseconds |

---

## 6. Common CSR Module

The root folder contains:

```text
buddy_csr.cpp
buddy_csr.hpp
```

The CSR graph contains:

| Field | Meaning |
|---|---|
| `V` | Number of vertices |
| `E` | Number of edges |
| `row_ptr` | Starting position of each vertex's neighbours |
| `col_idx` | Neighbour vertex numbers |
| `values` | Edge weights |

The common CSR module is used by the graph algorithms.

---

## 7. Common Wrapper

The file:

```text
wrapper.cpp
```

provides one menu for both assignments.

### Example

```text
===============================
      CS509 Common Wrapper
===============================

1. Assignment 1
2. Assignment 2
3. Exit
```

| Option | Action |
|---|---|
| `1` | Run Assignment 01 |
| `2` | Run Assignment 02 |
| `3` | Exit |

After selecting an assignment, the user can run:

```text
1. Run a single test case
2. Run all test files in batch
0. Go back
```

---

## 8. Compilation

Open a terminal in the root project folder.

Run:

```bash
make compile
```

The wrapper is compiled using:

```bash
g++ -O3 wrapper.cpp -o wrapper.exe
```

---

## 9. Run the Project

After compilation, run:

```bash
make run
```

You can also use:

```bash
make
```

The complete flow is:

```text
make
  |
  v
Compile
  |
  v
Run Wrapper
  |
  +------------------+
  |                  |
  v                  v
Assignment 01    Assignment 02
```

---

## 10. Clean the Project

To remove generated executable files and output files, run:

```bash
make clean
```

---

## 11. Assignment 01

Assignment 01 contains:

- Breadth First Search (BFS)
- Depth First Search (DFS)
- Single Source Shortest Path (SSSP)
- CSR Graph Representation

### BFS

BFS visits graph vertices level by level.

| Item | Details |
|---|---|
| Data Structure | Queue |
| Time Complexity | `O(V + E)` |
| Space Complexity | `O(V)` |

### DFS

DFS explores one path deeply before returning.

| Item | Details |
|---|---|
| Data Structure | Stack |
| Time Complexity | `O(V + E)` |
| Space Complexity | `O(V)` |

### SSSP

SSSP finds shortest distances from one source vertex.

| Item | Details |
|---|---|
| Algorithm | Dijkstra |
| Time Complexity | `O(V²)` |
| Space Complexity | `O(V)` |

---

## 12. Assignment 01 Files

| File | Purpose |
|---|---|
| `bfs_dfs_algo.cpp` | BFS and DFS implementation |
| `bfs_dfs_algo.hpp` | BFS and DFS declarations |
| `csr_graph.cpp` | CSR implementation |
| `csr_graph.hpp` | CSR declarations |
| `sssp.cpp` | SSSP implementation |
| `sssp.hpp` | SSSP declarations |
| `graph_driver.cpp` | BFS and DFS driver |
| `main.cpp` | SSSP driver |

---

## 13. Assignment 01 Test Files

### BFS and DFS

| Test File | Vertices | Edges |
|---|---:|---:|
| `graph_1.txt` | 5 | 5 |
| `graph_10.txt` | 10 | 11 |
| `graph_100.txt` | 100 | 99 |
| `graph_1000.txt` | 1,000 | 999 |
| `graph_10000.txt` | 10,000 | 9,999 |
| `graph_50000.txt` | 50,000 | 49,999 |
| `graph_100000.txt` | 100,000 | 99,999 |

### SSSP

| Test File | Vertices | Edges |
|---|---:|---:|
| `sssp_1.txt` | 5 | 6 |
| `sssp_10.txt` | 10 | 20 |
| `sssp_100.txt` | 100 | 300 |
| `sssp_1000.txt` | 1,000 | 3,000 |
| `sssp_10000.txt` | 10,000 | 30,000 |

---

## 14. Assignment 01 Execution

From the wrapper, select:

```text
1. Assignment 1
```

Then select the required algorithm:

```text
1. Breadth-First Search (BFS)
2. Depth-First Search (DFS)
3. Single-Source Shortest Path (SSSP)
```

Then select:

```text
1. Run a single test case
```

or:

```text
2. Run all test files in batch
```

---

## 15. Assignment 01 Output

Output files are stored in:

```text
Assignment_01/outputs/
```

Example:

```text
bfs_10_output.txt
bfs_100_output.txt
bfs_1000_output.txt

dfs_10_output.txt
dfs_100_output.txt
dfs_1000_output.txt

sssp_out_1.txt
sssp_out_10.txt
sssp_out_100.txt
```

---

## 16. Assignment 02

Assignment 02 contains:

1. Triangle Counting
2. Betweenness Centrality
3. Connected Components

All three algorithms use the CSR graph representation.

### Triangle Counting

Triangle Counting finds the number of triangles in an undirected graph.

### Betweenness Centrality

Betweenness Centrality measures the importance of vertices based on shortest paths.

### Connected Components

Connected Components finds separate groups of connected vertices.

---

## 17. Assignment 02 Files

| File | Purpose |
|---|---|
| `triangle_counting.cpp` | Triangle Counting implementation |
| `triangle_counting.hpp` | Triangle Counting declarations |
| `betweenness_centrality.cpp` | Betweenness Centrality implementation |
| `betweenness_centrality.hpp` | Betweenness Centrality declarations |
| `connected_components.cpp` | Connected Components implementation |
| `connected_components.hpp` | Connected Components declarations |
| `tc_driver.cpp` | Triangle Counting driver |
| `bc_driver.cpp` | Betweenness Centrality driver |
| `cc_driver.cpp` | Connected Components driver |

---

## 18. Assignment 02 Test Files

### Triangle Counting

| Test File | Vertices | Edges |
|---|---:|---:|
| `tc_1.txt` | 6 | 8 |
| `tc_10.txt` | 10 | 20 |
| `tc_100.txt` | 100 | 300 |
| `tc_1000.txt` | 1,000 | 3,000 |
| `tc_10000.txt` | 10,000 | 30,000 |

### Betweenness Centrality

| Test File | Vertices | Edges |
|---|---:|---:|
| `bc_1.txt` | 5 | 4 |
| `bc_10.txt` | 10 | 20 |
| `bc_100.txt` | 100 | 300 |
| `bc_1000.txt` | 1,000 | 3,000 |
| `bc_5000.txt` | 5,000 | 15,000 |
| `bc_10000.txt` | 10,000 | 30,000 |

### Connected Components

| Test File | Vertices | Edges |
|---|---:|---:|
| `cc_1.txt` | 8 | 4 |
| `cc_10.txt` | 10 | 20 |
| `cc_100.txt` | 100 | 300 |
| `cc_1000.txt` | 1,000 | 3,000 |
| `cc_10000.txt` | 10,000 | 30,000 |

---

## 19. Assignment 02 Execution

From the wrapper, select:

```text
2. Assignment 2
```

Then select:

```text
1. Triangle Counting
2. Betweenness Centrality
3. Connected Components
```

Then select:

```text
1. Run a single test case
```

or:

```text
2. Run all test files in batch
```

---

## 20. Assignment 02 Output

Output files are stored in:

```text
Assignment_02/outputs/
```

Example:

```text
tc_1_out.txt
tc_10_out.txt
tc_100_out.txt

bc_1_out.txt
bc_10_out.txt
bc_100_out.txt

cc_1_out.txt
cc_10_out.txt
cc_100_out.txt
```

---

## 21. Complexity Summary

| Algorithm | Time Complexity | Main Structure |
|---|---|---|
| BFS | `O(V + E)` | CSR + Queue |
| DFS | `O(V + E)` | CSR + Stack |
| SSSP / Dijkstra | `O(V²)` | CSR + Arrays |
| Triangle Counting | Depends on neighbour intersection | CSR |
| Betweenness Centrality | `O(V × E)` | CSR + BFS |
| Connected Components | `O(V + E)` | CSR + BFS |

Where:

```text
V = Number of vertices
E = Number of edges
```

---

## 22. Execution Flow

```text
                    CS509 Repository
                          |
                          v
                     make run
                          |
                          v
                    wrapper.cpp
                          |
                +---------+---------+
                |                   |
                v                   v
         Assignment 01       Assignment 02
                |                   |
        +-------+-------+     +-----+-----+-----+
        |       |       |     |           |     |
        v       v       v     v           v     v
       BFS     DFS     SSSP   TC          BC    CC
        |       |       |     |           |     |
        +-------+-------+     +-----------+-----+
                |                       |
                v                       v
          Output Files             Output Files
```

---

## 23. Input to Output Flow

```text
Input Test File
       |
       v
   CSR Loader
       |
       v
    CSR Graph
       |
       v
    Algorithm
       |
       v
Result + Execution Time
       |
       v
   Output File
```

---

## 24. Runtime Measurement

Execution time is measured using:

```cpp
std::chrono
```

The execution time is reported in:

```text
milliseconds (ms)
```

For very small test cases, the execution time may be shown as:

```text
0.0000 ms
```

---

## 25. Important Commands

| Command | Purpose |
|---|---|
| `make` | Build and run the project |
| `make compile` | Compile the wrapper |
| `make run` | Run the wrapper |
| `make clean` | Remove generated files |

---

## 26. Assignment README Files

| README | Purpose |
|---|---|
| `Assignment_01/README.md` | Assignment 01 details |
| `Assignment_02/README.md` | Assignment 02 details |
| `README.md` | Complete root repository information |

---

## 27. Conclusion

This repository contains the complete Buddy Assignment work for CS509 Software Laboratory.

### Assignment 01

- BFS
- DFS
- SSSP
- CSR

### Assignment 02

- Triangle Counting
- Betweenness Centrality
- Connected Components

The project uses C++17, g++, GNU Make and CSR graph representation.

The repository contains source code, drivers, test files, output files and a common wrapper for both assignments.

---

## Authors

| Name | Entry Number |
|---|---|
| **Prashant Kumar** | **2026CSM1028** |
| **Vikram Gurjar** | **2026CSM1039** |

**Course:** CS509 Software Laboratory  
**Program:** M.Tech CSE  
**Assignment Type:** Buddy Assignment
