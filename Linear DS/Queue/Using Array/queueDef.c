#include "queueDecl.h"
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
    for (int i=q->front;i<=q->rear;i++)
        printf("%d ",q->arr[i]);
    printf("\n");
}

int isFull(struct Queue *q){
    return (q->rear == SIZE-1)? 1:0;
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
    if (isFull(q)) 
        return 0;
    q->rear++;
    q->arr[q->rear] = data;
    if (q->front == -1)
        q->front++;
    return 1;
}

int dequeue(struct Queue *q, int *dataptr){
    if (isEmpty(q))
        return 0;
    for (int i=q->front; i < q->rear;i++){
        q->arr[i] = q->arr[i+1]; 
    }
    q->rear--;
    if (q->rear == -1)
        q->front--;
    return 1;
}

int destroy(struct Queue **q){
    free(*q);
    *q = NULL;
    return 1;
}