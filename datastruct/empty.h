#ifndef _EMPTY_H_
#define _EMPTY_H_

template <class T>
struct Empty { 
	T operator()() { return T(); }		
};

/* specialazition of pointer */
template <class T> 
struct Empty<T*> {
	T* operator()() { return 0; }
};

/* specialazition of int */
template <>
struct Empty <int> {
	int operator()() { return 0; }
};

/* specialazition of char */
template <>
struct Empty <char> {
	char operator()() { return 0; }
};

/* specialazition of bool */
template <>
struct Empty <bool> {
	bool operator()() { return false; }
};

/* specialazition of short */
template <>
struct Empty <short> {
	short operator()() { return 0; }
};

/* specialazition of long */
template <>
struct Empty <long> {
	long operator()() { return 0; }
};

/* specialazition of float */
template <>
struct Empty <float> {
	float operator()() { return 0.0f; }
};

/* specialazition of double */
template <>
struct Empty <double> {
	double operator()() { return 0.0f; }
};

#endif // _EMPTY_H_
