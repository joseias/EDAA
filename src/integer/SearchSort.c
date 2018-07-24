#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "SearchSort.h"

void testSearch() {
	int array[] = {1,3,5,7,9};
	int size = 5;
	int key = 10;
	int pos = binarySearchRec(array, 0, size-1, key);
	printf("%d -> %d\n", key, pos);
}

void testInsertionSort() {
	int i;
	int size = 7;					/*Elements in a*/
	int a[] = { 4,6,2,5,3,5,1 };

	for (i = 0; i<size; i++) {
		printf("%d ", a[i]);
	}

	insertionSort(a, size);

	printf("\n");
	for (i = 0; i<size; i++) {
		printf("%d ", a[i]);
	}
}

void testSelectionSort() {
	int i;
	int size = 7;						/*Elements in a*/
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

void testQuickSort() {
	int i;
	int size = 7;						/*Elements in a*/
	int a[] = { 4,6,2,5,3,5,1 };

	for (i = 0; i<size; i++) {
		printf("%d ", a[i]);
	}

	quickSortG(a, 0, size - 1);

	printf("\n");
	for (i = 0; i<size; i++) {
		printf("%d ", a[i]);
	}
}

void testQuickSortList() {
	int i;

	ll_List* list = ll_create();
	ll_add(list, 4);
	ll_add(list, 6);
	ll_add(list, 2);
	ll_add(list, 5);
	ll_add(list, 3);
	ll_add(list, 5);
	ll_add(list, 1);

	for (i = 0; i<ll_size(list); i++) {
		printf("%d ", ll_get(list, i));
	}

	quickSortGList(list, 0, ll_size(list) - 1);

	printf("\n");
	for (i = 0; i<ll_size(list); i++) {
		printf("%d ", ll_get(list, i));
	}
}

void testPartitionHoare() {
	int i;
	int size = 7;						/*Elements in a*/
	int a[] = { 4,6,2,5,3,5,1 };
	int s = partitionHoareG(a, 0, size - 1);
	printf("s-> %d \n", s);
	for (i = 0; i<size; i++) {
		printf("%d ", a[i]);
	}

}

int linearSearchSortedArray(int* array, int size, int key) {
	int pos;
	pos = 0;

	while (pos < size && array[pos]< key) {
		pos++;
	}

	if ((pos < size) && (array[pos] == key)) {
		return pos;
	}
	else {
		return -(pos + 1);
	}
}

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

int binarySearchRec(int* array, int left, int right, int key) {
	
	if (right >= left) {
		int middle = (left + right) / 2;

		if (key == array[middle]) {
			return middle;
		}
		else {
			if (key < array[middle]) {
				right = middle - 1;
			}
			else {
				left = middle + 1;
			}

			return binarySearchRec(array, left, right, key);
		}
	}
	else {
		return -(left + 1);
	}
}

/**
* Implements InsertionSort as in:
* LEVITIN, Anany. Introduction to the Design and Analysis of Algorithms. 3rd Edition. Pearson, 2011.
*/
void insertionSort(int a[], int size) {
	int i, v, j;

	for (i = 1; i<size; i++) {
		v = a[i];
		j = i - 1;
		while (j >= 0 && a[j]>v) {
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = v;
	}
}


/**
* Implements SelectionSort as in:
* LEVITIN, Anany. Introduction to the Design and Analysis of Algorithms. 3rd Edition. Pearson, 2011.
*/
void selectionSort(int a[], int size) {
	int i, min, j;

	for (i = 0; i<size - 1; i++) {
		min = i;
		for (j = i + 1; j<size; j++) {
			if (a[j]<a[min]) {
				min = j;
			}
		}
		swap(&a[i], &a[min]);
	}
}


/**
* Implements QuickSort using de original Hoare partition as in:
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
 * Implements the original Hoare partition as in:
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
 * Implements QuickSort partitioning as in:
 * GOODRICH, Michael T y TAMASSIA, Roberto.
 * Algorithm design and applications. Wiley Publishing, 2014.
 * pp. 255
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
 * Implements Hoare paritioning as in:
 * GOODRICH, Michael T y TAMASSIA, Roberto.
 * Algorithm design and applications. Wiley Publishing, 2014.
 * pp. 255
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


/**
* Only for testing purposes... 
* Implements QuickSort (over a list), partitioning as in:
* GOODRICH, Michael T y TAMASSIA, Roberto.
* Algorithm design and applications. Wiley Publishing, 2014.
* pp. 255
*/
void quickSortGList(ll_List* list, int l, int r){
	int s;
	if(l<r){
		s=partitionHoareGList(list,l,r);
		quickSortGList(list,l,s-1);
		quickSortGList(list,s+1,r);
	}
}

/**
* Only for testing purposes...
* Implements Hoare partitioning (of a double linked list) as in:
* GOODRICH, Michael T y TAMASSIA, Roberto.
* Algorithm design and applications. Wiley Publishing, 2014.
* pp. 255
*/
int partitionHoareGList(ll_List* list, int l, int r){
	int p=ll_get(list,r);
	int i=l;
	int j=r-1;

	while(i<=j){
		while(i<=j && ll_get(list, i)<=p){
			i++;
		}
		while(j>=i && ll_get(list, j)>=p){
			j--;
		}

		if(i<j){
			swapList(list, i, j);
		}
	}
	swapList(list, r, i);

	return i;
}

/**
* Swap two integers a and b
*/
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void swapList(ll_List* list, int a, int b){
	int tmp=ll_get(list,a);
	ll_set(list, ll_get(list, b), a);
	ll_set(list, tmp, b);
}


