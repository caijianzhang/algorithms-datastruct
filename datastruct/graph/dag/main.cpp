/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  2/17 17:34:20 2017
 ************************************************************************/

#include<iostream>
#include "dag.h"

using namespace std;

int main() {
    Vertex v0(0, "start");
    Vertex v1(1, "cut up chicken");
    Vertex v2(2, "mix marinade");
    Vertex v3(3, "marinate chicken");
    Vertex v4(4, "partially cook chicken");
    Vertex v5(5, "chop garlic");
    Vertex v6(6, "chop ginger");
    Vertex v7(7, "add garlic, ginger");
    Vertex v8(8, "finish cooking chicken");
    Vertex v9(9, "remove chicken");
    Vertex v10(10, "chop carrots");
    Vertex v11(11, "chop celery");
    Vertex v12(12, "rinse peanuts");
    Vertex v13(13, "cook carrots, celery, peanuts");
    Vertex v14(14, "add back chicken");
    Vertex v15(15, "mix cooking sauce");
    Vertex v16(16, "add cooking sauce");
    Vertex v17(17, "cook sauce until thick");
    Vertex v18(18, "remove completed dish");
    Vertex v19(19, "finished");

    Edge e0(v0, v1, 0);
    Edge e1(v1, v3, 6);
    Edge e2(v2, v3, 2);
    Edge e3(v3, v4, 15);
    Edge e4(v5, v7, 4);
    Edge e5(v6, v7, 3);
    Edge e6(v7, v8, 1);
    Edge e7(v8, v9, 2);
    Edge e8(v9, v13, 1);
    Edge e9(v10, v13, 4);
    Edge e10(v11, v13, 3);
    Edge e11(v12, v13, 2);
    Edge e12(v13, v14, 4);
    Edge e13(v15, v16, 3);
    Edge e14(v14, v16, 1);
    Edge e15(v16, v17, 1);
    Edge e16(v17, v18, 3);
    Edge e17(v18, v19, 1);
    Edge e18(v4, v7, 4);
    Edge e19(v0, v2, 0);
    Edge e20(v0, v5, 0);
    Edge e21(v0, v6, 0);
    Edge e22(v0, v10, 0);
    Edge e23(v0, v11, 0);
    Edge e24(v0, v12, 0);
    Edge e25(v0, v15, 0);
    DAGraph dga;
    dga.addEdge(e0);
    dga.addEdge(e1);
    dga.addEdge(e2);
    dga.addEdge(e3);
    dga.addEdge(e4);
    dga.addEdge(e5);
    dga.addEdge(e6);
    dga.addEdge(e7);
    dga.addEdge(e8);
    dga.addEdge(e9);
    dga.addEdge(e10);
    dga.addEdge(e11);
    dga.addEdge(e12);
    dga.addEdge(e13);
    dga.addEdge(e14);
    dga.addEdge(e15);
    dga.addEdge(e16);
    dga.addEdge(e17);
    dga.addEdge(e18);
    dga.addEdge(e19);
    dga.addEdge(e20);
    dga.addEdge(e21);
    dga.addEdge(e22);
    dga.addEdge(e23);
    dga.addEdge(e24);
    dga.addEdge(e25);
    dga.print();

    printf("indegree of v1 is %d\n", dga.getIndegree(v1));
    printf("outdegree of v5 is %d\n", dga.getOutdegree(v5));
    printf("weight of v4 to v7 is %d\n", dga.getWeight(v4, v7));
    vector<Vertex> sorted = dga.sort();
    for (vector<Vertex>::iterator it = sorted.begin(); it != sorted.end(); ++it) {
        printf("%s \n", it->getName().c_str());
    }
    printf("\n");

    vector<Vertex> shortestPath = dga.getShortestPath(v0);
    for (vector<Vertex>::iterator it = shortestPath.begin(); it != shortestPath.end(); ++it) {
        printf("%s \n", it->getName().c_str());
    }
    printf("\n");

    return 0;
}
