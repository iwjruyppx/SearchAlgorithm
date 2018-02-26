#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include "main.h"
#include "subscribeEvent.h"

#define MAX_SIZE 30


int callBack(uint32_t evtType, uint32_t taskId)
{
    printf("[%d]%s:[%s,%d][%s,%d]\n",__LINE__,__FUNCTION__, "evtType", evtType, "taskId", taskId);
    return 0;
}

void test1(int x)
{
    int i, j;
    for(i = 0; i< x; i++)
        subscribeEventCheck(i, callBack);
    
    for(i=0; i<MAX_SIZE; i++)
        for(j=0; j<MAX_SIZE; j++)
            unSubscribeEvent(i, j);
}

void test2(int x)
{
    int i, j;
    for(i=0; i<MAX_SIZE; i++)
        for(j=0; j<MAX_SIZE; j++)
            subscribeEvent(i, j);
    for(i=0; i<MAX_SIZE; i++)
        for(j=0; j<MAX_SIZE; j++)
            subscribeEvent(i, j);
    for(i = 0; i< x; i++)
        subscribeEventCheck(i, callBack);
}


void testInit(void)
{
    int i, j;
    for(i=0; i<MAX_SIZE; i++)
        for(j=0; j<MAX_SIZE; j++)
            subscribeEvent(i, j);
    for(i=0; i<MAX_SIZE; i++)
        for(j=0; j<MAX_SIZE; j++)
            unSubscribeEvent(i, j);
    for(i=0; i<MAX_SIZE; i++)
        for(j=i; j<MAX_SIZE; j++)
            subscribeEvent(i, j);
}

void init()
{
    subscribeEventInit();
}


 int main( void )
{
    init();
    testInit();
    test1(30);
    while(1)
    {
        test2(30);
    }
}

