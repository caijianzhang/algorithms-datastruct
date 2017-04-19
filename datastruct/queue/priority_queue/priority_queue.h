/*
 * Copyright (c) 2017
 * 
 * Permission to use, copy, modify, distribute and sell this software
 * for any purpose is hereby granted without fee.
 *
 * Ronnie Chang
 *
 */

#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_

#include "../queue.h"

template <class T>
class PriorityQueue : public Queue<T> {
public:
	typedef typename Queue<T>::Iterator Iterator;

public:
	PriorityQueue() {

	}

	~PriorityQueue() {

	}

public:
	virtual T pop() {
		// find the most priority one
		typename Queue<T>::Iterator priority = this->begin();
		typename Queue<T>::Iterator it = this->begin();
		for (; it != this->end(); ++it) {
			if (*priority < *it) {
				priority = it;
			}
		}

		if (priority != this->begin()) {
			// swap
			T temp = *priority;
			priority = *(this->begin());
			this->begin() = temp;
		}

		return Queue<T>::pop();
	}
};


#endif
