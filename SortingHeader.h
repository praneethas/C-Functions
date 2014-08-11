#ifndef SORTINGHEADER_H_
#define SORTINGHEADER_H_
#if defined __cplusplus
    extern "C" {
#endif

/**

General Utilities

**/
void swapNum(int* p, int* q);
void printArray(int *array, int n);
int maxVal(int a, int b);
int minVal(int a, int b);

/**

Header file definitions for Heapsort in c

**/
int leftChild(int *array, int i, int n);
int rightChild(int *array, int i, int n);
void MaxHeapify(int *array, int i, int n);
void buildMaxHeap(int *array, int start, int n);
int extractMax(int *array);
void treeReOrderMaxHeap(int *a, int begin, int end);
int* heapSort(int *array, int n);
void heapSortInPlace(int *array, int n);

#ifdef __cplusplus
	}
#endif
#endif
