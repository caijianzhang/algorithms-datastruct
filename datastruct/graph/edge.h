#ifndef _GRAPH_EDGE_H_
#define _GRAPH_EDGE_H_

#include "vertex.h"

template <class T>
class Edge {
public:
    const static int INFINITI;

public:
    // source verte
    Vertex<T> u;
    // target vertex
    Vertex<T> v;
    // weight
    int w;

    Edge(Vertex<T> u, Vertex<T> v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

template <class T> const int Edge<T>::INFINITI = 10000000;

#endif 
