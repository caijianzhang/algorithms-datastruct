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
#include "../node.h"

using namespace std;

template <class T>
class Haffman {
public:
	Haffman() {
		head = 0;
	}

	~Haffman() {
		if (head) {
			free(head);
		}

		head = 0;
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
	void build(PriorityQueue<T> queue) {
		while (queue.getSize() > 0) {
			T t = queue.pop();

			if (head == 0) {
				head = new Node<T>(t);
				continue;
			}

			Node<T>* left = new Node<T>(t);
			left->type = Type_Leaf;

			Node<T>* node = new Node<T>(left->data + head->data);
			node->left = left;
			node->right = head;
			head = node;
		}
	}

	void print() {
		cout << "head ";
		print(head);
	}

	void print(Node<T>* node) {
		if (node) {
			cout << node->data << endl;
			cout << endl;
		}

		if (node->left) {
			cout << "left ";
			print(node->left);
			cout << endl;
		}

		if (node->right) {
			cout << "right ";
			print(node->right);
			cout << endl;
		}
	}

private:
	Node<T>* head;
};

#endif // _BINARY_TREE_HAFFMAN_H_
