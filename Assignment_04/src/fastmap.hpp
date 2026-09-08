#ifndef FASTMAP_HPP
#define FASTMAP_HPP
#include <string>
struct FastMapResult{int N,K;double execution_time_ms;};
FastMapResult run_fastmap(const std::string& filepath,const std::string& output_filepath);
#endif
