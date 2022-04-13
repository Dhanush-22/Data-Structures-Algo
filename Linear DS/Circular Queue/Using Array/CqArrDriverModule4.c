#include "CqArrDec.h"
#include "CqArrDef.c"
#include <stdio.h>

int main()
{
    struct Queue *q;  //Take array size as 6
    int data = 0;
    init(&q);
    enqueue(q,1);
    enqueue(q,2);

    enqueue(q,3);
    enqueue(q,4);

    enqueue(q,5);
    enqueue(q,6);
    enqueue(q,7);

    display(q);

    dequeue(q,&data);
    dequeue(q,&data);

    enqueue(q,7);
    enqueue(q,8);
    display(q);


    dequeue(q,&data);
    dequeue(q,&data);
    dequeue(q,&data);
    dequeue(q,&data);
    display(q);
    return 0;
}