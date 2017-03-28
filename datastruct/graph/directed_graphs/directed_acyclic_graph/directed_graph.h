#ifndef _DIRECTED_GRAPH_H_
#define _DIRECTED_GRAPH_H_

#include "../../vertex.h"
#include "../../edge.h"
#include "../../vertex_list.h"

template <class T>
class DGraph {
public:
    typedef map< Vertex<T>, VertexList<T> > Map;
    DGraph(){}
    ~DGraph(){}
    
    void addEdge(Edge<T> e) {
        typename Map::iterator it = graph.find(e.u);
        if (it == graph.end()) {
            graph.insert(pair< Vertex<T>, VertexList<T> >(e.u, VertexList<T>()));
            it = graph.find(e.u);
        } 

        it->second.add(e.v);

        // add a pair with key e.v and blank value
        it = graph.find(e.v);
        if (it == graph.end()) {
            graph.insert(pair< Vertex<T>, VertexList<T> >(e.v, VertexList<T>()));
        }

        edges.push_back(e);
    }
    
     vector< Vertex<T> > getVertexs() {
        vector< Vertex<T> > vertexs;
        typename Map::iterator it = graph.begin();
        for (; it != graph.end(); ++it) {
            vertexs.push_back(it->first);
        }

        return vertexs;
    }

    void print() {
        typename Map::iterator it = graph.begin();
        for (; it != graph.end(); ++it) {
            printf("v->%s u->", it->first.getData().c_str());
            it->second.print();
            printf("\n");
        }
    }

    int getIndegree(Vertex<T> v) {
        int degree = 0;
        typename Map::iterator it = graph.begin();
        for (; it != graph.end(); ++it) {
            if (it->second.exist(v)) {
                degree ++;
            }
        }

        return degree;
    }

    int getOutdegree(Vertex<T> v) {
        typename Map::iterator it = graph.find(v);
        if (it == graph.end()) {
            return 0;
        }

        return it->second.count();
    }

    int getWeight(Vertex<T> u, Vertex<T> v) {
		typedef typename vector< Edge<T> >::iterator iterator;
        iterator it = edges.begin();
        for (; it != edges.end(); ++ it) {
            if ((*it).u.equal(u) && (*it).v.equal(v)) {
                return (*it).w;
            }
        }

        return Edge<T>::INFINITI;
    }

	const Map getGraph() {
        return graph;
	}

	void erase(const Vertex<T> v) {
        graph.erase(v);
	}

	const vector< Edge<T> > getEdges() {
	    return edges;
	}

protected:
    Map graph;
    vector< Edge<T> > edges;
};

#endif
