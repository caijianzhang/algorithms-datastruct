#ifndef _GRAPH_VERTEX_LIST_H_
#define _GRAPH_VERTEX_LIST_H_

#include "vertex.h"
#include "edge.h"

template <class T>
class VertexNode {
public:
    Vertex<T> v;
    VertexNode<T>* next;
    explicit VertexNode(Vertex<T> v) {
        this->v = v;
        next = 0;
    }

    ~VertexNode() {
        if (next != 0) {
            delete next;
        }
    }

    VertexNode<T>* clone() {
        VertexNode<T>* clone = new VertexNode<T>(v);
        clone->next = 0;
        if (next != 0) {
            clone->next = next->clone();
        }

        return clone;
    }
};

template <class T>
class VertexList {
public:
    VertexList() {
        head = 0;
    }

    explicit VertexList(Vertex<T> v) {
        head = new VertexNode<T>(v);
    }

    VertexList(const VertexList<T>& vl) {
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

    VertexNode<T>* getHead() {
        return head;
    }

    void add(Vertex<T> v) {
        if (head == 0) {
            head = new VertexNode<T>(v);
            return;
        }

        VertexNode<T>* last = head;
        while (last->next != 0) {
            last = last->next;
        }

        last->next = new VertexNode<T>(v);
    }

    int count() {
        int count = 0;
        VertexNode<T>* node = head;
        while (node) {
            count ++;
            node = node->next;
        }

        return count;
    }

    bool exist(Vertex<T> v) {
        VertexNode<T>* node = head;
        while (node) {
            if (node->v.equal(v)) {
                return true;
            }

            node = node->next;
        }

        return false;
    }

    void print() {
        VertexNode<T>* node = head;
        while (node) {
            printf("%s ->", node->v.getData().c_str());
            node = node->next;
        }
    }

private:
    VertexNode<T>* head;
};

#endif
