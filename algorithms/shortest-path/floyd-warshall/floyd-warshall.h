/*
 * Copyright (c) 2017
 * 
 * Permission to use, copy, modify, distribute and sell this software
 * for any purpose is hereby granted without fee.
 *
 * Ronnie Chang
 *
 */
#ifndef _FLOYD_WARSHALL_H_
#define _FLOYD_WARSHALL_H_

#include <vector>
#include "../../../datastruct/graph/edge.h"
#include "../../../datastruct/matrix/matrix.h"

class FloydWarshall {
	static const int INVALID = -1;
public:
	FloydWarshall(int size) : 
	size(size),
	matrix(size, size),
	shortest(size, size),
	pred(size, size) {
		matrix.setAll(BaseEdge::INFINITI);
	}

	~FloydWarshall() {

	}

public:
	void addEdge(int u, int v, int w) {
		matrix[u][v] = w;
	}

	bool calculate() {
		shortest = matrix;
		pred.setAll(INVALID);
		for (int u = 0; u < size; u++) {
			for (int v = 0; v < size; v++) {
				calculate(u, v, size - 1);
			}			
		}

		return true;
	}

	/*
	 * calculate the shortest path u->v, x is maybe one of the waypoints
	 */
	int calculate(int u, int v, int x) {
		int result = BaseEdge::INFINITI;
		if (u == v) return 0;
		if (u == x || v == x) return shortest[u][v];

		for (int i = 0; i <= x; i ++) {
			int ux = calculate(u, i, i - 1);
			int xv = calculate(i, v, i - 1);
			int uv = shortest[u][v];
			/*
			 * if u->i addition i->v less than u->v, that means i is the one of the waypoints of shortest path
			 */
			if (ux != BaseEdge::INFINITI &&
				xv != BaseEdge::INFINITI &&
				uv > ux + xv) {
				uv = ux + xv;
				shortest[u][v] = uv;
				pred[u][v] = x;
				printf("%d -> %d is %d, pred %d -> %d is %d\n", u, v, uv, u, v, x);
			} 

			if (result > uv) {
				result = uv;
			}
		}

		return result;
	}

	int getShortest() {
		int u = 0;
		int v = 0;
		if (getShortestPath(u, v)) {
			return shortest[u][v];
		}

		return BaseEdge::INFINITI;
	}

	vector<int> getShortestPath() {
		vector<int> result;
		int u = 0;
		int v = 0;
		if (getShortestPath(u, v)) {
			result.push_back(u);
			getPath(result, u, v);
			result.push_back(v);
		}

		return result;
	}

private:
	bool getShortestPath(int& u, int& v) {
		bool result = false;
		int s = 0;
		for (int i = 0; i < size; i ++) {
			for (int j = 0; j < size; j ++) {
				int ij = shortest[i][j];
				if (ij != BaseEdge::INFINITI && s < ij) {
					s = ij;
					u = i;
					v = j;
					result = true;
				}
			}
		}

		return result;
	}

	/*
	 * the pred point of u->v is saved is pred[Matrix<int>], if the u->v's pred point is x;
	 * then we must find the u->x and x->v's pred point till it is a directly edge.
	 */
	void getPath(vector<int>& path, int u, int v) {
		int p = pred[u][v];
		if (p != INVALID && p != u && p != v) {
			getPath(path, u, p);
			path.push_back(p);
			getPath(path, p, v);
		}
	}

private:
	Matrix<int> matrix;
	Matrix<int> shortest;
	Matrix<int> pred;
	int size;
};

#endif // _FLOYD_WARSHALL_H_
