#include "w_edge.hpp"
#include "edge.hpp"
#include "vertex.hpp"
#include <utility> // std::pair

template <class T>
w_edge::w_edge(vertex& v1, vertex& v2, T& weight) {
    this->v1 = v1;
    this->v2 = v2;
    this->weight = weight;
}

template<class T>
w_edge::w_edge(edge& e, T& weight) {
    std::pair<vertex&, vertex&> vertices = e.get_vertices();
    this->v1 = vertices->first();
    this->v2 = vertices->second();
    this->weight = weight;
}

template<class T>
T& w_edge::get_weight() {
    return this->weight;
}

template<class T>
void set_weight(T& weight) {
    this->weight = weight;
}
