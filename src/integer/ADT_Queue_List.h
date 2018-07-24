/********************************************************************************
* 																				*
* ADT Queue, implemented using a list (Double Linked List)				 		*
* 																				*
********************************************************************************/

#ifndef ADT_QUEUE_LIST_H_
#define ADT_QUEUE_LIST_H_

#include <stdbool.h>
#include "ADT_List_DoubleLinked.h"

typedef struct qll_queue
{
	ll_List* innerList;

}qll_Queue;

void qll_test();
qll_Queue* qll_create();
void qll_enqueue(qll_Queue* q, int e);
int qll_front(qll_Queue* q);
int qll_dequeue(qll_Queue* q);
int qll_size(qll_Queue* q);
bool qll_isEmpty(qll_Queue* q);

#endif /* ADT_QUEUE_LIST_H_ */
