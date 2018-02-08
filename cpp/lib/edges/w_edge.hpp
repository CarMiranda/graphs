#ifndef W_EDGE_HPP
#define W_EDGE_HPP

#include "edge.hpp"
#include "vertex.hpp"

template <class T>
class w_edge: public edge {

    public:
        w_edge(vertex& v1, vertex& v2, T& weight);
        w_edge(edge& e, T& weight);
        T& get_weight();
        void set_weight(T& weight);
    protected:
        T& weight;
};

#endif
