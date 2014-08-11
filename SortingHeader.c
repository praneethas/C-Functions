#include <stdio.h>
#include <stdlib.h>
#include "SortingHeader.h"

void swapNum(int* p, int* q)
{
        int temp = *p;
        *p = *q;
        *q = temp;
}

void printArray(int *array, int n)
{
        int i;
        for(i=0;i<n;i++)
        {
            printf("%d ",*(array+i));
        }
        printf("\n");
}

int maxVal(int a, int b)
{
    return (a>b?a:b);
}

int minVal(int a, int b)
{
    return (a<b?a:b);
}





int leftChild(int *array, int i, int n)
{
    if(2*i+1 < n)
    {
        return 2*i+1;
    }
    else{
        return -1;
    }
}

int rightChild(int *array, int i, int n)
{
    if(2*i+2 < n)
    {
        return 2*i+2;
    }
    else{
        return -1;
    }
}

void MaxHeapify(int *array, int i, int n)
{
    int left = leftChild(array, i, n);
    int right = rightChild(array, i, n);
    if(left == -1)
    {
        *(array+left) = -1;
    }
    if(right == -1)
    {
        *(array+right) = -1;
    }
    int largest, heapSize = n;
    if (left < heapSize && *(array+left) > *(array+i))
    {
        largest = left;
    }
    else
    {
        largest = i;
    }
    if (right < heapSize && *(array+right) > *(array+largest))
    {
        largest = right;
    }
    if (*(array+largest) != *(array+i))
    {
        swapNum(array+i, array+largest);
    }
}


void buildMaxHeap(int *array, int start, int n)
{
    int heapSize = n, i;
    //int start = 0;
    for(i=start;i<heapSize;i++)
    {
        MaxHeapify(array, i, heapSize);
    }
}

int extractMax(int *array)
{
    return *(array+0);
}

void treeReOrderMaxHeap(int *a, int begin, int end)
{
    int start = begin, swapChild, lChild;
    while(start*2+1 < end)
    {
        lChild = start*2 + 1;
        swapChild = start;

        if (a[swapChild] < a[lChild])
        {
            swapChild = lChild;
        }
        if (lChild+1 < end && a[swapChild] < a[lChild+1])
        {
            swapChild = lChild + 1;
        }
        if (swapChild != start)
        {
            swapNum(a+start, a+swapChild);
            start = swapChild;
        }
        else
            return;
    }
}

int* heapSort(int *array, int n)
{
    int temp,i;
    int heapsize = n;
    buildMaxHeap(array, 0, heapsize);
    int *newArray = (int*)malloc(n*sizeof(int));
    for(i=0;i<=n-1;i++)
    {
        treeReOrderMaxHeap(array, 0, heapsize);
        *(newArray+i) = *(array+0);
    	temp=*(array+0);
        *(array+0)=*(array+(heapsize-1));
        *(array+(heapsize-1))=temp;

        heapsize--;

    }
    return newArray;
 }

void heapSortInPlace(int *array, int n)
{
    int temp,i;
    int heapsize = n;
    buildMaxHeap(array, 0, heapsize);
    printArray(array, n);
    for(i=0;i<=n-1;i++)
    {
        /*temp=*(array+0);
        *(array+0)=*(array+(heapsize-1));
        *(array+(heapsize-1))=temp;*/

        //heapsize--;
        //treeReOrderMaxHeap(array, i+1, heapsize-1);
        //buildMaxHeap(array, i, heapsize);
        treeReOrderMaxHeap(array, i, heapsize);
        printArray(array, n);
    }
}
