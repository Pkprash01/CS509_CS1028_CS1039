#ifndef CONNECTED_COMPONENTS_HPP
#define CONNECTED_COMPONENTS_HPP

#include "../../buddy_csr.hpp"

struct ComponentResult {
    int num_components;
    int* component_ids; // Array of size V containing component ID per vertex
    double execution_time_ms;
};

ComponentResult find_connected_components(const CSRGraph& graph);
void free_component_result(ComponentResult& result);

#endif