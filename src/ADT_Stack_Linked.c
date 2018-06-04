/********************************************************************************
* 																				*
* ADT Stack, implementada utilizando nodos enlazados       				 		*
* 																				*
********************************************************************************/
#include "ADT_Stack_Linked.h"


void testStack() {
	Stack* s = createStack();
	//push(s, 1);
	//push(s, 2);
	//push(s, 3);

	//printf("%d \n", peek(s));

	//push(s, 4);
	//printf("%d \n", pop(s));

	//while (!isEmpty_Stack(s)) {
	//	printf("%d \n", pop(s));
	//}

	Point* p1 = (Point*)malloc(sizeof(Point));
	Point* p2= (Point*)malloc(sizeof(Point));
	Point* p3 = (Point*)malloc(sizeof(Point));
	Point* p4 = (Point*)malloc(sizeof(Point));

	p1->x = 1;
	p1->y = 1;

	p2->x = 2;
	p2->y = 2;

	p3->x = 3;
	p3->y = 3;

	p4->x = 4;
	p4->y = 4;

	push(s, p1);
	push(s, p2);
	push(s, p3);

	Point* tmp = (Point*)peek(s);
	printf("%d %d \n", tmp->x, tmp->y);

	push(s, p4);
	tmp = (Point*)pop(s);
	printf("%d %d \n", tmp->x, tmp->y);

	while (!isEmpty_Stack(s)) {
		tmp = (Point*)pop(s);
		printf("%d %d \n", tmp->x, tmp->y);
	}
}


Stack* createStack() {
	Stack* s = (Stack*) malloc(sizeof(Stack));
	s->size = 0;
	s->top = NULL;
	return s;
}

void push(Stack* s, Object e) {
	Node* tmp = createNode(e, NULL);
	
	if (isEmpty_Stack(s)) {
		s->top = tmp;
	}
	else {
		tmp->next = s->top;
		s->top = tmp;
	}
	s->size++;
}

Object peek(Stack* s) {
	if (!isEmpty_Stack(s)) {
		return s->top->value;
	}
	else {
		fprintf(stderr, "Stack is empty...");
		exit(EXIT_FAILURE);
	}
}

Object pop(Stack* s) {
	if (!isEmpty_Stack(s)) {
		Object value = s->top->value;
		Node* tmp = s->top;
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
int size_stack(Stack* s) {
	return s->size;
}

bool isEmpty_Stack(Stack* s) {
	return s->size == NULL;
}

Node* createNode(Object element, Node* next) {
	Node* nn = (Node*)malloc(sizeof(Node));
	nn->value = element;
	nn->next = next;
	return nn;
}
