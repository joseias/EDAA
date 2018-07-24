/********************************************************************************
* 																				*
* ADT Max Binary Heap using arrays (elements from 0)							*
* 																				*
********************************************************************************/

#include "ADT_BinaryHeap.h"

void hb_testHeapify(){
	int maxSize = 10;
	int lastElement = 2;
	int e[] = {1,2,3};
	int i;

	hb_Heap*h = hb_create(maxSize);
	h->elements = e;
	h->lastElement = lastElement;

	hb_heapify(h,0);

	for(i=0;i<=h->lastElement;i++){
		printf("%d ",h->elements[i]);
	}
	printf("\n");
}

void hb_testBuildHeap(){
	int size = 5;
	int e[] = {1,2,3,4,5};
	int i;

	hb_Heap*h = hb_build(e,size);

	for(i=0;i<=h->lastElement;i++){
		printf("%d ",h->elements[i]);
	}
	printf("\n");
}

void testInsert(){
	hb_Heap*h =  hb_create(15);
	hb_insert(h,1);
	hb_insert(h,2);
	hb_insert(h,3);
	hb_insert(h,4);
	hb_insert(h,5);
	hb_insert(h,6);

	int i;
	for(i=0; i< hb_size(h); i++){
		printf("%d ", h->elements[i]);
	}

	printf(" \n%d \n", hb_deleteMax(h));
	printf(" \n%d \n", hb_deleteMax(h));
	for(i=0; i<= h->lastElement; i++){
		printf("%d ", h->elements[i]);
	}

}

hb_Heap*hb_create(int maxSize){
	hb_Heap*h= (hb_Heap*)malloc(sizeof(hb_Heap));
	h->elements = (int*)malloc(sizeof(int)*(maxSize));
	h->maxSize = maxSize;
	h->lastElement = -1;
	return h;
}

void hb_heapify(hb_Heap*h, int i){
	if(i>=0){
		int max;
		int izq = hb_leftChild(i);
		int der = hb_rightChild(i);

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
			hb_swap(&(h->elements[i]), &(h->elements[max]));
			hb_heapify(h, max);
		}

	}
    else{
        fprintf(stderr, "Invalid heap index...");
        exit(EXIT_FAILURE);
    }
}

hb_Heap*hb_build(int* elements, int size){
	hb_Heap*h = hb_create(size);
	h->elements = elements;
	h->lastElement = size-1;
	h->maxSize = size;

	int i;
	for(i = h->lastElement/2;i >= 0; i-- ){
		hb_heapify(h,i);
	}
	return h;
}

void hb_insert(hb_Heap*h, int element){
	if(h->lastElement < h->maxSize-1){
		h->lastElement++;
		h->elements[h->lastElement] = element;
		int i = h->lastElement;

		while(i > 0 && h->elements[hb_parent(i)] < h->elements[i]){
			hb_swap(&(h->elements[hb_parent(i)]),&(h->elements[i]));
			i = hb_parent(i);
		}
	}
	else{
        fprintf(stderr, "Inserting in a full heap...");
        exit(EXIT_FAILURE);
	}
}

int hb_deleteMax(hb_Heap*h){
	if(h->lastElement >= 0){
		int result = h->elements[0];
		hb_swap(&(h->elements[0]),&(h->elements[h->lastElement]));
		h->lastElement--;
		if(h->lastElement > 0){
			hb_heapify(h,0);
		}
		return result;
	}
    else{
        fprintf(stderr, "Deleting from an empty heap...");
        exit(EXIT_FAILURE);
    }
}

int hb_searchMax(hb_Heap*h){
	if(h->lastElement >= 0){
		return h->elements[0];
	}
    else{
        fprintf(stderr, "Searching in an empty heap...");
        exit(EXIT_FAILURE);
    }
}

int hb_size(hb_Heap*h){
	return h->lastElement + 1;
}

/**
 * Swap two integer values
 */
void hb_swap(int* a, int* b){
	int tmp=*a;
	*a=*b;
	*b=tmp;
}

int hb_leftChild(int nodeIndex){
	return 2*nodeIndex+1;
}

int hb_rightChild(int nodeIndex){
	return 2*nodeIndex+2;
}

int hb_parent(int nodeIndex){
	return (nodeIndex - 1)/2;
}
