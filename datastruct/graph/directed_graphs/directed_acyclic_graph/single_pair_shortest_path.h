#ifndef _SINGLE_PAIR_SHORTEST_PATH_H_
#define _SINGLE_PAIR_SHORTEST_PATH_H_

#include "directed_graph.h"

template <class T>
vector<Vertex<T> > sort(DGraph<T> dg) {
    // copy a directed acyclic graph
    DGraph<T> temp = dg;
    vector<Vertex<T> > result;
    vector<Vertex<T> > vertexs = temp.getVertexs();
   
    while (vertexs.size() != 0) {
		typedef typename vector< Vertex<T> >::iterator iterator;
        for (iterator it = vertexs.begin(); it != vertexs.end(); ++it) {
            // if indegree of vertex is 0, means it's the top of graph
            if (temp.getIndegree(*it) == 0) {
                result.push_back(*it);
                temp.erase(*it);
                vertexs.erase(it);
                break;
            }
        }
    }

    return result;
}

template <class T>
vector<Vertex<T> > getShortestPath(DGraph<T> dg, Vertex<T> s) {
    vector<Vertex<T> > sorted = sort(dg);
    Vertex<T> target = *(sorted.rbegin());
    map<Vertex<T>, int> shortest;
    shortest.insert(pair<Vertex<T>, int>(s, 0));
    map<Vertex<T>, Vertex<T> > pred;
	map<Vertex<T>, VertexList<T> > graph = dg.getGraph();
	typedef typename vector< Vertex<T> >::iterator iterator;
	typedef typename map< Vertex<T>, VertexList<T> >::iterator _iterator;
	typedef typename map<Vertex<T>, int>::iterator __iterator;
    for (iterator it = sorted.begin(); it != sorted.end(); ++it) {
        printf("u is %s\n", it->getData().c_str());
        _iterator _it = graph.find(*it);
        if (_it != graph.end()) {
            VertexNode<T>* node = _it->second.getHead();
            while (node) {
                printf("v is %s \n", node->v.getData().c_str());
                int w = dg.getWeight(*it, node->v);
                printf("weight of u -> v is %d \n", w);
                if (w < Edge<T>::INFINITI) {
                    __iterator it_w = shortest.find(*it);
                    if (it_w != shortest.end() && it_w->second < Edge<T>::INFINITI) {
                        w += it_w->second;
                        __iterator it_s = shortest.find(node->v);
                        if (it_s != shortest.end() && w > it_s->second) {
                            continue;
                        }

                        shortest.insert(pair<Vertex<T>, int>(node->v, w));
                        pred.insert(pair<Vertex<T>, Vertex<T> >(node->v, *it));
                        printf("shortest of %s is %d\n", node->v.getData().c_str(), w);
                    }
                }

                node = node->next;
            }
        }
    }

    for (__iterator it = shortest.begin(); it != shortest.end(); ++it) {
        printf("u : %s, shortest : %d\n", it->first.getData().c_str(), it->second);
    }
    vector< Vertex<T> > result;
    __iterator it_w = shortest.find(target);
    if (it_w != shortest.end()) {
        typename map< Vertex<T>, Vertex<T> >::iterator it = pred.find(target);
        if (it != pred.end()) {
            result.push_back(it->first);
    
            while (it != pred.end()) {
                //result.push_back(it->first);
                result.insert(result.begin(), it->second);
                it = pred.find(it->second);
            }
        }
    }

    return result;
}

#endif
