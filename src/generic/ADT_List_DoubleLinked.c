/********************************************************************************
* 																				*
* ADT List, implementada como Lista Doblemente Enlazada 						*
* LOUDON, Kyle. Mastering Algorithms with C.. " O'Reilly Media, Inc.", 1999.  	*
*																				*
********************************************************************************/

#include "ADT_List_DoubleLinked.h"

void testLinkedList(){
	int i, index;
	Point* element;

	List* list=createList(comparePoints, destroyPoints);
	Point* p1 = (Point*)malloc(sizeof(Point));
	Point* p2 = (Point*)malloc(sizeof(Point));
	Point* p3 = (Point*)malloc(sizeof(Point));
	Point* p4 = (Point*)malloc(sizeof(Point));
	Point* t = (Point*)malloc(sizeof(Point));

	p1->x = 1;
	p1->y = 1;

	p2->x = 2;
	p2->y = 2;

	p3->x = 3;
	p3->y = 3;

	p4->x = 4;
	p4->y = 4;

	add(list, p1);
	add(list, p2);
	add(list, p3);
	add(list, p4);



	for(i=0;i<size_list(list);i++){
		element = (Point*) get(list, i);
		printf("Elemento en posicion %d es : ( %d, %d) \n", i, element->x, element->y);
	}

	printf("\n");
	printf("IndexOf (%d, %d) -> %d \n", p3->x, p3->y, indexOf(list, p3));

	index = 1;
	remove_at(list, index);


	printf("\n");
	for(i=0;i<size_list(list);i++){
		element = (Point*)get(list, i);
		printf("Elemento en posicion %d es : ( %d, %d) \n", i, element->x, element->y);
	}

	clear(list);
	printf("\n");
	for (i = 0; i<size_list(list); i++) {
		element = (Point*)get(list, i);
		printf("Elemento en posicion %d es : ( %d, %d) \n", i, element->x, element->y);
	}
}


List* createList(int(*comparator)(const void *, const void *), void(*destroyer)(const void*)) {
	List* list=(List*)malloc(sizeof(List));
	list->size=0;
	list->head=NULL;
	list->tail=NULL;
	list->comparator = comparator;
	list->destroyer = destroyer;
	return list;
}

int size_list(List* list){
	return list->size;
}

void add(List* list, void* element){
	add_at(list, element, list->size);
}

void add_at(List* list, void* element, unsigned int pos){
	Node* nn;
	Node* cn;
	Node* tmpl;

	if(pos>=0 && pos <= list->size){
		nn=createNode(element, NULL, NULL);

		if(list->size == 0){				/*Lista vac�a*/
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
				cn=getNodeAt(list,pos);		/*En este punto pos es una posicion v�lida de la lista*/

				if(pos==0){ 				/*Si pos es el comienzo de la lista*/
					cn->prev=nn;
					nn->next=cn;
					list->head=cn;
				}
				else{ 						/*Se a�ade en una posicion intermedia*/
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

void* get(List* list, unsigned int pos){
	Node* n=getNodeAt(list, pos);
	return n->data;
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
		
		if (list->destroyer!= NULL) {
			list->destroyer(cn->data);
		}
		free(cn);
	}
	else{
		fprintf(stderr, "Invalid list index %d\n", pos);
		exit(EXIT_FAILURE);
	}
}

int indexOf(List* list, void* element){
	int index=0;
	Node* tmp=list->head;

	while(tmp != NULL){
		if(list->comparator(tmp->data, element) == 0){
			return index;
		}
		tmp=tmp->next;
		index++;
	}
	return -1;
}

bool contains(List* list, void* element){
	return indexOf(list, element) != -1;
}
void clear(List* list){
	while(list->size>0){
		remove_at(list, list->size-1);
	}
}

int set(List *list, void* element, unsigned int pos){
	Node* n=getNodeAt(list, pos);
	int oldValue=n->data;
	n->data=element;
	return oldValue;
}

Node* createNode(void* element, Node* next, Node* prev){
	Node* nn=(Node*) malloc(sizeof(Node));
	nn->data=element;
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
