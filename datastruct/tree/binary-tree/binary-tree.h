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

/**
 * This is a complete binary tree, when add a node to the tree, it will be appended at the lastest.
 */ 
template <class T>
class BinaryTree : public Container {
public: 
	BinaryTree() {
		root = 0;
		height = 0;
	}

	~BinaryTree() {

	}

public: 
	virtual const string getClassName() {
		return string("BinaryTree");
	}

	virtual void destory() {
		destory(root);
	}

	virtual bool empty() {
		return root == 0;
	}

	virtual void adjust() {
		// do nothing
	}

	/**
	 * we put leaf nodes into a queue, when building a complete tree, we fetch the first node of the queue, 
	 * and append the newest node to the node, if the node has both left and right children, we remove from 
	 * it from the queue.
	 * imaging a tree like this:
	 *               1(root)
	 *              / 
	 *             2   
	 * now the queue is 1, 2.
	 * when we add a node name 3, we fetch the first node in queue, is node 1, and append the node 3 to node 1's right child,
	 * then put the node 3 into the queue, and remove node 1. now the tree like this:
	 *               1(root)
	 *              /  \ 
	 *             2    3
	 * and the queue is 2, 3.
	 * 
	 */ 
	void add(T data) {
		Tree::Node<T>* node = new Tree::Node<T>(data);
		size++;

		if (root == 0) {
			root = node;
			leafs.push_back(root);
			height = 1;
			return;
		}

		// get the first node
		Tree::Node<T>* lasted = leafs[0];
		if (!lasted->left) {
			lasted->left = node;
		} else {
			lasted->right = node;
			// if the fisrt node has both left and right children, we remove it.
			leafs.pop();
		}

		// put the newest node into the last
		leafs.push_back(node);
		
		// adjust the tree, in this case, we do nothing.
		adjust();

		// caclute the height
		cacluteHeight();
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
	void cacluteHeight() {
		while ((1 << height) < size) {
			height ++;
		}
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
			destory(node->right);
			delete node;
		}
	}

protected:
	// the root of the tree
	Tree::Node<T>* root;
	// the height of the tree
	int height;
	// store the leaf node
	Queue< Tree::Node<T>* > leafs;
};

#endif // _BINARY_TREE_BINARY_TREE_H_