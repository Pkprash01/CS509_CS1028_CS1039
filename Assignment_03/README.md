# CS509 Laboratory Repository — Buddy Tasks

## Repository Overview

This section documents the **Buddy Tasks for Assignment 03** of the CS509 Software Laboratory.

Assignment 03 has an individual MST task and two Buddy Tasks. This repository implements the **Buddy Task portion**:

1. **Gradient Descent (GD)**
2. **Maxflow-Mincut**

The implementations are written in **C++17**. Maxflow-Mincut uses the common **CSR (Compressed Sparse Row)** representation from the previous assignments.

---

## Student Details

| Field | Details |
|---|---|
| **Student 1** | Prashant Kumar |
| **Entry No.** | 2026CSM1028 |
| **Student 2** | Vikram Gurjar |
| **Entry No.** | 2026CSM1039 |
| **Program** | M.Tech CSE |
| **Course** | CS509 |
| **Assignment** | Assignment 03 |
| **Assignment Mode** | Buddy |

---

# Language and Environment

| Component | Configuration |
|---|---|
| **Programming Language** | C++ |
| **C++ Standard** | C++17 |
| **Compiler** | GCC / g++ / MinGW-w64 |
| **Operating Systems** | Windows / Linux |
| **Graph Representation** | CSR for Maxflow-Mincut |
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
│
├── Assignment_02/
│
└── Assignment_03/
    │
    ├── README.md
    │
    ├── src/
    │   ├── gradient_descent.cpp
    │   ├── gradient_descent.hpp
    │   ├── maxflow_mincut.cpp
    │   └── maxflow_mincut.hpp
    │
    ├── driver/
    │   ├── gd_driver.cpp
    │   └── maxflow_driver.cpp
    │
    ├── tests/
    │   ├── gd_01.txt
    │   ├── gd_02.txt
    │   ├── gd_03.txt
    │   ├── gd_04.txt
    │   ├── gd_05.txt
    │   ├── maxflow_10.txt
    │   ├── maxflow_100.txt
    │   ├── maxflow_1000.txt
    │   ├── maxflow_10000.txt
    │   └── maxflow_50000.txt
    │
    └── outputs/
        ├── gd_01_out.txt
        ├── gd_02_out.txt
        ├── gd_03_out.txt
        ├── gd_04_out.txt
        ├── gd_05_out.txt
        ├── maxflow_10_out.txt
        ├── maxflow_100_out.txt
        ├── maxflow_1000_out.txt
        ├── maxflow_10000_out.txt
        └── maxflow_50000_out.txt
