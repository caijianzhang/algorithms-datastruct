#ifndef _SINGLE_PAIR_SHORTEST_PATH_H_
#define _SINGLE_PAIR_SHORTEST_PATH_H_

#include "directed_graph.h"

vector<Vertex> sort(DGraph dg) {
    // copy a directed acyclic graph
    DGraph temp = dg;
    vector<Vertex> result;
    vector<Vertex> vertexs = temp.getVertexs();
   
    while (vertexs.size() != 0) {
        for (vector<Vertex>::iterator it = vertexs.begin(); it != vertexs.end(); ++it) {
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

vector<Vertex> getShortestPath(DGraph dg, Vertex s) {
    vector<Vertex> sorted = sort(dg);
    Vertex target = *(sorted.rbegin());
    map<Vertex, int> shortest;
    shortest.insert(pair<Vertex, int>(s, 0));
    map<Vertex, Vertex> pred;
	map<Vertex, VertexList> graph = dg.getGraph();
    for (vector<Vertex>::iterator it = sorted.begin(); it != sorted.end(); ++it) {
        printf("u is %s\n", it->getName().c_str());
        map<Vertex, VertexList>::iterator _it = graph.find(*it);
        if (_it != graph.end()) {
            VertexNode* node = _it->second.getHead();
            while (node) {
                printf("v is %s \n", node->v.getName().c_str());
                int w = dg.getWeight(*it, node->v);
                printf("weight of u -> v is %d \n", w);
                if (w < Edge::INFINITI) {
                    map<Vertex, int>::iterator it_w = shortest.find(*it);
                    if (it_w != shortest.end() && it_w->second < Edge::INFINITI) {
                        w += it_w->second;
                        map<Vertex, int>::iterator it_s = shortest.find(node->v);
                        if (it_s != shortest.end() && w > it_s->second) {
                            continue;
                        }

                        shortest.insert(pair<Vertex, int>(node->v, w));
                        pred.insert(pair<Vertex, Vertex>(node->v, *it));
                        printf("shortest of %s is %d\n", node->v.getName().c_str(), w);
                    }
                }

                node = node->next;
            }
        }
    }

    for (map<Vertex, int>::iterator it = shortest.begin(); it != shortest.end(); ++it) {
        printf("u : %s, shortest : %d\n", it->first.getName().c_str(), it->second);
    }
    vector<Vertex> result;
    map<Vertex, int>::iterator it_w = shortest.find(target);
    if (it_w != shortest.end()) {
        map<Vertex, Vertex>::iterator it = pred.find(target);
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
