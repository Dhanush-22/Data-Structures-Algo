#include <stdio.h>
#include <stdlib.h>
#include "heapDec.h"


int init(struct heap **s){
    *s = (struct heap *)malloc(sizeof(struct heap));
    if (!(*s)) return 0;
    (*s)->heapSize = 0;
    return 1;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int findMax(struct heap *h, int *max){
    if (h->heapSize == 0) return 0;
    *max = h->arr[1];
    return 1;
}

void maxHeapify(int *arr, int i, int heapSize)
{
    int maxIdx = i;
    int lIdx = 2*i;
    int rIdx = 2*i + 1;
    if (lIdx <= heapSize && arr[lIdx] > arr[maxIdx]) maxIdx = lIdx;
    if (rIdx <= heapSize && arr[rIdx] > arr[maxIdx]) maxIdx = rIdx;
    if (maxIdx != i){
        swap(&arr[maxIdx],&arr[i]);
        maxHeapify(arr,maxIdx,heapSize);
    }
    return ;
}

void display(struct heap *h){
    for(int i=1; i<=h->heapSize; i++)
        printf("%d ",h->arr[i]);
    printf("\n");
}


int extractMax(struct heap *h, int *max)
{
    if (h->heapSize == 0) return 0;
    *max = h->arr[1];
    h->arr[1] = h->arr[h->heapSize];
    h->heapSize--;
    maxHeapify(h->arr,1,h->heapSize);
    return 1;
}

int increaseKey(struct heap *h, int pos, int newKey)
{
    if (pos > h->heapSize || newKey < h->arr[pos]) return 0;
    h->arr[pos] = newKey;
    while (pos >= 1 && h->arr[pos/2] < h->arr[pos]){
        swap(&h->arr[pos/2],&h->arr[pos]);
        pos = pos/2;
    }
    return 1;
}

int insertElement(struct heap *h, int element)
{
    if (h->heapSize >= SIZE) return 0;
    h->heapSize++;
    h->arr[h->heapSize] = -1;
    increaseKey(h,h->heapSize,element);
    return 1;
}

int deleteElement(struct heap *h, int pos){
    if (h->heapSize == 0 || h->heapSize < pos) return 0;
    int max = h->arr[1];
    increaseKey(h,pos,max+10);
    int temp;
    extractMax(h,&temp);
    return 1;
}

int * heapSort(struct heap *h){
    if (h->heapSize == 0) return 0;

    int *arr = (int *)malloc(sizeof(int)*h->heapSize);
    int arrSize = h->heapSize;
    int n = h->heapSize;
    //Copy all elements
    for(int i=0; i<= arrSize;i++) arr[i] = h->arr[i];

    for(int i=n;i>=1;i--){
        swap(&arr[1],&arr[i]);
        arrSize--;
        maxHeapify(arr,1,arrSize);
    }

    //printf("\n");
    //free(ans);
    return arr;
}

int destroy(struct heap **h){
    free(*h);
    *h = NULL;
    return 1;
}