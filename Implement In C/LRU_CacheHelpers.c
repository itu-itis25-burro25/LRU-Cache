#include "LRU_CacheHelpers.h"


void DeleteFromLRU_Cache(stNode* DeletedNode){
    DeletedNode->Previous->Next = DeletedNode->Next;
    DeletedNode->Next->Previous = DeletedNode->Previous;
}
void InsertToLRU_CacheTail(stLRU_Cache* LRU_Cache , stNode* InsertedNode){
    InsertedNode->Next = LRU_Cache->Tail;
    InsertedNode->Previous = LRU_Cache->Tail->Previous;

    LRU_Cache->Tail->Previous->Next = InsertedNode;
    LRU_Cache->Tail->Previous = InsertedNode;
}
