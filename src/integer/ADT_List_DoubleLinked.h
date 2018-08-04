/********************************************************************************
* 																				*
* ADT List, implemented as double linked list									*
* 																				*
********************************************************************************/

#ifndef ADT_LIST_DOUBLELINKED_H_
#define ADT_LIST_DOUBLELINKED_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct ll_node
{
	int value;
	struct ll_node* next;
	struct ll_node* prev;
} ll_Node;


typedef struct ll_List
{
	int size;
	ll_Node* head;
	ll_Node* tail;
}ll_List;

void ll_test();
ll_List* ll_create();
int ll_size(ll_List* list);
void ll_add(ll_List* list, int element);
void ll_addAt(ll_List* list, int element, unsigned int pos);
int ll_get(ll_List* list, unsigned int pos);
void ll_removeAt(ll_List* list, unsigned int pos);
int ll_indexOf(ll_List* list, int element);
bool ll_contains(ll_List* list, int element);
void ll_clear(ll_List* list);
int ll_set(ll_List *list, int element, unsigned int pos);

/* ADT List, auxiliary functions not in the specification... */

ll_Node* ll_createNode(int element, ll_Node* next, ll_Node* prev);
ll_Node* ll_getNodeAt(ll_List* list, int unsigned pos);
void ll_print(ll_List* list);


/********************************************************************************
* 																				*
* ADT List, extra funtions...													*
* 																				*
********************************************************************************/

/* Index of last ocurrence of element in the list. */
int ll_lastIndexOf(ll_List* list, int element);

/*Recursive list reversal.*/
ll_List* ll_reverseRec(ll_List* list);

/*Removing duplicates just with TDA List operations*/
void ll_deleteDup(ll_List* list);
#endif /* ADT_LIST_DOUBLELINKED_H_ */

void ll_testAlternate();
ll_List* ll_alternate(ll_List* l1, ll_List* l2);