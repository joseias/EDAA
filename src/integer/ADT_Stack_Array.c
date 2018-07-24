/********************************************************************************
* 																				*
* ADT Stack, implemented over an array of limited size N			 	 		*
* 																				*
********************************************************************************/

#include "ADT_Stack_Array.h"

void sa_test(){
	sa_Stack* s=sa_create(3);
	sa_push(s, 1);
	sa_push(s, 2);
	sa_push(s, 3);

	printf("Peek -> %d \n", sa_peek(s));

	while(!sa_isEmpty(s)){
		printf("Pop -> %d \n", sa_pop(s));
	}
}

sa_Stack* sa_create(int maxSize){
	sa_Stack* s=(sa_Stack*) malloc(sizeof(sa_Stack));

	int* elements=(int*) malloc(sizeof(int)*maxSize);
	s->elements=elements;
	s->lastIndex=-1;
	s->maxSize=maxSize;

	return s;
}

void sa_push(sa_Stack* s, int e){
	if(s->lastIndex < s->maxSize-1){
		s->lastIndex++;
		s->elements[s->lastIndex]=e;
	}
	else{
		fprintf(stderr, "Stack is full...");
		exit(EXIT_FAILURE);
	}
}

int sa_peek(sa_Stack* s){
	if(s->lastIndex >= 0){
		return s->elements[s->lastIndex];
	}
	else{
		fprintf(stderr, "Stack is empty...");
		exit(EXIT_FAILURE);
	}
}


int sa_pop(sa_Stack* s){
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

int sa_size(sa_Stack* s){
	return s->lastIndex+1;
}
bool sa_isEmpty(sa_Stack* s){
	return !(s->lastIndex >= 0);
}
