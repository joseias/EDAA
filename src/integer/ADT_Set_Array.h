/********************************************************************************
* 																				*
* ADT Set, very inefficient  implementation using arrays. Only to illustrate	*
* the ADT definition															*
* 																				*
********************************************************************************/

#ifndef ADT_SET_ARRAY_H_
#define ADT_SET_ARRAY_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct seta_set {
	int size;
	int maxSize;
	int resizeFactor;
	int * elements;
}seta_Set;

void seta_test();
seta_Set* seta_create();
bool seta_contains(seta_Set* s, int element);
void seta_add(seta_Set* s, int element);
void seta_remove(seta_Set* s, int element);
seta_Set* seta_intersection(seta_Set* a, seta_Set* b);
seta_Set* seta_union(seta_Set* a, seta_Set* b);
void seta_print(seta_Set* s);

#endif /* ADT_SET_ARRAY_H_ */