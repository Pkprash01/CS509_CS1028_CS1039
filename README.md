# CS509 Laboratory Repository — Buddy Assignments

## Repository Overview

This repository contains the **Buddy Assignment work for the CS509 Software Laboratory**.

The repository contains four assignments:

1. **Assignment 01** — BFS, DFS, SSSP and CSR
2. **Assignment 02** — Triangle Counting, Betweenness Centrality and Connected Components
3. **Assignment 03** — Gradient Descent and Maxflow-Mincut Buddy Tasks
4. **Assignment 04** — K-Means Clustering and FastMap Buddy Tasks

The implementations are written in **C++17**. Graph algorithms use the common **CSR (Compressed Sparse Row)** representation where required.

---

## Student Details

| Field | Details |
|---|---|
| **Student 1** | Prashant Kumar |
| **Entry No.** | 2026CSM1028 |
| **Student 2** | Vikram Gurjar |
| **Entry No.** | 2026CSM1039 |
| **Program** | M.Tech CSE |
| **Course** | CS509 Software Laboratory |
| **Assignment Mode** | Buddy |

---

# Language and Environment
| Component | Configuration |
|---|---|
| **Programming Language** | C++ |
| **C++ Standard** | C++17 |
| **Compiler** | GCC / g++ / MinGW-w64 |
| **Operating Systems** | Windows / Linux |
| **Graph Representation** | CSR |
| **Timing Method** | `std::chrono::high_resolution_clock` |
| **Timing Unit** | Milliseconds (`ms`) |
| **Optimization** | `-O3` |

---

# Directory Structure
```text
CS509_CS1028_CS1039/
│
├── README.MD
├── wrapper.cpp
├── buddy_csr.cpp
├── buddy_csr.hpp
├── Makefile
├── .gitignore
│
├── Assignment_01/
│   ├── README.md
│   ├── src/
│   ├── driver/
│   ├── tests/
│   └── outputs/
│
├── Assignment_02/
│   ├── README.md
│   ├── src/
│   ├── driver/
│   ├── tests/
│   └── outputs/
│
├── Assignment_03/
│   ├── README.md
│   ├── src/
│   │   ├── gradient_descent.cpp
│   │   ├── gradient_descent.hpp
│   │   ├── maxflow_mincut.cpp
│   │   └── maxflow_mincut.hpp
│   │
│   ├── driver/
│   │   ├── gd_driver.cpp
│   │   └── maxflow_driver.cpp
│   │
│   ├── tests/
│   │   ├── gd_01.txt
│   │   ├── gd_02.txt
│   │   ├── gd_03.txt
│   │   ├── gd_04.txt
│   │   ├── gd_05.txt
│   │   ├── maxflow_10.txt
│   │   ├── maxflow_100.txt
│   │   ├── maxflow_1000.txt
│   │   ├── maxflow_10000.txt
│   │   └── maxflow_50000.txt
│   │
│   └── outputs/
│
└── Assignment_04/
    ├── README.md
    ├── src/
    │   ├── kmeans.cpp
    │   ├── kmeans.hpp
    │   ├── fastmap.cpp
    │   └── fastmap.hpp
    │
    ├── driver/
    │   ├── kmeans_driver.cpp
    │   └── fastmap_driver.cpp
    │
    ├── tests/
    │   ├── km_01.txt
    │   ├── km_02.txt
    │   ├── km_03.txt
    │   ├── km_04.txt
    │   ├── fm_01.txt
    │   ├── fm_02.txt
    │   └── fm_03.txt
    │
    └── outputs/
```
---

# Common Root Files
| File | Purpose |
|---|---|
| `README.MD` | Complete repository documentation |
| `wrapper.cpp` | Common menu for all assignments |
| `buddy_csr.cpp` | Common CSR implementation |
| `buddy_csr.hpp` | Common CSR declarations |
| `Makefile` | Build and clean commands |
| `.gitignore` | Ignored generated files |

---

# Common CSR Representation
The common files:

```text
buddy_csr.cpp
buddy_csr.hpp
```

are reused by the graph assignments.

The CSR structure contains:

| Field | Meaning |
|---|---|
| `V` | Number of vertices |
| `E` | Number of edges |
| `row_ptr` | Starting position of each adjacency list |
| `col_idx` | Destination vertex numbers |
| `values` | Edge weights or capacities |

