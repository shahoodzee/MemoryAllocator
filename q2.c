#include "functions.c"

int main() { 
	struct space space;
	int memSize = 50;
	initializeMemory(memSize, &space);
	char *s[3];
	s[0] = "Brian Kernighan";
	s[1] = "CS2850";
	s[2] = "Dennis Ritchie";
	int p[3];
	int pRemove;
	for (int i = 0; i < 3; i++) {
		p[i] = stackAllocator(stringLen(s[i]) + 5, &space);
		if (p[i] != space.len) copyString(s[i], space.memory + p[i], stringLen(s[i]));
		if (i == 1) pRemove  = p[i];
		if (i == 2) deallocator(pRemove, &space);
		printMemory(&space);
		printSizes(&space);
	}
	cleanMemory(&space);
}




//
//
