#include "avlDec.h"
#include <stdio.h>
#include <stdlib.h>

int nodeHeight(struct node *p){
    int hl,hr;
    if (!p) return 0;
    hl = (p && p->left)? p->left->height:0;
    hr = (p && p->right)? p->right->height:0;
    return (hl>hr)? (hl+1):(hr+1);
}

int balanceFactor(struct node *p){
    int hl,hr;
    if (!p) return 0;
    hl = (p && p->left)? p->left->height:0;
    hr = (p && p->right)? p->right->height:0;
    return (hl-hr);
}

struct node* LLcase(struct node **root,struct node *p)
{
    struct node *b = p->left;


    p->left = b->right;
    b->right = p;

    p->height = nodeHeight(p);
    b->height = nodeHeight(b);

    if((*root)==p) *root = b;
    return b;
}

struct node * RRcase(struct node **root,struct node *a)
{
    //printf("RR case %d\n",a->data);
    struct node *b = a->right;
    //struct node *c = b->right;

    a->right = b->left;                          //   a  (-2)               b
    b->left = a;                                 //     \                  /  \
                                                 //       b               a     c
    a->height = nodeHeight(a);                   //      /  \              \        
    b->height = nodeHeight(b);                   //    (BL)   c            (BL)

    if((*root)==a) *root = b;
    return b;

}

struct node * LRcase(struct node **root,struct node *a)
{
    struct node *b = a->left;
    struct node *c = b->right;

    a->left = c->right;
    b->right = c->left;

    c->left = b;
    c->right = a;

    a->height = nodeHeight(a);
    b->height = nodeHeight(b);
    c->height = nodeHeight(c);

    if ((*root)==a) *root = c;
    return c;
}

struct node * RLcase(struct node **root,struct node *a)
{
    struct node *b = a->right;
    struct node *c = b->left;

    a->right = c->left;
    b->left = c->right;

    c->right = b;
    c->left = a;

    a->height = nodeHeight(a);
    b->height = nodeHeight(b);
    c->height = nodeHeight(c);

    if ((*root)==a) *root = c;
    return c;
}

struct node* insertNode(struct node **root,struct node *p, int key)
{
    struct node *newNode = NULL;
    if (!p){
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = key;
        newNode->height = 1;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (p->data > key) p->left = insertNode(root,p->left,key);
    else if (p->data < key) p->right = insertNode(root,p->right,key);

    p->height = nodeHeight(p);

    //Balancing tree
    if (balanceFactor(p) == 2 && (balanceFactor(p->left) == 1 || balanceFactor(p->left) == 0)) return LLcase(root,p);
    else if (balanceFactor(p) == 2 && (balanceFactor(p->left) == -1|| balanceFactor(p->left) == 0) ) return LRcase(root,p);
    else if (balanceFactor(p) == -2 && (balanceFactor(p->right) == -1|| balanceFactor(p->right) == 0)) return RRcase(root,p);
    else if (balanceFactor(p) == -2 && (balanceFactor(p->right) == 1 || balanceFactor(p->right) == 0)) return RLcase(root,p);
    
    return p;
}

int searchNode(struct node *root ,int key)
{
    if (!root) return 0;
    if (root->data == key) return 1;
    if (root->data > key) return searchNode(root->left,key);
    else return searchNode(root->right,key);
}

int deleteNode(struct node **root,int key){
    if (!(*root)) return 0;
    //Locating the node
    if ((*root)->data > key) return deleteNode(&((*root)->left),key);
    else if ((*root)->data < key) return deleteNode(&((*root)->right),key);
    //after locating the node
    else{
        struct node *temp = *root;
        if((*root)->left == NULL){
            (*root) = (*root)->right;
            free(temp);
        }
        else if((*root)->right == NULL){
            (*root) = (*root)->left;
            free(temp);
        }
        else{ //has both sub trees
            struct node *maxNode = (*root)->left;
            while(maxNode->right)
                maxNode = maxNode->right;
            (*root)->data = maxNode->data;
            deleteNode(&((*root)->left),maxNode->data);
        }
    }
} 

struct node * DeleteAVL(struct node **root,struct node *p, int key)
{
    if (!p) return NULL;
    if (p->data > key)
        p->left = DeleteAVL(root,p->left,key);
    else if (p->data < key) 
        p->right = DeleteAVL(root,p->right,key);
    else{
        //printf("Found\n");
        //Element found 
        struct node *nodesLeft = p->left;
        struct node *nodesRight = p->right;
        struct node *temp = p;
        if(nodesLeft == NULL){
            p = p->right;
            free(temp);
        }
        else if(nodesRight == NULL){
            p=p->left;
            free(temp);
        }
        else{ //has both sub trees
            struct node *maxNode = p->left;
            while(maxNode->right)
                maxNode = maxNode->right;
            p->data = maxNode->data;
            p->left = DeleteAVL(root,p->left,maxNode->data);

        }

    }
    if (p) {
        p->height = nodeHeight(p);
    }

