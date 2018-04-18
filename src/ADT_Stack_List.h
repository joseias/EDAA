/********************************************************************************
* 																				*
* ADT Stack, implementada utilizando una Lista Doblemente Enlazada		 		*
* 																				*
********************************************************************************/

#ifndef ADT_STACK_LIST_H_
#define ADT_STACK_LIST_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "ADT_List_DoubleLinked.h"

typedef struct Stack
{
	List* innerList;
}Stack;

void testStack();
Stack* createStack();
void push(Stack* s, int e);
int peek(Stack* s);
int pop(Stack* s);
void specific_pop(Stack* s, int e);
int size_stack(Stack* s);
bool isEmpty_Stack(Stack* s);

#endif /* ADT_STACK_LIST_H_ */
