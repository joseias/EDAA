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

typedef struct node
{
	int value;
	struct node* next;
} Node;


typedef struct queue
{
	int size;
	Node* front;
	Node* rear;
}Queue;

void testQueue();
Queue* createQueue();
void enqueue(Queue* q, int e);
int front(Queue* q);
int dequeue(Queue* q);
int size_queue(Queue* q);
bool isEmpty_Queue(Queue* q);
void multi_enqueue(Queue* q, int e[], int asize);

Node* createNode(int element, Node* next);
#endif /* ADT_QUEUE_LINKED_H_ */
