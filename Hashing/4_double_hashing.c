#include <stdio.h>
#define SIZE 10

struct element{
    int flag;
    int value;
};


int checkPrime(int n){
    int flag = 0;
    for(int i=2; (i*i)<= n; i++)
        if(n%i == 0)
            return 0;
    return 1;
}
int getNearestPrime(int n)
{
    int num=n-1;
    if(checkPrime(num)) return num;
    else return getNearestPrime(num);
}
int R;

int hashFun(int ele) {
    return (ele%SIZE);
}
int hash2(int ele) {
    return (R - (ele % R));
}

int insert(struct element h[], int key)
{
    int idx;
    for(int i=0;i<SIZE;i++){
        idx = (hashFun(key) + i*(hash2(key)))%SIZE;
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
        idx = (hashFun(key) + i*(hash2(key)))%SIZE;
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
        idx = (hashFun(key) + i*(hash2(key)))%SIZE;
        if (h[idx].value == key){
            h[idx].flag = 0;
            return 1;
        }
    }
}

void traverseHT(struct element h[])
{
    for(int i=0;i<SIZE;i++){
        if(h[i].flag == 1)
            printf("%d ",h[i].value);
        else if (h[i].flag == 0)
            printf("-1 ");
    }
    printf("\n");
}

int main()
{
    struct element h[SIZE];
    R = getNearestPrime(SIZE);

    for(int i=0;i<SIZE;i++){
        h[i].flag=0;
        h[i].value=-1;
    }

    int arr[] = {5,25,15,35,95};
    int n = sizeof(arr)/sizeof(int);

    for(int i=0;i<n;i++){
        insert(h,arr[i]);
    }
    
    traverseHT(h);
    search(h,95);
    deleteKey(h,95);
    deleteKey(h,15);
    printf("After performing delete operation on 95 and 15 \n");
    traverseHT(h);
    insert(h,11);
    traverseHT(h);
    search(h,35);
    return 0;
}