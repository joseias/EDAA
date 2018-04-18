/********************************************************************************
* 																				*
* ADT Queue, implementada utilizando dos pilas		      				 		*
* 																				*
********************************************************************************/


#ifndef ADT_QUEUE_TWOSTACKS_H_
#define ADT_QUEUE_TWOSTACKS_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "ADT_Stack_List.h"

typedef struct queue
{
	Stack* in;
	Stack* out;
}Queue;

void testQueue();
Queue* createQueue();
void enqueue(Queue* q, int e);
int front(Queue* q);
int dequeue(Queue* q);
int size_queue(Queue* q);
bool isEmpty_Queue(Queue* q);

#endif /* ADT_QUEUE_TWOSTACKS_H_ */
