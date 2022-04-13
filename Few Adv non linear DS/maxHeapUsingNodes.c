#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

struct node 
{
    int data;
    struct node *left,*right,*parent;
};

struct Queue {
    struct node* arr[SIZE];
    int front,rear;
};

//Queue

int init(struct Queue **q){
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

int destroy(struct Queue **q){
    free(*q);
    *q = NULL;
    return 1;
}


int levelOrder(struct node *root)
{
    struct Queue *q;
    init(&q);
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
    printf("\n");
    destroy(&q);
    return 1;
}


struct node * getNode(int x,struct node *p)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->left = newNode->right = NULL;
    newNode->parent = p;
    return newNode;
}

int ins(struct node **root,int x)
{
    if(!(*root))
    {
        *root = getNode(x,NULL);
        return 1;
    }
    else{
        struct Queue *q = NULL;
        init(&q);
        struct node *currentNode = *root;
        enqueue(q,currentNode);
        struct node *temp = NULL; //for dequeue node
        struct node *newNode = NULL;
        int flag = 0;
        while(!isEmpty(q)){
            dequeue(q,&currentNode);
            if (currentNode->left == NULL)
            {
                newNode = getNode(x,currentNode);
                currentNode->left = newNode;
                currentNode = newNode;
                flag = 1;
            }
            else if (currentNode->right == NULL)
            {
                newNode = getNode(x,currentNode);
                currentNode->right = newNode;
                currentNode = newNode;
                flag = 1;
            }
            else{
                if (currentNode->left)
                    enqueue(q,currentNode->left);
                if (currentNode->right)
                    enqueue(q,currentNode->right);
            }
            int temp;
            if (flag == 1){
                while(currentNode->parent && currentNode->data > currentNode->parent->data)
                {
                    temp = currentNode->data;
                    currentNode->data = currentNode->parent->data;
                    currentNode->parent->data = temp;
                    currentNode = currentNode->parent;
                }
                break;
            }
        }
        destroy(&q);
        return 1;
    }
}


int maxHeapify(struct node *root, int nodeData)
{
    struct Queue *q;
    init(&q);
    enqueue(q,root);
    struct node *currentNode = NULL;
    int flag = 0;
    while(!isEmpty(q))
    {
        dequeue(q,&currentNode);
        if(currentNode->data == nodeData)
            break;
        else
        {
            if (currentNode->left)
                enqueue(q,currentNode->left);
            if (currentNode->right)
                enqueue(q,currentNode->right);
        }
        
    }
    int maxData;
    int temp;
    struct node *maxDataNode = NULL;
    while(1){
        maxDataNode = currentNode;
        maxData = maxDataNode->data;
        if (currentNode->left && currentNode->left->data > maxData){
            maxDataNode = currentNode->left;
            maxData = maxDataNode->data;
        }
        if (currentNode->right && currentNode->right->data > maxData){
            maxDataNode = currentNode->right;
            maxData = maxDataNode->data;
        }
        if (maxDataNode == currentNode){
            break;
        }
        else{
            temp = currentNode->data;
            currentNode->data = maxData;
            maxDataNode->data = temp;
            currentNode = maxDataNode;
            levelOrder(root);
        }
    }
    destroy(&q);
}


int extractMax(struct node *root, int *dataPtr)
{
    if(!root) return 0;
    *dataPtr = root->data;
    root->data = -1;
    maxHeapify(root,root->data);
    return 1;
}

int main()
{
    int arr[] = {80,60,40,100,30,120,10};
    int n = sizeof(arr)/sizeof(int);
    struct node *root = NULL;
    for(int i=0;i<n;i++)
    {
        ins(&root,arr[i]);
        levelOrder(root);
    }

    int temp;
    extractMax(root,&temp);
    printf("Max is %d\n",temp);
    levelOrder(root);

    extractMax(root,&temp);
    printf("Max is %d\n",temp);
    levelOrder(root);

    return 0;
}