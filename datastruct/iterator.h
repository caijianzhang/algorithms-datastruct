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
template <class T, bool stl>
struct Iterator_Traits {
	typedef T value_type;
};

template <class T>
struct Iterator_Traits<T, true> {
	typedef typename T::value_type value_type;
};

/*
 * specialization for pointer
 */
template <class T>
struct Iterator_Traits<T*, false> {
	typedef T value_type;
};

/*
 * specialization for const
 */
template <class T, bool stl>
struct Iterator_Traits<const T, stl> {
	typedef T value_type;
};

/*
 * specialization for const pointer
 */
template <class T>
struct Iterator_Traits<const T*, false> {
	typedef T value_type;
};

template <class T, bool stl = false>
class Iterator {
public:
	typedef typename Iterator_Traits<T, stl>::value_type value_type;
	typedef Iterator<T, stl> Self;

public:
	Iterator(T iterator) {
		this->iterator = iterator;
	}

protected:
	Iterator() {

	}

public:
	Self& operator++() {
		++iterator;
		return *this;
	}

	Self operator++(int) {
		Self self = *this;
		++iterator;
		return self;
	}

	Self& operator--() {
		--iterator;
		return *this;
	}

	Self operator--(int) {
		Self self = *this;
		--iterator;
		return self;
	}
	
	value_type& operator*() {
		return *iterator;
	}
	
	T& operator->() {
		return iterator;
	}

	void operator=(const value_type value) {
		*iterator = value;
	}
	
	bool operator==(const Self& it) {
		return iterator == it.iterator;
	}

	bool operator!=(const Self& it) {
		return !(*this == it);
	}
private:
	T iterator;
};

#endif // _ITERATOR_H_
