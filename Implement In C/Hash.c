#include "Hash.h"
#include "Node.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

stHashTable* CreateHashTable(int Size){
    stHashTable* HashTable = malloc(sizeof(stHashTable));

    HashTable->Size = Size;
    HashTable->Table = malloc(sizeof(stHashEntry)*Size);
    
    return HashTable;
}
void InitializeHashTable(stHashTable* HashTable){
    for(int i = 0; i < HashTable->Size; i++){
        HashTable->Table[i].Node = NULL;
        HashTable->Table[i].State = Empty;
    }
}

int HashFunction(stHashTable* HashTable , int Key){
      int Result = 0;

    for(int i = 0; i < 10; i++){
        Result += Key;
        Result = (Result*Result) % HashTable->Size;
    }

    return Result;
}

bool InsertToHashTable(stHashTable* HashTable , int Key , stNode* InsertedNode){
    int Index = HashFunction(HashTable , Key);

    int i = Index;
    do{

        if(HashTable->Table[i].State != Full){
            HashTable->Table[i].Node =  InsertedNode;
            HashTable->Table[i].State = Full;

            return true;
        }

        i = (i + 1) % HashTable->Size;
    }while(i != Index);

    return false;
}
bool DeleteFromHashTable(stHashTable* HashTable , stNode* DeletedNode){
    int Index = HashFunction(HashTable , DeletedNode->Key);

    int i = Index;
    do{

        if(HashTable->Table[i].State != Empty){
            if(HashTable->Table[i].State == Full && HashTable->Table[i].Node->Key == DeletedNode->Key){
                HashTable->Table[i].Node = NULL;
                HashTable->Table[i].State  = Deleted;

                return true;
            }
        }else{
            return false;
        }

        i = (i + 1) % HashTable->Size;
    }while(i != Index);

    return false;
}

stHashEntry* LookUpHashTable(stHashTable* HashTable , int Key){
    int Index = HashFunction(HashTable , Key);

    int i = Index;
    do{

        if(HashTable->Table[i].State != Empty){
            if(HashTable->Table[i].State == Full && HashTable->Table[i].Node->Key == Key){
                return &HashTable->Table[i];
            }
        }else{
            return NULL;
        }

        i = (i + 1) % HashTable->Size;
    }while(i != Index);

    return NULL;
}
