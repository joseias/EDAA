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
	while(!isEmpty_Queue(q)){
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
	if(!isEmpty_Queue(q)){

		if(isEmpty_Stack(q->out)){
			while(!isEmpty_Stack(q->in)){
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
	if(!isEmpty_Queue(q)){

		if(isEmpty_Stack(q->out)){
			while(!isEmpty_Stack(q->in)){
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

int size_queue(Queue* q){
	return size_stack(q->in) + size_stack(q->out);
}

bool isEmpty_Queue(Queue* q){
	return size_queue(q)<=0;
}
