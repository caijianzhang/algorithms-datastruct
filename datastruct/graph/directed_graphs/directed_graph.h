/*
 * Copyright (c) 2017
 * 
 * Permission to use, copy, modify, distribute and sell this software
 * for any purpose is hereby granted without fee.
 *
 * Ronnie Chang
 *
 */

#ifndef _GRAPH_DIRECTED_GRAPH_H_
#define _GRAPH_DIRECTED_GRAPH_H_ 

#include "../graph.h"

template <class Key, class Value>
class DirectedGraph : public Graph<Key, Value> {
public:
	typedef typename Graph<Key, Value>::type_vertex type_vertex;
	typedef typename Graph<Key, Value>::type_edge type_edge;
	typedef typename Graph<Key, Value>::type_node type_node;
	typedef AdjacencyList<type_vertex, type_node> type_list;

public:
	DirectedGraph() {}
	~DirectedGraph() {}

public:
	

};

#endif // _GRAPH_DIRECTED_GRAPH_H_
