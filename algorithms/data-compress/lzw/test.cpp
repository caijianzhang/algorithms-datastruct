
#include "lzw.h"

int main() {
	LZW lzw;
	vector<int> result = lzw.compress("TATAGATCTTAATATA");
	for (vector<int>::iterator it = result.begin(); it != result.end(); ++it) {
		printf("%d\n", *it);
	}

	string text = lzw.decompress(result);
	printf("%s\n", text.c_str());
	return 0;
}

