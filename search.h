
#ifndef __SEARCH_H
#define __SEARCH_H

#define SEARCH_NON  0
#define SEARCH_ERROR_EMPTY  -1
#define SEARCH_ERROR_FULL  -2
#define SEARCH_ERROR_EXISTED  -3

typedef struct
{
    int memSize;
    void *mem;
    int useSize;
}searchMem_t;

void *searchIndex(searchMem_t *mem, int index);
int searchNodeAdd(searchMem_t *mem, int index, void *ptr);
int searchNodeDel(searchMem_t *mem, int index);
void searchInit(searchMem_t *mem);

#endif /* __SEARCH_H */