The graph is loaded and converted to CSR before the graph algorithm is started.

For Assignment 03 Maxflow-Mincut, CSR conversion is preprocessing and is not included in the reported algorithm execution time.

---

# Common Wrapper
The file:

```text
wrapper.cpp
```

provides a common menu.

```text
===============================
      CS509 Common Wrapper
===============================

1. Assignment 1
2. Assignment 2
3. Assignment 3
4. Assignment 4
5. Exit
```

| Option | Action |
|---|---|
| `1` | Run Assignment 01 |
| `2` | Run Assignment 02 |
| `3` | Run Assignment 03 Buddy Tasks |
| `4` | Run Assignment 04 Buddy Tasks |
| `5` | Exit |

Each assignment provides options for running individual tests or available test files in batch.

---

# Compilation
From the root directory:

```bash
make compile
```

The project uses:

```text
C++17
g++
-O3
```

---

# Run
Run the common wrapper using:

```bash
make run
```

or:

```bash
make
```

---

# Clean
Remove generated executable and output files using:

```bash
make clean
```

---

# Assignment 01
## Assignment 01 Overview

Assignment 01 contains:

1. Breadth First Search (BFS)
2. Depth First Search (DFS)
3. Single Source Shortest Path (SSSP)
4. CSR Graph Representation

---

## BFS

BFS visits graph vertices level by level.

| Item | Details |
|---|---|
| **Data Structure** | Queue |
| **Time Complexity** | `O(V + E)` |
| **Space Complexity** | `O(V)` |

---

## DFS

DFS explores one path deeply before returning.

| Item | Details |
|---|---|
| **Data Structure** | Stack |
| **Time Complexity** | `O(V + E)` |
| **Space Complexity** | `O(V)` |

---

## SSSP

SSSP finds shortest distances from one source vertex.

| Item | Details |
|---|---|
| **Algorithm** | Dijkstra |
| **Time Complexity** | `O(V²)` |
| **Space Complexity** | `O(V)` |

---

## Assignment 01 Files

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

## Assignment 01 Tests

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

## Assignment 01 Output

Output files are stored in:

```text
Assignment_01/outputs/
```

---

# Assignment 02
## Assignment 02 Overview

Assignment 02 contains:

1. Triangle Counting
2. Betweenness Centrality
3. Connected Components

All three algorithms use the CSR graph representation.

---

## Triangle Counting

Triangle Counting finds the number of triangles in an undirected graph.

---

## Betweenness Centrality

Betweenness Centrality measures the importance of vertices based on shortest paths.

---

## Connected Components

Connected Components finds separate groups of connected vertices.

---

## Assignment 02 Files

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

## Assignment 02 Tests

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

## Assignment 02 Output

Output files are stored in:

```text
Assignment_02/outputs/
```

---

# Assignment 03 — Buddy Tasks
## Assignment 03 Overview

Assignment 03 contains the two Buddy Tasks:

1. **Gradient Descent (GD)**
2. **Maxflow-Mincut**

The Assignment 03 implementation is written in C++17.

---

# 1. Gradient Descent
Gradient Descent is used to minimize a one-variable polynomial.

The polynomial is represented as:

```text
f(x) = c0 + c1*x + c2*x^2 + ... + cd*x^d
```

The derivative is calculated from the same coefficient array:

```text
f'(x) = c1 + 2*c2*x + ... + d*cd*x^(d-1)
```

The update is:

```text
x_new = x - learning_rate * f'(x)
```

The program stops when:

```text
|f'(x)| <= tolerance
```

or when the maximum number of iterations is reached.

The same implementation is used for all five required degrees.

---

## Gradient Descent Input

The input format is:

```text
DEGREE d
COEFFICIENTS c0 c1 c2 ... cd
INITIAL_X x0
LEARNING_RATE alpha
TOLERANCE epsilon
MAX_ITERATIONS n
```

### Example

```text
DEGREE 6
COEFFICIENTS 0 0 1 0 0.5 0 0.1
INITIAL_X 2
LEARNING_RATE 0.02
TOLERANCE 0.000001
MAX_ITERATIONS 20000
```

---

## Gradient Descent Output

The driver prints:

