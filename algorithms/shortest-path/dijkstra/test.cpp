#include "../../../datastruct/graph/directed_graphs/directed_graph.h"
#include "dijkstra.h"


int main() {
	DirectedGraph<string, string> graph;
	Vertex<string, string> v0("1", "first");
	Vertex<string, string> v1("2", "second");
	Vertex<string, string> v2("3", "third");
	Vertex<string, string> v3("4", "four");
	Vertex<string, string> v4("5", "five");
	Vertex<string, string> v5("6", "six");
	Vertex<string, string> v6("7", "seven");
	Edge<string, string> e0(v0, v1, 1);
	Edge<string, string> e1(v0, v2, 1);
	Edge<string, string> e2(v0, v3, 3);
	Edge<string, string> e3(v2, v3, 1);
	Edge<string, string> e4(v2, v1, 1);
	Edge<string, string> e5(v1, v4, 1);
	Edge<string, string> e6(v3, v5, 2);
	Edge<string, string> e7(v4, v5, 1);
	Edge<string, string> e8(v5, v6, 1);
	Edge<string, string> e9(v6, v5, 1);
	graph.addEdge(e0);
	graph.addEdge(e1);
	graph.addEdge(e2);
	graph.addEdge(e3);
	graph.addEdge(e4);
	graph.addEdge(e5);
	graph.addEdge(e6);
	graph.addEdge(e7);
	graph.addEdge(e8);
	graph.addEdge(e9);

	printf("v0's outdegree is %d\n", graph.getOutdegree(v0));
	printf("v1's indegree is %d\n", graph.getIndegree(v1));

	Dijkstra<string, string> dijkstra;
	dijkstra.calculate(graph, v0, v6);
	printf("the shortest of v0 -> v6 is %d\n", dijkstra.getShortest());

	vector<Vertex<string, string> > path = dijkstra.getShortestPath();
	vector<Vertex<string, string> >::iterator it = path.begin();
	for (; it != path.end(); ++it) {
		printf("%s->", it->getValue().c_str());
	}

	printf("\n");

	return 0;
}
