/********************************************************************************
* 																				*
* ADT Set , implementacion MUY ineficiente utilizando un arreglo y elementos 	*
* desde la posicion 0. Solo para ilustrar el concepto de TDA		 			*
* 																				*
********************************************************************************/
#include "ADT_Set_Array.h"

void testSet() {
	Set* a = setCreate();
	setAdd(a, 1);
	setAdd(a, 2);
	setAdd(a, 3);
	setAdd(a, 4);
	
	setPrint(a);

	Set* b = setCreate();
	setAdd(b, 3);
	setAdd(b, 4);
	setAdd(b, 5);
	setAdd(b, 6);
	setAdd(b, 7);

	setPrint(b);

	Set* in = setIntersection(a,b);
	setPrint(in);

	Set* un = setUnion(a, b);
	setPrint(un);
}



Set* setCreate() {
	Set* s = (Set*)calloc(1,sizeof(Set));
	s->resizeFactor = 2;
	s->maxSize = s->resizeFactor;
	s->size = 0;
	s->elements = (int*)calloc(s->maxSize,sizeof(int));
	return s;
}

bool setContains(Set* s, int element) {
	int i;
	for (i = 0; i<s->size; i++) {
		if (s->elements[i] == element) {
			return true;
		}
	}
	return false;
}

void setAdd(Set* s, int element) {

	if (!setContains(s, element)) {
		if (s->size >= s->maxSize) {
			s->maxSize = s->maxSize + s->resizeFactor;
			int * resizedElements = (int*) calloc(s->maxSize, sizeof(int));
			memcpy(resizedElements, s->elements, sizeof(int) * s->size);
			free(s->elements);
			s->elements = resizedElements;
		}

		if (s->elements != NULL) {
			s->elements[s->size] = element;
			s->size++;
		}
		else {
			fprintf(stderr, "Extra memory allocation failed ...\n");
			exit(EXIT_FAILURE);
		}
	}
	else {
		fprintf(stderr, "Set already contains %d \n", element);
		exit(EXIT_FAILURE);
	}
}

void setRemove(Set* s, int element) {
	int i=0;

	/*Search the ocurrence of the element...*/
	bool found = false;
	while (i < s->size && !found) {
		if (s->elements[i] != element) {
			found = true;
		}
		else {
			i++;
		}
	}

	if (found) {
		for (/*i from while loop*/; i < s->size-1; i++) {
			s->elements[i] = s->elements[i + 1];
		}
		s->size--;
	}
}

Set* setIntersection(Set* a, Set* b) {

	Set* result = setCreate();
	int i;
	for (i = 0; i<a->size; i++) {
		int element = a->elements[i];

		if (setContains(b, element)) {
			setAdd(result, element);
		}
	}
	return result;
}

Set* setUnion(Set* a, Set* b) {
	Set* result = setCreate();
	int i;
	for (i = 0; i<a->size; i++) {
		int element = a->elements[i];
		setAdd(result, element);
	}

	for (i = 0; i<b->size; i++) {
		int element = b->elements[i];
		if (!setContains(result, element)) {
			setAdd(result, element);
		}
	}
	return result;
}

void setPrint(Set* s) {
	int i;
	for (i = 0; i<s->size; i++) {
		printf("%d ", s->elements[i]);
	}
	printf("\n");
}
