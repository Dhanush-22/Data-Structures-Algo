#include <stdio.h>
#include <stdlib.h>
#include "splayDec.h"

//Rotations
struct node * zig(struct node **root, struct node *p)
{
   struct node *pl = p->left;
   p->left = pl->right;
   pl->right = p;
   if(*root == p) *root = pl;
   return pl;
}  

struct node * zag(struct node **root, struct node *p) 
{
   struct node *pr = p->right;
   p->right = pr->left;
   pr->left = p;
   if(*root == p) *root = pr;
   return pr;
}


struct node *splay(struct node **Mainroot,struct node *root, int key)
{
    if (root == NULL || root->data == key)
        return root;
 
    if (root->data > key)
    {
        if (root->left == NULL) return root;
 
        if (root->left->data > key) //Zig Zig
        {
            root->left->left = splay(Mainroot,root->left->left, key);
            root = zig(Mainroot,root);
        }
        else if (root->left->data < key) // Zig-Zag (Left Right)
        {
            root->left->right = splay(Mainroot,root->left->right, key);
            if (root->left->right != NULL)
                root->left = zag(Mainroot,root->left);
        }


        return zig(Mainroot,root);
    }
    else
    {
        if (root->right == NULL) return root;
 
        // Zig-Zag
        if (root->right->data > key)
        {
            root->right->left = splay(Mainroot,root->right->left, key);
            if (root->right->left != NULL)
                root->right = zig(Mainroot,root->right);
        }
        else if (root->right->data < key)
        {
            root->right->right = splay(Mainroot,root->right->right, key);
            root = zag(Mainroot,root);
        }
 
        return zag(Mainroot,root);
    }
}

int insertNode(struct node **root, struct node *newNode)
{
    if (!(*root)){
        *root = newNode;
        return 1;
    }
    if (newNode->data < (*root)->data)
        return insertNode(&((*root)->left),newNode);
    else
        return insertNode(&((*root)->right),newNode);
}

int insertMyNode(struct node **root,int element)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = element;
    newNode->left = newNode->right = NULL;
    insertNode(root,newNode);

    splay(root,*root,element);
    printf("After splay operation, level order : ");
    levelOrder(*root);
    printf("\n");
    return 1;
}



int searchNode(struct node **Mainroot,struct node *root ,int key)
{
    if (!root) return 0;
    if (root->data == key){
        splay(Mainroot,*Mainroot,key);
        return 1;
    }
    else if (root->data < key) return searchNode(Mainroot,root->right,key);
    else return searchNode(Mainroot,root->left,key); 
}

struct node * maxNode(struct node *root){
    if(root->right == NULL)
        return root;
    else
        return maxNode(root->right);   
}

int deleteMyNode(struct node **root,int data)
{
    if (!(*root)) return 0; //key not found
    if (data < (*root)->data)
        return deleteMyNode(&((*root)->left),data);
    else if (data > (*root)->data)
        return deleteMyNode(&((*root)->right),data);
    else{
        struct node *temp;
        if((*root)->left == NULL){
            temp = *root;
            *root = (*root)->right;
            free(temp);
            return 1;
        }
        else if ((*root)->right == NULL){
            temp = *root;
            *root = (*root)->left;
            free(temp);
            return 1;
        }
        else{
            struct node *maxnode = maxNode((*root)->left);
            (*root)->data = maxnode->data;
            return deleteMyNode(&((*root)->left),maxnode->data);
        }
    }

} 


int deleteNode(struct node **root,int data){
    if (!(*root)) return 0;
    if (!(searchNode(root,*root,data))) return 0;
    deleteMyNode(root,data);
    return 1;
}

int inorder(struct node *root){
    //LVR
    if (!root) return 0;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
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


   
