#include "ctt.h"
#include <iostream>

using namespace std;

int main() {
	CTT ctt;
	vector<string> operators;
	int cost = ctt.getMinimumCost("ATGATCGGCAT", "CAATGTGAATC", operators);
	cout << "the cost is " << cost << endl;

	vector<string>::iterator it = operators.begin();
	for (; it != operators.end(); ++it) {
		cout << *it << endl;
	}
	return 0;
}
