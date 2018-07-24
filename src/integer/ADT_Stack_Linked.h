/********************************************************************************
* 																				*
* ADT Stack, implemented with single linked nodes		  				 		*
* 																				*
********************************************************************************/

#ifndef ADT_STACK_LINKED_H_
#define ADT_STACK_LINKED_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct sl_node
{
	int value;
	struct sl_node* next;
} sl_Node;


typedef struct sl_stack
{
	int size;
	sl_Node* top;
}sl_Stack;

void sl_test();
sl_Stack* sl_create();
void sl_push(sl_Stack* s, int e);
int sl_peek(sl_Stack* s);
int sl_pop(sl_Stack* s);
int sl_size(sl_Stack* s);
bool sl_isEmpty(sl_Stack* s);

sl_Node* sl_createNode(int element, sl_Node* next);
#endif /* ADT_STACK_LINKED_H_ */
