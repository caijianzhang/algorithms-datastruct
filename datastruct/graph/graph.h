/*
 * Copyright (c) 2017
 * 
 * Permission to use, copy, modify, distribute and sell this software
 * for any purpose is hereby granted without fee.
 *
 * Ronnie Chang
 *
 */

#ifndef _GRAPH_GRAPH_H_
#define _GRAPH_GRAPH_H_

#include "../container.h"
#include "../iterator.h"
#include "../list/adjacency_list.h"
#include "vertex.h"
#include "edge.h"

template <class Key, class Value>
class Graph {
public:
	typedef Vertex<Key, Value> _vertex;
	typedef Edge<Key, Value> _edge;
	typedef typename AdjacencyList<_vertex, _edge>::Iterator Iterator;

public:
	Graph() {}
	~Graph() {}

public:
	void addEdge(_edge edge) {
		if (!table.exist(edge.u, edge)) {
			table.put(edge.u, edge);
        }
	}

	Iterator begin() {
		return table.begin();
	}

	Iterator end() {
		return table.end();
	}

protected:
	AdjacencyList<_vertex, _edge> table;
};

#endif // _GRAPH_GRAPH_H_
