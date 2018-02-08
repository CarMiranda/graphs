#ifndef TREE_HPP
#define TREE_HPP

#include "Node.hpp"

template <class T>
class Tree {

    public:
        Tree();
        Tree(Node<T> root);
        Tree(T& root_value);
        Tree(Node<T>& forest);
        ~Tree();

        Node<T>& forest();
        Node<T> root();

        Node<T>& dfs(T& key);
        Node<T>& bfs(T& key);
        int height();
        T& get_list_df();
        T& get_list_bf();

    private:
        Node<T> root;
}

#endif
