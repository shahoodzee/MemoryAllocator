#include "functions.c"
int main() { 
	struct space space;
	initializeMemory(10, &space);
	int n = 1;
	int delete = 0;
	int pOld = 0;
	char *q;
	char **s = &q;
	while (n) {
		delete = delete + 1;
		n = readString(s);
		if (n && stringLen(*s)) {
			int p = heapAllocator(stringLen(*s) + 2, &space);
			copyString(*s, space.memory + p, stringLen(*s));
			if (!(delete % 3)) deallocator(pOld, &space);
			if (!((delete % 3) - 2)) pOld = p;
			printMemory(&space);
			printSizes(&space);
			
		}
		free(*s);
	}
	cleanMemory(&space);
}




//
//
