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

	while(!isEmptyStack(s)){
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
	if(!isEmptyStack(s)){
		int last = sizeList(s->innerList) - 1;
		return get(s->innerList, last);
	}
	else{
		fprintf(stderr, "Stack is empty...");
		exit(EXIT_FAILURE);
	}
}

int pop(Stack* s){
	if(!isEmptyStack(s)){
		int last = sizeList(s->innerList) - 1;
		int e = get(s->innerList, last);
		removeAt(s->innerList,last);
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
	while(!isEmptyStack(s)){
		tmp = pop(s);
		if(tmp != e){
			push(aux, tmp);
		}
	}

	while(!isEmptyStack(aux)){
		push(s, pop(aux));
	}
}

int sizeStack(Stack* s){
	return sizeList(s->innerList);
}

bool isEmptyStack (Stack* s){
	return sizeStack(s) <= 0;
}
