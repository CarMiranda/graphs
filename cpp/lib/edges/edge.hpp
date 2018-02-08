#ifndef EDGE_HPP
#define EDGE_HPP

#include "vertex.hpp"

class edge {

    public:
    edge(vertex& v1, vertex& v2);
    ~edge();

    pair<vertex&, vertex&> get_vertices();

    protected:
        vertex& v1, v2;

};

#endif
