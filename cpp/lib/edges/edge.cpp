#include "edge.hpp"
#include "vertex.hpp"

edge::edge(vertex& v1, vertex& v2) {
    this->v1 = v1;
    this->v2 = v2;
}

~edge::edge() {
}

pair<vertex&, vertex&> edge::get_vertices() {
    return pair<vertex&, vertex&>(this->v1, this->v2);
}