    //Balancing tree
    if (balanceFactor(p) == 2 && (balanceFactor(p->left) == 1 || balanceFactor(p->left) == 0)) return LLcase(root,p);
    else if (balanceFactor(p) == 2 && (balanceFactor(p->left) == -1|| balanceFactor(p->left) == 0) ) return LRcase(root,p);
    else if (balanceFactor(p) == -2 && (balanceFactor(p->right) == -1 || balanceFactor(p->right) == 0)) return RRcase(root,p);
    else if (balanceFactor(p) == -2 && (balanceFactor(p->right) == 1 || balanceFactor(p->right) == 0)) return RLcase(root,p);
    
    return p;
}



int inorder(struct node *p){
    //LVR
    if(!p) return 1;
    inorder(p->left);
    printf("%d ",p->data);
    inorder(p->right);
}

int preorder(struct node *root)
{
    //VLR
    if (!root) return 0;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);

}
int postorder(struct node *root)
{
    //LRV
    if (!root) return 0;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int destroyTree(struct node **root){
    if (!(*root)) return 1;
    else{
        destroyTree(&((*root)->left));
        destroyTree(&((*root)->right));
        deleteNode(&(*root),(*root)->data);
    }
}




//Queue (FOR LEVEL ORDER)

int init2(struct Queue **q){
    *q = (struct Queue *)malloc(sizeof(struct Queue));
    if (!(*q))
        return 0;
    (*q)->front = -1;
    (*q)->rear = -1;
    return 1;
}


int isFull(struct Queue *q){
    return (q->rear == SIZE-1)? 1:0;
}

int isEmpty(struct Queue *q){
    return (q->front == -1)? 1:0;
}


int enqueue(struct Queue *q,struct node *n){
    if (isFull(q)) 
        return 0;
    q->rear++;
    q->arr[q->rear] = n;
    if (q->front == -1)
        q->front++;
    return 1;
}

int dequeue(struct Queue *q,struct node **n){
    if (isEmpty(q))
        return 0;
    *n = q->arr[q->front];
    for (int i=q->front; i < q->rear;i++){
        q->arr[i] = q->arr[i+1]; 
    }
    q->rear--;
    if (q->rear == -1)
        q->front--;
    return 1;
}

int destroy2(struct Queue **q){
    free(*q);
    *q = NULL;
    return 1;
}

int levelOrder(struct node *root)
{
    struct Queue *q;
    init2(&q);
    if (!root) return 0;
    enqueue(q,root);
    struct node *temp;
    while (!isEmpty(q))
    {
        dequeue(q,&temp);
        printf("%d ",temp->data);
        if (temp->left) enqueue(q,temp->left);
        if (temp->right) enqueue(q,temp->right);
    }
    destroy2(&q);
    return 1;
}

