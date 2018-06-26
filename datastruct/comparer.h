/*
 * Copyright (c) 2017
 * 
 * Permission to use, copy, modify, distribute and sell this software
 * for any purpose is hereby granted without fee.
 *
 * Ronnie Chang
 *
 */

#ifndef _COMPARER_H_
#define _COMPARER_H_

#include <string>
#include <stdio.h>

using namespace std;

template <class T>
struct Comparer {
	int operator()(T t1, T t2) {
		if (t1 > t2) {
			return 1;
		} else if (t1 < t2) {
			return -1;
		}

		return 0;
	}
};

#endif // 