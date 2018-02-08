#include "Node.hpp"

template <class T>
Node<T>::Node(T key_value) {
    this.key_value = key_value;
    this.left = nullptr;
    this.right = nullptr;
}

template <class T>
Node<T>::Node(T& key_value) {
    this.key_value = *key_value;
    this.left = nullptr;
    this.right = nullptr;
}

template <class T>
Node<T>::Node(T& key_value, Node<T>& left, Node<T>& right) {
    this.key_value = *key_value;
    this.left = left;
    this.right = right;
}

template <class T>
T Node<T>::getValue() {
    return this.key_value;
}

template <class T>
void Node<T>::setValue(T key_value) {
    this.key_value = key_value;
}

template <class T>
void Node<T>::setValue(T& key_value) {
    this.key_value = *key_value;
}

template <class T>
Node<T>& Node<T>::getLeft() {
    return this.left;
}

template <class T>
Node<T>& Node<T>::getRight() {
    return this.right;
}

template <class T>
void Node<T>::setLeft(Node<T>& node) {
    this.left = node;
}

template <class T>
void Node<T>::setRight(Node<T>& node) {
    this.right = node;
}
