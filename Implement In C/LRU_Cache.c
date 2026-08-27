#include "LRU_Cache.h"
#include "LRU_CacheHelpers.h"

#include "Hash.h"
#include "Node.h"

#include <stdio.h>

void PrintLRU_Cache(stLRU_Cache* LRU_Cache){

    stNode* CurrentNode = LRU_Cache->Head->Next;

    printf("LRU_Cache Current State: ");
    for(int i = 0; i < LRU_Cache->CurrentSize; i++){
        printf("%d " , CurrentNode->Value);
        CurrentNode = CurrentNode->Next;
    }

    printf("\n");
    
}

stLRU_Cache* CreateLRU_Cache(int Capacity){
    stLRU_Cache* LRU_Cache = malloc(sizeof(stLRU_Cache));

    LRU_Cache->Capacity = Capacity;
    LRU_Cache->CurrentSize = 0;
    LRU_Cache->HashTable = CreateHashTable(TableMaxSize);
    InitializeHashTable(LRU_Cache->HashTable);

    LRU_Cache->Head = malloc(sizeof(stNode));
    LRU_Cache->Tail = malloc(sizeof(stNode));

    LRU_Cache->Head->Next = LRU_Cache->Tail;
    LRU_Cache->Tail->Previous = LRU_Cache->Head;

    return LRU_Cache;
}

int LRU_CacheGet(stLRU_Cache* LRU_Cache , int Key){
    stHashEntry* Entry = LookUpHashTable(LRU_Cache->HashTable , Key);

    if(Entry == NULL){
        return -1;
    }else{
        DeleteFromLRU_Cache(Entry->Node);
        InsertToLRU_CacheTail(LRU_Cache , Entry->Node);

        return Entry->Node->Value;
    }
}

void LRU_CachePut(stLRU_Cache* LRU_Cache , int Key , int Value){
    stHashEntry* Entry = LookUpHashTable(LRU_Cache->HashTable , Key);

    if(Entry != NULL){
        Entry->Node->Value = Value;
        DeleteFromLRU_Cache(Entry->Node);
        InsertToLRU_CacheTail(LRU_Cache , Entry->Node);
    }else{

        stNode* NewNode = malloc(sizeof(stNode));
        NewNode->Key = Key;NewNode->Value = Value;NewNode->Next = NULL;NewNode->Previous = NULL;

        if(LRU_Cache->CurrentSize < LRU_Cache->Capacity){
            InsertToHashTable(LRU_Cache->HashTable , Key , NewNode);
            
            InsertToLRU_CacheTail(LRU_Cache , NewNode);
            LRU_Cache->CurrentSize++;
        }else{
            DeleteFromHashTable(LRU_Cache->HashTable , LRU_Cache->Head->Next);
            InsertToHashTable(LRU_Cache->HashTable , Key, NewNode);

            stNode* TempNode = LRU_Cache->Head->Next;
            DeleteFromLRU_Cache(LRU_Cache->Head->Next);
            free(TempNode);

            InsertToLRU_CacheTail(LRU_Cache , NewNode);
            
        }
    }
}

void LRU_CacheFree(stLRU_Cache* LRU_Cache){

    stNode* CurrentNode = LRU_Cache->Head->Next;
    while(CurrentNode != LRU_Cache->Tail){
        stNode* TempNode = CurrentNode;
        CurrentNode = CurrentNode->Next;

        free(TempNode);
    }

    free(LRU_Cache->Head);
    free(LRU_Cache->Tail);

    free(LRU_Cache->HashTable->Table);
    free(LRU_Cache->HashTable);

    free(LRU_Cache);
}
