/********************************************************************************
* 																				*
* ADT List, implemented as Double Linked List									*
* LOUDON, Kyle. Mastering Algorithms with C.. " O'Reilly Media, Inc.", 1999.  	*
*																				*
********************************************************************************/

#ifndef ADT_LIST_DOUBLELINKED_H_
#define ADT_LIST_DOUBLELINKED_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Comparators.h"
#include "Destructors.h"

typedef struct ll_node {
	void* data;
	struct node* next;
	struct node* prev;
} Node;


typedef struct ll_List {
	int size;
	Node* head;
	Node* tail;

	int(*comparator)(const void*, const void*); /* Pointer to a function used to properly compare data (must return 0 if equals) */
	void(*destroyer)(const void*); /* Pointer to a function used to propertly free the data in the list, could be NULL */
}List;

void testLinkedList();
List* createList(int(*comparator)(const void *, const void *), void(*destroyer)(const void*));
int size_list(List* list);
void add(List* list, void* element);
void add_at(List* list, void* element, unsigned int pos);
void* get(List* list, unsigned int pos);
void remove_at(List* list, unsigned int pos);
int indexOf(List* list, void* element);
bool contains(List* list, void* element);
void clear(List* list);
void* set(List *list, void* element, unsigned int pos);

/* ADT List, auxiliary functions not in the specification... */
Node* createNode(void* element, Node* next, Node* prev);
Node* getNodeAt(List* list, unsigned int pos);


#endif /* ADT_LIST_DOUBLELINKED_H_ */