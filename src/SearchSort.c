#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "SearchSort.h"

int binarySearch(int* array, int size, int key){
	int left, right, middle;
	left=0;
	right=size-1;

	while(left<=right){
		middle=(left+right)/2;

		if(key == array[middle] ){
			return middle;
		}
		else{
			if(key < array[middle] ){
				right=middle-1;
			}
			else{
				left=middle+1;
			}
		}
	}
	return -(left+1);
}
int linearSearchSortedArray(int* array, int size, int key){
	int pos;
	pos=0;

	while(pos < size && array[pos]< key){
		pos++;
	}

	if((pos < size) && (array[pos] == key)){
		return pos;
	}
	else{
		return -(pos+1);
	}
}


void testPartitionHoare(){
	int i;
	int size=7; /*Igual a la cantidad de elementos en a*/
	int a[]={4,6,2,5,3,5,1};
	int s=partitionHoareG(a,0,size-1);
	printf("s-> %d \n", s);
	for(i=0;i<size;i++){
		printf("%d ",a[i]);
	}

}

void testQuickSort(){
	int i;
	int size=7; /*Igual a la cantidad de elementos en a*/
	int a[]={4,6,2,5,3,5,1};

	for(i=0;i<size;i++){
		printf("%d ",a[i]);
	}

	quickSortG(a,0,size-1);

	printf("\n");
	for(i=0;i<size;i++){
		printf("%d ",a[i]);
	}
}

/**
 * Implementa QuickSort de acuerdo al particionamiento original de Hoare segun:
 * CORMEN, Thomas H., LEISERSON, Charles E., RIVEST, Ronald L. y STEIN, Clifford.
 * Introduction to Algorithms. 3rd Edition. MIT press, 2009, pp. 185
 */
void quickSort(int a[], int l, int r){
	int s;
	if(l<r){
		s=partitionHoare(a,l,r);
		quickSort(a,l,s);
		quickSort(a,s+1,r);
	}
}
/**
 * Implementa version original particionamiento de Hoare segun:
 * CORMEN, Thomas H., LEISERSON, Charles E., RIVEST, Ronald L. y STEIN, Clifford.
 * Introduction to Algorithms. 3rd Edition. MIT press, 2009, pp. 185
 */
int partitionHoare(int a[], int l, int r){
	int p=a[l];
	int i=l-1;
	int j=r+1;

	while(true){
		do{
			j--;
		}
		while(a[j]>p);

		do{
			i++;
		}
		while(a[i]<p);

		if(i<j){
			swap(&a[i], &a[j]);
		}
		else{
			return j;
		}
	}
}

/**
 * Implementa QuickSort de acuerdo al particionamiento segun:
 * GOODRICH, Michael T y TAMASSIA, Roberto.
 * Algorithm design and applications. Wiley Publishing, 2014, pp 255
 */
void quickSortG(int a[], int l, int r){
	int s;
	if(l<r){
		s=partitionHoareG(a,l,r);
		quickSortG(a,l,s-1);
		quickSortG(a,s+1,r);
	}
}
/**
 * Implementa particionamiento de Hoare segun:
 * GOODRICH, Michael T y TAMASSIA, Roberto. Algorithm design and applications. Wiley Publishing, 2014.
 */
int partitionHoareG(int a[], int l, int r){
	int p=a[r];
	int i=l;
	int j=r-1;

	while(i<=j){
		while(i<=j && a[i]<=p){
			i++;
		}
		while(j>=i && a[j]>=p){
			j--;
		}

		if(i<j){
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[r], &a[i]);

	return i;
}


void testQuickSortList(){
	int i;

	List* list=createList();
	add(list, 4);
	add(list, 6);
	add(list, 2);
	add(list, 5);
	add(list, 3);
	add(list, 5);
	add(list, 1);

	for(i=0;i<size_list(list);i++){
		printf("%d ",get(list,i));
	}

	quickSortGList(list, 0, size_list(list)-1);

	printf("\n");
	for(i=0;i<size_list(list);i++){
		printf("%d ",get(list,i));
	}
}


/**
 * Implementa QuickSort de acuerdo al particionamiento segun:
 * GOODRICH, Michael T y TAMASSIA, Roberto.
 * Algorithm design and applications. Wiley Publishing, 2014, pp 255
 */
void quickSortGList(List* list, int l, int r){
	int s;
	if(l<r){
		s=partitionHoareGList(list,l,r);
		quickSortGList(list,l,s-1);
		quickSortGList(list,s+1,r);
	}
}
/**
 * Implementa particionamiento de Hoare segun:
 * GOODRICH, Michael T y TAMASSIA, Roberto. Algorithm design and applications. Wiley Publishing, 2014.
 */
int partitionHoareGList(List* list, int l, int r){
	int p=get(list,r);
	int i=l;
	int j=r-1;

	while(i<=j){
		while(i<=j && get(list, i)<=p){
			i++;
		}
		while(j>=i && get(list, j)>=p){
			j--;
		}

		if(i<j){
			swapList(list, i, j);
		}
	}
	swapList(list, r, i);

	return i;
}

void swapList(List* list, int a, int b){
	int tmp=get(list,a);
	set(list, get(list, b), a);
	set(list, tmp, b);
}

/**
 * Intercambia los valores de los enteros a y b
 */
void swap(int* a, int* b){
	int tmp=*a;
	*a=*b;
	*b=tmp;
}


void testInsertionSort(){
	int i;
	int size=7; /*Igual a la cantidad de elementos en a*/
	int a[]={4,6,2,5,3,5,1};

	for(i=0;i<size;i++){
		printf("%d ",a[i]);
	}

	insertionSort(a,size);

	printf("\n");
	for(i=0;i<size;i++){
		printf("%d ",a[i]);
	}
}
/**
 * Implementa InsertionSort segun:
 * LEVITIN, Anany. Introduction to the Design and Analysis of Algorithms. 3rd Edition. Pearson, 2011.
 */
void insertionSort(int a[], int size){
	int i, v, j;

	for(i=1;i<size;i++){
		v=a[i];
		j=i-1;
		while(j>=0 && a[j]>v){
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=v;
	}
}


void testSelectionSort() {
	int i;
	int size = 7; /*Igual a la cantidad de elementos en a*/
	int a[] = { 4,6,2,5,3,5,1 };

	for (i = 0; i<size; i++) {
		printf("%d ", a[i]);
	}

	selectionSort(a, size);

	printf("\n");
	for (i = 0; i<size; i++) {
		printf("%d ", a[i]);
	}
}
/**
 * Implementa SelectionSort segun:
 * LEVITIN, Anany. Introduction to the Design and Analysis of Algorithms. 3rd Edition. Pearson, 2011.
 */
void selectionSort(int a[], int size){
	int i, min, j;

	for(i=0;i<size-1;i++){
		min=i;
		for(j=i+1; j<size; j++){
			if(a[j]<a[min]){
				min=j;
			}
		}
		swap(&a[i], &a[min]);
	}
}

