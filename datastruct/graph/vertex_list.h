#ifndef _GRAPH_VERTEX_LIST_H_
#define _GRAPH_VERTEX_LIST_H_

#include "vertex.h"
#include "edge.h"

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

#endif
