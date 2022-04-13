#ifndef STACKDECLARATION_H_   /* Include guard */
#define STACKDECLARATION_H_
#define SIZE 1000
struct stack
{
    int arr[SIZE];
    int top;
};



int init(struct stack **);
int isEmpty(struct stack *);
int isFull(struct stack *);
int push(struct stack *, int );
int peek(struct stack *, int *);
int pop(struct stack **, int *);
int destroy(struct stack **);

#endif


