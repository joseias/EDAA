/********************************************************************************
* 																				*
* ADT Stack, implementaded with two queues (single node queue)      			*
* 																				*
********************************************************************************/

#include "ADT_Stack_TwoQueues.h"

void sq_test(){
	sq_Stack* s=sq_create(3);
	sq_push(s, 1);
	sq_push(s, 2);
	sq_push(s, 3);

	printf("Peek -> %d \n", sq_peek(s));

	while(!sq_isEmpty(s)){
		printf("Pop -> %d \n", sq_pop(s));
	}
}

sq_Stack* sq_create(){
	sq_Stack* s=(sq_Stack*)malloc(sizeof(sq_Stack));
	s->in=ql_create();
	s->out= ql_create();
	return s;
}

void sq_push(sq_Stack* s, int e){
	ql_enqueue(s->in,e);
}

int sq_peek(sq_Stack* s){
	while(ql_size(s->in) > 1){
		ql_enqueue(s->out, ql_dequeue(s->in));
	}
	int e = ql_dequeue(s->in);
	ql_enqueue(s->out,e);

	ql_Queue* tmp=s->in;
	s->in=s->out;
	s->out=tmp;
	return e;
}

int sq_pop(sq_Stack* s){
	while(ql_size(s->in) > 1){
		ql_enqueue(s->out, ql_dequeue(s->in));
	}
	int e = ql_dequeue(s->in);

	ql_Queue* tmp=s->in;
	s->in=s->out;
	s->out=tmp;
	return e;
}
int sq_size(sq_Stack* s){
	return ql_size(s->in) + ql_size(s->out); /*s->out deberia estar vacio*/
}
bool sq_isEmpty(sq_Stack* s){
	return sq_size(s) <= 0;
}
