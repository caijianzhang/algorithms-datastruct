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

#ifndef _BALANCE_BINARY_TREE_BINARY_TREE_H_
#define _BALANCE_BINARY_TREE_BINARY_TREE_H_

#include <iostream>
#include "binary-tree.h"
#include "node.h"

using namespace std;

/**
 * This is a complete binary tree, when add a node to the tree, it will be appended at the lastest.
 */ 
template <class T>
class BalanceBinaryTree : public BinaryTree<T> {
public: 
	BalanceBinaryTree() {
		
	}

	virtual ~BalanceBinaryTree() {
		leafs.clear();
	}

public: 
	virtual const string getClassName() {
		return string("BalanceBinaryTree");
	}

	/**
	 * we put leaf nodes into a queue, when building a complete tree, we fetch the first node of the queue, 
	 * and then append the newest node to the node, if the node has both left and right children, we remove it
	 * from the queue.
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
	virtual void addNode(Tree::Node<T>* node) {
		// get the first node
		Tree::Node<T>* lasted = leafs[0];
		if (lasted) {
			if (!lasted->left) {
				lasted->left = node;
			} else {
				lasted->right = node;
				// if the fisrt node has both left and right children, we remove it.
				leafs.pop();
			}
		}

		// put the newest node into the last
		leafs.push_back(node);
	}

protected:
	// store the leaf node
	Queue< Tree::Node<T>* > leafs;
};

#endif // _BALANCE_BINARY_TREE_BINARY_TREE_H_