#ifndef _ADT_H_
#define _ADT_H_

#include <string>
#include <stdio.h>
#include "empty.h"
#include "iterator.h"

using namespace std;

template <class ValueType>
class Adt {
public:
	Adt() {
	}

	virtual ~Adt() {
	}

public:
	virtual const string getClassName() = 0;
	virtual Iterator<ValueType> begin() = 0;
	virtual Iterator<ValueType> end() = 0;
	
	/*
	 * put value at the head of the datastruct
	 */
	 virtual void push_head(const ValueType value) {
		notSupport("push_head(const ValueType value)");
	 }
	
	/*
	 * put value at the end of the datastruct
	 */
	virtual void push_back(const ValueType value) {
		notSupport("push_back(const ValueType value)");
	}

	/*
	 * put the value at the position what the iterator pointed 
	 */ 
	virtual void put(const ValueType value, Iterator<ValueType> it) { 
		notSupport("put(const ValueType value, Iterator<ValueType> it)");		
	}

	/*
	 * get value by []
	 */
	virtual ValueType operator[](int index) {
		notSupport("[ index ]");
		return Empty<ValueType>()();
	}

	int getSize() {
		return size;
	}

protected:
	void notSupport(string operatorName) {
		printf("%s not support operator \"%s\"\n", getClassName().c_str(), operatorName.c_str());
	}

	// size 
	int size;
};

#endif // _ADT_H_
