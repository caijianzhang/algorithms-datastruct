/*
 * Copyright (c) 2018
 * 
 * Permission to use, copy, modify, distribute and sell this software
 * for any purpose is hereby granted without fee.
 *
 * Ronnie Chang
 * 
 * Created by zhangcaijian on 2018-6-21
 *
 */

#ifndef _BINARY_SEARCH_TREE_BINARY_TREE_H_
#define _BINARY_SEARCH_TREE_BINARY_TREE_H_

#include <iostream>
#include "../../container.h"
#include "../../queue/queue.h"
#include "binary-tree.h"
#include "node.h"

template <class T>
class BinarySearchTree : public BinaryTree<T> {
public: 
	BinarySearchTree() {

	}

	~BinarySearchTree() {

	}

	virtual const string getClassName() {
		return string("BinarySearchTree");
	}

	virtual void addNode(Tree::Node<T>* node) {
		addNode(0, this->root, node);
	}

	virtual void adjust() {
		// do nothing
	}

	T find(T key) {
		Tree::Node<T>* node = find(this->root, key);
		if (node) {
			return node->data;
		}

		return Empty<T>()();
	}

private:
	void addNode(Tree::Node<T>* parent, Tree::Node<T>* tree, Tree::Node<T>* node) {
		if (!tree) {
			if (node->data < parent->data) {
				parent->left = node;
			} else {
				parent->right = node;
			}

			return;
		}

		if (node->data < tree->data) {
			addNode(tree, tree->left, node);
		} else {
			addNode(tree, tree->right, node);
		}
	}

	Tree::Node<T>* find(Tree::Node<T>* node, T key) {
		if (!node) return Empty<Tree::Node<T>*>()();

		if (node->data == key) {
			return node;
		}

		Tree::Node<T>* result = find(node->left, key);
		if (result) return result;

		return find(node->right, key);
	}
};

#endif // _BINARY_SEARCH_TREE_BINARY_TREE_H_

