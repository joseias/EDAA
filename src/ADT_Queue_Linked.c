/********************************************************************************
* 																				*
* ADT Queue, implementada utilizando nodos enlazados       				 		*
* 																				*
********************************************************************************/
#include "ADT_Queue_Linked.h"

void testQueue(){
	Queue *q=createQueue();
	enqueue(q,1);
	enqueue(q,2);
	enqueue(q,3);

	printf("Dequeued- > %d\n", dequeue(q));
	printf("Dequeued- > %d\n", dequeue(q));

	enqueue(q,4);
	enqueue(q,5);

	int elements[]={6,7,8,9};
	multi_enqueue(q,elements,4);

	int e;
	while(!isEmpty_Queue(q)){
		e=dequeue(q);
		printf("%d\n",e);
	}
}

Queue* createQueue(){
	Queue* q=(Queue*)malloc(sizeof(Queue));
	q->size=0;
	q->front=NULL;
	q->rear=NULL;
	return q;
}
void enqueue(Queue* q, int e){
	Node* nn=createNode(e,NULL);
	if(q->size == 0){				/*Cola vacía*/
		q->front=nn;
		q->rear=nn;
	}
	else{
		q->rear->next=nn;
		q->rear=nn;
	}
	q->size++;
}

void multi_enqueue(Queue* q, int e[], int asize){
	int i;
	for(i=0;i<asize;++i){
		enqueue(q, e[i]);
	}
}

int front(Queue* q){
	if(q->size>0){
		return q->front->value;
	}
	else{
		fprintf(stderr, "Queue is empty...");
		exit(EXIT_FAILURE);
	}
}

int dequeue(Queue* q){
	if(q->size>0){
		int e=q->front->value;
		Node* tmp=q->front;
		q->front=q->front->next;
		free(tmp);
		q->size--;
		return e;
	}
	else{
		fprintf(stderr, "Queue is empty...");
		exit(EXIT_FAILURE);
	}
}

int size_queue(Queue* q){
	return q->size;
}

bool isEmpty_Queue(Queue* q){
	return q->size <=0 ;
}

Node* createNode(int element, Node* next){
	Node* nn=(Node*) malloc(sizeof(Node));
	nn->value=element;
	nn->next=next;
	return nn;
}
