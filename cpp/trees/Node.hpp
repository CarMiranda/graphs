#ifndef NODE_HPP
#define NODE_HPP

template <class T>
class Node {
    public:
        Node(T key_value);
        Node(T& key_value);
        Node(T key_value, Node<T>& left, Node<T>& right);
        Node(T& key_value, Node<T>& left, Node<T>& right);

        T getValue();
        void setValue(T key_value);
        void setValue(T& key_value);
        Node<T> getLeft();
        Node<T> getRight();
        void setLeft(Node<T>& node);
        void setRight(Node<T>& node);
    private:
        T key_value;
        Node<T> *left;
        Node<T> *right;
};

#endif
