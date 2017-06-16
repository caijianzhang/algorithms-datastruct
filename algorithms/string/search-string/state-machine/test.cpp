#include "search-by-state-machine.h"

int main() {
	StateMachine sm;
	sm.build("ACACAGA");
	sm.print();
	return 0;
}