```text
Algorithm: Gradient Descent
Degree: ...
Final x: ...
Final f(x): ...
Iterations: ...
Converged: true
Execution time: ... ms
```

---

## Gradient Descent Tests

| Test File | Degree | Initial x | Rate | Tolerance | Max Iterations | Expected x* |
|---|---:|---:|---:|---:|---:|---:|
| `gd_01.txt` | 2 | 0 | 0.10 | 0.000001 | 5,000 | 3 |
| `gd_02.txt` | 4 | 2 | 0.02 | 0.000001 | 10,000 | 0 |
| `gd_03.txt` | 6 | 2 | 0.02 | 0.000001 | 20,000 | 0 |
| `gd_04.txt` | 8 | 2 | 0.01 | 0.00000001 | 50,000 | 0 |
| `gd_05.txt` | 10 | 2 | 0.005 | 0.0000000001 | 100,000 | 0 |

---

## Gradient Descent Driver

```text
Assignment_03/driver/gd_driver.cpp
```

The driver:

1. Reads the polynomial input file.
2. Validates the input parameters.
3. Starts the timer.
4. Calls Gradient Descent.
5. Stops the timer.
6. Prints the result and execution time.
7. Releases allocated memory.

Run using:

```bash
./gd_driver <input_file>
```

---

# 2. Maxflow-Mincut
Maxflow-Mincut works on a directed graph with positive integer capacities.

The maximum-flow value is computed using a **Dinic-style maximum flow algorithm**.

After maximum flow is complete, the residual graph is searched from the source. The reachable vertices form the source side of a valid minimum cut.

The implementation reports:

- Maximum flow
- Minimum cut capacity
- Source-side vertices
- Sink-side vertices
- Cut edges
- Execution time

The correctness condition is:

```text
Maximum flow = Minimum cut capacity
```

---

## Maxflow-Mincut Input

The input uses a directed adjacency-list format:

```text
V E
u degree neighbor1 capacity1 neighbor2 capacity2 ...
...
u degree ...
SOURCE s
SINK t
```

Only outgoing original edges are listed. Reverse residual edges are created internally.

### Example

```text
6 10
0 2 1 16 2 13
1 2 2 10 3 12
2 2 1 4 4 14
3 2 2 9 5 20
4 2 3 7 5 4
5 0
SOURCE 0
SINK 5
```

---

## Maxflow-Mincut Tests

| Test File | Vertices |
|---|---:|
| `maxflow_10.txt` | 10 |
| `maxflow_100.txt` | 100 |
| `maxflow_1000.txt` | 1,000 |
| `maxflow_10000.txt` | 10,000 |
| `maxflow_50000.txt` | 50,000 |

The test graphs are directed, sparse and contain positive capacities.

---

## Maxflow-Mincut Driver

```text
Assignment_03/driver/maxflow_driver.cpp
```

The driver:

1. Reads the graph.
2. Validates source and sink.
3. Converts the graph to CSR.
4. Starts the timer after CSR preparation.
5. Calls Maxflow-Mincut.
6. Extracts the minimum cut.
7. Stops the timer.
8. Prints flow, cut and execution time.
9. Releases allocated memory.

Run using:

```bash
./maxflow_driver <input_file>
```

---

# Assignment 03 CSR Requirement
The graph input is converted to CSR before the Maxflow-Mincut algorithm starts.

The flow is:

```text
Input File
    |
    v
Read Graph
    |
    v
CSR Conversion
    |
    v
Start Timer
    |
    v
Maxflow
    |
    v
Minimum Cut
    |
    v
Stop Timer
```

CSR conversion is preprocessing and is not included in the reported algorithm time.

For Maxflow-Mincut, minimum-cut extraction from the final residual graph is part of the measured algorithm work.

---

# Assignment 03 Timing
Timing uses:

```cpp
std::chrono::high_resolution_clock
```

The reported unit is:

```text
milliseconds (ms)
```

For Gradient Descent, the algorithm itself is timed.

For Maxflow-Mincut, maximum flow and required minimum-cut extraction are timed.

File reading, parsing and CSR conversion are outside the measured algorithm time.

---

# Input Validation
## Gradient Descent

The driver checks:

- Valid degree
- Correct coefficient count
- Positive learning rate
- Positive tolerance
- Positive maximum iterations

