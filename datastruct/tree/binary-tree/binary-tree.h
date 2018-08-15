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

#ifndef _BINARY_TREE_BINARY_TREE_H_
#define _BINARY_TREE_BINARY_TREE_H_

#include <iostream>
#include "../../container.h"
#include "../../queue/queue.h"
#include "node.h"

using namespace std;
 
template <class T>
class BinaryTree : public Container {
public: 
	BinaryTree() {
		root = 0;
		height = 0;
	}

	virtual ~BinaryTree() {
		destory();
	}

public: 
	virtual const string getClassName() {
		return string("BinaryTree");
	}

	virtual void destory() {
		destory(root);
		root = 0;
	}

	virtual void clear() {
		destory();
		size = 0;
		height = 0;
	}

	virtual bool empty() {
		return root == 0;
	}

	virtual void adjust() {
		// do nothing
	}

	virtual void addNode(Tree::Node<T>* node) {
		
	}

	void add(T data) {
		Tree::Node<T>* node = new Tree::Node<T>(data);
		size++;

		if (root == 0) {
			root = node;
		} else {
			addNode(node);
		}
		// adjust the tree, in this case, we do nothing.
		adjust();
		// caclute the height
		calcuteHeight();
	}

	T pop() {
		notSupport("BinaryTree::pop");
		return Empty<T>()();
	}

	T getRoot() {
		if (root) {
			return *root;
		}

		return Empty<T>()();
	}

	int getHeight() {
		return height;
	}

	void print() {
		if (root) {
			print(root);
		}

		cout << endl;
	}

private: 
	void calcuteHeight() {
		height = calcuteHeight(root);
	}

	int calcuteHeight(Tree::Node<T>* node) {
		if (!node) return 0;

		int left = calcuteHeight(node->left);
		int right = calcuteHeight(node->right);
		return left > right ? (left + 1) : (right + 1);
	}

	void print(Tree::Node<T>* node) {
		if (!node) return;

		// print left children
		print(node->left);
		// print parent
		cout << node->data << " ";
		// print right children
		print(node->right);
	}

	void destory(Tree::Node<T>* node) {
		if (node) {
			destory(node->left);
			node->left = 0;
			destory(node->right);
			node->right = 0;
			delete node;
		}
	}

protected:
	// the root of the tree
	Tree::Node<T>* root;
	// the height of the tree
	int height;
};

#endif // _BINARY_TREE_BINARY_TREE_H_