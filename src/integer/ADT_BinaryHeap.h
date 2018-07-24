/********************************************************************************
* 																				*
* ADT Max Binary Heap using arrays (elements from 0)							*
* 																				*
********************************************************************************/

#ifndef ADT_BINARYHEAP_H_
#define ADT_BINARYHEAP_H_

#include <stdlib.h>
#include <stdio.h>

typedef struct hb_heap{
	int maxSize;
	int lastElement;
	int* elements;
}hb_Heap;

void hb_testHeapify();
void hb_testBuildHeap();

hb_Heap*hb_create(int maxSize);
void hb_heapify(hb_Heap*h, int i);
hb_Heap*hb_build(int* elements, int size);
void hb_insert(hb_Heap*h, int element);
int hb_deleteMax(hb_Heap*h);
int hb_searchMax(hb_Heap*h);
int hb_size(hb_Heap*h);

void hb_swap(int* a, int* b);
int hb_leftChild(int nodeIndex);
int hb_rightChild(int nodeIndex);
int hb_parent(int nodeIndex);

#endif /* ADT_BINARYHEAP_H_ */
