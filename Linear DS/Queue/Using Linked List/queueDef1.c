#include "queueDecl1.h"
#include <stdio.h>
#include <stdlib.h>


int init(struct Queue **q){
    *q = (struct Queue*)malloc(sizeof(struct Queue));
    if (!(*q))
        return 0;
    (*q)->head = NULL;
    (*q)->tail = NULL;
}

int isEmpty(struct Queue *q){ return (!(q->head))? 1:0;}

int isFull(struct Queue *q){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode){
        free(newNode);
        return 1;
    }
    free(newNode);
    return 0;
}


int getFront(struct Queue *q,int *dataPtr){
    if (isEmpty(q))
        return 0;
    *dataPtr = q->head->data;
    return 1;
}

int getRear(struct Queue *q,int *dataPtr){
    if (isEmpty(q))
        return 0;
    *dataPtr = q->tail->data;
    return 1;
}

void display(struct Queue *q){
    struct Node *it = q->head;
    while (it){
        printf("%d ",it->data);
        it = it->next;
    }
    printf("\n");
}

int enqueue(struct Queue *q,int data){
    if (isFull(q)) return 0;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if(!q->tail){  //If queue is empty
        q->tail = newNode;
        q->head = newNode;
        return 1;
    }
    q->tail->next = newNode;
    q->tail = newNode;
    return 1;
}

int dequeue(struct Queue *q,int *dataPtr){
    if (isEmpty(q))
        return 0;

    struct Node *temp = q->head;
    q->head = q->head->next;
    free(temp);

    if (!q->head)
        q->tail = NULL;
    
    return 1;
}

int destroy(struct Queue **q){
    while((*q) != NULL){
        struct Node *temp = (*q)->head;
        (*q)->head = (*q)->head->next;
        free(temp);
    }
    return 1;
}