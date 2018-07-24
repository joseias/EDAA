/********************************************************************************
* 																				*
* ADT Stack, implemented using a list (Double Linked List)				 		*
* 																				*
********************************************************************************/

#ifndef ADT_STACK_LIST_H_
#define ADT_STACK_LIST_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "ADT_List_DoubleLinked.h"

typedef struct sll_Stack
{
	ll_List* innerList;
}sll_Stack;

void sll_test();
sll_Stack* sll_create();
void sll_push(sll_Stack* s, int e);
int sll_peek(sll_Stack* s);
int sll_pop(sll_Stack* s);
void sll_especificPop(sll_Stack* s, int e);
int sll_size(sll_Stack* s);
bool sll_isEmpty(sll_Stack* s);

#endif /* ADT_STACK_LIST_H_ */
