#include "Tree.hpp"

template <class T>
Tree<T>::Tree() {
    this.root = new Node<T>();
}

template <class T>
Tree<T>::Tree(Node<T> root) {
    this.root = root;
}

template <class T>
Tree<T>::Tree(T& root_value) {
    this.root = new Node<T>(root_value);
}

template <class T>
Tree<T>::Tree(Node<T>[] forest) {
    this.root = new Node<T>(forest); 
}

template <class T>
~Tree<T>::Tree() {
    delete this.root;
}

template <class T>
Node<T>[] Tree<T>::
