/********************************************************************************
* 																				*
* ADT Max Heap Binario, implementado utilizando un arreglo y elementos desde la *
* posicion 0		 															*
* 																				*
********************************************************************************/

#ifndef ADT_BINARYHEAP_H_
#define ADT_BINARYHEAP_H_

#include <stdlib.h>
#include <stdio.h>

typedef struct binaryHeap{
	int maxSize;
	int lastElement;
	int* elements;
}BinaryHeap;

void testHeapify();
void testBuildHeap();

BinaryHeap* createHeap(int maxSize);
void heapify(BinaryHeap* h, int i);
BinaryHeap* buildHeap(int* elements, int size);
void insert(BinaryHeap* h, int element);
int deleteMax(BinaryHeap* h);
int searchMax(BinaryHeap* h);
int size_heap(BinaryHeap* h);

void swap(int* a, int* b);
int leftChild(int nodeIndex);
int rightChild(int nodeIndex);
int parent(int nodeIndex);

#endif /* ADT_BINARYHEAP_H_ */
