/*
 * Copyright (c) 2017
 * 
 * Permission to use, copy, modify, distribute and sell this software
 * for any purpose is hereby granted without fee.
 *
 * Ronnie Chang
 *
 */

#ifndef _STACK_H_
#define _STACK_H_

#include "../queue.h"

template <class T, int Size = 32>
class Stack : public Queue<T, Size> {
public:
	virtual T pop() {
		if (this->size == 0) {
			return Empty<T>()();
		}

		this->size --;
		this->arrivalSize --;
		return *(this->queue + this->size);		
	}

	T get() {
		if (this->size == 0) {
			return Empty<T>()();
		}

		return *(this->queue + this->size - 1);
	}
};

#endif 
