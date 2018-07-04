/*
 * ADT_Stack_TwoQueues.c.h
 *
 *  Created on: Oct 17, 2017
 *      Author: Someone
 */

#ifndef ADT_STACK_TWOQUEUES_H_
#define ADT_STACK_TWOQUEUES_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "ADT_Queue_Linked.h"

typedef struct stack
{
	Queue* in;
	Queue* out;
}Stack;

void testStack();
Stack* createStack();
void push(Stack* s, int e);
int peek(Stack* s);
int pop(Stack* s);
int sizeStack(Stack* s);
bool isEmptyStack(Stack* s);


#endif /* ADT_STACK_TWOQUEUES_H_ */
