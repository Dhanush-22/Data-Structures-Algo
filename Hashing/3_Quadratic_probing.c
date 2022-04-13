#include <stdio.h>
#define SIZE 10

struct element{
    int flag;
    int value;
};


int hashFun(int ele) {
    return (ele%SIZE);
}

int insert(struct element h[], int key)
{
    int idx;
    for(int i=0;i<SIZE;i++){
        idx = (hashFun(key) + (i*i))%SIZE;
        if (h[idx].value == -1 | h[idx].flag == 0){
            h[idx].value = key;
            h[idx].flag = 1;
            return 1;
        }
    }
}

int search(struct element h[], int key)
{
    int idx;
    for(int i=0; i<SIZE;i++)
    {
        idx = (hashFun(key) + (i*i))%SIZE;
        if (h[idx].value == key){
            if (h[idx].flag == 0){
                printf("Element %d not found\n",key);
                return 0;
            }
            printf("Element %d found\n",key);
            return 1;
        }
        else if (h[idx].value == -1){
            printf("Element %d not found\n",key);
            return 0;
        }
    }
    printf("Element not found\n");
    return 0;
}

int deleteKey(struct element h[],int key)
{
    int idx;
    if(!search(h,key)) return 0;
    for(int i=0;i<SIZE;i++)
    {
        idx = (hashFun(key) + (i*i))%SIZE;
        if (h[idx].value == key){
            h[idx].flag = 0;
            return 1;
        }
    }
}

void traverseHT(struct element h[])
{
    for(int i=0;i<SIZE;i++)
        //if(h[i].flag == 1)
            printf("%d ",h[i].value);
    printf("\n");
}

int main()
{
    struct element h[SIZE];

    for(int i=0;i<SIZE;i++){
        h[i].flag=0;
        h[i].value=-1;
    }

    int arr[] = {23,43,13,27};
    int n = sizeof(arr)/sizeof(int);

    for(int i=0;i<n;i++)
        insert(h,arr[i]);
    
    traverseHT(h);
    search(h,13);
    deleteKey(h,13);
    search(h,13);
    search(h,74);

    return 0;
}