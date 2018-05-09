/********************************************************************************
* 																				*
* ADT Set , implementacion MUY ineficiente utilizando un arreglo y elementos 	*
* desde la posicion 0. Solo para ilustrar el concepto de TDA		 			*
* 																				*
********************************************************************************/

#ifndef ADT_SET_ARRAY_H_
#define ADT_SET_ARRAY_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Set {
	int size;
	int maxSize;
	int resizeFactor;
	int * elements;
}Set;

void testSet();
Set* setCreate();
bool setContains(Set* s, int element);
void setAdd(Set* s, int element);
void setRemove(Set* s, int element);
Set* setIntersection(Set* a, Set* b);
Set* setUnion(Set* a, Set* b);
void setPrint(Set* s);

#endif /* ADT_SET_ARRAY_H_ */