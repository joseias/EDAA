/********************************************************************************
* 																				*
* ADT Queue, implemented with single linked nodes		     				 	*
* 																				*
********************************************************************************/

#ifndef ADT_QUEUE_LINKED_H_
#define ADT_QUEUE_LINKED_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct ql_node
{
	int value;
	struct ql_node* next;
} ql_Node;


typedef struct ql_queue
{
	int size;
	ql_Node* ql_front;
	ql_Node* rear;
}ql_Queue;

void ql_test();
ql_Queue* ql_create();
void ql_enqueue(ql_Queue* q, int e);
int ql_front(ql_Queue* q);
int ql_dequeue(ql_Queue* q);
int ql_size(ql_Queue* q);
bool ql_isEmpty(ql_Queue* q);
void ql_multiEnqueue(ql_Queue* q, int e[], int asize);

ql_Node* ql_createNode(int element, ql_Node* next);
#endif /* ADT_QUEUE_LINKED_H_ */
