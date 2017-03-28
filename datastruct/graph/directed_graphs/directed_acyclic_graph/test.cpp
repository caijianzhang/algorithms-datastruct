/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  2/17 17:34:20 2017
 ************************************************************************/

#include<iostream>
#include "directed_graph.h"
#include "single_pair_shortest_path.h"

using namespace std;

int main() {
    Vertex<string> v0(0, "start");
    Vertex<string> v1(1, "cut up chicken");
    Vertex<string> v2(2, "mix marinade");
    Vertex<string> v3(3, "marinate chicken");
    Vertex<string> v4(4, "partially cook chicken");
    Vertex<string> v5(5, "chop garlic");
    Vertex<string> v6(6, "chop ginger");
    Vertex<string> v7(7, "add garlic, ginger");
    Vertex<string> v8(8, "finish cooking chicken");
    Vertex<string> v9(9, "remove chicken");
    Vertex<string> v10(10, "chop carrots");
    Vertex<string> v11(11, "chop celery");
    Vertex<string> v12(12, "rinse peanuts");
    Vertex<string> v13(13, "cook carrots, celery, peanuts");
    Vertex<string> v14(14, "add back chicken");
    Vertex<string> v15(15, "mix cooking sauce");
    Vertex<string> v16(16, "add cooking sauce");
    Vertex<string> v17(17, "cook sauce until thick");
    Vertex<string> v18(18, "remove completed dish");
    Vertex<string> v19(19, "finished");

    Edge<string> e0(v0, v1, 0);
    Edge<string> e1(v1, v3, 6);
    Edge<string> e2(v2, v3, 2);
    Edge<string> e3(v3, v4, 15);
    Edge<string> e4(v5, v7, 4);
    Edge<string> e5(v6, v7, 3);
    Edge<string> e6(v7, v8, 1);
    Edge<string> e7(v8, v9, 2);
    Edge<string> e8(v9, v13, 1);
    Edge<string> e9(v10, v13, 4);
    Edge<string> e10(v11, v13, 3);
    Edge<string> e11(v12, v13, 2);
    Edge<string> e12(v13, v14, 4);
    Edge<string> e13(v15, v16, 3);
    Edge<string> e14(v14, v16, 1);
    Edge<string> e15(v16, v17, 1);
    Edge<string> e16(v17, v18, 3);
    Edge<string> e17(v18, v19, 1);
    Edge<string> e18(v4, v7, 4);
    Edge<string> e19(v0, v2, 0);
    Edge<string> e20(v0, v5, 0);
    Edge<string> e21(v0, v6, 0);
    Edge<string> e22(v0, v10, 0);
    Edge<string> e23(v0, v11, 0);
    Edge<string> e24(v0, v12, 0);
    Edge<string> e25(v0, v15, 0);
    DGraph<string> dg;
    dg.addEdge(e0);
    dg.addEdge(e1);
    dg.addEdge(e2);
    dg.addEdge(e3);
    dg.addEdge(e4);
    dg.addEdge(e5);
    dg.addEdge(e6);
    dg.addEdge(e7);
    dg.addEdge(e8);
    dg.addEdge(e9);
    dg.addEdge(e10);
    dg.addEdge(e11);
    dg.addEdge(e12);
    dg.addEdge(e13);
    dg.addEdge(e14);
    dg.addEdge(e15);
    dg.addEdge(e16);
    dg.addEdge(e17);
    dg.addEdge(e18);
    dg.addEdge(e19);
    dg.addEdge(e20);
    dg.addEdge(e21);
    dg.addEdge(e22);
    dg.addEdge(e23);
    dg.addEdge(e24);
    dg.addEdge(e25);
    dg.print();

    printf("indegree of v1 is %d\n", dg.getIndegree(v1));
    printf("outdegree of v5 is %d\n", dg.getOutdegree(v5));
    printf("weight of v4 to v7 is %d\n", dg.getWeight(v4, v7));
    vector<Vertex<string> > sorted = sort(dg);
    for (vector<Vertex<string> >::iterator it = sorted.begin(); it != sorted.end(); ++it) {
        printf("%s \n", it->getData().c_str());
    }
    printf("\n");

    vector<Vertex<string> > shortestPath = getShortestPath(dg, v0);
    for (vector<Vertex<string> >::iterator it = shortestPath.begin(); it != shortestPath.end(); ++it) {
        printf("%s \n", it->getData().c_str());
    }
    printf("\n");

    return 0;
}
