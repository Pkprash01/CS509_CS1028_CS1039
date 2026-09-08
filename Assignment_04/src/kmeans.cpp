#include "kmeans.hpp"
#include <fstream>
#include <iostream>
#include <cmath>
#include <chrono>

KMeansResult run_kmeans(const std::string& filepath, const std::string& output_filepath) {
    std::ifstream infile(filepath.c_str());
    if (!infile.is_open()) {
        return {0, 0, 0, 0.0, 0.0, false};
    }

    int N, D, K;
    if (!(infile >> N >> D >> K) || N <= 0 || D <= 0 || K <= 0 || K > N) {
        return {0, 0, 0, 0.0, 0.0, false};
    }

    double* points = new double[N * D];
    for (int i = 0; i < N * D; i++) {
        infile >> points[i];
    }

    int max_iter;
    double tolerance;
    std::string label;
    infile >> label >> max_iter;
    infile >> label >> tolerance;
    infile.close();

    double* centroids = new double[K * D];
    int* assign = new int[N];
    int* old_assign = new int[N];

    for (int c = 0; c < K; c++) {
        for (int d = 0; d < D; d++) {
            centroids[c * D + d] = points[c * D + d];
        }
    }

    for (int i = 0; i < N; i++) {
        assign[i] = -1;
    }

    auto start = std::chrono::high_resolution_clock::now();
    int iter = 0;
    bool converged = false;

    while (iter < max_iter) {
        for (int i = 0; i < N; i++) {
            old_assign[i] = assign[i];
        }

        for (int i = 0; i < N; i++) {
            double best = 1e300;
            int best_c = 0;

            for (int c = 0; c < K; c++) {
                double dist = 0;
                for (int d = 0; d < D; d++) {
                    double x = points[i * D + d] - centroids[c * D + d];
                    dist += x * x;
                }
                if (dist < best) {
                    best = dist;
                    best_c = c;
                }
            }

            assign[i] = best_c;
        }

        double* sums = new double[K * D];
        int* counts = new int[K];

        for (int i = 0; i < K * D; i++) {
            sums[i] = 0;
        }
        for (int c = 0; c < K; c++) {
            counts[c] = 0;
        }

        for (int i = 0; i < N; i++) {
            counts[assign[i]]++;
            for (int d = 0; d < D; d++) {
                sums[assign[i] * D + d] += points[i * D + d];
            }
        }

        double max_shift = 0;
        for (int c = 0; c < K; c++) {
            if (counts[c] > 0) {
                double shift = 0;
                for (int d = 0; d < D; d++) {
                    double new_center = sums[c * D + d] / counts[c];
                    double x = new_center - centroids[c * D + d];
                    shift += x * x;
                    centroids[c * D + d] = new_center;
                }
                shift = std::sqrt(shift);
                if (shift > max_shift) {
                    max_shift = shift;
                }
            }
        }

        delete[] sums;
        delete[] counts;

        iter++;

        bool same = true;
        for (int i = 0; i < N; i++) {
            if (assign[i] != old_assign[i]) {
                same = false;
                break;
            }
        }

        if (same || max_shift <= tolerance) {
            converged = true;
            break;
        }
    }

    double wcss = 0;
    for (int i = 0; i < N; i++) {
        for (int d = 0; d < D; d++) {
            double x = points[i * D + d] - centroids[assign[i] * D + d];
            wcss += x * x;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    double ms = std::chrono::duration<double, std::milli>(end - start).count();

    std::ofstream out(output_filepath.c_str());
    if (!out.is_open()) {
        delete[] points;
        delete[] centroids;
        delete[] assign;
        delete[] old_assign;
        return {N, D, K, wcss, ms, converged};
    }

    out << "Algorithm: K-Means Clustering\n";
    out << "K: " << K << "\n";
    out << "Point assignments:\n";
    for (int i = 0; i < N; i++) {
        out << i << " " << assign[i] << "\n";
    }

    out << "Final centroids:\n";
    out.setf(std::ios::fixed);
    out.precision(6);
    for (int c = 0; c < K; c++) {
        out << c << ":";
        for (int d = 0; d < D; d++) {
            out << " " << centroids[c * D + d];
        }
        out << "\n";
    }

    out << "WCSS: " << wcss << "\n";
    out << "Iterations: " << iter << "\n";
    out << "Converged: " << (converged ? "true" : "false") << "\n";
    out << "Execution time: " << ms << " ms\n";
    out.close();

    delete[] points;
    delete[] centroids;
    delete[] assign;
    delete[] old_assign;

    return {N, D, K, wcss, ms, converged};
}