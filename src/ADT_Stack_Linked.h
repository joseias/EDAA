/********************************************************************************
* 																				*
* ADT Stack, implementada utilizando nodos enlazados       				 		*
* 																				*
********************************************************************************/

#ifndef ADT_STACK_LINKED_H_
#define ADT_STACK_LINKED_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct point {
	int x;
	int y;
}Point;

typedef Point* Object;

typedef struct nodeStack
{
	Object value;
	struct nodeStack* next;
} NodeStack;


typedef struct stack
{
	int size;
	NodeStack* top;
}Stack;

void testStack();
Stack* createStack();
void push(Stack* s, Object e);
Object peek(Stack* s);
Object pop(Stack* s);
int sizeStack(Stack* s);
bool isEmptyStack(Stack* s);

NodeStack* createNodeStack(Object element, NodeStack* next);
#endif /* ADT_STACK_LINKED_H_ */
