#include "Hash.h"
#include "Node.h"

#include <stdlib.h>

#ifndef _LRU_Cache_
#define _LRU_Cache_

#define TableMaxSize 10000

typedef struct stLRU_Cache{
    stHashTable* HashTable;
    
    stNode  *Head , *Tail;

    int Capacity , CurrentSize;
}stLRU_Cache;

void PrintLRU_Cache(stLRU_Cache* LRU_Cache);

stLRU_Cache* CreateLRU_Cache(int Capacity);
int LRU_CacheGet(stLRU_Cache* LRU_Cache , int Key);
void LRU_CachePut(stLRU_Cache* LRU_Cache , int Key , int Value);
void LRU_CacheFree(stLRU_Cache* LRU_Cache);

#endif