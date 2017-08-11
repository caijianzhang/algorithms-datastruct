/*
 * Copyright (c) 2017
 * 
 * Permission to use, copy, modify, distribute and sell this software
 * for any purpose is hereby granted without fee.
 *
 * Ronnie Chang
 *
 */

#ifndef _BINARY_TREE_NODE_H_
#define _BINARY_TREE_NODE_H_

typedef enum {
	Type_Node = 0,
	Type_Leaf = 1
} NodeType;

template <class T>
class Node {
public:
	Node(T data) {
		this->data = data;
		left = 0;
		right = 0;
		type = Type_Node;
	}

	Node* left;
	Node* right;
	NodeType type;
	T data;
};

#endif // _BINARY_TREE_NODE_H_
