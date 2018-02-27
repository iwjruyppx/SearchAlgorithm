
/* Standard includes. */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

#include "insertionSort.h"

typedef struct
{
    int index;
    void *info;
}searchInfo_t, *psearchInfo_t;

typedef struct
{
    uint32_t taskId;
    void *next;
}node_t, *pNode_t;

int insertionSort(void *mem, int maxSize)
{
    psearchInfo_t a = (psearchInfo_t)mem;
    searchInfo_t tmp;
    int i,j;
    
    for(i=1;i<maxSize;i++)
    {
        memcpy(&tmp, &a[i], sizeof(searchInfo_t));
        for(j=i; j>0 && tmp.index < a[j-1].index; j--)
            memcpy(&a[j], &a[j-1], sizeof(searchInfo_t));
        memcpy( &a[j], &tmp,sizeof(searchInfo_t));
    }
    for(i=0;i<maxSize;i++)
    {
        pNode_t b = a[i].info;
        printf("[%d]:%d, %d\n", i, a[i].index, b->taskId);
    }
    return -1;    
}
