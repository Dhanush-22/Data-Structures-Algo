#ifndef BST_H
#define BST_H

struct node {
    struct node *left;
    int data;
    struct node *right;
};

#define SIZE 1000
struct Queue{
    struct node* arr[SIZE];
    int front;
    int rear;
};

int insertNode(struct node **, struct node *);
int searchNode(struct node * ,int);
int deleteNode(struct node **,int);

//recursive traversals
int inorder(struct node *);
int preorder(struct node *);
int postorder(struct node *);
int levelOrder(struct node *);

//Main operations (Standard methods)
int pathBetweenNodes(struct node *, int, int);
int checkAVL(struct node *);
int count(struct node *); //No. of ith degree nodes
int count(struct node *);
int countLeaf(struct node *);
int height(struct node *);

//iterative traversals
int itInorder(struct node *);
int itPreOrder(struct node *);



int destroyTree(struct node **);


//Queue to implement level order traversal

int init2(struct Queue **);

int isEmpty(struct Queue *);
int isFull(struct Queue *);

int enqueue(struct Queue *,struct node * );
int dequeue(struct Queue *,struct node **);

int destroy2(struct Queue **);


//STACK for iterative traversals

struct stack{
    struct node *arr[100];
    int top;
};

int init3(struct stack **s);
int isEmpty3(struct stack *s);
int isFull3(struct stack *s);
int push(struct stack *s, struct node *n);
int peek(struct stack *s, struct node **node);
int pop(struct stack *s, struct node **node);
int destroy3(struct stack **s);

#endif