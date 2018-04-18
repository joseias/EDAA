
#ifndef PROBLEMSOLUTIONS_H_
#define PROBLEMSOLUTIONS_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#include "ADT_Queue_List.h"
#include "ADT_Stack_List.h"

void testBalancing();
bool verifyBalancing();

void testPosEval();
int posEval(char* exp, int size);
void testInvert();
Queue* invert(Queue* q);

void testIsPalindromo();
bool isPalindromo(char* word, int start, int end);

#endif /* PROBLEMSOLUTIONS_H_ */
