/********************************************************************************
* 																				*
* Solution to some class and exam exercises				     				 	*
* 																				*
********************************************************************************/

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
	sl_Stack* s = sl_create();

	for (i = 0; i < length; i++) {
		cs = exp[i];
		if (cs == '(' || cs == '[' || cs == '{') {
			sl_push(s, cs);
		}

		if (cs == ')' || cs == ']' || cs == '}') {
			if (sl_isEmpty(s)) {
				return false;
			}
			else {
				csc = sl_pop(s);

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

	return sl_isEmpty(s);
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
	sl_Stack* s = sl_create();
	int i;
	int op1, op2;
	for (i = 0; i < size; i++) {
		if (isdigit(exp[i])) { /*Is a number*/
			sl_push(s, exp[i] - '0');
		}
		else {
			if (exp[i] == '+') {
				op1 = sl_pop(s);
				op2 = sl_pop(s);
				sl_push(s, op2 + op1);
			}

			if (exp[i] == '-') {
				op1 = sl_pop(s);
				op2 = sl_pop(s);
				sl_push(s, op2 - op1);
			}

			if (exp[i] == '*') {
				op1 = sl_pop(s);
				op2 = sl_pop(s);
				sl_push(s, op2*op1);
			}

			if (exp[i] == '/') {
				op1 = sl_pop(s);
				op2 = sl_pop(s);
				sl_push(s, op2 / op1);
			}
		}
	}

	return sl_pop(s);
}

void testInvert() {
	ql_Queue*  q = ql_create();
	ql_enqueue(q, 1);
	ql_enqueue(q, 2);
	ql_enqueue(q, 3);
	ql_enqueue(q, 4);

	ql_Queue* iq = invert(q);

	while (!ql_isEmpty(iq)) {
		printf("%d\n", ql_dequeue(iq));
	}
}

ql_Queue* invert(ql_Queue* q) {
	ql_Queue* iq = ql_create();
	sl_Stack* s = sl_create();
	while (!ql_isEmpty(q)) {
		sl_push(s, ql_dequeue(q));
	}

	while (!sl_isEmpty(s)) {
		ql_enqueue(iq, sl_pop(s));
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
	ql_Queue* fila1 = ql_create();
	ql_enqueue(fila1, 1);
	ql_enqueue(fila1, 2);
	ql_enqueue(fila1, 3);
	ql_enqueue(fila1, 4);

	ql_Queue* fila2 = ql_create();
	reverseQueue(fila1, fila2);

	while (!ql_isEmpty(fila2)) {
		printf("%d \n", ql_dequeue(fila2));
	}
}

void reverseQueue(ql_Queue* q1, ql_Queue* q2) {
	if (ql_isEmpty(q2)) {
		sl_Stack* tmp = sl_create();

		while (!ql_isEmpty(q1)) {
			sl_push(tmp, ql_dequeue(q1));
		}

		while (!sl_isEmpty(tmp)) {
			ql_enqueue(q2, sl_pop(tmp));
		}
	}
	else {
		fprintf(stderr, "q2 must be empty...");
		exit(EXIT_FAILURE);
	}
}

int testSizeStackNoSize() {
	sl_Stack* s = sl_create();
	sl_push(s, 1);
	sl_push(s, 2);
	sl_push(s, 3);
	sl_push(s, 4);

	int size = sizeStackNoSize(s);
	printf("%d \n", size);
}

int sizeStackNoSize(sl_Stack* s) {
	sl_Node* tmp = s->top;
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
	int result = multArray(a, size);
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
