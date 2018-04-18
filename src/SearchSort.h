#ifndef SEARCH_H_
#define SEARCH_H_

#endif /* SEARCH_H_ */

#include <stdbool.h>
#include "ADT_List_DoubleLinked.h"

int binarySearch(int* array, int size, int key);
int linearSearch(int* array, int size, int key);

void testPartitionHoare();
void testQuickSort();
void quickSort(int a[], int l, int r);
void quickSortG(int a[], int l, int r);
int partitionHoare(int a[], int l, int r);
int partitionHoareG(int a[], int l, int r);
void swap(int* a, int* b);

void testQuickSortList();
void quickSortGList(List* list, int l, int r);
int partitionHoareGList(List* list, int l, int r);
void swapList(List* list, int a, int b);

void testInsertionSort();
void insertionSort(int a[], int size);

void testSelectionSort();
void selectionSort(int a[], int size);

void testBubbleSort();
void bubbleSort(int a[], int size);