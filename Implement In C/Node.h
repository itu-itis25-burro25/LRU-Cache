#ifndef _Node_
#define _Node_

typedef struct stNode{
    int Key;
    int Value;
    struct stNode* Next;
    struct stNode* Previous;
}stNode;

#endif