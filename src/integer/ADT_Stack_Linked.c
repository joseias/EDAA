/********************************************************************************
* 																				*
* ADT Stack, implemented with single linked nodes		  				 		*
* 																				*
********************************************************************************/
#include "ADT_Stack_Linked.h"


void sl_test() {
	sl_Stack* s = sl_create(3);
	sl_push(s, 1);
	sl_push(s, 2);
	sl_push(s, 3);

	printf("Peek -> %d \n", sl_peek(s));

	while (!sl_isEmpty(s)) {
		printf("Pop -> %d \n", sl_pop(s));
	}
}


sl_Stack* sl_create() {
	sl_Stack* s = (sl_Stack*) malloc(sizeof(sl_Stack));
	s->size = 0;
	s->top = NULL;
	return s;
}

void sl_push(sl_Stack* s, int e) {
	sl_Node* tmp = sl_createNode(e, NULL);
	
	if (sl_isEmpty(s)) {
		s->top = tmp;
	}
	else {
		tmp->next = s->top;
		s->top = tmp;
	}
	s->size++;
}

int sl_peek(sl_Stack* s) {
	if (!sl_isEmpty(s)) {
		return s->top->value;
	}
	else {
		fprintf(stderr, "Stack is empty...");
		exit(EXIT_FAILURE);
	}
}

int sl_pop(sl_Stack* s) {
	if (!sl_isEmpty(s)) {
		int value = s->top->value;
		sl_Node* tmp = s->top;
		s->top = tmp->next;
		free(tmp);
		s->size--;
		return value;
	}
	else {
		fprintf(stderr, "Stack is empty...");
		exit(EXIT_FAILURE);
	}
}
int sl_size(sl_Stack* s) {
	return s->size;
}

bool sl_isEmpty(sl_Stack* s) {
	return s->size == 0;
}

sl_Node* sl_createNode(int element, sl_Node* next) {
	sl_Node* nn = (sl_Node*)malloc(sizeof(sl_Node));
	nn->value = element;
	nn->next = next;
	return nn;
}
