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

using namespace std;

template <class Key, class Value>
class Graph {
public:
	typedef Vertex<Key, Value> type_vertex;
	typedef Edge<Key, Value> type_edge;
	typedef pair<type_vertex, type_edge> type_node;
	typedef typename AdjacencyList<type_vertex, type_edge>::Iterator Iterator;

public:
	Graph() {}
	~Graph() {}

public:
	void addEdge(type_edge edge) {
		type_node node(edge.v, edge);
		if (!table.exist(edge.u, node)) {
			table.put(edge.u, node);
        }
	}

	int getIndegree(type_vertex v) {
		return table.getIndegree(v);
	}

	int getOutdegree(type_vertex v) {
		return table.getOutdegree(v);
	}

protected:
	AdjacencyList<type_vertex, type_node> table;
};

#endif // _GRAPH_GRAPH_H_
