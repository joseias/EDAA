/********************************************************************************
* 																				*
* ADT Queue, implementaded with two stacks (single node stack)      			*
* 																				*
********************************************************************************/


#ifndef ADT_QUEUE_TWOSTACKS_H_
#define ADT_QUEUE_TWOSTACKS_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "ADT_Stack_Linked.h"

typedef struct qs_queue
{
	sl_Stack* in;
	sl_Stack* out;
}qs_Queue;

void qs_test();
qs_Queue* qs_create();
void qs_enqueue(qs_Queue* q, int e);
int qs_front(qs_Queue* q);
int qs_dequeue(qs_Queue* q);
int qs_size(qs_Queue* q);
bool qs_isEmpty(qs_Queue* q);

#endif /* ADT_QUEUE_TWOSTACKS_H_ */
