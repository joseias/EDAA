/********************************************************************************
* 																				*
* ADT Queue, implementada utilizando nodos enlazados       				 		*
* 																				*
********************************************************************************/

#ifndef ADT_QUEUE_LINKED_H_
#define ADT_QUEUE_LINKED_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct nodeQueue
{
	int value;
	struct nodeQueue* next;
} NodeQueue;


typedef struct queue
{
	int size;
	NodeQueue* front;
	NodeQueue* rear;
}Queue;

void testQueue();
Queue* createQueue();
void enqueue(Queue* q, int e);
int front(Queue* q);
int dequeue(Queue* q);
int sizeQueue(Queue* q);
bool isEmptyQueue(Queue* q);
void multi_enqueue(Queue* q, int e[], int asize);

NodeQueue* createNodeQueue(int element, NodeQueue* next);
#endif /* ADT_QUEUE_LINKED_H_ */
