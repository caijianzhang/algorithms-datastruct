#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_

#include "../queue.h"

template <class T>
class PriorityQueue : public Queue<T> {
public:
	PriorityQueue() {

	}

	~PriorityQueue() {

	}

public:
	virtual T pop() {
		// find the most priority one
		Iterator<T> priority = this->begin();
		Iterator<T> it = this->begin();
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
