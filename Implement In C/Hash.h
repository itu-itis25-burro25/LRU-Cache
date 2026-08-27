#include "Node.h"

#include <stdio.h>
#include <stdbool.h>

#ifndef _HASH_
#define _HASH_

typedef enum enState {Empty , Full , Deleted} enState;

typedef struct stHashEntry{
    stNode* Node;
    enState State;
}stHashEntry;
typedef struct stHashTable{
    stHashEntry* Table;
    int Size;
}stHashTable;

stHashTable* CreateHashTable(int Size);
int HashFunction(stHashTable* HashTable , int Key);
void InitializeHashTable(stHashTable* HashTable);

bool InsertToHashTable(stHashTable* HashTable , int Key  , stNode*  InsertedNode);
bool DeleteFromHashTable(stHashTable* HashTable , stNode* DeletedNode);

stHashEntry* LookUpHashTable(stHashTable* HashTable , int Key);

#endif