/********************************************************************************
* 																				*
* ADT Queue, implementada utilizando una Lista Doblemente Enlazada		 		*
* 																				*
********************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "ADT_Queue_List.h"

void testQueue(){
	Queue *q=createQueue();
	enqueue(q,1);
	enqueue(q,2);
	enqueue(q,3);
	enqueue(q,4);
	int e;
	while(!isEmptyQueue(q)){
		e=dequeue(q);
		printf("%d\n",e);
	}
}

Queue* createQueue(){
	List* innL=createList();
	Queue* q=(Queue*) malloc(sizeof(Queue));
	q->innerList=innL;
	return q;
}
void enqueue(Queue* q, int e){
	add(q->innerList, e);
}
int front(Queue* q){
	if(!isEmptyQueue(q)){
		return get(q->innerList,0);
	}
	else{
		fprintf(stderr, "Queue is empty...");
		exit(EXIT_FAILURE);
	}
}
int dequeue(Queue* q){
	int e=0;
	if(!isEmptyQueue(q)){
		e=get(q->innerList,0);
		removeAt(q->innerList,0);
		return e;
	}
	else{
		fprintf(stderr, "Queue is empty...");
		exit(EXIT_FAILURE);
	}
}
int sizeQueue(Queue* q){
	return sizeList(q->innerList);
}
bool isEmptyQueue(Queue* q){
	return sizeQueue(q)<=0;
}

