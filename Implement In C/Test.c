#include "LRU_Cache.h"

int main(void){
    stLRU_Cache* LRU_Cache = CreateLRU_Cache(3);

    LRU_CachePut(LRU_Cache ,  1 , 10);
    LRU_CachePut(LRU_Cache , 2 , 30);
    LRU_CachePut(LRU_Cache , 3 , 50);

    PrintLRU_Cache(LRU_Cache);

    LRU_CachePut(LRU_Cache , 29 , 33);

    PrintLRU_Cache(LRU_Cache);

    LRU_CachePut(LRU_Cache , 21 , 530);
    LRU_CachePut(LRU_Cache , 2 , 30);

    PrintLRU_Cache(LRU_Cache);

    LRU_CacheGet(LRU_Cache , 21);
    
    PrintLRU_Cache(LRU_Cache);

    LRU_CacheGet(LRU_Cache , 29);

    PrintLRU_Cache(LRU_Cache);

    LRU_CacheFree(LRU_Cache);
}