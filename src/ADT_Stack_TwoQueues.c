#include "ADT_Stack_TwoQueues.h"

void testStack(){
	Stack* s=createStack(3);
	push(s, 1);
	push(s, 2);
	push(s, 3);

	printf("Peek -> %d \n", peek(s));

	while(!isEmptyStack(s)){
		printf("Pop -> %d \n", pop(s));
	}
}

Stack* createStack(){
	Stack* s=(Stack*)malloc(sizeof(Stack));
	s->in=createQueue();
	s->out=createQueue();
	return s;
}

void push(Stack* s, int e){
	enqueue(s->in,e);
}

int peek(Stack* s){
	while(sizeQueue(s->in) > 1){
		enqueue(s->out, dequeue(s->in));
	}
	int e = dequeue(s->in);
	enqueue(s->out,e);

	Stack* tmp=s->in;
	s->in=s->out;
	s->out=tmp;
	return e;
}
int pop(Stack* s){
	while(sizeQueue(s->in) > 1){
		enqueue(s->out, dequeue(s->in));
	}
	int e = dequeue(s->in);

	Stack* tmp=s->in;
	s->in=s->out;
	s->out=tmp;
	return e;
}
int sizeStack(Stack* s){
	return sizeQueue(s->in) + sizeQueue(s->out); /*s->out deberia estar vacio*/
}
bool isEmptyStack(Stack* s){
	return sizeStack(s) <= 0;
}
