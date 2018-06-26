/*
 * Copyright (c) 2017
 * 
 * Permission to use, copy, modify, distribute and sell this software
 * for any purpose is hereby granted without fee.
 *
 * Ronnie Chang
 *
 */

#ifndef _BINARY_TREE_HAFFMAN_H_
#define _BINARY_TREE_HAFFMAN_H_

#include <iostream>
#include "../../../queue/priority_queue/priority_queue.h"
#include "../../../queue/stack/stack.h"
#include "../node.h"

using namespace std;
using namespace Tree;

template <class T>
class Haffman {
public:
	Haffman() {
		head = 0;
	}

	~Haffman() {
		if (head) {
			free(head);
			head = 0;
		}
	}

protected:
	void free(Node<T>* node) {
		if (node->left) 
			free(node->left);

		if (node->right) 
			free(node->right);

		delete node;
	}

public:
	void addNode(T node) {
		queue.push_back(new Node<T>(node));
	}

	void build() {
		while (queue.getSize() > 0) {
			Node<T>* n1 = queue.pop();
			Node<T>* n2 = queue.pop();
			if (n2 == 0) {
				head = n1;
				break;
			}

			Node<T>* node = new Node<T>(n1->data + n2->data);
			node->type = Type_Node;
			node->left = n1;
			node->right = n2;
			queue.push_back(node);
		}
	}

	void print() {
		Stack<int> path;
		print(head, path);
	}

private:
	void print(Node<T>* node, Stack<int>& path) {
		if (node->left) {
			path.push_back(0);
			print(node->left, path);
			path.pop();
		}
		
		if (node->right) {
			path.push_back(1);
			print(node->right, path);
			path.pop();
		} 
		
		if (node->type == Type_Leaf) {
			cout << node->data << " : ";
			for (Queue<int>::Iterator it = path.begin(); it != path.end(); it++) {
				cout << *it;
			}

			cout << endl;
		}
	}
private:
	Node<T>* head;
	PriorityQueue< Node<T>* > queue;
};

#endif // _BINARY_TREE_HAFFMAN_H_
