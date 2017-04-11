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

using namespace std;

template <class Key, class Value>
class Vertex {
public:
    Vertex(Key key, Value value) {
        this->key = key;
        this->value = value;
    }

    Vertex(const Vertex<T>& v) {
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

    Key getKey() {
        return key;
    }

    bool equal(Vertex v) const {
        return this->key == v.key;
    }

private:
    Key key;
    Value value;
};

// std::map use operator '<' for sorting
template <class Key, class Value>
bool operator < (const Vertex<Key, Value> u, const Vertex<Key, Value> v) {
    return u.getKey() < v.getKey();
}

#endif
