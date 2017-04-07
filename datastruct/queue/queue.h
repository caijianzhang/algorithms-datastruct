#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include "../empty.h"
#include "../adt.h"

template <class T, int Size = 32>
class Queue : public Adt<T> {
	const static int ChunkSize = Size;

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
		if (buffer != 0) {
			delete buffer;
			buffer = 0;
		}
	}

public:
    virtual const string getClassName() {
		return string("Queue");
	}

	virtual Iterator<T> begin() {
		return Iterator<T>(queue);	
	}

	virtual Iterator<T> end() {
		return Iterator<T>(queue + this->size);
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
			printf("out of bounds\n");
			return Empty<T>()();
		}

		return *(queue + index);
	}

protected:
	int bufferSize;
	int arrivalSize;
	T* queue;
	T* buffer;
};

#endif
