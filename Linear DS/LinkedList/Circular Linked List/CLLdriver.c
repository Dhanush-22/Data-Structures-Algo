#include "CLLDecl.h"
#include "CLLDef.c"
#include <stdio.h>

int main()
{
    struct Node *tail;
    struct Node *keyPtr = NULL;
    init(&tail);
    insertAfterNode(&tail,-1,50);
    insertAfterNode(&tail,50,1);
    //traverse(tail);
    for (int i=10;i>1;i--){
        insertAfterNode(&tail,1,i); //insertAfterNode(struct Node **tail, int pre, int data)
        traverse(tail);
    }
    deleteElement(&tail,5);
    deleteElement(&tail,6);
    searchElement(tail,4,&keyPtr);
    if(keyPtr)
        printf("Found %d\n",keyPtr->data);
    destroy(&tail);
    traverse(tail);
    return 0;
}