#include "queueDecl1.h"
#include "queueDef1.c"
#include <stdio.h>

int main()
{
    int data;
    struct Queue *q;
    init(&q);
    for (int i=1;i<=10;i++)
        enqueue(q,i*i);
    display(q);

    getFront(q,&data);
    printf("Front : %d\n",data);

    getRear(q,&data);
    printf("Rear : %d\n",data);

    dequeue(q,&data);

    getFront(q,&data);
    printf("Front : %d\n",data);

    while (!isEmpty(q))
        dequeue(q,&data);
        //display(q)
    destroy(&q);
    return 0;
}