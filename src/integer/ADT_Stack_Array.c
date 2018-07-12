/********************************************************************************
* 																				*
* ADT Stack, implementada utilizando un arreglo y tamaño limitado N  	 		*
* 																				*
********************************************************************************/
#include "ADT_Stack_Array.h"

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

Stack* createStack(int maxSize){
	Stack* s=(Stack*) malloc(sizeof(Stack));

	int* elements=(int*) malloc(sizeof(int)*maxSize);
	s->elements=elements;
	s->lastIndex=-1;
	s->maxSize=maxSize;

	return s;
}

void push(Stack* s, int e){
	if(s->lastIndex < s->maxSize-1){
		s->lastIndex++;
		s->elements[s->lastIndex]=e;
	}
	else{
		fprintf(stderr, "Stack is full...");
		exit(EXIT_FAILURE);
	}
}

int peek(Stack* s){
	if(s->lastIndex >= 0){
		return s->elements[s->lastIndex];
	}
	else{
		fprintf(stderr, "Stack is empty...");
		exit(EXIT_FAILURE);
	}
}


int pop(Stack* s){
	int e;
	if(s->lastIndex >= 0){
		e=s->elements[s->lastIndex];
		s->lastIndex--;
		return e;
	}
	else{
		fprintf(stderr, "Stack is empty...");
		exit(EXIT_FAILURE);
	}
}

int sizeStack(Stack* s){
	return s->lastIndex+1;
}
bool isEmptyStack(Stack* s){
	return !(s->lastIndex >= 0);
}
