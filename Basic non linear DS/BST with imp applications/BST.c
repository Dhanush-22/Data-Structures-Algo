#include "BST.h"
#include <stdio.h>
#include <stdlib.h>


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

int searchNode(struct node *root ,int key)
{
    if (!root) return 0;
    if (root->data == key) return 1;
    else if (root->data < key) return searchNode(root->right,key);
    else return searchNode(root->left,key); 
}

struct node * maxNode(struct node *root){
    if(root->right == NULL)
        return root;
    else
        return maxNode(root->right);   
}

int deleteleafNode(struct node **root,int data)
{
    if ((*root)->data == data){
        if ((*root)->left == NULL && (*root)->right == NULL){
            free(*root);
            *root = NULL;
            return 1;
        }
        else{
            printf("Can't delete %d as it is not a leaf node\n",data);
            return 0;
        }
    }
    if (data < (*root)->data)
        return deleteNode(&((*root)->left),data);
    else
        return deleteNode(&((*root)->right),data);

}

int deleteNode(struct node **root,int data)
{
    if (!(*root)) return 0; //key not found
    if (data < (*root)->data)
        return deleteNode(&((*root)->left),data);
    else if (data > (*root)->data)
        return deleteNode(&((*root)->right),data);
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
            return deleteNode(&((*root)->left),maxnode->data);
        }
    }

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

int* path(struct node *root,int n1){
    if (!searchNode(root,n1)) return 0;
    if (!root) return 0;
    int *arr = (int *)malloc(sizeof(int)*100);
    int i=1;
    int count = 0;
    while (root){
        if (root->data > n1){
            arr[i++] = root->data;
            count++;
            root = root->left;
        }
        else if(root->data < n1){
            arr[i++] = root->data;
            count++;
            root = root->right;
        }
        else{
            arr[i++] = root->data;
            count++;
            arr[0] = count;
            return arr;
        }
    }
}

int pathBetweenNodes(struct node *root, int n1, int n2)
{
    int *arr1, *arr2;
    arr1 = path(root,n1);
    arr2 = path(root,n2);
    int c1 = arr1[0];
    int c2 = arr2[0];
    int i,j,k;
    //case 1 : Root to node
    if(n1 == root->data){
        for(int i=1;i<c2;i++)
            printf("%d->",arr2[i]);
        printf("%d",arr2[c2]);
        printf("\n");
        free(arr1);
        free(arr2);
        return 1;
    }

    //case 2 : node to root
    if (n2 == root->data){
        for(int i=c1;i>1;i--)
            printf("%d->",arr1[i]);
        printf("%d",arr2[1]);
        printf("\n");
        free(arr1);
        free(arr2);
        return 1;
    }

    //case 3 : when both on different trees
    for (k=1;k<c1 && k<c2;k++){
        if (arr1[k]== arr2[k] && arr1[k+1] != arr2[k+1])
            break;
    }
    if (k==c2){
        for(k=c1;k>c2;k--)
            printf("%d->",arr1[k]);
        printf("%d\n",arr1[c2]);
    }
    else if (k==c1){
        for(k;k<c2;k++)
            printf("%d->",arr2[k]);
        printf("%d\n",arr2[c2]);
    }
    else{
        i=c1;
        j=k+1;
        while (i >= k)
            printf("%d->",arr1[i--]);
        for (j;j<c2;j++)
            printf("%d->",arr2[j]);
        printf("%d",arr2[c2]);
        printf("\n");
    }
    free(arr1);
    free(arr2);
    return 1;
}

int destroyTree(struct node **root){
    if (!(*root)) return 1;
    else{
        destroyTree(&((*root)->left));
        destroyTree(&((*root)->right));
        deleteNode(&(*root),(*root)->data);
    }
}


//Queue

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


//STACK
int init3(struct stack **s)
{
    *s = (struct stack *)malloc(sizeof(struct stack));
    if(!(*s)) return 0;
    (*s)->top = -1;
    return 1;
}

