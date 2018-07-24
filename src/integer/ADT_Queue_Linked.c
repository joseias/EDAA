/********************************************************************************
* 																				*
* ADT Queue, implemented with single linked nodes		     				 	*
* 																				*
********************************************************************************/

#include "ADT_Queue_Linked.h"

void ql_test(){
	ql_Queue* q=ql_create();
	ql_enqueue(q,1);
	ql_enqueue(q,2);
	ql_enqueue(q,3);

	printf("Dequeued- > %d\n", ql_dequeue(q));
	printf("Dequeued- > %d\n", ql_dequeue(q));

	ql_enqueue(q,4);
	ql_enqueue(q,5);

	int elements[]={6,7,8,9};
	ql_multiEnqueue(q,elements,4);

	int e;
	while(!ql_isEmpty(q)){
		e=ql_dequeue(q);
		printf("%d\n",e);
	}
}

ql_Queue* ql_create(){
	ql_Queue* q=(ql_Queue*)malloc(sizeof(ql_Queue));
	q->size=0;
	q->ql_front=NULL;
	q->rear=NULL;
	return q;
}

void ql_enqueue(ql_Queue* q, int e){
	ql_Node* nn=ql_createNode(e,NULL);
	if(q->size == 0){				/*Empty queue*/
		q->ql_front=nn;
		q->rear=nn;
	}
	else{
		q->rear->next=nn;
		q->rear=nn;
	}
	q->size++;
}

void ql_multiEnqueue(ql_Queue* q, int e[], int asize){
	int i;
	for(i=0;i<asize;++i){
		ql_enqueue(q, e[i]);
	}
}

int ql_front(ql_Queue* q){
	if(q->size>0){
		return q->ql_front->value;
	}
	else{
		fprintf(stderr, "Queue is empty...");
		exit(EXIT_FAILURE);
	}
}

int ql_dequeue(ql_Queue* q){
	if(q->size>0){
		int e=q->ql_front->value;
		ql_Node* tmp=q->ql_front;
		q->ql_front=q->ql_front->next;
		free(tmp);
		q->size--;
		return e;
	}
	else{
		fprintf(stderr, "Queue is empty...");
		exit(EXIT_FAILURE);
	}
}

int ql_size(ql_Queue* q){
	return q->size;
}

bool ql_isEmpty(ql_Queue* q){
	return q->size <=0 ;
}

ql_Node* ql_createNode(int element, ql_Node* next){
	ql_Node* nn=(ql_Node*) malloc(sizeof(ql_Node));
	nn->value=element;
	nn->next=next;
	return nn;
}
