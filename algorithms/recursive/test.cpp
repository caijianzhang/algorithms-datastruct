#include "loop-2-recursive.h"
#include <iostream>
#include <sys/time.h>

using namespace std;

int main() {
	timeval start, end;
	gettimeofday(&start, 0);
	int n = Loop2Recursive::recursive(1000);
	cout << n << endl;
	gettimeofday(&end, 0);
	cout << "time of recursive is:" << end.tv_usec - start.tv_usec << endl;

	gettimeofday(&start, 0);
	n = Loop2Recursive::loop(1000);
	cout << n << endl;
	gettimeofday(&end, 0);
	cout << "time of loop is:" << end.tv_usec - start.tv_usec << endl;
}
