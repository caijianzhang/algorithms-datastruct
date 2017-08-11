#include <string>
#include <iostream>
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
	os << "name:" << data.name << " weigth:" << data.weigth;
	return os;
}

template<>
struct PriorityComparer<Data> {
	bool operator()(Data t1, Data t2) {
		return t1.weigth < t2.weigth;
	}
};

int main() {
	PriorityQueue<Data> pq;
	pq.push_back(Data("A", 0.1));
	pq.push_back(Data("B", 0.2));
	pq.push_back(Data("C", 0.3));
	pq.push_back(Data("D", 0.4));

	Haffman<Data> haffman;
	haffman.build(pq);
	haffman.print();
	return 0;
}
