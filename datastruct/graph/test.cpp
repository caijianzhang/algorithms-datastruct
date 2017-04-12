#include "graph.h"

bool exist(Graph<string, string> graph, Edge<string, string> edge) {
	Graph<string, string>::Iterator it = graph.begin();
	for (; it != graph.end(); ++it) {
		if (it->first == edge.u) {
			printf("key:%s, values:%d \n", it->first.getKey().c_str(), (int)it->second.size());
			list< Edge<string, string> >::iterator _it = it->second.begin();
			for (; _it != it->second.end(); _it++) {
				if ((*_it) == edge) {
					printf("value is : %s \n", (*_it).v.getValue().c_str());
					printf("edge is : %s \n", edge.v.getValue().c_str());
					return true;
				}
			}
		}
	}

	return false;
}

int main() {
	Graph<string, string> graph;
	Vertex<string, string> v0("1", "first");
	Vertex<string, string> v1("2", "second");
	Vertex<string, string> v2("3", "third");
	Vertex<string, string> v3("4", "four");
	Edge<string, string> e0(v0, v1, 1);
	Edge<string, string> e1(v0, v2, 2);
	Edge<string, string> e2(v0, v3, 3);
	printf("e0 is %s\n", exist(graph, e0) ? "exist" : "not exist");
	graph.addEdge(e0);
	printf("e1 is %s\n", exist(graph, e1) ? "exist" : "not exist");
	graph.addEdge(e1);
	printf("e2 is %s\n", exist(graph, e2) ? "exist" : "not exist");
	graph.addEdge(e2);

	Graph<string, string>::Iterator it = graph.begin();
	for (; it != graph.end(); ++it) {
		printf("key:%s, values:%d (", it->first.getKey().c_str(), (int)it->second.size());
		list< Edge<string, string> >::iterator _it = it->second.begin();
		for (; _it != it->second.end(); _it++)
			printf("%s ", (*_it).v.getValue().c_str());
		printf(")\n");
	}

	return 0;
}
