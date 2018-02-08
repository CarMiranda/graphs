#ifndef BINTREE_HPP
#define BINTREE_HPP

#include "Node.hpp"

template <class T>
class BinarySearchTree {
    public:
        BinarySearchTree();
	    ~BinarySearchTree();

	    void insert(Node<T> node);
	    Node<T> search(T& key);
	    void destroy_tree();
        Node<T> getRoot();
    private:
	    void destroy_tree(Node<T> leaf);
	    void insert(T& key, Node<T> leaf);
	    Node<T> search(T key, Node<T> *leaf);

	    Node<T> root;
};

#endif 
