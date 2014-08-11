#include <stdio.h>
#include <stdlib.h>

#include "SortingHeader.h"

int main()
{
    int array[] = {25, 21, 20, 5, 10, 12, 15, 8, 2, 6, 2, 9};
    int n = (int)sizeof(array)/sizeof(array[0]),i;
    int *newArray = (int*)malloc(n*sizeof(int));
    int *newArray1 = (int*)malloc(n*sizeof(int));
    printf("Before Heapsort:\n");
    printArray(array, n);
    printf("After Heapsort:\n");
    newArray = heapSort(array, n);
    printArray(newArray, n);
    printArray(array, n);
    /*printf("Before Heapsort Inplace:\n");
    printArray(array, n);
    printf("After Heapsort Inplace:\n");
    heapSortInPlace(array, n);
    printArray(array, n);*/
    return 0;
}
