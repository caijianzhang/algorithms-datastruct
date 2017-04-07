#include "queue.h"

int main() {
	Queue<int, 5> queue;
	queue.push_back(123);
	queue.push_back(456);
	queue.push_back(789);
	queue.pop();
	queue.pop();
	Iterator<int> it = queue.begin();

	for (; it != queue.end(); ++it) {
		printf("%d\n", *it);
	}

	queue.push_back(3223);
	queue.push_back(31231313);
	queue.push_back(1231313);
	queue.push_back(343244);

	for (it = queue.begin(); it != queue.end(); ++it) {
		printf("-- %d\n", *it);
	}

	printf("%d\n", queue[100]);

	return 0;
}
