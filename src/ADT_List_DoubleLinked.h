/********************************************************************************
* 																				*
* ADT List, implementada como Lista Doblemente Enlazada 						*
* 																				*
********************************************************************************/

#ifndef ADT_LIST_DOUBLELINKED_H_
#define ADT_LIST_DOUBLELINKED_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct node
{
	int value;
	struct node* next;
	struct node* prev;
} Node;


typedef struct List
{
	int size;
	Node* head;
	Node* tail;
}List;

List* createList();
int size_list(List* list);
void add(List* list, int element);
void add_at(List* list, int element, unsigned int pos);
int get(List* list, unsigned int pos);
void remove_at(List* list, unsigned int pos);
int indexOf(List* list, int element);
bool contains(List* list, int element);
void clear(List* list);
int set(List *list, int element, unsigned int pos);

/* ADT List, funciones auxiliares pero que no forman parte de la especificacion */
Node* createNode(int element, Node* next, Node* prev);
Node* getNodeAt(List* list, int unsigned pos);
void testLinkedList();

int lastIndexOf(List* list, int element);
List* reverseRec(List* list);
#endif /* ADT_LIST_DOUBLELINKED_H_ */
