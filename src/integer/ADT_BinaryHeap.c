/********************************************************************************
* 																				*
* ADT Max Heap Binario, implementado utilizando un arreglo y elementos desde la *
* posicion 0		 															*
* 																				*
********************************************************************************/
#include "ADT_BinaryHeap.h"

void testHeapify(){
	int maxSize = 10;
	int lastElement = 2;
	int e[] = {1,2,3};
	int i;

	BinaryHeap* h = createHeap(maxSize);
	h->elements = e;
	h->lastElement = lastElement;

	heapify(h,1);

	for(i=0;i<=h->lastElement;i++){
		printf("%d ",h->elements[i]);
	}
}

void testBuildHeap(){
	int size = 5;
	int e[] = {1,2,3,4,5};
	int i;

	BinaryHeap* h = buildHeap(e,size);

	for(i=0;i<=h->lastElement;i++){
		printf("%d ",h->elements[i]);
	}
}

void testInsert(){
	BinaryHeap* h =  createHeap(15);
	insert(h,1);
	insert(h,2);
	insert(h,3);
	insert(h,4);
	insert(h,5);
	insert(h,6);

	int i;
	for(i=0; i< size_heap(h); i++){
		printf("%d ", h->elements[i]);
	}

	printf(" \n%d \n", deleteMax(h));
	printf(" \n%d \n", deleteMax(h));
	for(i=0; i<= h->lastElement; i++){
		printf("%d ", h->elements[i]);
	}

}

BinaryHeap* createHeap(int maxSize){
	BinaryHeap* h= (BinaryHeap*)malloc(sizeof(BinaryHeap));
	h->elements = (int*)malloc(sizeof(int)*(maxSize));
	h->maxSize = maxSize;
	h->lastElement = -1;
	return h;
}

void heapify(BinaryHeap* h, int i){
	if(i>=0){
		int max;
		int izq = leftChild(i);
		int der = rightChild(i);

		if(izq <= h->lastElement && h->elements[izq]>h->elements[i] ){
			max = izq;
		}
		else{
			max = i;
		}

		if(der <= h->lastElement && h->elements[der]>h->elements[max] ){
			max = der;
		}

		if(max != i){
			swap(&(h->elements[i]), &(h->elements[max]));
			heapify(h, max);
		}

	}
    else{
        fprintf(stderr, "Invalid heap index...");
        exit(EXIT_FAILURE);
    }
}

BinaryHeap* buildHeap(int* elements, int size){
	BinaryHeap* h = createHeap(size);
	h->elements = elements;
	h->lastElement = size-1;
	h->maxSize = size;

	int i;
	for(i = h->lastElement/2;i >= 0; i-- ){
		heapify(h,i);
	}
	return h;
}

void insert(BinaryHeap* h, int element){
	if(h->lastElement < h->maxSize-1){
		h->lastElement++;
		h->elements[h->lastElement] = element;
		int i = h->lastElement;

		while(i > 0 && h->elements[parent(i)] < h->elements[i]){
			swap(&(h->elements[parent(i)]),&(h->elements[i]));
			i = parent(i);
		}
	}
	else{
        fprintf(stderr, "Inserting in a full heap...");
        exit(EXIT_FAILURE);
	}
}

int deleteMax(BinaryHeap* h){
	if(h->lastElement >= 0){
		int result = h->elements[0];
		swap(&(h->elements[0]),&(h->elements[h->lastElement]));
		h->lastElement--;
		if(h->lastElement > 0){
			heapify(h,0);
		}
		return result;
	}
    else{
        fprintf(stderr, "Deleting from an empty heap...");
        exit(EXIT_FAILURE);
    }
}

int searchMax(BinaryHeap* h){
	if(h->lastElement >= 0){
		return h->elements[0];
	}
    else{
        fprintf(stderr, "Searching in an empty heap...");
        exit(EXIT_FAILURE);
    }
}

int size_heap(BinaryHeap* h){
	return h->lastElement + 1;
}
/**
 * Intercambia los valores de los enteros a y b
 */
void swap(int* a, int* b){
	int tmp=*a;
	*a=*b;
	*b=tmp;
}

int leftChild(int nodeIndex){
	return 2*nodeIndex+1;
}

int rightChild(int nodeIndex){
	return 2*nodeIndex+2;
}

int parent(int nodeIndex){
	return (nodeIndex - 1)/2;
}
