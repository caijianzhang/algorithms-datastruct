/*
 * Copyright (c) 2017
 * 
 * Permission to use, copy, modify, distribute and sell this software
 * for any purpose is hereby granted without fee.
 *
 * Ronnie Chang
 *
 */

#ifndef _vertexs_shortest_DIJKSTRA_H_
#define _vertexs_shortest_DIJKSTRA_H_

#include <vector>
#include "../../../datastruct/graph/directed_graphs/directed_graph.h"
#include "../../../datastruct/queue/priority_queue/priority_queue.h"

template <class Key, class Value>
struct Node {
	Vertex<Key, Value> vertex;
	int shortest;
};	

// specialization PriorityComparer for Node 
template <class Key, class Value>
struct PriorityComparer<Node<Key, Value> > {
	bool operator()(Node<Key, Value> n1, Node<Key, Value> n2) {
		return n1.shortest < n2.shortest;
	}
};

template <class Key, class Value>
class Dijkstra {
public:
	typedef Vertex<Key, Value> type_vertex;
	typedef Edge<Key, Value> type_edge;
	typedef Node<Key, Value> Node;

public:
	Dijkstra() {}
	~Dijkstra() {}

public:
	bool calculate(DirectedGraph<Key, Value> graph, type_vertex source, type_vertex target) {
		this->source = source;
		this->target = target;
		vertexs.clear();	
		path.clear();
		Node node;
		node.vertex = source;
		node.shortest = 0;
		vertexs.push_back(node);

		while (vertexs.getSize() != 0) {
			relex(graph, target);
		}
		
		if (path.find(target) != path.end())
			return true;
		return false;
	}

	int getShortest() {
		typename map<type_vertex, int>::iterator it = shortest.find(target);
		if (it != shortest.end()) {
			return it->second;
		}

		return BaseEdge::INFINITI;
	}

	vector<type_vertex> getShortestPath() {
		vector<type_vertex> shortest;
		typename map<type_vertex, type_vertex>::iterator it = path.find(target);
		while (it != path.end()) {
			shortest.insert(shortest.begin(), it->second);
			it = path.find(it->second);
		}

		shortest.push_back(target);
		return shortest;
	}

protected:
	void relex(DirectedGraph<Key, Value> graph, type_vertex target) {
		// get the shortest one
		Node node = vertexs.pop();
		typename Graph<Key, Value>::value_type value = graph[node.vertex];
		typename Graph<Key, Value>::value_type::iterator it = value.begin();
		if (it == value.end()) {
			// if this vertex's outdegree is 0, we save the shortest value in 'shortest'
			shortest.erase(node.vertex);
			shortest.insert(pair<type_vertex, int>(node.vertex, node.shortest));
			return;
		}

		for (; it != value.end(); ++it) {
			type_vertex v = it->first;
			type_edge e = it->second;
			int n = getShortest(v);
			if (node.shortest + e.w < n) {
				n = node.shortest + e.w;
				path.erase(v);
				path.insert(pair<type_vertex, type_vertex>(v, node.vertex));
				shortest.erase(v);
				shortest.insert(pair<type_vertex, int>(v, n));
			} else {
				continue;
			}

			printf("key: %s's vertexs is %d\n", v.getKey().c_str(), n);
			Node x;
			x.vertex = v;
			x.shortest = n;
			setVertexs(v, x);
		}

		return;
	}

	void setVertexs(type_vertex v, Node n) {
		typename PriorityQueue<Node>::Iterator it = vertexs.begin();
		for (; it != vertexs.end(); ++it) {
			if ((*it).vertex == v) {
				it = n;
				return;
			}
		}

		vertexs.push_back(n);
	}

	int getShortest(type_vertex v) {
		int result = BaseEdge::INFINITI;
		typename map<type_vertex, int>::iterator it = shortest.find(v);
		if (it != shortest.end())
			result = it->second;

		return result;
	}

protected:
	PriorityQueue<Node, PriorityComparer<Node> > vertexs;
	map<type_vertex, int> shortest;
	map<type_vertex, type_vertex> path;
	type_vertex source;
	type_vertex target;
};

#endif // _vertexs_shortest_DIJKSTRA_H_
