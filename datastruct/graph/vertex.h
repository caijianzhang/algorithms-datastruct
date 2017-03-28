#ifndef _GRAPH_VERTEX_H_
#define _GRAPH_VERTEX_H_
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

template <class T>
class Vertex {
public:
    Vertex() {
        id = 0;
        data = T();
    }

    Vertex(int id, T data) {
        this->id = id;
        this->data = data;
    }

    Vertex(const Vertex<T>& v) {
        this->id = v.id;
        this->data = v.data;
    }

    ~Vertex() {

    }

    void setData(T data) {
        this->data = data;
    }

    T getData() const {
        return data;
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
    T data;
};

// std::map use operator '<' for sorting
template <class T>
bool operator < (const Vertex<T> u, const Vertex<T> v) {
    return u.getId() < v.getId();
}

#endif
