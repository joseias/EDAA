/********************************************************************************
* 																				*
* ADT Stack, implementada utilizando una Lista Doblemente Enlazada		 		*
* 																				*
********************************************************************************/

#include "ADT_Stack_List.h"

void testStack(){
	Stack* s=createStack();
	push(s, 1);
	push(s, 2);
	push(s, 3);
	push(s, 2);
	push(s, 4);
	push(s, 2);
	push(s, 5);

	printf("Peek -> %d \n", peek(s));

	specific_pop(s, 2);

	while(!isEmpty_Stack(s)){
		printf("Pop -> %d \n", pop(s));
	}
}
Stack* createStack(){
	List* innL=createList();
	Stack* s=(Stack*) malloc(sizeof(Stack));
	s->innerList=innL;
	return s;
}
void push(Stack* s, int e){
	add(s->innerList, e);
}
int peek(Stack* s){
	if(!isEmpty_Stack(s)){
		int last = size_list(s->innerList) - 1;
		return get(s->innerList, last);
	}
	else{
		fprintf(stderr, "Stack is empty...");
		exit(EXIT_FAILURE);
	}
}

int pop(Stack* s){
	if(!isEmpty_Stack(s)){
		int last = size_list(s->innerList) - 1;
		int e = get(s->innerList, last);
		remove_at(s->innerList,last);
		return e;
	}
	else{
		fprintf(stderr, "Stack is empty...");
		exit(EXIT_FAILURE);
	}
}

void specific_pop(Stack* s, int e){
	Stack* aux = createStack();
	int tmp;
	while(!isEmpty_Stack(s)){
		tmp = pop(s);
		if(tmp != e){
			push(aux, tmp);
		}
	}

	while(!isEmpty_Stack(aux)){
		push(s, pop(aux));
	}
}

int size_stack(Stack* s){
	return size_list(s->innerList);
}

bool isEmpty_Stack (Stack* s){
	return size_stack(s) <= 0;
}
