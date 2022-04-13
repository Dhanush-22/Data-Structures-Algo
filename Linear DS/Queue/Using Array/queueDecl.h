#ifndef QUEUEDECL_H_ // To include Guard
#define QUEUEDECL_H_

#define SIZE 1000
struct Queue{
    int arr[SIZE];
    int front;
    int rear;
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

