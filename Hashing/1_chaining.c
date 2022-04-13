#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

int insert(struct node **head,int ele)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if(!newNode) return 0;
    newNode->data = ele;
    newNode->next = NULL;
    if(!(*head)){
        *head = newNode;
        return 1;
    }
    struct node *iter = *head;
    struct node *iterFolower = NULL;
    while(iter && iter->data < ele){
        iterFolower = iter;
        iter = iter->next;
    }
    if(iter == *head){
        newNode->next = iter;
        *head = newNode;
        return 1;
    }

    iterFolower->next = newNode;
    newNode->next = iter;
    return 1;  
}

void traverse(struct node *it){
    if(!it) return;
    while(it){
        printf("%d ",it->data);
        it = it->next;
    }
    printf("\n");
}

int searchNode(struct node *it, int key)
{
    while (it && it->data != key && it->data < key)
        it = it->next;
    if (it && it->data == key){
        printf("Element %d is found\n",key);
        return 1;
    }
    printf("Element %d is not found\n",key);
    return 0;
}

int deleteNode(struct node **head, int key)
{
    struct node *it, *itFollower;
    it = *head;
    itFollower = NULL;

    while(it && it->data != key && it->data < key){
        itFollower = it;
        it = it->next;
    }

    if (it && it->data == key)
    {
        if(!itFollower){
            *head = (*head)->next;
        }
        else{
            itFollower->next = it->next;
        }
        free(it);
        return 1;
    }
    printf("Element %d to be deleted is not found\n",key);
    return 0;   
}

int destroy(struct node **head){
    struct node *temp = NULL;
    while(*head){
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    return 1;
}

int hashFunc(int ele, int m) {
    return (ele%m);
}

int createHashTable(struct node **ht, int m, int arr[], int n)
{
    //initialize all to NULL
    for(int i=0;i<m;i++) ht[i] = NULL;
    int idx;

    for(int i=0;i<n;i++)
    {
        idx = hashFunc(arr[i],m);
        insert(&ht[idx],arr[i]);
    }
}

void traverseHT(struct node **ht,int m)
{
    //traverse through hashTable
    for(int j=0;j<m;j++)
        if(ht[j])
            traverse(ht[j]);
}

int insertKey(struct node **ht, int m,int key)
{
    int idx = hashFunc(key,m);
    return insert(&ht[idx],key); 
}

int searchKey(struct node **ht, int m, int key)
{
    int idx = hashFunc(key,m);
    return searchNode(ht[idx],key);
}

int deleteKey(struct node **ht, int m, int key){
    int idx = hashFunc(key,m);
    return deleteNode(&ht[idx],key);
}

int destroyHt(struct node **ht,int m)
{
    for(int i=0;i<m;i++)
        if(ht[i])
            destroy(&ht[i]);
    ht = NULL;
    return 1;
}

int main()
{
    int m = 10;
    struct node **ht = (struct node **)malloc(sizeof(struct node *)*m);
    int arr[] = {16,12,25,39,6,122,5,68,75};

    createHashTable(ht,m,arr,sizeof(arr)/sizeof(int));

    insertKey(ht,m,2);
    insertKey(ht,m,1);

    traverseHT(ht,m);

    searchKey(ht,m,1);
    deleteKey(ht,m,26);
    searchKey(ht,m,25);
    searchKey(ht,m,132);
    searchKey(ht,m,2);


    destroyHt(ht,m);
    return 0;
}