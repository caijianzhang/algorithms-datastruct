#ifndef _DIRECTED_GRAPH_H_
#define _DIRECTED_GRAPH_H_

#include "../../vertex.h"
#include "../../edge.h"
#include "../../vertex_list.h"

class DGraph {
public:
    typedef map<Vertex, VertexList> Map;
    DGraph(){}
    ~DGraph(){}
    
    void addEdge(Edge e) {
        map<Vertex, VertexList>::iterator it = graph.find(e.u);
        if (it == graph.end()) {
            graph.insert(pair<Vertex, VertexList>(e.u, VertexList()));
            it = graph.find(e.u);
        } 

        it->second.add(e.v);

        // add a pair with key e.v and blank value
        it = graph.find(e.v);
        if (it == graph.end()) {
            graph.insert(pair<Vertex, VertexList>(e.v, VertexList()));
        }

        edges.push_back(e);
    }
    
     vector<Vertex> getVertexs() {
        vector<Vertex> vertexs;
        Map::iterator it = graph.begin();
        for (; it != graph.end(); ++it) {
            vertexs.push_back(it->first);
        }

        return vertexs;
    }

    void print() {
        map<Vertex, VertexList>::iterator it = graph.begin();
        for (; it != graph.end(); ++it) {
            printf("v->%s u->", it->first.getName().c_str());
            it->second.print();
            printf("\n");
        }
    }

    int getIndegree(Vertex v) {
        int degree = 0;
        map<Vertex, VertexList>::iterator it = graph.begin();
        for (; it != graph.end(); ++it) {
            if (it->second.exist(v)) {
                degree ++;
            }
        }

        return degree;
    }

    int getOutdegree(Vertex v) {
        map<Vertex, VertexList>::iterator it = graph.find(v);
        if (it == graph.end()) {
            return 0;
        }

        return it->second.count();
    }

    int getWeight(Vertex u, Vertex v) {
        vector<Edge>::iterator it = edges.begin();
        for (; it != edges.end(); ++ it) {
            if ((*it).u.equal(u) && (*it).v.equal(v)) {
                return (*it).w;
            }
        }

        return Edge::INFINITI;
    }

	const map<Vertex, VertexList> getGraph() {
        return graph;
	}

	void erase(const Vertex v) {
        graph.erase(v);
	}

	const vector<Edge> getEdges() {
	    return edges;
	}

protected:
    map<Vertex, VertexList> graph;
    vector<Edge> edges;
};

#endif
