// q1.c

#include <stdio.h>
#include "functions.c"

int main() {
    struct space mem;

    // Test initializeMemory
    printf("Initialize Memory:\n");
    initializeMemory(10, &mem);

    // Test cleanMemory
    printf("\nClean Memory:\n");
    cleanMemory(&mem);

    return 0;
}
