#include "fastmap.hpp"
#include <fstream>
#include <iostream>
#include <cmath>
#include <chrono>
#include <iomanip>

FastMapResult run_fastmap(const std::string& filepath, const std::string& output_filepath) {
    std::ifstream in(filepath.c_str());
    if (!in.is_open()) {
        return {0, 0, 0.0};
    }

    int N, K;
    if (!(in >> N >> K) || N <= 0 || K <= 0 || K >= N) {
        return {0, 0, 0.0};
    }

    double* dist = new double[N * N];
    for (int i = 0; i < N * N; i++) {
        in >> dist[i];
    }
    in.close();

    double* work = new double[N * N];
    double* coord = new double[N * K];
    for (int i = 0; i < N * N; i++) {
        work[i] = dist[i];
    }
    for (int i = 0; i < N * K; i++) {
        coord[i] = 0;
    }

    int* pivA = new int[K];
    int* pivB = new int[K];

    auto start = std::chrono::high_resolution_clock::now();

    for (int dim = 0; dim < K; dim++) {
        int a = 0, b = 0;
        double best = -1;

        for (int i = 0; i < N; i++) {
            if (work[0 * N + i] > best) {
                best = work[i];
                a = i;
            }
        }

        best = -1;
        for (int i = 0; i < N; i++) {
            if (work[a * N + i] > best) {
                best = work[a * N + i];
                b = i;
            }
        }

        pivA[dim] = a;
        pivB[dim] = b;

        double dab = work[a * N + b];
        if (dab == 0) {
            continue;
        }

        for (int i = 0; i < N; i++) {
            double dai = work[a * N + i];
            double dbi = work[b * N + i];
            coord[i * K + dim] = (dai * dai + dab * dab - dbi * dbi) / (2 * dab);
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                double x = work[i * N + j];
                double c = coord[i * K + dim] - coord[j * K + dim];
                double v = x * x - c * c;
                if (v < 0 && v > -1e-9) {
                    v = 0;
                }
                work[i * N + j] = std::sqrt(v);
            }
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    double ms = std::chrono::duration<double, std::milli>(end - start).count();

    std::ofstream out(output_filepath.c_str());
    if (out.is_open()) {
        out << "Algorithm: FastMap\n";
        out << "Target dimensions: " << K << "\n";
        out << "Pivots per dimension:\n";
        for (int d = 0; d < K; d++) {
            out << "Dim " << d + 1 << ": " << pivA[d] << " " << pivB[d] << "\n";
        }
        out << "Object coordinates:\n";

        for (int i = 0; i < N; i++) {
            out << i << ":";
            for (int d = 0; d < K; d++) {
                double value = coord[i * K + d];
                double rounded = std::round(value);

                if (std::fabs(value - rounded) < 1e-9) {
                    out << " " << static_cast<long long>(rounded);
                } else {
                    out << " " << std::fixed << std::setprecision(6) << value;
                }
            }
            out << "\n";
        }

        out << "Execution time: " << std::fixed << std::setprecision(6) << ms << " ms\n";
        out.close();
    }

    delete[] dist;
    delete[] work;
    delete[] coord;
    delete[] pivA;
    delete[] pivB;

    return {N, K, ms};
}
