/********************************************************************************
* 																				*
* ADT Stack, implementada utilizando un arreglo y tamaño limitado N  	 		*
* 																				*
********************************************************************************/

#ifndef ADT_STACK_ARRAY_H_
#define ADT_STACK_ARRAY_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Stack
{
	int *elements;
	int maxSize;
	int lastIndex;
}Stack;

void testStack();
Stack* createStack(int maxSize);
void push(Stack* s, int e);
int peek(Stack* s);
int pop(Stack* s);
int size_stack(Stack* s);
bool isEmpty_Stack(Stack* s);


#endif /* ADT_STACK_ARRAY_H_ */
