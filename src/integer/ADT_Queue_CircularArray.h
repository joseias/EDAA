/********************************************************************************
* 																				*
* ADT Queue, implemented as a circular array				               		*
* 																				*
********************************************************************************/

#ifndef ADT_QUEUE_CIRCULARARRAY_H_
#define ADT_QUEUE_CIRCULARARRAY_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct qca_Queue
{
	int *elements;
	int front; /*Index of the array cell which holds the first element in the queue*/
	int rear;  /*Index of the next available array cell*/
	int maxSize;

}qca_Queue;

void qca_test();
qca_Queue* qca_create();
void qca_enqueue(qca_Queue* q, int e);
int qca_front(qca_Queue* q);
int qca_dequeue(qca_Queue* q);
int qca_size(qca_Queue* q);
bool qca_isEmpty(qca_Queue* q);

#endif /* ADT_QUEUE_CIRCULARARRAY_H_ */
