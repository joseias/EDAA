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

typedef struct node
{
	Object value;
	struct node* next;
} Node;


typedef struct queue
{
	int size;
	Node* top;
}Stack;

void testStack();
Stack* createStack();
void push(Stack* s, Object e);
Object peek(Stack* s);
Object pop(Stack* s);
int size_stack(Stack* s);
bool isEmpty_Stack(Stack* s);

Node* createNode(Object element, Node* next);
#endif /* ADT_STACK_LINKED_H_ */