```

---

# Assignment 03 Buddy Task

The assignment specification defines two Buddy Tasks:

- Gradient Descent
- Maxflow-Mincut

The graph-based Maxflow-Mincut task reads an adjacency-list file and converts it to CSR before the algorithm is called. The CSR conversion is preprocessing and is not included in the reported algorithm time.

---

# 1. Gradient Descent (GD)

Gradient Descent is used to minimize a one-variable polynomial:

```text
f(x) = c0 + c1*x + c2*x^2 + ... + cd*x^d
```

The derivative is calculated from the same coefficient array:

```text
f'(x) = c1 + 2*c2*x + ... + d*cd*x^(d-1)
```

The update used by the implementation is:

```text
x_new = x - learning_rate * f'(x)
```

The program stops when:

```text
|f'(x)| <= tolerance
```

or when the maximum number of iterations is reached.

The same implementation is used for all five required polynomial degrees. Separate hard-coded functions are not used for the individual tests.

---

## Gradient Descent Input

The input file uses the following format:

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

- Algorithm name
- Polynomial degree
- Final x
- Final f(x)
- Number of iterations
- Convergence status
- Execution time

Example format:

```text
Algorithm: Gradient Descent
Degree: 6
Final x: ...
Final f(x): ...
Iterations: ...
Converged: true
Execution time: ... ms
```

---

# 2. Maxflow-Mincut

The Maxflow-Mincut implementation uses a directed graph with positive integer capacities.

The maximum-flow value is computed using a **Dinic-style maximum flow algorithm**.

After maximum flow is complete, the final residual graph is searched from the source. The vertices still reachable from the source form the source side of one valid minimum cut.

The implementation reports:

- Maximum flow
- Minimum cut capacity
- Source-side vertices
- Sink-side vertices
- Cut edges
- Execution time

The maximum-flow value and minimum-cut capacity must be equal.

---

## Maxflow-Mincut Input

The input file uses a directed adjacency-list format:

```text
V E
u0 degree neighbor1 capacity1 neighbor2 capacity2 ...
...
u(V-1) degree ...
SOURCE s
SINK t
```

Only outgoing original edges are listed. Reverse residual edges are created internally by the max-flow algorithm.

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

# CSR Graph Representation

The common files:

```text
buddy_csr.cpp
buddy_csr.hpp
```

are reused for the graph conversion.

The CSR structure contains:

| Field | Meaning |
|---|---|
| `V` | Number of vertices |
| `E` | Number of edges |
| `row_ptr` | Starting and ending positions of each adjacency list |
| `col_idx` | Destination vertex numbers |
| `values` | Edge capacities |

The driver reads the input and prepares the CSR graph before starting the algorithm timer.

The CSR conversion is therefore not included in the reported Maxflow-Mincut execution time.

---

# Drivers

## Gradient Descent Driver

```text
Assignment_03/driver/gd_driver.cpp
```

The driver:

1. Reads the polynomial input file.
2. Validates the input parameters.
3. Starts the timer.
4. Calls the Gradient Descent algorithm.
5. Stops the timer.
6. Prints the result and execution time.
7. Releases allocated memory.

Run using:

```bash
./gd_driver <input_file>
```

---

## Maxflow-Mincut Driver

```text
Assignment_03/driver/maxflow_driver.cpp
```

The driver:

1. Reads and validates the source and sink.
2. Loads the directed graph into CSR.
3. Starts the timer after CSR preparation.
4. Calls the Maxflow-Mincut algorithm.
5. Extracts the minimum cut from the final residual graph.
6. Stops the timer.
7. Prints the flow, cut and execution time.
8. Releases allocated memory.

Run using:

```bash
./maxflow_driver <input_file>
```

---

# Required Gradient Descent Tests

The five tests use the exact polynomial functions and parameters from the Assignment 03 specification.

| Test File | Degree | Initial x | Rate | Tolerance | Max Iterations | Expected x* |
|---|---:|---:|---:|---:|---:|---:|
| `gd_01.txt` | 2 | 0 | 0.10 | 1e-6 | 5,000 | 3 |
| `gd_02.txt` | 4 | 2 | 0.02 | 1e-6 | 10,000 | 0 |
| `gd_03.txt` | 6 | 2 | 0.02 | 1e-6 | 20,000 | 0 |
| `gd_04.txt` | 8 | 2 | 0.01 | 1e-8 | 50,000 | 0 |
| `gd_05.txt` | 10 | 2 | 0.005 | 1e-10 | 100,000 | 0 |

---

# Gradient Descent Benchmark Results

| Test File | Degree | Actual x | Actual f(x) | Iterations | Time (ms) | Status |
|---|---:|---:|---:|---:|---:|---|
| `gd_01.txt` | 2 | 2.9999995063 | 0.0000000000 | 70 | 0.000460 | **Pass** |
| `gd_02.txt` | 4 | 0.0000002379 | 0.0000000000 | 180 | 0.001332 | **Pass** |
| `gd_03.txt` | 6 | 0.0000004835 | 0.0000000000 | 349 | 0.003615 | **Pass** |
| `gd_04.txt` | 8 | 0.0000000050 | 0.0000000000 | 948 | 0.012579 | **Pass** |
| `gd_05.txt` | 10 | 0.0000000000 | 0.0000000000 | 2364 | 0.038818 | **Pass** |

The final x values are close to the expected global minimum values. All five tests reached the requested tolerance before the maximum iteration limit.

---

# Required Maxflow-Mincut Tests

The assignment requires the following graph sizes:

| Test File | Vertices (V) |
|---|---:|
| `maxflow_10.txt` | 10 |
| `maxflow_100.txt` | 100 |
| `maxflow_1000.txt` | 1,000 |
| `maxflow_10000.txt` | 10,000 |
| `maxflow_50000.txt` | 50,000 |

The generated graphs are directed and sparse. Each file contains a valid source-to-sink path and positive integer capacities.

---

# Maxflow-Mincut Benchmark Results

| Test File | V | E | Source | Sink | Maximum Flow | Cut Capacity | Time (ms) | Status |
|---|---:|---:|---:|---:|---:|---:|---:|---|
| `maxflow_10.txt` | 10 | 20 | 0 | 9 | 23 | 23 | 0.002063 | **Pass** |
| `maxflow_100.txt` | 100 | 200 | 0 | 99 | 59 | 59 | 0.019109 | **Pass** |
| `maxflow_1000.txt` | 1,000 | 2,000 | 0 | 999 | 104 | 104 | 0.075603 | **Pass** |
| `maxflow_10000.txt` | 10,000 | 20,000 | 0 | 9,999 | 115 | 115 | 0.783356 | **Pass** |
| `maxflow_50000.txt` | 50,000 | 100,000 | 0 | 49,999 | 91 | 91 | 3.317961 | **Pass** |

For every test, the maximum-flow value is equal to the capacity of the reported minimum cut.

---

# Timing

The timing follows the Assignment 03 requirement.

For Gradient Descent:

```text
Start timer
    |
    v
