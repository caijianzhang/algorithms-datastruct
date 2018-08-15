/*
 * Copyright (c) 2017
 * 
 * Permission to use, copy, modify, distribute and sell this software
 * for any purpose is hereby granted without fee.
 *
 * Ronnie Chang
 *
 */

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include "../empty.h"
#include "../iterator.h"
#include "../container.h"

template <class T, int Size = 32>
class Queue : public Container {
	const static int ChunkSize = Size;

public:
	typedef Iterator<T*> Iterator;

public:
	Queue() {
		this->arrivalSize = this->bufferSize = ChunkSize;
		this->size = 0;
		this->queue = this->buffer = new T[bufferSize];
	}

	Queue(const Queue<T>& queue) {
		this->arrivalSize = this->bufferSize = queue.bufferSize;
		this->size = queue.size;
		this->queue = this->buffer = new T[bufferSize];

		for (int i = 0; i < this->size; ++i) {
			this->queue[i] = queue.queue[i];
		}
	}

	virtual ~Queue() {
		
	}

public:
    virtual const string getClassName() {
		return string("Queue");
	}

	virtual Iterator begin() {
		return Iterator(queue);	
	}

	virtual Iterator end() {
		return Iterator(queue + this->size);
	}

	virtual void push_back(const T value) {
		if (this->size > arrivalSize - 1) {
			if (arrivalSize < bufferSize) {
				// move to head
				for (int i = 0; i < this->size; ++i) {
					buffer[i] = queue[i];
				}
				
				arrivalSize = bufferSize;
				queue = buffer;
			} else {
				// resize
				bufferSize += ChunkSize;
				T* newBuffer = new T[bufferSize];
				memcpy(newBuffer, queue, sizeof(T) * this->size);
				delete buffer;
				queue = buffer = newBuffer;
			}
		}

		*(queue + (this->size++)) = value;
	}

	virtual T pop() {
		if (this->size == 0) {
			return Empty<T>()();
		}

		this->size --;
		arrivalSize --;
		return *(queue++);		
	}

	virtual T operator[](int index) {
		if (index >= this->size) {
			// out of bounds
			return Empty<T>()();
		}

		return *(queue + index);
	}

	virtual void destory() {
		if (buffer) {
			delete []buffer;
			buffer = 0;
		}
	}

	virtual void clear() {
		queue = 0;
		bufferSize = 0;
		arrivalSize = 0;
		size = 0;
	}

	virtual bool empty() {
		return size <= 0;
	}

protected:
	int bufferSize;
	int arrivalSize;
	T* queue;
	T* buffer;
};

#endif
