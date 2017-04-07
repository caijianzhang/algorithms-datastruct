#ifndef _ITERATOR_H_
#define _ITERATOR_H_

template <class T>
class Iterator {
public:
	Iterator(T* ptr) {
		this->ptr = ptr;
	}

public:
	Iterator<T>& operator++() {
		++ptr;
		return *this;
	}

	Iterator<T> operator++(int) {
		Iterator<T> self = *this;
		++ptr;
		return self;
	}

	Iterator<T>& operator--() {
		--ptr;
		return *this;
	}

	Iterator<T> operator--(int) {
		Iterator<T> self = *this;
		--ptr;
		return self;
	}
	
	const T operator*() {
		return *ptr;
	}
	
	T& operator->() {
		return *ptr;
	}

	void operator=(const T value) {
		*ptr = value;
	}
	
	bool operator==(const Iterator<T>& it) {
		return ptr == it.ptr;
	}

	bool operator!=(const Iterator<T>& it) {
		return !(operator==(it));
	}

private:
	T* ptr;
};

#endif // _ITERATOR_H_
