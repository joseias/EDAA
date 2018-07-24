/********************************************************************************
* 																				*
* ADT List, implemented as Double Linked List									*
* LOUDON, Kyle. Mastering Algorithms with C.. " O'Reilly Media, Inc.", 1999.  	*
*																				*
********************************************************************************/

#include "ADT_List_DoubleLinked.h"

void main() {
	testLinkedList();
}


void ll_testList() {
	int i, index;
	Point* element;

	List* list = createList(comparePoints, destroyPoints);
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

	t->x = 5;
	t->y = 5;

	add(list, p1);
	add(list, p2);
	add(list, p3);
	add(list, p4);



	for (i = 0; i<size_list(list); i++) {
		element = (Point*)get(list, i);
		printf("Element at position %d is : ( %d, %d) \n", i, element->x, element->y);
	}

	printf("\n");
	printf("IndexOf (%d, %d) -> %d \n", p3->x, p3->y, indexOf(list, p3));

	index = 1;
	remove_at(list, index);

	printf("\n");
	printf("Setting (%d, %d) at position %d \n", t->x, t->y, index);
	set(list, t, index);

	printf("\n");
	for (i = 0; i<size_list(list); i++) {
		element = (Point*)get(list, i);
		printf("Element at position %d is : ( %d, %d) \n", i, element->x, element->y);
	}

	clear(list);
	printf("\n");
	for (i = 0; i<size_list(list); i++) {
		element = (Point*)get(list, i);
		printf("Element at position %d is : ( %d, %d) \n", i, element->x, element->y);
	}
}


List* ll_createList(int(*comparator)(const void *, const void *), void(*destroyer)(const void*)) {
	List* list = (List*)malloc(sizeof(List));
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	list->comparator = comparator;
	list->destroyer = destroyer;
	return list;
}

int ll_size(List* list) {
	return list->size;
}

void ll_add(List* list, void* element) {
	ll_addAt(list, element, list->size);
}

void ll_addAt(List* list, void* element, unsigned int pos) {
	Node* nn;
	Node* cn;
	Node* tmpl;

	if (pos >= 0 && pos <= list->size) {
		nn = createNode(element, NULL, NULL);

		if (list->size == 0) {				/* The list is empty*/
			list->head = nn;
			list->tail = nn;
		}
		else {								/* The list is not empty */
			if (pos == list->size) { 		/* If pos points to the list end */
				tmpl = list->tail;
				tmpl->next = nn;
				nn->prev = tmpl;
				list->tail = nn;
			}
			else {
				cn = getNodeAt(list, pos);	/* At this point, pos is a valid position */

				if (pos == 0) { 			/* If pos points to the list init*/
					cn->prev = nn;
					nn->next = cn;
					list->head = cn;
				}
				else { 						/* Adds to intermediate position */
					(cn->prev)->next = nn;
					nn->prev = cn->prev;
					cn->prev = nn;
					nn->next = cn;
				}
			}
		}
		list->size++;
	}
	else {
		fprintf(stderr, "Invalid list index %d\n", pos);
		exit(EXIT_FAILURE);
	}

}

void* ll_get(List* list, unsigned int pos) {
	Node* n = getNodeAt(list, pos);
	return n->data;
}

void ll_removeAt(List* list, unsigned int pos) {
	Node* cn;
	Node* cnn;
	Node* cnp;

	if (pos >= 0 && pos < list->size) {
		cn = getNodeAt(list, pos);

		cnp = cn->prev;
		cnn = cn->next;


		if (cnp == NULL) { /*cn = head (the one with ->prev = NULL)*/
			list->head = cnn;
		}
		else {
			cnp->next = cnn;
		}

		if (cnn == NULL) { /*cn = trail (the one with ->next = NULL)*/
			list->tail = cnp;
		}
		else {
			cnn->prev = cnp;
		}
		list->size--;

		if (list->destroyer != NULL) {
			list->destroyer(cn->data);
		}
		free(cn);
	}
	else {
		fprintf(stderr, "Invalid list index %d\n", pos);
		exit(EXIT_FAILURE);
	}
}

int ll_indexOf(List* list, void* element) {
	int index = 0;
	Node* tmp = list->head;

	while (tmp != NULL) {
		if (list->comparator(tmp->data, element) == 0) {
			return index;
		}
		tmp = tmp->next;
		index++;
	}
	return -1;
}

bool ll_contains(List* list, void* element) {
	return indexOf(list, element) != -1;
}

void ll_clear(List* list) {
	while (list->size>0) {
		remove_at(list, list->size - 1);
	}
}

void* ll_set(List *list, void* element, unsigned int pos) {
	Node* n = getNodeAt(list, pos);
	int oldValue = n->data;
	n->data = element;
	return oldValue;
}

Node* ll_createNode(void* element, Node* next, Node* prev) {
	Node* nn = (Node*)malloc(sizeof(Node));
	nn->data = element;
	nn->next = next;
	nn->prev = prev;

	return nn;
}
Node* ll_getNodeAt(List* list, unsigned int pos) {
	Node* tmp;
	int i;
	if (pos >= 0 && pos < list->size) {
		tmp = list->head;

		for (i = 1; i <= pos; i++) {
			tmp = tmp->next;
		}

		return tmp;
	}
	else {
		fprintf(stderr, "Invalid list index %d\n", pos);
		exit(EXIT_FAILURE);
	}
}