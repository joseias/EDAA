#ifndef SEARCH_H_
#define SEARCH_H_

#endif /* SEARCH_H_ */

#include <stdbool.h>
#include "ADT_List_DoubleLinked.h"

void testSearch();
int linearSearchSortedArray(int* array, int size, int key);
int binarySearch(int* array, int size, int key);
int binarySearchRec(int* array, int left, int right, int key);


void testPartitionHoare();
void testQuickSort();
void quickSort(int a[], int l, int r);
void quickSortG(int a[], int l, int r);
int partitionHoare(int a[], int l, int r);
int partitionHoareG(int a[], int l, int r);
void swap(int* a, int* b);

void testQuickSortList();
void quickSortGList(ll_List* list, int l, int r);
int partitionHoareGList(ll_List* list, int l, int r);
void swapList(ll_List* list, int a, int b);

void testInsertionSort();
void insertionSort(int a[], int size);

void testSelectionSort();
void selectionSort(int a[], int size);
