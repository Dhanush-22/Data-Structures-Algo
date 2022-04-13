#include "queueDecl.h"
#include "queueDef.c"
#include <stdio.h>


int main()
{
    int data = 0;
    struct Queue *q;
    init(&q);
    for (int i=1;i<=10;i++)
        enqueue(q,i);
    display(q);

    getFront(q,&data);
    printf("Front : %d\n",data);

    getRear(q,&data);
    printf("Rear : %d\n",data);

    dequeue(q,&data);
    dequeue(q,&data);

    getFront(q,&data);
    printf("Rear : %d\n",data);

    while(!isEmpty(q)){
        dequeue(q,&data);
        //display(q);
    }
    printf("\n");
    destroy(&q);
}