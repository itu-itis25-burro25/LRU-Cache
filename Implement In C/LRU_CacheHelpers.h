#include "LRU_Cache.h"

#ifndef _LRU_CacheHelpers_
#define _LRU_CacheHelpers_

void DeleteFromLRU_Cache(stNode* DeletedNode);
void InsertToLRU_CacheTail(stLRU_Cache* LRU_Cache , stNode* InsertedNode);

#endif