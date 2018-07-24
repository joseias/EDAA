/********************************************************************************
* 																				*
* ADT Stack, implementaded with two queues (single node queue)      			*
* 																				*
********************************************************************************/

#ifndef ADT_STACK_TWOQUEUES_H_
#define ADT_STACK_TWOQUEUES_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "ADT_Queue_Linked.h"

typedef struct sq_stack
{
	ql_Queue* in;
	ql_Queue* out;

}sq_Stack;

void sq_test();
sq_Stack* sq_create();
void sq_push(sq_Stack* s, int e);
int sq_peek(sq_Stack* s);
int sq_pop(sq_Stack* s);
int sq_size(sq_Stack* s);
bool sq_isEmpty(sq_Stack* s);


#endif /* ADT_STACK_TWOQUEUES_H_ */
