#ifndef _GRAPH_VERTEX_H_
#define _GRAPH_VERTEX_H_
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

#endif
