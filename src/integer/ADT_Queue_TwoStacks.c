/********************************************************************************
* 																				*
* ADT Queue, implementada utilizando dos pilas		      				 		*
* 																				*
********************************************************************************/
#include "ADT_Queue_TwoStacks.h"

void testQueue(){
	Queue *q=createQueue();
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

Queue* createQueue(){
	Queue* q = (Queue*) malloc(sizeof(Queue));

	Stack* in=createStack();
	Stack* out=createStack();
	q->in=in;
	q->out=out;

	return q;
}

void enqueue(Queue* q, int e){
	push(q->in,e);
}

int front(Queue* q){
	if(!isEmptyQueue(q)){

		if(isEmptyStack(q->out)){
			while(!isEmptyStack(q->in)){
				push(q->out, pop(q->in));
			}
		}

		return peek(q->out);
	}
	else{
		fprintf(stderr, "Queue is empty...");
		exit(EXIT_FAILURE);
	}
}

int dequeue(Queue* q){
	if(!isEmptyQueue(q)){

		if(isEmptyStack(q->out)){
			while(!isEmptyStack(q->in)){
				push(q->out, pop(q->in));
			}
		}

		return pop(q->out);
	}
	else{
		fprintf(stderr, "Queue is empty...");
		exit(EXIT_FAILURE);
	}
}

int sizeQueue(Queue* q){
	return sizeStack(q->in) + sizeStack(q->out);
}

bool isEmptyQueue(Queue* q){
	return sizeQueue(q)<=0;
}
