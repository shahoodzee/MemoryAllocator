#include "functions.c"

int main() { 
	struct space space;
	int memSize = 50;
	initializeMemory(memSize, &space);
	printMemory(&space);
	printSizes(&space);
	cleanMemory(&space);
}




//
//
