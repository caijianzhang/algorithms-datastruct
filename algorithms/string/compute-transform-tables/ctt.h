/*
 * Copyright (c) 2017
 * 
 * Permission to use, copy, modify, distribute and sell this software
 * for any purpose is hereby granted without fee.
 *
 * Ronnie stringng
 *
 */
#ifndef _COMPUTE_TRANSFORM_TABLES_H_
#define _COMPUTE_TRANSFORM_TABLES_H_

#include <string>
#include <iostream>
#include <vector>

using namespace std;
	
static const string OPERATION_COMPLETE = "complete";
static const string OPERATION_COTY = "copy";
static const string OPERATION_REPLACE = "replace";
static const string OPERATION_INSERT = "insert";
static const string OPERATION_DELETE = "delete";

class CTT {
private:
	static const int COST_COPY = -1;
	static const int COST_REPLACE = 1;
	static const int COST_INSERT = 2;
	static const int COST_DELETE = 2;
public:
	CTT(){}

	/**
	 * the mode is so slow....., because it will repeat calculation cost[x][y] meny times
	 * we can stored cost[x][y] in an array, when each recursion we search cost[x][y] first, if we get it, returned immediately.
	 *
	 */
	int getMinimumCost(string x, string y, vector<string>& operators) {
		int xLen = x.size() + 1;
		int yLen = y.size() + 1;
		int** cost = (int**)malloc(xLen * sizeof(int*));
		cost[0] = (int*)malloc(xLen * yLen * sizeof(int));
		for (int i = 1; i < xLen; i++) {
			cost[i] = cost[i-1] + yLen;
		}

		for (int i = 0; i < xLen; ++i) {
			for (int j = 0; j < yLen; ++j) {
				cost[i][j] = 0x7fffffff;
			}
		}

		int result = getMinimumCost(x, y, operators, cost);
		free(cost);
		return result;
	}

	int getMinimumCost(string x, string y, vector<string>& operators, int** pCost) {
		int xLen = x.size();
		int yLen = y.size();

		vector<string> op;
		string operation = OPERATION_COMPLETE;
		int cost = 0;

		do {
			if (xLen == 0 && yLen == 0) {
				cost = 0;
				break;
			}

			if (xLen == 0 && yLen != 0) {
				cost = getMinimumCost(x, y.substr(0, yLen-1), op, pCost) + COST_INSERT;
				operation = OPERATION_INSERT + " space to " + y[yLen-1];
				break;
			}

			if (yLen == 0 && xLen != 0) {
				cost = getMinimumCost(x.substr(0, xLen-1), y, op, pCost) + COST_DELETE;
				operation = OPERATION_DELETE + " " + x[xLen - 1];
				break;
			}

			if (pCost[xLen][yLen] < 0x7fffffff) {
				cost = pCost[xLen][yLen];
				break;
			}

			if (x[xLen-1] == y[yLen-1]) {
				// copy
				cost = getMinimumCost(x.substr(0, xLen - 1), y.substr(0, yLen - 1), op, pCost) + COST_COPY;
				operation = OPERATION_COTY + " " + x[xLen-1] + " to " + y[yLen-1];
			} else {
				// replace
				cost = getMinimumCost(x.substr(0, xLen - 1), y.substr(0, yLen - 1), op, pCost) + COST_REPLACE;
				operation = OPERATION_REPLACE + " " + x[xLen-1] + " to " + y[yLen-1];
			}
				
			// insert
			vector<string> tmp;
			int iCost = getMinimumCost(x, y.substr(0, yLen - 1), tmp, pCost) + COST_INSERT;
			if (cost > iCost) {
				cost = iCost;
				op = tmp;
				operation = OPERATION_INSERT + " space to " + y[yLen-1];
			}
				
			// delete
			tmp.clear();
			int dCost = getMinimumCost(x.substr(0, xLen - 1), y, tmp, pCost) + COST_DELETE;
			if (cost > dCost) { 
				cost = dCost;
				op = tmp;
				operation = OPERATION_DELETE + " " + x[xLen - 1];
			}
		} while (0);

		vector<string>::iterator it = op.begin();
		for (; it != op.end(); ++it) {
			operators.push_back(*it);
		}
		operators.push_back(operation);
		pCost[xLen][yLen] = cost;
		return cost;
	}

	/**
	 * this mode is fast then 'getMinimumCost'
	 *
	 *
	 */
	int getMinimumCost2(string x, string y, vector<string> operators) {
		int xLen = x.size();
		int yLen = y.size();
		int** cost = (int**)malloc(xLen * sizeof(int*));
		cost[0] = (int*)malloc(xLen * yLen * sizeof(int));
		for (int i = 1; i < xLen; i++) {
			cost[i] = cost[i-1] + yLen;
		}

		string** op = new string*[xLen];
		op[0] = new string[xLen * yLen];
		for (int i = 1; i < xLen; i++) {
			op[i] = op[i-1] + yLen;
		}
	
		cost[0][0] = 0;
		for (int i = 1; i < xLen; i ++) {
			cost[i][0] = COST_DELETE;
			op[i][0] = OPERATION_DELETE + " " + x[i];
		}

		for (int j = 1; j < yLen; j ++) {
			cost[0][j] = COST_INSERT;
			op[0][j] = OPERATION_INSERT + " " + y[j];
		}

		for (int i = 1; i < xLen; i++) {
			for (int j = 1; j < yLen; j++) {
				if (x[i] == y[j]) {
					cost[i][j] = cost[i-1][j-1] + COST_COPY;
					op[i][j] = OPERATION_COTY + " " + x[i] + " to " + y[j];
				} else {
					cost[i][j] = cost[i-1][j-1] + COST_REPLACE;
					op[i][j] = OPERATION_REPLACE + " " + x[i] + " to " + y[j];
				}

				if (cost[i-1][j] + COST_DELETE < cost[i][j]) {
					cost[i][j] = cost[i-1][j] + COST_DELETE;
					op[i][j] = OPERATION_DELETE + " " + x[i];
				}

				if (cost[i][j-1] + COST_INSERT < cost[i][j]) {
					cost[i][j] = cost[i][j-1] + COST_INSERT;
					op[i][j] = OPERATION_INSERT + " " + y[j];
				}
			}
		}
	
		int resultCost = cost[xLen-1][yLen-1];
		free(cost[0]);
		free(cost);
		delete []op[0];
		delete []op;
		return resultCost;
	}

	void getOperators(int** cost, string** op, int x, int y, vector<string>& operators) {
		
	}
};

#endif // _COMPUTE_TRANSFORM_TABLES_H_
