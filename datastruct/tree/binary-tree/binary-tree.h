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

#include "../../container.h"
#include "node.h"

template <class T>
class BinaryTree : public Container {
public: 
	BinaryTree() {
		head = end = 0;
	}

	~BinaryTree() {

	}

public: 
	virtual const string getClassName() {
		return string("BinaryTree");
	}

	virtual void clear() {

	}

	virtual bool empty() {
		return head == 0;
	}

	virtual void adjust() {
		// do nothing
	}

	void add(T data) {
		Tree::Node<T>* node = new Tree::Node<T>(data);
		if (head == 0) {
			head = end = node;
			return;
		}

		if (end->left == 0) {
			end->left = node;
		} else {
			end->right = node;
			end = end->left;
		}
	}

	T pop() {

	}

	T top() {
		if (head) {
			return *head;
		}

		return Empty<T>()();
	}

protected:
	Tree::Node<T>* head;
	Tree::Node<T>* end;
};

#endif // _BINARY_TREE_BINARY_TREE_H_