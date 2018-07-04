/********************************************************************************
* 																				*
* ADT Queue, implementada utilizando un arreglo circular                		*
* 																				*
********************************************************************************/

#ifndef ADT_QUEUE_CIRCULARARRAY_H_
#define ADT_QUEUE_CIRCULARARRAY_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Queue
{
	int *elements;
	int front; /*Index of the array cell which holds the first element in the queue*/
	int rear;  /*Index of the next available array cell*/
	int maxSize;

}Queue;

void testQueue();
Queue* createQueue();
void enqueue(Queue* q, int e);
int front(Queue* q);
int dequeue(Queue* q);
int sizeQueue(Queue* q);
bool isEmptyQueue(Queue* q);

#endif /* ADT_QUEUE_CIRCULARARRAY_H_ */
