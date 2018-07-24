/********************************************************************************
* 																				*
* ADT Set, very inefficient  implementation using arrays. Only to illustrate	*
* the ADT definition															*
* 																				*
********************************************************************************/

#include "ADT_Set_Array.h"

void testSet() {
	seta_Set* a = seta_create();
	seta_add(a, 1);
	seta_add(a, 2);
	seta_add(a, 3);
	seta_add(a, 4);

	printf("Set A -> ");
	seta_print(a);

	seta_Set* b = seta_create();
	seta_add(b, 3);
	seta_add(b, 4);
	seta_add(b, 5);
	seta_add(b, 6);
	seta_add(b, 7);

	printf("Set B -> ");
	seta_print(b);

	seta_Set* in = seta_intersection(a, b);
	printf("A interception B -> ");
	seta_print(in);

	seta_Set* un = seta_union(a, b);
	printf("A union B -> ");
	seta_print(un);
}



seta_Set* seta_create() {
	seta_Set* s = (seta_Set*)calloc(1, sizeof(seta_Set));
	s->resizeFactor = 2;
	s->maxSize = s->resizeFactor;
	s->size = 0;
	s->elements = (int*)calloc(s->maxSize, sizeof(int));
	return s;
}

bool seta_contains(seta_Set* s, int element) {
	int i;
	for (i = 0; i<s->size; i++) {
		if (s->elements[i] == element) {
			return true;
		}
	}
	return false;
}

void seta_add(seta_Set* s, int element) {

	if (!seta_contains(s, element)) {
		if (s->size >= s->maxSize) {
			s->maxSize = s->maxSize + s->resizeFactor;
			int * resizedElements = (int*)calloc(s->maxSize, sizeof(int));
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

void seta_remove(seta_Set* s, int element) {
	int i = 0;

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
		for (/*i from while loop*/; i < s->size - 1; i++) {
			s->elements[i] = s->elements[i + 1];
		}
		s->size--;
	}
}

seta_Set* seta_intersection(seta_Set* a, seta_Set* b) {

	seta_Set* result = seta_create();
	int i;
	for (i = 0; i<a->size; i++) {
		int element = a->elements[i];

		if (seta_contains(b, element)) {
			seta_add(result, element);
		}
	}
	return result;
}

seta_Set* seta_union(seta_Set* a, seta_Set* b) {
	seta_Set* result = seta_create();
	int i;
	for (i = 0; i<a->size; i++) {
		int element = a->elements[i];
		seta_add(result, element);
	}

	for (i = 0; i<b->size; i++) {
		int element = b->elements[i];
		if (!seta_contains(result, element)) {
			seta_add(result, element);
		}
	}
	return result;
}

void seta_print(seta_Set* s) {
	int i;
	for (i = 0; i<s->size; i++) {
		printf("%d ", s->elements[i]);
	}
	printf("\n");
}
