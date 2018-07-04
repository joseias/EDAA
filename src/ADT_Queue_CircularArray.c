/********************************************************************************
* 																				*
* ADT Queue, implementada utilizando un arreglo circular                		*
* 																				*
********************************************************************************/
#include "ADT_Queue_CircularArray.h"

void testQueue(){
	Queue *q=createQueue(3);
	enqueue(q,1);
	enqueue(q,2);
	enqueue(q,3);

	printf("Dequeued- > %d\n", dequeue(q));
	printf("Dequeued- > %d\n", dequeue(q));

	enqueue(q,4);
	enqueue(q,5);

	int e;
	while(!isEmptyQueue(q)){
		e=dequeue(q);
		printf("%d\n",e);
	}
}
Queue* createQueue(int maxSize){
	Queue* q=(Queue*)malloc(sizeof(Queue));
	q->maxSize=maxSize+1;
	q->front=0;
	q->rear=0;
	q->elements=(int*) malloc(sizeof(int) * q->maxSize);

	return q;
}

void enqueue(Queue* q, int e){
	if((q->maxSize - q->front + q->rear) % q->maxSize == q->maxSize -1 ){
		fprintf(stderr, "Queue is full...");
		exit(EXIT_FAILURE);
	}
	else{
		q->elements[q->rear]=e;
		q->rear=(q->rear+1) % q->maxSize;
	}
}

int dequeue(Queue* q){
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
int sizeQueue(Queue* q){
	return ((q->maxSize - q->front + q->rear) % q->maxSize);
}
bool isEmptyQueue(Queue* q){
	return !(sizeQueue(q)>0);
}
