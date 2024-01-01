// functions.c

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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
    for (int i = 0; i < mem->len; i++) {
        printf("%c", mem->memory[i]);
    }
    printf("\n");
}

void printSizes(struct space *mem) {
    for (int i = 0; i < mem->len; i++) {
        printf("%d", mem->sizes[i]);
    }
    printf("\n");
}

void initializeMemory(int len, struct space *mem) {
    mem->memory = (char *)malloc(len * sizeof(char));
    mem->sizes = (int *)malloc(len * sizeof(int));
    mem->len = len;

    for (int i = 0; i < mem->len; i++) {
        mem->memory[i] = FREE;
        mem->sizes[i] = FREESIZE;
    }

    printMemory(mem);
    printSizes(mem);
}

void cleanMemory(struct space *mem) {
    for (int i = 0; i < mem->len; i++) {
        mem->memory[i] = FREE;
        mem->sizes[i] = FREESIZE;
    }

    printMemory(mem);
    printSizes(mem);

    free(mem->memory);
    free(mem->sizes);
}

int stackAllocator(int nbytes, struct space *mem) {
    int t0 = 0;
    while (t0 + nbytes < mem->len && mem->sizes[t0] != FREESIZE) {
        t0++;
    }

    if (t0 + nbytes == mem->len) {
        return mem->len;
    }

    int t = 0;
    while (t < nbytes && t0 + t < mem->len) {
        mem->memory[t0 + t] = BUSY;
        mem->sizes[t0 + t] = BUSYSIZE;
        t++;
    }

    mem->sizes[t0] = nbytes;
    return t0;
}

void deallocator(int t0, struct space *mem) {
    if (t0 == mem->len || t0 < 0) {
        return;
    }

    int nbytes = mem->sizes[t0];
    int t = 0;
    while (t < nbytes) {
        mem->memory[t0 + t] = FREE;
        mem->sizes[t0 + t] = FREESIZE;
        t++;
    }
}



int main() {
    struct space mem;
    int len = 50;  // Adjust the length as needed

    printf("Initializing Memory:\n");
    initializeMemory(len, &mem);

    printf("\nAllocating Memory:\n");
    int allocIndex1 = stackAllocator(20, &mem);
    printMemory(&mem);
    printSizes(&mem);
    printf("Allocated at Index: %d\n", allocIndex1);

    printf("\nDeallocating Memory:\n");
    deallocator(allocIndex1, &mem);
    printMemory(&mem);
    printSizes(&mem);

    printf("\nTrying to Allocate Insufficient Memory:\n");
    int allocIndex2 = stackAllocator(30, &mem);
    printf("Allocated at Index: %d\n", allocIndex2);

    return 0;
}