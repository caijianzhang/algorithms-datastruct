#include "lcs.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
	string s1 = "abcdabcdabbd123456";
	string s2 = "ababcdabd245";
	string lcs = LCS::findLargestCommonSequence(s1, s2);
	cout << "the largest common sequence is:" << lcs << endl;
	return 0;
}
