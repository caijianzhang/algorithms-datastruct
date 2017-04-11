#include "adjacency_list.h"
#include <string>

using namespace std;

int main() {
	AdjacencyList<string, int> al;
	al.put("1", 1);
	al.put("1", 2);
	al.put("1", 3);
	al.put("2", 1);
	al.put("2", 2);

	AdjacencyList<string, int>::Iterator it = al.begin();
	for (; it != al.end(); ++it) {
		printf("key:%s, values:%d (", it->first.c_str(), (int)it->second.size());
		list<int>::iterator _it = it->second.begin();
		for (; _it != it->second.end(); _it++)
			printf("%d", *_it);
		printf(")\n");
	}
	return 0;
}
