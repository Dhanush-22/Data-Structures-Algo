#include "CqArrDec.h"
#include <stdio.h>
#include <stdlib.h>


int init(struct Queue **q){
    *q = (struct Queue *)malloc(sizeof(struct Queue));
    if (!(*q))
        return 0;
    (*q)->front = -1;
    (*q)->rear = -1;
    return 1;
}
void display(struct Queue *q){
    if (isEmpty(q)) return;
    for (int i=q->front;1;i++){
        if (i == SIZE)
            i=i%SIZE;
        printf("%d ",q->arr[i]);
        if (i == q->rear)
            break;      
    }
    printf("\n");
}


int isFull(struct Queue *q){
    if (q->front ==0 && q->rear == SIZE-1)
        return 1;
    if (q->rear - q->front == -1)
        return 1;
    return 0;
}

int isEmpty(struct Queue *q){
    return (q->front == -1)? 1:0;
}

int getFront(struct Queue *q,int *dataptr){
    if (isEmpty(q))
        return 0;
    *dataptr = q->arr[q->front];
    return 1;
}

int getRear(struct Queue *q,int *dataptr){
    if (isEmpty(q))
        return 0;
    *dataptr = q->arr[q->rear];
    return 1;
}

int enqueue(struct Queue *q,int data){
    if (isFull(q)){
        return 0;
    }
    q->rear++;
    if (q->rear >= SIZE)
        q->rear = (q->rear)%SIZE; //printf("Here\n");
    q->arr[q->rear] = data;
    if (q->front == -1) //When this is the first item in queue
        q->front++;
    return 1;
}

int dequeue(struct Queue *q, int *dataptr){
    if (isEmpty(q))
        return 0;
    
    *dataptr = q->arr[q->front];
    if (q->front == q->rear){
        q->front = -1;
        q->rear = -1;
        return 1;
    }
    q->front++;
    if (q->front >= SIZE)
        q->front = q->front%SIZE;
    return 1;
}

int destroy(struct Queue **q){
    free(*q);
    *q = NULL;
    return 1;
}