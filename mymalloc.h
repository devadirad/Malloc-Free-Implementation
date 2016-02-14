#include <stdio.h>
#include <unistd.h>					//for Sbrk

#define blocksize 1<<20				//allocate huge size for our block
#define recogpattern 0xAAAAAAAA		//recognizing pattern

static char myblock[blocksize];		// Use this memory to simulate malloc

/*
 This structure will hold the meta data for the dyanamically allocated memory.
 */
typedef struct mementry_T mementry;

struct mementry_T {
    mementry *prev,*succ;			//links to previous and next memory chunk
    int recognize;					//use a pattern to know that the pointer is on a mementry structure
    int isfree;					    //flag set to denote memory is allocated. Use bitfield for free
    unsigned int size;				//size of the individual chunk
};



void *mymalloc(unsigned int size,char *file, int line);
void myfree(void *p1, char *file, int line);
