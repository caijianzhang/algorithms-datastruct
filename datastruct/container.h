/*
 * Copyright (c) 2017
 * 
 * Permission to use, copy, modify, distribute and sell this software
 * for any purpose is hereby granted without fee.
 *
 * Ronnie Chang
 *
 */

#ifndef _CONTAINER_H_
#define _CONTAINER_H_

#include <string>
#include <stdio.h>
#include "empty.h"
#include "iterator.h"

using namespace std;

class Container {
public:
	Container() {
	}

	virtual ~Container() {
		destory();
	}

public:
	virtual const string getClassName() = 0;

	virtual void destory() {}

	virtual bool empty() = 0;
	
	/*
	 * get the size of the objects
	 */
	virtual int getSize() {
		return size;
	}

protected:
	void notSupport(string operatorName) {
		printf("%s not support operator \"%s\"\n", getClassName().c_str(), operatorName.c_str());
	}

	// size 
	int size;
};

#endif // _CONTAINER_H_
