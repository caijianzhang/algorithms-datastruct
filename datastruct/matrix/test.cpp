#include "matrix.h"

int main() {
	Matrix<int> matrix(10, 10);
	matrix[0][0] = 1;
	matrix[9][9] = 2;

	printf("0,0 -> %d\n", matrix[0][0]);
	printf("9,9 -> %d\n", matrix[9][9]);
	return 0;
}
