/********************************************************************************
* 																				*
* ADT Queue, implemented as a circular array				               		*
* 																				*
********************************************************************************/
#include "ADT_Queue_CircularArray.h"

void qca_test(){
	qca_Queue *q= qca_create(3);
	qca_enqueue(q,1);
	qca_enqueue(q,2);
	qca_enqueue(q,3);

	printf("Dequeued- > %d\n", qca_dequeue(q));
	printf("Dequeued- > %d\n", qca_dequeue(q));

	qca_enqueue(q,4);
	qca_enqueue(q,5);

	int e;
	while(!qca_isEmpty(q)){
		e= qca_dequeue(q);
		printf("%d\n",e);
	}
}
qca_Queue* qca_create(int maxSize){
	qca_Queue* q=(qca_Queue*)malloc(sizeof(qca_Queue));
	q->maxSize=maxSize+1;
	q->front=0;
	q->rear=0;
	q->elements=(int*) malloc(sizeof(int) * q->maxSize);

	return q;
}

void qca_enqueue(qca_Queue* q, int e){
	if((q->maxSize - q->front + q->rear) % q->maxSize == q->maxSize -1 ){
		fprintf(stderr, "Queue is full...");
		exit(EXIT_FAILURE);
	}
	else{
		q->elements[q->rear]=e;
		q->rear=(q->rear+1) % q->maxSize;
	}
}

int qca_dequeue(qca_Queue* q){
	if(q->front ==  q->rear){
		fprintf(stderr, "Queue is empty...");
		exit(EXIT_FAILURE);
	}
	else{
		int e=q->elements[q->front];
		q->elements[q->front]=0;
		q->front=(q->front+1) % q->maxSize;
		return e;
	}
}
int qca_size(qca_Queue* q){
	return ((q->maxSize - q->front + q->rear) % q->maxSize);
}
bool qca_isEmpty(qca_Queue* q){
	return !(qca_size(q)>0);
}
