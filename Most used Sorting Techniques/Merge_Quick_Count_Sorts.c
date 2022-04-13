#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void display(int arr[],int n){
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");
    return ;
}
void display2(int arr[],int i, int j)
{
    for(int k=i;k<=j;k++) printf("%d ",arr[k]);
    printf("\n");
}

int bubbleSort(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if (arr[j]>arr[j+1]) swap(&arr[j+1],&arr[j]);
    return 1;
}
int insertionSort(int arr[], int n)
{
    int minIdx, key;
    for (int i=1; i<n; i++){
        key = arr[i];
        minIdx = i-1;

        while(minIdx >=0 && key < arr[minIdx]){
            arr[minIdx+1] = arr[minIdx];
            minIdx--;
        }
        if (i != minIdx+1) arr[minIdx+1] = key;
    }
    return 1;
}
int selectionSort(int arr[], int n)
{
    int minIdx;
    for(int i=0; i<n-1; i++)
    {
        minIdx = i;
        for(int j=i+1; j<n; j++)
        {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        if (minIdx != i)
            swap(&arr[i],&arr[minIdx]);
    }
    return 1;
}
int mergeArr(int arr[],int p,int q, int r){
    //display2(arr,p,r);
    int leftArr[q-p+1 +1], rightArr[r-q +1];
    int i,j,k;
    i=k=0;
    leftArr[q-p+1] = 10000;
    rightArr[r-q] = 10000;

    //Copy array elements
    for(int idx=p;idx<=q;idx++) leftArr[i++] = arr[idx];
    for(int idx=q+1;idx<=r;idx++) rightArr[k++] = arr[idx];
    i=k=j=0;
    //display(leftArr,sizeof(leftArr)/sizeof(int));
    //display(rightArr,sizeof(rightArr)/sizeof(int));

    for(int k=p;k<=r;k++){
        if(leftArr[i] < rightArr[j]) arr[k] = leftArr[i++];
        else arr[k] = rightArr[j++];
    }
    //display(arr,r-p+1);
    return 1;
}
int mergeSort(int arr[],int startIdx, int endIdx)
{
    if (endIdx > startIdx){
        int midIdx = (startIdx+endIdx)/2;
        mergeSort(arr,startIdx,midIdx);
        mergeSort(arr,midIdx+1,endIdx);
        //printf("counter : %d\n",counter++);
        //display2(arr,startIdx,midIdx);
        //display2(arr,midIdx+1,endIdx);
        mergeArr(arr,startIdx,midIdx,endIdx);
        //display2(arr,startIdx,endIdx);
    }
}
int getPartition(int arr[],int startIdx, int endIdx)
{
    int i = startIdx-1;
    int key = arr[endIdx];
    for(int j=startIdx; j<endIdx;j++){
        if (arr[j] <= key){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[endIdx]);
    return i+1;
}

int quickSort(int arr[],int startIdx, int endIdx){
    int partitionIdx;
    if (endIdx > startIdx){
        partitionIdx = getPartition(arr,startIdx,endIdx);
        quickSort(arr,startIdx,partitionIdx-1);
        quickSort(arr,partitionIdx+1,endIdx);
    }
    return 1;
}

int * mergeTwoLists(int A[], int B[], int m, int n){
    if (!m | !n) return 0;
    int i,j,k;
    i=j=k=0;
    int *C = (int *)malloc(sizeof(int)*(m+n));
    while (i<m && j<n){
        if (A[i] < B[j])
            C[k++] = A[i++];
        else
            C[k++] = B[j++];
    }

    while (i<m)
        C[k++] = A[i++];
    while (j<n)
        C[k++] = B[j++];
    display(C,m+n);
    return C;
}

int countSort(int arr[], int n)
{
    int max = arr[0];
    //Find max
    for(int i=1;i<n;i++)
        if (arr[i] > max) max = arr[i];

    int count[max+1];


    //Initialize all to zero
    for(int i=0;i<=max+1;i++)
        count[i] = 0;

    for(int i=0;i<n;i++)
        count[arr[i]]++;

    //display(b,max+1);
    
    int j,k;
    j=k=0;

    while(j<=max+1){
        if (count[j] != 0){
            arr[k++] = j;
            count[j]--;
        }
        else j++;
    }
    printf(">");
    return 1;
}

int radixSort();
int bucketSort();

int main()
{
    int arr1[] = {2,7,3,5,6,4};
    int arr2[] = {1,2,4,-5,-4};
    int arr3[] = {6,3,9,10,15,6,8,12,3,6};
    int arr4[] = {2,7,3,5,6,4};
    int arr5[] = {7,6,2,5,4};
    int arr6[] = {6,3,9,10,15,6,8,12,3,6};

    int n1 = sizeof(arr1)/sizeof(int);
    int n2 = sizeof(arr2)/sizeof(int);
    int n3 = sizeof(arr3)/sizeof(int);
    int n4 = sizeof(arr4)/sizeof(int);
    int n5 = sizeof(arr5)/sizeof(int);
    int n6 = sizeof(arr6)/sizeof(int);

    printf("Before Sorting : ");
    display(arr1,n1);
    bubbleSort(arr1,n1);
    printf("After Sorting using bubble sort : ");
    display(arr1,n1);

    printf("Before Sorting : ");
    display(arr2,n2);    
    insertionSort(arr2,n2);
    printf("After Sorting using insertion sort : ");
    display(arr2,n2);

    printf("Before Sorting : ");
    display(arr3,n3);
    selectionSort(arr3,n3); 
    printf("After Sorting using selection sort : ");
    display(arr3,n3);

    printf("Before Sorting : ");
    display(arr4,n4);
    countSort(arr4,n4);
    printf("After Sorting using count sort : ");
    display(arr4,n4); 

    printf("Before Sorting : ");
    display(arr5,n5);
    mergeSort(arr5,0,n5-1);
    printf("After Sorting using merge sort : ");
    display(arr5,n5);

    printf("Before Sorting : ");
    display(arr6,n6);
    quickSort(arr6,0,n6-1);
    printf("After Sorting using quick sort : ");
    display(arr6,n6);

    return 0;
}