Gradient Descent
    |
    v
Stop timer
```

For Maxflow-Mincut:

```text
Read input
    |
    v
Build CSR
    |
    v
Start timer
    |
    v
Maxflow
    |
    v
Minimum-cut extraction
    |
    v
Stop timer
```

File reading, parsing and CSR conversion are not included in the reported algorithm time.

---

# Complexity Summary

| Algorithm | Main Approach | Main Data Structure |
|---|---|---|
| Gradient Descent | Iterative polynomial optimization | Dynamic coefficient array |
| Maxflow-Mincut | Dinic-style maximum flow | CSR + residual edge arrays |

For Gradient Descent, each iteration evaluates the polynomial derivative in `O(d)` time, where `d` is the polynomial degree.

For Maxflow-Mincut, the practical performance depends on the graph structure and the number of blocking-flow phases.

---

# Wrapper Execution

The common `wrapper.cpp` now contains Assignment 03.

Main menu:

```text
===============================
  CS509 Common Wrapper Menu
===============================
1. Assignment 1
2. Assignment 2
3. Assignment 3 (Buddy Tasks)
4. Exit
```

Assignment 03 menu:

```text
--- Assignment 3: Buddy Tasks ---
1. Gradient Descent (GD)
2. Maxflow-Mincut
0. Back to Main Menu
```

Each algorithm supports:

```text
1. Run a single test case
2. Run all test files in batch
0. Cancel / Go back
```

---

# Compilation

From the root project directory:

```bash
make compile
```

This compiles the common wrapper.

The wrapper compiles the selected Assignment 03 algorithm when it is selected from the menu.

---

# Run

```bash
make run
```

or:

```bash
make
```

---

# Clean

```bash
make clean
```

Generated executables and Assignment 03 output files are removed by the clean target.

---

# Output Files

All Assignment 03 output files are stored inside:

```text
Assignment_03/outputs/
```

This keeps the output organization consistent with Assignment 01 and Assignment 02.

---

# References

* **CS509 Assignment 03 Specification**
* **Stanford CS231n — Optimization / Gradient Descent**
* **MIT OpenCourseWare 6.046J — Max Flow and Min Cut**
* **C++17 Standard Library — `std::chrono`**

---

# Conclusion

The Assignment 03 Buddy Task portion implements both required algorithms:

| Buddy Task | Implementation |
|---|---|
| **Gradient Descent** | Generic polynomial representation and iterative update |
| **Maxflow-Mincut** | Dinic-style maximum flow with residual-graph minimum-cut extraction |

All required Gradient Descent tests converged successfully, and all required Maxflow-Mincut tests produced equal maximum-flow and minimum-cut values.

---

## Authors

| Name | Entry Number |
|---|---|
| **Prashant Kumar** | **2026CSM1028** |
| **Vikram Gurjar** | **2026CSM1039** |

**Course:** CS509 Software Laboratory  
**Program:** M.Tech CSE  
**Assignment:** Assignment 03  
**Assignment Type:** Buddy
