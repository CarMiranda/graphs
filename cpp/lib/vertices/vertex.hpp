#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <set>
#include <string>
#include <utility>

class vertex {
    public:
        vertex(const graph&, const std::string label);
        ~vertex();
        std::string get_label() const;
        void set_label(const std::string label);
        void add_edge(const vertex& to)
        void add_edge(const vertex& to, const double weight);
        double get_weight(const vertex& to) const;
        std::set<vertex&> get_adjacents() const;
        std::set<vertex&> get_successors() const;
        std::set<vertex&> get_predecessors() const;
        int get_degree() const;
        void mark();
        bool is_marked() const;
        bool operator==(const vertex& v) const;
    private:
        std::set<vertex&> adjacents;
        std::set<std::pair<double,vertex&> predecessors, successors;
        std::string label;
        graph& gr;
        bool loopback, marked;
        void add_predecessor();
};

#endif
