#include "CqLLDecl.h"
#include <stdio.h>
#include <stdlib.h>

int init(struct Queue **q){
    (*q)->tail = NULL;
    return 1;
}

int isEmpty(struct Queue *q){
    if (!q->tail)
        return 1;
    return 0;
}

int isFull(struct Queue *q){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode){
        return 1;
    }
    free(newNode);
    return 0; 
}

int getFront(struct Queue *q,int *dataPtr){
    if (isEmpty(q))
        return 0;
    *dataPtr = q->tail->next->data;
    return 1;
}

int getRear(struct Queue *q,int *dataPtr){
    if (isEmpty(q))
        return 0;
    *dataPtr = q->tail->data;
    return 1;
}

int enqueue(struct Queue *q,int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode) return 0;
    newNode->data = data;
    if(q->tail){
        newNode->next = q->tail->next;
        q->tail->next = newNode;
        q->tail = newNode;
        return 1;
    }
    newNode->next = newNode;
    q->tail = newNode;
    return 1;
}

int dequeue(struct Queue *q,int *dataPtr){
    if(isEmpty(q)) return 0;
    struct Node *temp = q->tail->next;
    if(temp == q->tail)
        q->tail = NULL;
    else
        q->tail->next = temp->next;
    free(temp);
    return 1;
}

int traverse(struct Queue *q){
    struct Node *it = q->tail->next;
    do{
        printf("%d ",it->data);
        it = it->next;
    } while(it != q->tail->next);
    printf("\n");
    return 1;
}

int destroy(struct Queue **q){
    int dummy;
    while(!isEmpty(*q)){
        dequeue(*q,&dummy);
    }
    *q = NULL;
    return 1;
}
