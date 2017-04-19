/*
 * Copyright (c) 2017
 * 
 * Permission to use, copy, modify, distribute and sell this software
 * for any purpose is hereby granted without fee.
 *
 * Ronnie Chang
 *
 */

#ifndef _GRAPH_EDGE_H_
#define _GRAPH_EDGE_H_

#include "vertex.h"

class BaseEdge {
public:
    const static int INFINITI = 10000000;
};

template <class Key, class Value>
class Edge : public BaseEdge {
public:
    // source verte
    Vertex<Key, Value> u;
    // target vertex
    Vertex<Key, Value> v;
    // weight
    int w;
	

    Edge(const Vertex<Key, Value>& u, const Vertex<Key, Value>& v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }

	bool operator==(const Edge<Key, Value>& edge) const {
		return this->u == edge.u &&
			   this->v == edge.v &&
			   this->w == edge.w;
	}

	bool operator<(const Edge<Key, Value>& edge) const {
			return this->w < edge.w;
	}
};

#endif 
