/********************************************************************************
* 																				*
* ADT Stack, implemented over an array of limited size N			 	 		*
* 																				*
********************************************************************************/

#ifndef ADT_STACK_ARRAY_H_
#define ADT_STACK_ARRAY_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct sa_stack
{
	int *elements;
	int maxSize;
	int lastIndex;

}sa_Stack;

void sa_test();
sa_Stack* sa_create(int maxSize);
void sa_push(sa_Stack* s, int e);
int sa_peek(sa_Stack* s);
int sa_pop(sa_Stack* s);
int sa_size(sa_Stack* s);
bool sa_isEmpty(sa_Stack* s);


#endif /* ADT_STACK_ARRAY_H_ */
