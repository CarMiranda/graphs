#ifndef O_EDGE_HPP
#define O_EDGE_HPP

#include "vertex.hpp"
#include "edge.hpp"

class o_edge: public edge {

    public:
        vertex& get_starting_vertex();
        vertex& get_ending_vertex();
        void reverse();

};

#endif
