#ifndef HEAPDEC_H
#define HEAPDEC_H

#define SIZE 1000

struct heap{
    int arr[SIZE];
    int heapSize;
};

int init(struct heap **);

int findMax(struct heap *, int *);
void maxHeapify(int *, int , int );
int extractMax(struct heap *, int *);
int increaseKey(struct heap *, int, int);

int insertElement(struct heap *, int );
int deleteElement(struct heap *, int );
int * heapSort(struct heap *);

int destroy(struct heap **);


#endif