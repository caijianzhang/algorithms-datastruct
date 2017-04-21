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

template <class T, class Extend = void>
struct PriorityComparer {
	// if t1's priority is higher than t2, return true, otherwise return false
	bool operator()(T t1, T t2) {
		return t1 > t2;
	}
};

template <class T, class Comparer = PriorityComparer<T> >
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
		// find the highest priority one
		typename Queue<T>::Iterator priority = this->begin();
		typename Queue<T>::Iterator it = this->begin();
		for (; it != this->end(); ++it) {
			if (!Comparer()(*priority, *it)) {
				priority = it;
			}
		}

		if (priority != this->begin()) {
			// swap the highest priority one whith the head one
			T temp = *priority;
			priority = *(this->begin());
			this->begin() = temp;
		}

		return Queue<T>::pop();
	}
};


#endif
