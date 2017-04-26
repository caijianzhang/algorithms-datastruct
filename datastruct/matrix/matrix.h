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
		memset(matrix, 0, sizeof(T) * row * column);
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
		if (r >= row) {
			perror("out of bounds\n");
			return 0;
		}

		return &matrix[r * column];
	}

	// set the every element to value]
	void setAll(T value) {
		for (int i = 0; i < row * column; i++) {
			matrix[i] = value;
		}
	}

	// clear the matrix 
	void clear() {
		memset(matrix, 0, sizeof(T) * row * column);
	}

	Matrix<T>& operator=(const Matrix<T>& m) {
		if (this->row != m.row || this->column != m.column) {
			perror("cann't copy");
			return *this;
		}

		for (int i = 0; i < row * column; i ++) {
			this->matrix[i] = m.matrix[i];
		}
		return *this;
	}

protected:
	int row;
	int column;
	T* matrix;
};

#endif // _MATRIX_H_
