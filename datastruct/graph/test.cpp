#include "graph.h"

int main() {
	Graph<string, string> graph;
	Vertex<string, string> v0("1", "first");
	Vertex<string, string> v1("2", "second");
	Vertex<string, string> v2("3", "third");
	Vertex<string, string> v3("4", "four");
	Edge<string, string> e0(v0, v1, 1);
	Edge<string, string> e1(v0, v2, 2);
	Edge<string, string> e2(v0, v3, 3);
	Edge<string, string> e3(v2, v1, 3);
	graph.addEdge(e0);
	graph.addEdge(e1);
	graph.addEdge(e2);
	graph.addEdge(e3);

	printf("v0's outdegree is %d\n", graph.getOutdegree(v0));
	printf("v1's indegree is %d\n", graph.getIndegree(v1));

	return 0;
}
