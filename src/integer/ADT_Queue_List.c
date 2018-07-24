/********************************************************************************
* 																				*
* ADT Queue, implemented using a list (Double Linked List)				 		*
* 																				*
********************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "ADT_Queue_List.h"

void qll_test(){
	qll_Queue *q= qll_create(3);
	qll_enqueue(q,1);
	qll_enqueue(q,2);
	qll_enqueue(q,3);

	printf("Dequeued- > %d\n", qll_dequeue(q));
	printf("Dequeued- > %d\n", qll_dequeue(q));

	qll_enqueue(q,4);
	qll_enqueue(q,5);

	int e;
	while(!qll_isEmpty(q)){
		e= qll_dequeue(q);
		printf("%d\n",e);
	}
}

qll_Queue* qll_create(){
	ll_List* innL=ll_create();
	qll_Queue* q=(qll_Queue*) malloc(sizeof(qll_Queue));
	q->innerList=innL;
	return q;
}

void qll_enqueue(qll_Queue* q, int e){
	ll_add(q->innerList, e);
}

int qll_front(qll_Queue* q){
	if(!qll_isEmpty(q)){
		return ll_get(q->innerList,0);
	}
	else{
		fprintf(stderr, "Queue is empty...");
		exit(EXIT_FAILURE);
	}
}
int qll_dequeue(qll_Queue* q){
	int e=0;
	if(!qll_isEmpty(q)){
		e=ll_get(q->innerList,0);
		ll_removeAt(q->innerList,0);
		return e;
	}
	else{
		fprintf(stderr, "Queue is empty...");
		exit(EXIT_FAILURE);
	}
}
int qll_size(qll_Queue* q){
	return ll_size(q->innerList);
}
bool qll_isEmpty(qll_Queue* q){
	return qll_size(q)<=0;
}

