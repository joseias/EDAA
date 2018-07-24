/********************************************************************************
* 																				*
* Solution to some class and exam exercises				     				 	*
* 																				*
********************************************************************************/

#ifndef PROBLEMSOLUTIONS_H_
#define PROBLEMSOLUTIONS_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#include "ADT_Queue_Linked.h"
#include "ADT_Stack_Linked.h"

void testBalancing();
bool verifyBalancing();

void testPosEval();
int posEval(char* exp, int size);

void testInvert();
ql_Queue* invert(ql_Queue* q);

void testIsPalindromo();
bool isPalindromo(char* word, int start, int end);

/* 2018-SI-Certamen-I */
void testReverseQueue();
void reverseQueue(ql_Queue* q1, ql_Queue* q2);

int testSizeStackNoSize();
int sizeStackNoSize(sl_Stack* s);

void testMultArray();
long multArray(int* a, int size);
#endif /* PROBLEMSOLUTIONS_H_ */
