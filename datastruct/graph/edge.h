#ifndef _GRAPH_EDGE_H_
#define _GRAPH_EDGE_H_

#include "vertex.h"

class Edge {
public:
    const static int INFINITI;

public:
    // source verte
    Vertex u;
    // target vertex
    Vertex v;
    // weight
    int w;

    Edge(Vertex u, Vertex v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

const int Edge::INFINITI = 10000000;

#endif 
