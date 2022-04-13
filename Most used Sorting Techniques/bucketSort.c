#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *next;
};

int insertNode(struct node **head, int element){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (!newNode){
        printf("Node is null\n");
        return -1;
    }
    newNode->data = element;

    if (!(*head))
        newNode->next = NULL;
    else
        newNode->next = *head;
    *head = newNode;
    return 1;
}

int deleteNode(struct node **head){
    if (!(*head)){
        printf("Head is NULL\n");
        return -1;
    }
    int deletedKey = (*head)->data;
    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
    return deletedKey;
}

void traverse(struct node *p){
    if (!p) 
        return;
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int destroy(struct node **head){
    while(*head){
        //traverse(*head);
        deleteNode(head);
    }
    //deleteNode(head);
    return 1;
}


void display(int arr[],int n){
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");
    return ;
}

int getMaxPlace(int arr[], int n)
{
    int max = arr[0];
    for(int i=1;i<n;i++)
        if(arr[i] > max) max = arr[i];
    int count = 0;
    while(max > 0)
    {
        max = max/10;
        count++;
    }
    return count;
}

int bubbleSort(struct node *head)
{
    if(!(head->next)) return 1;
    struct node *iter1, *iter2, *iter3;
    iter1 = iter2 = head;
    int temp;
    while(iter1){
        iter2 = head;
        iter3 = head->next;
        while(iter3){
            if (iter2->data > iter3->data){
                //Swap
                temp = iter2->data;
                iter2->data = iter3->data;
                iter3->data = temp;
            }
            
            iter2 = iter2->next;
            iter3 = iter3->next;
        }
        iter1 = iter1->next;
    }
}

int powerN(int a, int n)
{
    if (n==0) return 1;
    else return a*powerN(a,n-1);
}

int bucketSort(int arr[], int n)
{
    struct node **ptrArr = (struct node **)malloc(sizeof(struct node *)*10);

    for(int j=0;j<10;j++)
        ptrArr[j] = NULL;
    
    int level = getMaxPlace(arr,n)-1;
    
    for(int i=n-1; i>=0; i--)
        insertNode(&ptrArr[(arr[i]/powerN(10,level)%10)],arr[i]);
    
    for(int j=0;j<10;j++){
        if (ptrArr[j])
            bubbleSort(ptrArr[j]);
    }

    int j,k;
    j=k=0;
    int item;

    while(k<10){
        while(ptrArr[k]){
            item = deleteNode(&ptrArr[k]);
            arr[j++] = item; 
        }
        k++;
    }
    return 1;
}


int main()
{
    int arr[] = {237,146,259,348,152,163,235,48,36,62,1000,2};
    int n = sizeof(arr)/sizeof(int);
    printf("Before sorting : ");
    display(arr,n);
    bucketSort(arr,n);
    printf("After using bucket sort ");
    display(arr,n);
    return 0;
}
