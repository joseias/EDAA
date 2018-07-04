#include "ProblemSolutions.h"

void testBalancing() {

	char exp[] = "{(1+2)-[2+3]}}";
	int size = 14;

	bool balanced = verifyBalancing(exp, size);

	if (balanced) {
		printf("Balanced...");
	}
	else {
		printf("Not balanced");
	}
}
bool verifyBalancing(char exp[], int length) {

	int i = 0;
	char cs, csc;
	Stack* s = createStack();

	for (i = 0; i < length; i++) {
		cs = exp[i];
		if (cs == '(' || cs == '[' || cs == '{') {
			push(s, cs);
		}

		if (cs == ')' || cs == ']' || cs == '}') {
			if (isEmptyStack(s)) {
				return false;
			}
			else {
				csc = pop(s);

				if (cs == ')' && csc != '(') {
					return false;
				}

				if (cs == ']' && csc != '[') {
					return false;
				}

				if (cs == '}' && csc != '{') {
					return false;
				}
			}
		}
	}

	return isEmptyStack(s);
}

/********************************************************************************
* 																				*
* Very simple postfix expression evaluator								 		*
* 																				*
********************************************************************************/
void testPosEval() {
	char exp[] = "231*+9-";
	int r = posEval(exp, 7);
	printf("%d", r);
}
int posEval(char* exp, int size) {
	Stack* s = createStack();
	int i;
	int op1, op2;
	for (i = 0; i < size; i++) {
		if (isdigit(exp[i])) { /*Is a number*/
			push(s, exp[i] - '0');
		}
		else {
			if (exp[i] == '+') {
				op1 = pop(s);
				op2 = pop(s);
				push(s, op2 + op1);
			}

			if (exp[i] == '-') {
				op1 = pop(s);
				op2 = pop(s);
				push(s, op2 - op1);
			}

			if (exp[i] == '*') {
				op1 = pop(s);
				op2 = pop(s);
				push(s, op2*op1);
			}

			if (exp[i] == '/') {
				op1 = pop(s);
				op2 = pop(s);
				push(s, op2 / op1);
			}
		}
	}

	return pop(s);
}

void testInvert() {
	Queue*  q = createQueue();
	enqueue(q, 1);
	enqueue(q, 2);
	enqueue(q, 3);
	enqueue(q, 4);

	Queue* iq = invert(q);

	while (!isEmptyQueue(iq)) {
		printf("%d\n", dequeue(iq));
	}
}
Queue* invert(Queue* q) {
	Queue* iq = createQueue();
	Stack* s = createStack();
	while (!isEmptyQueue(q)) {
		push(s, dequeue(q));
	}

	while (!isEmptyStack(s)) {
		enqueue(iq, pop(s));
	}

	return iq;
}

void testIsPalindromo() {
	char* word = "sasas";

	if (isPalindromo(word, 0, 4)) {
		printf("Palindromo");
	}
	else {
		printf("Not palindromo");
	}
}

bool isPalindromo(char* word, int start, int end) {
	if (start >= end) {
		return true;
	}

	if (word[start] != word[end]) {
		return false;
	}

	return isPalindromo(word, start + 1, end - 1);
}

void testReverseQueue() {
	Queue* fila1 = createQueue();
	enqueue(fila1, 1);
	enqueue(fila1, 2);
	enqueue(fila1, 3);
	enqueue(fila1, 4);

	Queue* fila2 = createQueue();
	reverseQueue(fila1, fila2);

	while (!isEmptyQueue(fila2)) {
		printf("%d \n", dequeue(fila2));
	}
}

void reverseQueue(Queue* q1, Queue* q2) {

	if (isEmptyQueue(q2)) {
		Stack* tmp = createStack();

		while (!isEmptyQueue(q1)) {
			push(tmp, dequeue(q1));
		}

		while (!isEmptyStack(tmp)) {
			enqueue(q2, pop(tmp));
		}
	}
	else {
		fprintf(stderr, "q2 must be empty...");
		exit(EXIT_FAILURE);
	}
}

int testSizeStackNoSize() {
	Stack* s = createStack();
	push(s, 1);
	push(s, 2);
	push(s, 3);
	push(s, 4);

	int size = sizeStackNoSize(s);
	printf("%d \n", size);
}

int sizeStackNoSize(Stack* s) {
	NodeStack* tmp = s->top;
	int size = 0;

	while (tmp != NULL) {
		size++;
		tmp = tmp->next;
	}

	return size;
}


void testMultArray() {
	int a[] = { 1,2,3,4 };
	int size = 4;
	int result = multArray(&a, size);
	printf("%d \n", result);
}
int multArray(int* a, int size) {
	if (size > 0) {
		if (size == 1) {
			return a[size - 1];
		}
		else {
			return a[size - 1] * multArray(a, size - 1);
		}
	}
	else {
		fprintf(stderr, "size must be >= 0...");
		exit(EXIT_FAILURE);
	}
}
