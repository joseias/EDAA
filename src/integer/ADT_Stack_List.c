/********************************************************************************
* 																				*
* ADT Stack, implemented using a list (Double Linked List)				 		*
* 																				*
********************************************************************************/

#include "ADT_Stack_List.h"

void sll_test(){
	sll_Stack* s = sll_create();
	sll_push(s, 1);
	sll_push(s, 2);
	sll_push(s, 3);
	sll_push(s, 2);
	sll_push(s, 4);
	sll_push(s, 2);
	sll_push(s, 5);

	printf("Peek -> %d \n", sll_peek(s));

	sll_especificPop(s, 2);

	while(!sll_isEmpty(s)){
		printf("Pop -> %d \n", sll_pop(s));
	}
}

sll_Stack* sll_create(){
	ll_List* innL=ll_create();
	sll_Stack* s=(sll_Stack*) malloc(sizeof(sll_Stack));
	s->innerList=innL;
	return s;
}

void sll_push(sll_Stack* s, int e){
	ll_add(s->innerList, e);
}

int sll_peek(sll_Stack* s){
	if(!sll_isEmpty(s)){
		int last = ll_size(s->innerList) - 1;
		return ll_get(s->innerList, last);
	}
	else{
		fprintf(stderr, "Stack is empty...");
		exit(EXIT_FAILURE);
	}
}

int sll_pop(sll_Stack* s){
	if(!sll_isEmpty(s)){
		int last = ll_size(s->innerList) - 1;
		int e = ll_get(s->innerList, last);
		ll_removeAt(s->innerList,last);
		return e;
	}
	else{
		fprintf(stderr, "Stack is empty...");
		exit(EXIT_FAILURE);
	}
}

void sll_especificPop(sll_Stack* s, int e){
	sll_Stack* aux = sll_create();
	int tmp;
	while(!sll_isEmpty(s)){
		tmp = sll_pop(s);
		if(tmp != e){
			sll_push(aux, tmp);
		}
	}

	while(!sll_isEmpty(aux)){
		sll_push(s, sll_pop(aux));
	}
}

int sll_size(sll_Stack* s){
	return ll_size(s->innerList);
}

bool sll_isEmpty (sll_Stack* s){
	return sll_size(s) <= 0;
}
