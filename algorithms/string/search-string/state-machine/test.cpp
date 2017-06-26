#include "search-by-state-machine.h"

int main() {
	StateMachine sm;
	sm.build("ACACAGA");
	sm.print();

	int result[10];
	int size = 0;
	
	SearchString::search("ACACACAGAGAACAC", sm, result, &size);
	for (int i = 0; i < size; i ++) 
		printf("the substring end at : %d\n", result[i]);

	return 0;
}