int isEmpty3(struct stack *s) {return (s->top == -1)? 1:0;}
int isFull3(struct stack *s) {return (s->top == 99)? 1:0;}

int push(struct stack *s, struct node *n)
{
    if(isFull3(s))
        return 0;
    s->top++;
    s->arr[s->top] = n;
    return 1;
}

int peek(struct stack *s, struct node **node)
{
    if (isEmpty3(s))
        return 0;
    *node = s->arr[s->top];
    return 1;
}

int pop(struct stack *s, struct node **node)
{
    if (isEmpty3(s))
        return 0;
    *node = s->arr[s->top];
    s->top--;
    return 1;
}

int destroy3(struct stack **s)
{
    free(*s);
    *s = NULL;
    return 1;
}

//iterative traversals
int itInorder(struct node *root)
{
    struct stack *s;
    struct node *temp = NULL;
    init3(&s);
    while(root || !isEmpty3(s))
    {
        if (root)
        {
            push(s,root);
            root = root->left;
        }
        else{
            pop(s,&temp);
            printf("%d ",temp->data);
            root = temp->right;
        }
    }    
}

int itPreOrder(struct node *root)
{
    struct stack *s;
    struct node *temp = NULL;
    init3(&s);
    while(root || !isEmpty3(s))
    {
        if (root)
        {
            printf("%d ",root->data);
            push(s,root);
            root = root->left;
        }
        else{
            pop(s,&temp);
            root = temp->right;
        }
    }
}

int count(struct node *root)
{
    int x,y;
    if(root)
    {
        x=count(root->left);
        y=count(root->right);
        return x+y+1;
    }
    return 0;
}

int countLeaf(struct node *root)
{
    struct Queue *q;
    init2(&q);

    if (!root) return 0;
    enqueue(q,root);
    struct node *temp;
    int Leafcount, deg1, deg2;
    Leafcount=deg1=deg2=0;

    while (!isEmpty(q))
    {
        dequeue(q,&temp);
        if(!temp->left && !temp->right)
            Leafcount++;
        if(!temp->left && temp->right)
            deg1++;
        if(temp->left && !temp->right)
            deg1++;
        if(temp->left && temp->right)
            deg2++;
        if (temp->left)
            enqueue(q,temp->left);
        if (temp->right)
            enqueue(q,temp->right);
    }
    printf("Leaf Nodes %d\n",Leafcount);
    printf("Degree 1 : %d\n",deg1);
    printf("Degree 2 : %d\n",deg2);
    destroy2(&q);
    return 1;
}

int height(struct node *root)
{
    int x,y;
    x=y=0;
    if (!root)
        return 0;
    x = height(root->left);
    y = height(root->right);
    if (x>y) return x+1;
    else return y+1;
}

int checkAVL(struct node *root)
{
    struct Queue *q = NULL;
    init2(&q);
    int leftHeight, rightHeight;
    enqueue(q,root);
    struct node *temp = NULL;
    while(!isEmpty(q))
    {
        leftHeight = rightHeight = 0;
        dequeue(q,&temp);
        if (temp->left)
            leftHeight = height(temp->left);
        if (temp->right)
            rightHeight = height(temp->right);
        //printf("Node %d left height is %d right height is %d\n",temp->data,leftHeight,rightHeight);
        if (leftHeight - rightHeight >= 2 || leftHeight - rightHeight <= -2)
        {
            destroy2(&q);
            printf("Not an AVl\n");
            return 0;
        }
        else{
            if (temp->left)
                enqueue(q,temp->left);
            if (temp->right)
                enqueue(q,temp->right);
        }
    }
    printf("It is an AVL tree\n");
    return 1;
}


int getLeafCount(struct node *root)
{
    if (!root) return 0;
    else if (!root->left && !root->right)
        return 1;
    else
        return getLeafCount(root->right) + getLeafCount(root->left);
}
int getFullCount(struct node *root)
{
    if (!root) return 0;
    else
        return 1+getFullCount(root->right) + getFullCount(root->left);
}