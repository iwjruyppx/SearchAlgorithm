#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include "main.h"
#include "subscribeEvent.h"

#define MAX_SIZE 30

struct newFlashEvents{
    uint32_t addr;
    uint8_t length;
    uint8_t command;
};


static int callBack(uint32_t evtType, uint32_t taskId, void* evtData)
{
    struct newFlashEvents *aaa = (struct newFlashEvents *)evtData;
    printf("[%d]%s:[%s,%d][%s,%d][%s,%d][%s,%d][%s,%d]\n",__LINE__,__FUNCTION__, "evtType", evtType, "taskId", taskId, "addr", aaa->addr, "command", aaa->command, "length", aaa->length);
    return 0;
}

void test2(int x)
{
    int i, j;
    struct newFlashEvents aaa;
    aaa.addr =123;
    aaa.command = 11;
    aaa.length = 22;
    for(i=0; i<MAX_SIZE; i++)
        for(j=0; j<MAX_SIZE; j++)
            subscribeEvent(i, j);
    for(i=0; i<MAX_SIZE; i++)
        for(j=0; j<MAX_SIZE; j++)
            subscribeEvent(i, j);
    for(i = 0; i< x; i++)
        subscribeEventCheck(i, &aaa, callBack);
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
    while(1)
    {
        test2(30);
    }
}

