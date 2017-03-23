/*************************************************************************
	> File Name: DAGraph.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  2/17 17:33:54 2017
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Vertex {
public:
    Vertex() {
        id = 0;
        name = string();
    }

    Vertex(int id, string name) {
        this->id = id;
        this->name = name;
    }

    Vertex(const Vertex& v) {
        this->id = v.id;
        this->name = v.name;
    }

    ~Vertex() {

    }

    void setName(string name) {
        this->name = name;
    }

    string getName() const {
        return name;
    }

    void setId(int id) {
        this->id = id;
    }

    int getId() const {
        return id;
    }

    bool equal(Vertex v) const {
        return this->id == v.id;
    }

private:
    int id;
    string name;
};

// std::map use operator '<' for sorting
bool operator < (const Vertex u, const Vertex v) {
    return u.getId() < v.getId();
}

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

class VertexNode {
public:
    Vertex v;
    VertexNode* next;
    explicit VertexNode(Vertex v) {
        this->v = v;
        next = 0;
    }

    ~VertexNode() {
        if (next != 0) {
            delete next;
        }
    }

    VertexNode* clone() {
        VertexNode* clone = new VertexNode(v);
        clone->next = 0;
        if (next != 0) {
            clone->next = next->clone();
        }

        return clone;
    }
};

class VertexList {
public:
    VertexList() {
        head = 0;
    }

    explicit VertexList(Vertex v) {
        head = new VertexNode(v);
    }

    VertexList(const VertexList& vl) {
        head = 0;
        if (vl.head != 0) {
            head = vl.head->clone();
        }
    }
    
    ~VertexList() {
        if (head != 0) {
            delete head;
            head = 0;
        }
    }

    VertexNode* getHead() {
        return head;
    }

    void add(Vertex v) {
        if (head == 0) {
            head = new VertexNode(v);
            return;
        }

        VertexNode* last = head;
        while (last->next != 0) {
            last = last->next;
        }

        last->next = new VertexNode(v);
    }

    int count() {
        int count = 0;
        VertexNode* node = head;
        while (node) {
            count ++;
            node = node->next;
        }

        return count;
    }

    bool exist(Vertex v) {
        VertexNode* node = head;
        while (node) {
            if (node->v.equal(v)) {
                return true;
            }

            node = node->next;
        }

        return false;
    }

    void print() {
        VertexNode* node = head;
        while (node) {
            printf("%s ->", node->v.getName().c_str());
            node = node->next;
        }
    }

private:
    VertexNode* head;
};

class DAGraph {
public:
    typedef map<Vertex, VertexList> Map;
    DAGraph(){}
    ~DAGraph(){}
    
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
    
    vector<Vertex> sort() {
        // copy a directed acyclic graph
        DAGraph dga = *this;
        vector<Vertex> result;
        vector<Vertex> vertexs = getVertexs();
       
        while (vertexs.size() != 0) {
            for (vector<Vertex>::iterator it = vertexs.begin(); it != vertexs.end(); ++it) {
                // if indegree of vertex is 0, means it's the top of graph
                if (dga.getIndegree(*it) == 0) {
                    result.push_back(*it);
                    dga.graph.erase(*it);
                    vertexs.erase(it);
                    break;
                }
            }
        }
        return result;
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

    vector<Vertex> getShortestPath(Vertex s) {
        vector<Vertex> sorted = sort();
        Vertex target = *(sorted.rbegin());
        map<Vertex, int> shortest;
        shortest.insert(pair<Vertex, int>(s, 0));
        map<Vertex, Vertex> pred;
        for (vector<Vertex>::iterator it = sorted.begin(); it != sorted.end(); ++it) {
            printf("u is %s\n", it->getName().c_str());
            map<Vertex, VertexList>::iterator _it = graph.find(*it);
            if (_it != graph.end()) {
                VertexNode* node = _it->second.getHead();
                while (node) {
                    printf("v is %s \n", node->v.getName().c_str());
                    int w = getWeight(*it, node->v);
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

protected:
    map<Vertex, VertexList> graph;
    vector<Edge> edges;
};
