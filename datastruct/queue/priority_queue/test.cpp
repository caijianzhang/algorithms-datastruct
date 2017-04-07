#include "priority_queue.h"

int main() {
	PriorityQueue<int> queue;
	queue.push_back(123);
	queue.push_back(456);

	queue.push_back(1);
	queue.push_back(4560);
	queue.push_back(43);
	queue.push_back(199);
	queue.push_back(109434);
	queue.push_back(-1);
	queue.push_back(25);
	queue.push_back(90);
	Iterator<int> it = queue.begin();

	while (queue.getSize() > 0)
		printf("priority value is : %d\n", queue.pop());

	return 0;
}
