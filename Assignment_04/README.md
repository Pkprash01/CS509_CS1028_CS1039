# CS509 Laboratory — Assignment 04

## Assignment Overview

Assignment 04 contains the tasks:

1. **K-Means Clustering**
2. **FastMap**


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
| **Assignment** | Assignment 04 |
| **Mode** | Buddy |
| **Language** | C++17 |

---

# Directory Structure

```text
Assignment_04/
│
├── README.md
│
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

# 1. K-Means Clustering

K-Means is a clustering algorithm that divides the input data points into `K` clusters.

The implementation:

1. Reads the input points.
2. Uses the first `K` points as initial centroids.
3. Assigns every point to the nearest centroid.
4. Updates the centroid of every cluster.
5. Repeats the process until convergence or the maximum number of iterations is reached.

The implementation also reports the final cluster assignments, centroids, WCSS, number of iterations, convergence status and execution time.

---

## K-Means Input Format

```text
N D K
point coordinates ...
MAX_ITERATIONS value
TOLERANCE value
```

Where:

- `N` = number of points
- `D` = number of dimensions
- `K` = number of clusters
- `MAX_ITERATIONS` = maximum number of iterations
- `TOLERANCE` = convergence tolerance

---

## K-Means Tests

| Test File | Points (N) | Dimensions (D) | Clusters (K) |
|---|---:|---:|---:|
| `km_01.txt` | 100 | 2 | 3 |
| `km_02.txt` | 1,000 | 2 | 5 |
| `km_03.txt` | 10,000 | 5 | 8 |
| `km_04.txt` | 100,000 | 5 | 10 |

---

## K-Means Output

The output contains:

- Cluster assignment for each point
- Final centroid values
- WCSS
- Number of iterations
- Convergence status
- Execution time

Output files are stored in:

```text
Assignment_04/outputs/
```

Example:

```text
km_01_out.txt
km_02_out.txt
km_03_out.txt
km_04_out.txt
```

---

# 2. FastMap

FastMap is a dimensionality-reduction algorithm that maps objects from a distance space into a lower-dimensional space.

For every target dimension, the implementation:

1. Selects a farthest pair of objects.
2. Uses the selected pair as pivots.
3. Calculates the coordinate of every object.
4. Updates the remaining distances.
5. Repeats for the required number of dimensions.

---

## FastMap Input Format

```text
N K
d(0,0) d(0,1) ... d(0,N-1)
d(1,0) d(1,1) ... d(1,N-1)
...
d(N-1,0) ... d(N-1,N-1)
```

Where:

- `N` = number of objects
- `K` = target number of dimensions
- `d(i,j)` = distance between objects `i` and `j`

The input contains an `N × N` distance matrix.

---

## FastMap Tests

| Test File | Objects (N) | Target Dimensions (K) |
|---|---:|---:|
| `fm_01.txt` | 10 | 2 |
| `fm_02.txt` | 100 | 2 |
| `fm_03.txt` | 1,000 | 3 |

These are the FastMap test files currently included in the repository.

---

## FastMap Output

The output contains:

- Pivot pair selected for each dimension
- Coordinates generated for each object
- Execution time

Output files are stored in:

```text
Assignment_04/outputs/
```

Example:

```text
fm_01_out.txt
fm_02_out.txt
fm_03_out.txt
```

---

# Source and Driver Files

| File | Purpose |
|---|---|
| `src/kmeans.cpp` | K-Means implementation |
| `src/kmeans.hpp` | K-Means declarations |
| `src/fastmap.cpp` | FastMap implementation |
| `src/fastmap.hpp` | FastMap declarations |
| `driver/kmeans_driver.cpp` | K-Means driver |
| `driver/fastmap_driver.cpp` | FastMap driver |

---

# Compilation

K-Means can be compiled using:

```bash
g++ -std=c++17 -O2 -Wall -Wextra Assignment_04/src/kmeans.cpp Assignment_04/driver/kmeans_driver.cpp -o Assignment_04/driver/kmeans_exec.exe
```

FastMap can be compiled using:

```bash
g++ -std=c++17 -O2 -Wall -Wextra Assignment_04/src/fastmap.cpp Assignment_04/driver/fastmap_driver.cpp -o Assignment_04/driver/fastmap_exec.exe
```

---

# Running Through Wrapper

Assignment 04 is integrated with the root `wrapper.cpp`.

From the repository root:

```bash
make
```

Select:

```text
4. Assignment 4
```

The Assignment 04 menu is:

```text
--- Assignment 4: Buddy Tasks ---
1. K-Means Clustering
2. FastMap
0. Back to Main Menu
```

The available test files can be executed individually or in batch mode through the wrapper.

---

# Output Directory

Before running Assignment 04, the output directory is created automatically if required:

```text
Assignment_04/outputs/
```

This prevents output-file creation failures when the directory does not already exist.

---

# Timing

Execution time is measured using:

```cpp
std::chrono::high_resolution_clock
```

The timing is used to report the execution time of the algorithm.

---

# Summary

| Task | Main Approach | Main Data Structure |
|---|---|---|
| K-Means Clustering | Nearest-centroid assignment and centroid update | Dynamic arrays |
| FastMap | Farthest-pivot selection and distance reduction | Distance matrix and arrays |

---

# Authors

| Name | Entry Number |
|---|---|
| **Prashant Kumar** | **2026CSM1028** |
| **Vikram Gurjar** | **2026CSM1039** |

**Course:** CS509 Software Laboratory  
**Program:** M.Tech CSE  
**Assignment Type:** Buddy Assignment