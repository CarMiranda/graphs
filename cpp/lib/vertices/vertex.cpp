#include "vertex.hpp"

vertex::vertex(const graph& g, const std::string l) : label(l) {
    gr = &g;
}

~vertex::vertex() {}

std::string vertex::get_label() const {
    return label;
}

void vertex::set_label(const std::string label) {
    this->label = label;
}

void vertex::add_edge(const double weight, const vertex& to) {
    edges.insert(std::pair<double,vertex&>(weight, to));
    if (to == this) {
        loopback = true;
    }
}

std::set<vertex&> vertex::get_adjacents() const {
    return edges;
}

std::set<vertex&> vertex::get_successors() const {
    for (std::set<pair<double, vertex&> >::iterator it = edges.begin(); it != edges.end(); ++it) {
        
    }
}

std::set<vertex&> vertex::get_predecessors() const {
}

int vertex::get_degree() const {
    return edges.size() + (loopback ? 1 : 0);
}

void vertex::mark() {
    marked = true;
}

bool vertex::is_marked() const {
    return marked;
}

bool vertex::operator==(const vertex& v) const {
    return v.get_label() == label;
}