## Maxflow-Mincut

The driver checks:

- Valid vertex numbers
- Valid source and sink
- Source is different from sink
- Source and sink are present
- Positive capacities

---

# Assignment 03 Output
Output files are stored in:

```text
Assignment_03/outputs/
```

Example:

```text
gd_01_out.txt
gd_02_out.txt
gd_03_out.txt
gd_04_out.txt
gd_05_out.txt

maxflow_10_out.txt
maxflow_100_out.txt
maxflow_1000_out.txt
maxflow_10000_out.txt
maxflow_50000_out.txt
```

---

# Wrapper Execution
The main menu is:

```text
===============================
      CS509 Common Wrapper
===============================

1. Assignment 1
2. Assignment 2
3. Assignment 3
4. Assignment 4
5. Exit
```

Assignment 03 menu:

```text
--- Assignment 3: Buddy Tasks ---

1. Gradient Descent
2. Maxflow-Mincut
0. Back to Main Menu
```

Each algorithm can be run using a single test case or all available tests.

---

# Assignment 04 — Buddy Tasks
## Assignment 04 Overview

Assignment 04 contains the two Buddy Tasks:

1. **K-Means Clustering**
2. **FastMap**

The Assignment 04 implementation is written in C++17.

---

# 1. K-Means Clustering
K-Means is an iterative clustering algorithm used to divide data points into `K` clusters.

The implementation starts with the first `K` input points as the initial centroids. Each point is assigned to the nearest centroid using Euclidean distance. The centroids are then recomputed from the assigned points.

The process continues until the assignments stop changing, the centroid movement becomes smaller than the given tolerance, or the maximum number of iterations is reached.

The program reports the final cluster assignments, final centroids, WCSS (Within-Cluster Sum of Squares), number of iterations and execution time.

---

## K-Means Input
The input format is:

```text
N D K
point coordinates ...
MAX_ITERATIONS value
TOLERANCE value
```

Here, `N` is the number of points, `D` is the number of dimensions and `K` is the number of clusters.

---

## K-Means Tests

| Test File | Purpose |
|---|---|
| `km_01.txt` | Small clustering test |
| `km_02.txt` | Medium clustering test |
| `km_03.txt` | Larger clustering test |
| `km_04.txt` | Larger dimensional clustering test |

---

## K-Means Driver

```text
Assignment_04/driver/kmeans_driver.cpp
```

The driver reads the input file, starts the timer, calls the K-Means implementation, writes the result to the output file and prints the execution time.

Run using:

```bash
./kmeans_driver <input_file> <output_file>
```

---

# 2. FastMap
FastMap is a dimensionality reduction algorithm that maps objects from a distance space into a lower-dimensional coordinate space.

For each dimension, the implementation selects a farthest pair of pivot objects. The coordinates of the objects are calculated using their distances to the selected pivots. The remaining distances are then deflated before processing the next dimension.

The program reports the selected pivots, generated coordinates and execution time.

---

## FastMap Input
The input format is:

```text
N K
N x N distance matrix
```

Here, `N` is the number of objects and `K` is the target number of dimensions.

---

## FastMap Tests

| Test File | Purpose |
|---|---|
| `fm_01.txt` | Small distance-matrix test |
| `fm_02.txt` | Medium distance-matrix test |
| `fm_03.txt` | Larger distance-matrix test |

A very large `10,000 x 10,000` distance matrix is not included in the repository because the text input would be extremely large and the current implementation stores the distance matrix in memory.

---

## FastMap Driver

```text
Assignment_04/driver/fastmap_driver.cpp
```

The driver reads the distance matrix, starts the timer, calls FastMap, writes the result to the output file and prints the execution time.

Run using:

```bash
./fastmap_driver <input_file> <output_file>
```

---

# Assignment 04 Output
Output files are stored in:

```text
Assignment_04/outputs/
```

Example output files are:

```text
km_01_out.txt
km_02_out.txt
km_03_out.txt
km_04_out.txt

fm_01_out.txt
fm_02_out.txt
fm_03_out.txt
```

---

# Assignment 04 Wrapper Execution
The Assignment 04 menu is:

```text
--- Assignment 4: Buddy Tasks ---

1. K-Means Clustering
2. FastMap
0. Back to Main Menu
```

