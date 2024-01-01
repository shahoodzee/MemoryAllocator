#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


#define BUSY '+'
#define FREE '_'
#define BUSYSIZE -1
#define FREESIZE 0

struct space {
        char *memory;
        int *sizes;
        int len;
};

void printMemory(struct space *mem) {
        int i = 0;
        while (i < mem->len) {
		printf("%c", *(mem->memory + i));
                i = i + 1;
        }
	printf("\n");
}

void printSizes(struct space *mem) {
        int i = 0;
        int c;
	while (i < mem->len) {
                int n = *(mem->sizes + i);
                int t = 10000;
                while (n > 9) {
                        c = n/t;
                        n = n - c * t;
                        t = t / 10;
                        if (c) {
                        	c =  c % 10 + '0';
				printf("%c", c);
                                i = i + 1;
                        }
                }
		c =  n % 10 + '0';
		printf("%c", c);
                i = i + 1;
        }
	printf("\n");

}

void copyString(char *sIn, char *sOut, int len) {
        int t = 0;
        while (t < len) {
                *(sOut + t) = *(sIn + t);
                t = t + 1;
        }
}
int stringLen(char *s) {
        int t = 0;
        while (*(s + t) != '\0')
                t++;
        return t;
}

