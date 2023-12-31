// functions.c

#include <unistd.h>
#include <stdlib.h>

#define BUSY '+'
#define FREE ' '
#define BUSYSIZE -1
#define FREESIZE 0

struct space {
    char *memory;
    int *sizes;
    int len;
};

void printDash(int len){
    for (int i = 0; i < len; ++i) {
            printf("_");
    }
    printf("\n");

}

void printMemory(struct space *mem) {

    printDash(mem->len);
    for (int i = 0; i < mem->len; ++i) {
        if (mem->sizes[i] == FREESIZE) {
            printf("0");
        }
    }
    printf("\n");
}

void printSizes(struct space *mem) {
    printDash(mem->len);
    printf("\n");
    for (int i = 0; i < mem->len; ++i) {
        if (mem->sizes[i] == FREESIZE) {
            printf("0");
        }
    }
}

void initializeMemory(int memSize, struct space *mem) {
    // Allocate memory block for characters
    mem->memory = (char *)malloc(memSize * sizeof(char));
    
    // Allocate memory block for sizes
    mem->sizes = (int *)malloc(memSize * sizeof(int));

    // Set len to memSize
    mem->len = memSize;

    // Initialize memory and sizes arrays
    for (int i = 0; i < memSize; ++i) {
        mem->memory[i] = FREE;
        mem->sizes[i] = FREESIZE;
    }

    // Print memory and sizes
    printMemory(mem);
    printSizes(mem);
}

void cleanMemory(struct space *mem) {
    // Set all entries of memory and sizes to FREE and FREESIZE
    for (int i = 0; i < mem->len; ++i) {
        mem->memory[i] = FREE;
        mem->sizes[i] = FREESIZE;
    }

    // Print memory and sizes
    printMemory(mem);
    printSizes(mem);

    // Free allocated memory
    free(mem->memory);
    free(mem->sizes);
}
