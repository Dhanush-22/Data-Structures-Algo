#ifndef QUEUEDECL1_H_ // To include Guard
#define QUEUEDECL1_H_

struct Node{
    int data;
    struct Node *next;
};

struct Queue{
    struct Node *head;
    struct Node *tail;
};

int init(struct Queue **);
int isEmpty(struct Queue *);
int isFull(struct Queue *);

int getFront(struct Queue *,int *);
int getRear(struct Queue *,int *);

int enqueue(struct Queue *,int);
int dequeue(struct Queue *,int *);

int destroy(struct Queue **);

#endif