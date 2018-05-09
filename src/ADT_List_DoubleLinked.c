/********************************************************************************
* 																				*
* ADT List, implementada como Lista Doblemente Enlazada 						*
* 																				*
********************************************************************************/

#include "ADT_List_DoubleLinked.h"

void testLinkedList(){
	int i, element, index;
	List* list=createList();
	add(list,1);
	add(list,3);
	add(list,5);
	add(list,3);
	add(list,7);


	for(i=0;i<size_list(list);i++){
		element=get(list, i);
		printf("Elemento en posicion %d es : %d \n", i, element);
	}

	printf("\n");
	printf("IndexOf %d -> %d \n", 3, indexOf(list, 3));
	printf("LastIndexOf %d -> %d \n", 3, lastIndexOf(list, 3));

	element=7;
	index=indexOf(list, element);
	printf("Indice de %d es: %d \n", element, index);

	remove_at(list, index);


	printf("\n");
	for(i=0;i<size_list(list);i++){
		element=get(list, i);
		printf("Elemento en posicion %d es : %d \n", i, element);
	}

	clear(list);
	add(list,2);
	add(list,4);
	add(list,6);
	add(list,8);

	printf("\n");
	for(i=0;i<size_list(list);i++){
		element=get(list, i);
		printf("Elemento en posicion %d es : %d \n", i, element);
	}

	List* rev = reverseRec(list);
	printf("\n");
	for (i = 0; i<size_list(rev); i++) {
		printf("Elemento en posicion %d es : %d \n", i, get(rev, i));
	}
}
List* createList(){
	List* list=(List*)malloc(sizeof(List));
	list->size=0;
	list->head=NULL;
	list->tail=NULL;
	return list;
}
int size_list(List* list){
	return list->size;
}
void add(List* list, int element){
	add_at(list, element, list->size);
}
void add_at(List* list, int element, unsigned int pos){
	Node* nn;
	Node* cn;
	Node* tmpl;

	if(pos>=0 && pos <= list->size){
		nn=createNode(element, NULL, NULL);

		if(list->size == 0){				/*Lista vacía*/
			list->head=nn;
			list->tail=nn;
		}
		else{								/*Lista no vacia*/
			if(pos==list->size){ 			/* Si pos es el final de la lista*/
				tmpl=list->tail;
				tmpl->next=nn;
				nn->prev=tmpl;
				list->tail=nn;
			}
			else{
				cn=getNodeAt(list,pos);		/*En este punto pos es una posicion válida de la lista*/

				if(pos==0){ 				/*Si pos es el comienzo de la lista*/
					cn->prev=nn;
					nn->next=cn;
					list->head=cn;
				}
				else{ 						/*Se añade en una posicion intermedia*/
					(cn->prev)->next=nn;
					nn->prev=cn->prev;
					cn->prev=nn;
					nn->next=cn;
				}
			}
		}
		list->size++;
	}
	else{
		fprintf(stderr, "Invalid list index %d\n", pos);
		exit(EXIT_FAILURE);
	}

}
int get(List* list, unsigned int pos){
	Node* n=getNodeAt(list, pos);
	return n->value;
}
void remove_at(List* list, unsigned int pos){
	Node* cn;
	Node* cnn;
	Node* cnp;

	if(pos>=0 && pos < list->size){
		cn=getNodeAt(list, pos);

		cnp=cn->prev;
		cnn=cn->next;


		if(cnp == NULL){ /*cn = head (es el que tiene ->prev = NULL)*/
			list->head=cnn;
		}
		else{
			cnp->next=cnn;
		}

		if(cnn == NULL){ /*cn = trail (es el que tiene ->next = NULL)*/
			list->tail=cnp;
		}
		else{
			cnn->prev=cnp;
		}
		list->size--;
		free(cn);
	}
	else{
		fprintf(stderr, "Invalid list index %d\n", pos);
		exit(EXIT_FAILURE);
	}
}
int indexOf(List* list, int element){
	int index=0;
	Node* tmp=list->head;

	while(tmp != NULL){
		if(tmp->value == element){
			return index;
		}
		tmp=tmp->next;
		index++;
	}
	return -1;
}

bool contains(List* list, int element){
	return indexOf(list, element) != -1;
}
void clear(List* list){
	while(list->size>0){
		remove_at(list, list->size-1);
	}
}
int set(List *list, int element, unsigned int pos){
	Node* n=getNodeAt(list, pos);
	int oldValue=n->value;
	n->value=element;
	return oldValue;
}

Node* createNode(int element, Node* next, Node* prev){
	Node* nn=(Node*) malloc(sizeof(Node));
	nn->value=element;
	nn->next=next;
	nn->prev=prev;

	return nn;
}
Node* getNodeAt(List* list, unsigned int pos){
	Node* tmp;
	int i;
	if(pos>=0 && pos < list->size){
		tmp=list->head;

		for(i=1;i<=pos;i++){
			tmp=tmp->next;
		}

		return tmp;
	}
	else{
		fprintf(stderr, "Invalid list index %d\n", pos);
		exit(EXIT_FAILURE);
	}
}


int lastIndexOf(List* list, int element) {

	int index;
	for (index = size_list(list) - 1; index >= 0; index--) {
		if (get(list, index) == element) {
			return index;
		}
	}

	return -1;
}


List* reverseRec(List* list) {
	List* rev;
	int e;
	if (size_list(list) == 0) {
		return createList();
	}
	else {
		e = get(list,0);
		remove_at(list,0);
		rev = reverseRec(list);
		add(rev,e);
		return rev;
	}
}