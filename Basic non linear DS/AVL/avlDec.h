#ifndef AVLDEC_H
#define AVLDEC_H

struct node {
    struct node *left;
    int data,height;
    struct node *right;
};

struct node* insertNode(struct node **,struct node *, int );
struct node* DeleteAVL(struct node **,struct node *, int );
int searchNode(struct node * ,int);
int deleteNode(struct node **,int);


int nodeHeight(struct node *p);
int balanceFactor(struct node *p);

//Imbalance correctors
struct node * LLcase(struct node **root,struct node *p);
struct node * RRcase(struct node **root,struct node *p);
struct node * LRcase(struct node **root,struct node *p);
struct node * RLcase(struct node **root,struct node *p);

//Recursive traversals
int inorder(struct node *);
int preorder(struct node *);
int postorder(struct node *);
int levelOrder(struct node *);

//int leftRotation(struct node **root);
//int rightRotation(struct node **root);

int destroyTree(struct node **);

//for level order traversal
#define SIZE 1000
struct Queue{
    struct node* arr[SIZE];
    int front;
    int rear;
};

//Queue

int init2(struct Queue **);

int isEmpty(struct Queue *);
int isFull(struct Queue *);

int enqueue(struct Queue *,struct node * );
int dequeue(struct Queue *,struct node **);

int destroy2(struct Queue **);


#endif
