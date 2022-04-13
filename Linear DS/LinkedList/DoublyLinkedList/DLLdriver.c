#include "DLLDec.h"
#include "DLLDef.c"
#include <stdio.h>

int main(){
    struct node *head;
    struct node *tail;

    init(&head,&tail);

    insertElement(&head,&tail,1,1);
    insertElement(&head,&tail,2,2);
    insertElement(&head,&tail,3,1);
    insertElement(&head,&tail,4,4);
    insertElement(&head,&tail,2,5);
    insertElement(&head,&tail,3,6);

    traverse(head,tail,1);
    traverse(head,tail,0);
/*
    deleteElement(&head,&tail,1);
    traverse(head,tail,1);
    traverse(head,tail,0);

    deleteElement(&head,&tail,8);
    traverse(head,tail,1);
    traverse(head,tail,0); */

    reverse(&head,&tail);
    traverse(head,tail,1);
    traverse(head,tail,0);

    destroy(&head);
    return 0;
}