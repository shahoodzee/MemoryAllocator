#include "functions.c"

int main() { 
	struct space space;
	int memSize = 100;
	initializeMemory(memSize, &space);
	char *s[5];
	s[0] = "Brian Kernighan";
	s[1] = "CS2850";
	s[2] = "Dennis Ritchie";
	s[3] = "The C Programming Language";
	s[4] = "and";
	int p[5];
	int pRemove = space.len;
	for (int i = 0; i < 5; i++) {
		p[i] = heapAllocatorQ3(stringLen(s[i])  + 2, &space);
		if (p[i] != space.len) copyString(s[i], space.memory + p[i], stringLen(s[i]));
		if (i == 1) pRemove  = p[i];
		if (i == 2 && pRemove) deallocator(pRemove, &space);
		printMemory(&space);
		printSizes(&space);
	}
	cleanMemory(&space);
}




//
//
