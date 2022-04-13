#include "heapDec.h"
#include "heapDef.c"


int main()
{
    int a[] = {-1,30,80,15,40,100,60,50};
    struct heap *h;
    init(&h);
    int n = sizeof(a)/sizeof(int);
    for(int i=1;i<n;i++)
        insertElement(h,a[i]);
    display(h);

    int *sortedArr = heapSort(h);
    printf("Sorted array : ");
    for(int i=1; i<= h->heapSize;i++) printf("%d ",sortedArr[i]);

    printf("\nAfter deleting an element at index 2 : ");
    deleteElement(h,2);
    display(h);

    printf("After deleting an element at index 1 : ");
    deleteElement(h,1);
    display(h);

    printf("After deleting an element at index 4 : ");
    deleteElement(h,4);
    display(h);

    destroy(&h);
    free(sortedArr);
    return 0;    
}