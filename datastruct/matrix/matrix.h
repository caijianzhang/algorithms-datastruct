/*
 * Copyright (c) 2017
 * 
 * Permission to use, copy, modify, distribute and sell this software
 * for any purpose is hereby granted without fee.
 *
 * Ronnie Chang
 *
 */

#ifndef _MATRIX_H_
#define _MATRIX_H_

#include "../container.h"
#include "../iterator.h"

template <class T>
class Matrix : public Container {
public:
	Matrix(int row, int column) {
		this->row = row;
		this->column = column;
		this->size = row * column;
		matrix = new T[row * column];
	}

	~Matrix() {
		if (matrix != 0) {
			delete []matrix;
			matrix = 0;
		}
	}

public:
	const string getClassName() {
		return "Matrix";
	}

	// return const pointer because the address of the metrix cann't be modified
	// like this Metrix[x] = x will be obtain an error
	T* const operator[](int r) {
		return &matrix[r * column];
	}

protected:
	int row;
	int column;
	T* matrix;
};

#endif // _MATRIX_H_
