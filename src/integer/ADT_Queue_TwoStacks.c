/********************************************************************************
* 																				*
* ADT Queue, implementaded with two stacks (single node stack)      			*
* 																				*
********************************************************************************/

#include "ADT_Queue_TwoStacks.h"

void qs_test(){
	qs_Queue* q=qs_create();
	qs_enqueue(q,1);
	qs_enqueue(q,2);
	qs_enqueue(q,3);

	printf("Dequeued- > %d\n", qs_dequeue(q));
	printf("Dequeued- > %d\n", qs_dequeue(q));

	qs_enqueue(q,4);
	qs_enqueue(q,5);

	int e;
	while(!qs_isEmpty(q)){
		e=qs_dequeue(q);
		printf("%d\n",e);
	}
}

qs_Queue* qs_create(){
	qs_Queue* q = (qs_Queue*) malloc(sizeof(qs_Queue));

	sl_Stack* in=sl_create();
	sl_Stack* out=sl_create();
	q->in=in;
	q->out=out;

	return q;
}

void qs_enqueue(qs_Queue* q, int e){
	sl_push(q->in,e);
}

int qs_front(qs_Queue* q){
	if(!qs_isEmpty(q)){

		if(sl_isEmpty(q->out)){
			while(!sl_isEmpty(q->in)){
				sl_push(q->out, sl_pop(q->in));
			}
		}

		return sl_peek(q->out);
	}
	else{
		fprintf(stderr, "Queue is empty...");
		exit(EXIT_FAILURE);
	}
}

int qs_dequeue(qs_Queue* q){
	if(!qs_isEmpty(q)){

		if(sl_isEmpty(q->out)){
			while(!sl_isEmpty(q->in)){
				sl_push(q->out, sl_pop(q->in));
			}
		}

		return sl_pop(q->out);
	}
	else{
		fprintf(stderr, "Queue is empty...");
		exit(EXIT_FAILURE);
	}
}

int qs_size(qs_Queue* q){
	return sl_size(q->in) + sl_size(q->out);
}

bool qs_isEmpty(qs_Queue* q){
	return qs_size(q)<=0;
}
