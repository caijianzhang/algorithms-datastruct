#include "floyd-warshall.h"

int main() {
	FloydWarshall fw(9);
	fw.addEdge(0, 1, 3);
	fw.addEdge(0, 2, 8);
	fw.addEdge(1, 3, 1);
	fw.addEdge(2, 1, 4);
	fw.addEdge(3, 2, 5);
	fw.addEdge(1, 6, 4);
	fw.addEdge(2, 5, 3);
	fw.addEdge(5, 7, 1);
	fw.addEdge(6, 7, 2);
	fw.addEdge(7, 8, 3);
	fw.calculate();
	printf("shortest is %d\n", fw.getShortest());
	vector<int> path = fw.getShortestPath();
	vector<int>::iterator it = path.begin();
	printf("shortest path is: ");
	for (; it != path.end(); ++ it) {
		printf("%d -> ", *it);
	}
	printf("\n");
	return 0;
}
