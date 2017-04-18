/*
 * Copyright (c) 2017
 * 
 * Permission to use, copy, modify, distribute and sell this software
 * for any purpose is hereby granted without fee.
 *
 * Ronnie Chang
 *
 */

#ifndef _ITERATOR_H_
#define _ITERATOR_H_

/*
 * traits of Iterator
 */
template <class T>
struct Iterator_Traits {
	typedef T value_type;
};

/*
 * specialization for pointer
 */
template <class T>
struct Iterator_Traits<T*> {
	typedef T value_type;
};

/*
 * specialization for const
 */
template <class T>
struct Iterator_Traits<const T> {
	typedef T value_type;
};

/*
 * specialization for const pointer
 */
template <class T>
struct Iterator_Traits<const T*> {
	typedef T value_type;
};

template <class T>
class Iterator {
public:
	typedef typename Iterator_Traits<T>::value_type value_type;

public:
	Iterator(T iterator) {
		this->iterator = iterator;
	}

protected:
	Iterator() {

	}

public:
	Iterator<T>& operator++() {
		++iterator;
		return *this;
	}

	Iterator<T> operator++(int) {
		Iterator<T> self = *this;
		++iterator;
		return self;
	}

	Iterator<T>& operator--() {
		--iterator;
		return *this;
	}

	Iterator<T> operator--(int) {
		Iterator<T> self = *this;
		--iterator;
		return self;
	}
	
	const value_type operator*() {
		return iterator;
	}
	
	value_type& operator->() {
		return iterator;
	}

	void operator=(const value_type value) {
		*iterator = value;
	}
	
	bool operator==(const Iterator<T>& it) {
		return iterator == it.iterator;
	}

	bool operator!=(const Iterator<T>& it) {
		return !operator==(it);
	}
private:
	T iterator;
};

#endif // _ITERATOR_H_
