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
		size = 0;
	}

	virtual ~Container() {
		destory();
	}

public:
	virtual const string getClassName() = 0;

	/**
	 *  the inheritance class should impletement this mothod for release momory.
	 */ 
	virtual void destory() {}

	/** 
	 * if you don't use #size in inheritance class, you should overrite this mothod. 
	 */ 
	virtual bool empty() {
		return size <= 0;
	}
	
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
