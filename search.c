
/* Standard includes. */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

#include "search.h"

typedef struct
{
    int index;
    void *info;
}searchInfo_t, *psearchInfo_t;

int findIndex(searchMem_t *mem, int index)
{
    psearchInfo_t p = (psearchInfo_t)mem->mem;
    int i;
    
    for(i=0;i<mem->useSize;i++)
        if(p[i].index == index)
            return i;
        
    return -1;    
}

void *searchIndex(searchMem_t *mem, int index)
{
    psearchInfo_t p = (psearchInfo_t)mem->mem;
    int i = findIndex(mem, index);

    if( i < 0)
        return NULL;
    
    return p[i].info;
}

static void nodeAdd(searchMem_t *mem, int index, void *ptr)
{
    psearchInfo_t p = (psearchInfo_t)mem->mem;

    p[mem->useSize].index = index;
    p[mem->useSize].info = ptr;
    mem->useSize++;
}

int searchNodeAdd(searchMem_t *mem, int index, void *ptr)
{
    if(((mem->useSize+1) * sizeof(searchInfo_t)) > mem->memSize )
        return  SEARCH_ERROR_FULL;
    
    if(findIndex(mem, index) >= 0)
        return  SEARCH_ERROR_EXISTED;
    
    nodeAdd(mem, index, ptr);
    return SEARCH_NON;
}

void *searchNodeModify(searchMem_t *mem, int index, void *ptr)
{
    psearchInfo_t p = (psearchInfo_t)mem->mem;
    int i = findIndex(mem, index);

    if( i < 0)
        return NULL;

    p[i].info = ptr;
    return p[i].info;
}

static void nodeDel(searchMem_t *mem, int index)
{
    psearchInfo_t p = (psearchInfo_t)mem->mem;
    int i;
    for(i=index+1; i<mem->useSize; i++)
        memcpy(&p[i-1], &p[i],sizeof(searchInfo_t));
    
    mem->useSize--;
}

int searchNodeDel(searchMem_t *mem, int index)
{
    int i = findIndex(mem, index);
    if(i < 0)
        return  SEARCH_ERROR_EMPTY;

    nodeDel(mem, i);

    return SEARCH_NON;
}

void searchInit(searchMem_t *mem)
{
    uint8_t *ptr = (uint8_t *)mem->mem;
    int i;
    
    for(i=0; i<mem->memSize; i++)
        ptr[i] = 0x00;
    
    mem->useSize = 0;
}
