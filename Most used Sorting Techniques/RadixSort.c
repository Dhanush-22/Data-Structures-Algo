#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int level = 0;

int isSorted(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
        if(arr[i] > arr[i+1])
            return 0;
    return 1;
}

int insertNode(struct node **head, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    //if(!(*head)) *head = newNode;
    newNode->next = *head;
    *head = newNode;
}

int deleteNode(struct node **head, int *dataPtr)
{
    if (!*head) return 0;
    *dataPtr = (*head)->data;
    *head = (*head)->next;
    return 1;
}

void display(struct node *head)
{
    if(!head) {
        // printf("-1\n");
        return;
    }
    while(head)
    {
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
}

void displayArr(int arr[],int n)
{
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int destroy(struct node **head)
{
    struct node *temp = NULL;
    while(*head)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    return 1;
}


int powe(int a, int n)
{
    if(n==0)
        return 1;
    else 
        return a*powe(a,n-1);
}

void traverse(struct node *ptrArr[])
{
    for(int i=0;i<10;i++)
        display(ptrArr[i]);
}

int radixSort(struct node *ptrArr[], int arr[], int n)
{
    int idx;
    int temp;
    while(!isSorted(arr,n))
    {
        printf("Level : %d\n",level);
        for(int i=n-1;i>=0;i--)
        {
            idx = (arr[i]/powe(10,level))%10;
            insertNode(&ptrArr[idx],arr[i]);
        }
        // traverse(ptrArr);

        //copy back to array
        int j=0;
        for(int i=0;i<10;i++)
        {
            while(ptrArr[i])
            {
                deleteNode(&ptrArr[i],&temp);
                arr[j++] = temp;
            }
        }
        displayArr(arr,n);
        printf("\n");
        level++;
    }

}

int main()
{
    struct node *ptrArr[10];

    //initialize all to NULL
    for(int i=0;i<10;i++)
        ptrArr[i] = NULL;
    // int arr[] = {25,36,46,15,20};
    int arr[] = {2512,3687,4654,1521,1982,2513,4655};
    int n = sizeof(arr)/sizeof(int);
    radixSort(ptrArr,arr,n);
    return 0;
}