#ifndef _QUEUE_H_
#define _QUEUE_H_

template <class T>
class Queue {
public:
	Queue();
	Queue(const Queue<T> queue);
	~Queue();

public:
	void add(T data);
	T get();
	

private:

}

#endif
