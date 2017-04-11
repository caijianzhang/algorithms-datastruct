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
	}

public:
	virtual const string getClassName() = 0;
	
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