Each task can be run using a single test case or all available test files.

---

# Assignment 04 Timing
Timing uses:

```cpp
std::chrono::high_resolution_clock
```

The reported unit is:

```text
milliseconds (ms)
```

For K-Means, the measured work includes the clustering iterations and centroid updates. For FastMap, the measured work includes pivot selection, coordinate calculation and distance deflation.

File reading and input parsing are outside the measured algorithm time.

---

# Assignment 04 Complexity Summary
| Algorithm | Main Approach | Main Data Structure |
|---|---|---|
| K-Means | Repeated assignment and centroid update | Arrays |
| FastMap | Pivot selection and distance deflation | Distance Matrix + Arrays |

---

# Complexity Summary
| Algorithm | Main Approach | Main Data Structure |
|---|---|---|
| BFS | Breadth-first traversal | CSR + Queue |
| DFS | Depth-first traversal | CSR + Stack |
| SSSP | Dijkstra | CSR + Arrays |
| Triangle Counting | Neighbour intersection | CSR |
| Betweenness Centrality | Shortest-path processing | CSR |
| Connected Components | Graph traversal | CSR |
| Gradient Descent | Polynomial optimization | Coefficient Array |
| Maxflow-Mincut | Dinic-style maximum flow | CSR + Residual Graph |
| K-Means | Iterative clustering | Arrays |
| FastMap | Dimensionality reduction | Distance Matrix + Arrays |

For Gradient Descent, each iteration evaluates the polynomial derivative using the coefficient array.

---

# Execution Flow
```text
                         CS509 Repository
                                |
                                v
                           make run
                                |
                                v
                           wrapper.cpp
                                |
          +-------------------+-------------------+-------------------+
          |                   |                   |                   |
          v                   v                   v                   v
    Assignment 01       Assignment 02       Assignment 03       Assignment 04
          |                   |                   |                   |
    +-----+-----+       +-----+-----+       +-----+-----+       +-----+-----+
    |     |     |       |     |     |       |           |       |           |
    v     v     v       v     v     v       v           v       v           v
   BFS   DFS   SSSP     TC    BC    CC      GD       Maxflow  K-Means    FastMap
```

---
# Input to Output Flow
## Assignment 01 and Assignment 02

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

## Assignment 03 Gradient Descent

```text
Gradient Descent Input
       |
       v
Read Polynomial
       |
       v
Evaluate f(x) and f'(x)
       |
       v
Update x
       |
       v
Check Tolerance
       |
       v
Result + Time
```

## Assignment 03 Maxflow-Mincut

```text
Graph Input
    |
    v
Adjacency List
    |
    v
CSR Conversion
    |
    v
Residual Network
    |
    v
Maximum Flow
    |
    v
Minimum Cut
    |
    v
Result + Time
```

---

# Important Commands
| Command | Purpose |
|---|---|
| `make` | Build and run the project |
| `make compile` | Compile the project |
| `make run` | Run the common wrapper |
| `make clean` | Remove generated files |

---

# Assignment README Files
| README | Purpose |
|---|---|
| `README.MD` | Root repository documentation |
| `Assignment_01/README.md` | Assignment 01 details |
| `Assignment_02/README.md` | Assignment 02 details |
| `Assignment_03/README.md` | Assignment 03 Buddy Task details |
| `Assignment_04/README.md` | Assignment 04 Buddy Task details |

---

# Conclusion
This repository contains the Buddy Assignment work for the CS509 Software Laboratory.

### Assignment 01

- BFS
- DFS
- SSSP
- CSR

### Assignment 02

- Triangle Counting
- Betweenness Centrality
- Connected Components

### Assignment 03

- Gradient Descent
- Maxflow-Mincut

### Assignment 04

- K-Means Clustering
- FastMap

The project uses:

- C++17
- g++
- GNU Make
- CSR graph representation
- `std::chrono` for timing

The repository contains source files, drivers, test files, output folders, README files and a common wrapper.

---

# Authors
| Name | Entry Number |
|---|---|
| **Prashant Kumar** | **2026CSM1028** |
| **Vikram Gurjar** | **2026CSM1039** |

**Course:** CS509 Software Laboratory  
**Program:** M.Tech CSE  
**Assignment Type:** Buddy Assignment
