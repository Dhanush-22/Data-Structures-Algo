#ifndef SPLAYDEC_H
#define SPLAYDEC_H

struct node {
    struct node *left;
    int data;
    struct node *right;
};

//Operations
int insertNode(struct node **, struct node *);
int searchNode(struct node **,struct node * ,int);
int deleteNode(struct node **,int);


//Rotations
struct node* zig(struct node **root, struct node *p);
struct node* zag(struct node **root, struct node *p);


//Traversals
int inorder(struct node *);
int preorder(struct node *);
int postorder(struct node *);
int levelOrder(struct node *);
int destroyTree(struct node **);


//QUEUE for level order

#define SIZE 1000
struct Queue{
    struct node* arr[SIZE];
    int front;
    int rear;
};

int init2(struct Queue **);
int isFull(struct Queue *);
int isEmpty(struct Queue *);
int enqueue(struct Queue *,struct node *);
int dequeue(struct Queue *,struct node **);
int destroy2(struct Queue **);


#endif
