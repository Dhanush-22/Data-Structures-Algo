#include "stackDeclaration.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/*
#define SIZE 1000
struct stack
{
    int arr[SIZE];
    int top;
};
*/



int init(struct stack **s)
{
    *s = (struct stack *)malloc(sizeof(struct stack));
    if (*s == NULL) {return 0;}
    (*s)->top = -1;
    return 1;
}

int isEmpty(struct stack *s)
{
    if (s->top == -1) {return 1;}
    return 0;
}

int isFull(struct stack *s)
{
    if(s->top == SIZE-1)
     {
         printf("STACK is full");
         return 1;
    }
    return 0;
}
int push(struct stack *s, int data)
{
    if (isFull(s)) return 0;
    (s->top)++;
    s->arr[s->top] = data;
    return 1;
}

int peek(struct stack *s, int *dataPtr)
{
    if (isEmpty(s)) return 0;
    *dataPtr = s->arr[s->top];
    return 1; 
}

int pop(struct stack **s, int *dataPtr)
{
    if (isEmpty(*s)) 
        return 0;
    *dataPtr = (*s)->arr[(*s)->top];
    (*s)->top = (*s)->top - 1;
    return 1;
}

int destroy(struct stack **s)
{
    free(*s);
    *s = NULL;
    return 1;
}
