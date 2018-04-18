#include "ProblemSolutions.h"

void testBalancing(){

	char exp[]="{(1+2)-[2+3]}}";
	int size= 14;

	bool balanced=verifyBalancing(exp, size);

	if(balanced){
		printf("Balanced...");
	}
	else{
		printf("Not balanced");
	}
}
bool verifyBalancing(char exp[], int length){

	int i=0;
	char cs, csc;
	Stack* s=createStack();

	for(i=0;i<length;i++){
		cs=exp[i];
		if(cs=='(' || cs=='[' || cs=='{' ){
			push(s, cs);
		}

		if(cs==')' || cs==']' || cs=='}' ){
			if(isEmpty_Stack(s)){
				return false;
			}
			else{
				csc=pop(s);

				if(cs == ')' && csc != '('){
					return false;
				}

				if(cs == ']' && csc != '['){
					return false;
				}

				if(cs == '}' && csc != '{'){
					return false;
				}
			}
		}
	}

	return isEmpty_Stack(s);
}

/********************************************************************************
* 																				*
* Very simple postfix expression evaluator								 		*
* 																				*
********************************************************************************/
void testPosEval(){
	char exp[]="231*+9-";
	int r=posEval(exp, 7);
	printf("%d", r);
}
int posEval(char* exp, int size){
	Stack* s=createStack();
	int i;
	int op1,op2;
	for(i=0;i<size;i++){
		if(isdigit(exp[i])){ /*Is a number*/
			push(s,exp[i]- '0');
		}
		else{
			if(exp[i]=='+'){
				op1=pop(s);
				op2=pop(s);
				push(s, op2+op1);
			}

			if(exp[i]=='-'){
				op1=pop(s);
				op2=pop(s);
				push(s, op2-op1);
			}

			if(exp[i]=='*'){
				op1=pop(s);
				op2=pop(s);
				push(s, op2*op1);
			}

			if(exp[i]=='/'){
				op1=pop(s);
				op2=pop(s);
				push(s, op2/op1);
			}
		}
	}

	return pop(s);
}

void testInvert(){
	Queue*  q=createQueue();
	enqueue(q,1);
	enqueue(q,2);
	enqueue(q,3);
	enqueue(q,4);

	Queue* iq=invert(q);

	while(!isEmpty_Queue(iq)){
		printf("%d\n", dequeue(iq));
	}
}
Queue* invert(Queue* q){
	Queue* iq=createQueue();
	Stack* s=createStack();
	while(!isEmpty_Queue(q)){
		push(s,dequeue(q));
	}

	while(!isEmpty_Stack(s)){
		enqueue(iq,pop(s));
	}

	return iq;
}

void testIsPalindromo(){
	char* word= "sasas";

	if(isPalindromo(word, 0, 4)){
		printf("Palindromo");
	}
	else{
		printf("Not palindromo");
	}
}

bool isPalindromo(char* word, int start, int end){
	if(start >= end ){
		return true;
	}

	if(word[start] != word[end]){
		return false;
	}

	return isPalindromo(word, start+1, end-1);
}
