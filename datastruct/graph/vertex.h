/*
 * Copyright (c) 2017
 * 
 * Permission to use, copy, modify, distribute and sell this software
 * for any purpose is hereby granted without fee.
 *
 * Ronnie Chang
 *
 */

#ifndef _GRAPH_VERTEX_H_
#define _GRAPH_VERTEX_H_

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "../empty.h"

using namespace std;

template <class Key, class Value>
class Vertex {
public:
	Vertex() {
		this->key = Empty<Key>()();
		this->value = Empty<Value>()();
	}

    Vertex(Key key, Value value) {
        this->key = key;
        this->value = value;
    }

    Vertex(const Vertex<Key, Value>& v) {
        this->key = v.key;
        this->value = v.value;
    }

    ~Vertex() {

    }

    void setValue(Value value) {
        this->value = value;
    }

    Value getValue() const {
        return value;
    }

    Key getKey() const {
        return key;
    }

	bool operator<(const Vertex<Key, Value> v) const {
		return this->key < v.key;
	}

    bool operator==(const Vertex& v) const {
        return this->key == v.key;
    }

private:
    Key key;
    Value value;
};

#endif
