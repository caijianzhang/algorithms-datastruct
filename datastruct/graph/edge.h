#ifndef _GRAPH_EDGE_H_
#define _GRAPH_EDGE_H_

#include "vertex.h"

template <class Key, class Value>
class Edge {
public:
    const static int INFINITI = 10000000;

public:
    // source verte
    Vertex<Key, Value> u;
    // target vertex
    Vertex<Key, Value> v;
    // weight
    int w;

    Edge(Vertex<Key, Value> u, Vertex<Key, Value> v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

#endif 
