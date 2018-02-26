#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include "main.h"
#include "search.h"

static searchMem_t mem;

#define MAX_SIZE 30

void testInit(void)
{
    int i;
    for(i=0; i<MAX_SIZE; i++)
        searchNodeAdd(&mem, i, NULL);
    for(i=0; i<MAX_SIZE; i++)
        searchNodeDel(&mem, i);
    for(i=0; i<MAX_SIZE; i++)
        searchNodeAdd(&mem, i, NULL);
}

void init()
{
    mem.memSize = 8 * MAX_SIZE;
    mem.mem = (void *)malloc(mem.memSize);
    searchInit(&mem);
}

 int main( void )
{
    init();
    testInit();
    while(1)
    {
      printf("$$ddasdasd\n");
    }
}

