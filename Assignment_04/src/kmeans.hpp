#ifndef KMEANS_HPP
#define KMEANS_HPP
#include <string>
struct KMeansResult { int N,D,K; double wcss,execution_time_ms; bool converged; };
KMeansResult run_kmeans(const std::string& filepath,const std::string& output_filepath);
#endif
