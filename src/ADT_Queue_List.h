/********************************************************************************
* 																				*
* ADT Queue, implementada utilizando una Lista Doblemente Enlazada		 		*
* 																				*
********************************************************************************/

#ifndef ADT_QUEUE_LIST_H_
#define ADT_QUEUE_LIST_H_

#include <stdbool.h>
#include "ADT_List_DoubleLinked.h"

typedef struct Queue
{
	List* innerList;
}Queue;

void testQueue();
Queue* createQueue();
void enqueue(Queue* q, int e);
int front(Queue* q);
int dequeue(Queue* q);
int sizeQueue(Queue* q);
bool isEmptyQueue(Queue* q);

#endif /* ADT_QUEUE_LIST_H_ */
