#include "o_edge.hpp"
#include "vertex.hpp"

vertex& o_edge::get_starting_point() {
    return this->v1;
}

vertex& o_edge::get_ending_point() {
    return this->v2;
}

void o_edge::reverse() {
    vertex& vtemp = this->v1;
    this->v1 = this->v2;
    this->v2 = vtemp;
}
