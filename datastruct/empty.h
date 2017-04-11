/*
 * Copyright (c) 2017
 * 
 * Permission to use, copy, modify, distribute and sell this software
 * for any purpose is hereby granted without fee.
 *
 * Ronnie Chang
 *
 */

#ifndef _EMPTY_H_
#define _EMPTY_H_

template <class T>
struct Empty { 
	T operator()() { return T(); }		
};

/* specialization of pointer */
template <class T> 
struct Empty<T*> {
	T* operator()() { return 0; }
};

/* specialization of int */
template <>
struct Empty <int> {
	int operator()() { return 0; }
};

/* specialization of char */
template <>
struct Empty <char> {
	char operator()() { return 0; }
};

/* specialization of bool */
template <>
struct Empty <bool> {
	bool operator()() { return false; }
};

/* specialization of short */
template <>
struct Empty <short> {
	short operator()() { return 0; }
};

/* specialization of long */
template <>
struct Empty <long> {
	long operator()() { return 0; }
};

/* specialization of float */
template <>
struct Empty <float> {
	float operator()() { return 0.0f; }
};

/* specialization of double */
template <>
struct Empty <double> {
	double operator()() { return 0.0f; }
};

/* specialization of void */
template <>
struct Empty <void> {
	void operator()() {  }
}

#endif // _EMPTY_H_
