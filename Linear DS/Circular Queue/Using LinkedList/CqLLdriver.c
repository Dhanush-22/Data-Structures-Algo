#include "CqLLDecl.h"
#include "CqLLDef.c"
#include <stdio.h>

int main()
{
    struct Queue *q;
    int data;
    init(&q);
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    traverse(q);
    dequeue(q,&data);
    traverse(q);
    destroy(&q);
    return 0;
}