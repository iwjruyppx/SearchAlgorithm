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


void test3(int x)
{
    subscribeEvent(1000, 1000);
    subscribeEvent(11, 11);
    subscribeEvent(50, 50);
    subscribeEvent(1200, 1200);
    subscribeEvent(30, 30);
    subscribeEvent(66, 66);
    subscribeEvent(77, 77);
    subscribeEvent(88, 88);
    subscribeEvent(99, 99);
    subscribeEvent(1111, 1111);
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
        test3(30);
    }
}

