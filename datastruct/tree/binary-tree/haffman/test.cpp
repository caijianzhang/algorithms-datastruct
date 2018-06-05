#include <string>
#include <iostream>
#include "../node.h"
#include "haffman.h"

using namespace std;

struct Data {
	string name;
	float weigth;

	Data() {}
	Data(string name, float w) {
		this->name = name;
		this->weigth = w;
	}
};

Data operator+(Data d1, Data d2) {
	return Data("Node", d1.weigth + d2.weigth);
}

ostream& operator<<(ostream& os, const Data data) {
	os << data.name;
	return os;
}

template<>
struct PriorityComparer< Node<Data>* > {
	bool operator()(Node<Data>* n1, Node<Data>* n2) {
		return n1->data.weigth < n2->data.weigth;
	}
};

int main() {
	Haffman<Data> haffman;
	haffman.addNode(Data("A", 45));
	haffman.addNode(Data("B", 13));
	haffman.addNode(Data("C", 12));
	haffman.addNode(Data("D", 16));
	haffman.addNode(Data("E", 9));
	haffman.addNode(Data("F", 5));
	haffman.build();
	haffman.print();
	return 0;
}
