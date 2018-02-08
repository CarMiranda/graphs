#include <stdlib.h>
#include "BinaryTree.hpp"

template <class T>
BinarySearchTree<T>::BinarySearchTree() {
	root = NULL;
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree() {
    destroy_leaf(this.root);
}

template <class T>
Node<T> BinarySearchTree<T>::getRoot() {
    return this.root;
}

template <class T>
void BinarySearchTree<T>::destroy_tree(Node<T>& leaf) {
	if (leaf != NULL) {
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

template <class T>
void BinarySearchTree<T>::insert(T& key, Node<T> leaf) {
	if (*key < leaf.getValue()) {
		if (leaf.getLeft() != nullptr) {
			insert(key, leaf.getLeft());
		} else {
			leaf.setLeft(new Node<T>(key));
            leaf.getLeft()->setLeft(nullptr);
            leaf.getLeft()->setRight(nullptr);
		}
	} else if (*key >= leaf.getValue()) {
		if (leaf.getRight() != nullptr) {
			insert(key, leaf.getRight());
		} else {
			leaf.setRight(new Node<T>(key));
		}
	}
}

template <class T>
Node<T> BinarySearchTree<T>::search(T& key) {
	if (*key == this.root.getValue()) {
		return this;
	} else if (this.root.getLeft() != nullptr && *key < this.root.getValue()) {
		return search(key, leaf.getLeft());
	} else if (this.root.getRight() != nullptr && *key > this.root.getValue()) {
		return search(key, leaf.getRight());
	} else {
        return nullptr;
    }
}

template <class T>
void BinaryTree<T>::insert(T key) {
	if (root != NULL) {
		insert(key, root);
	} else {
		root = new Node<T>;
		root->key_value = key;
		root->left = NULL;
		root->right = NULL;
	}
}

template <class T>
Node<T> *BinaryTree<T>::search(T key) {
	return search(key, root);
}

template <class T>
void BinaryTree<T>::destroy_tree() {
	destroy_tree(root);
}
