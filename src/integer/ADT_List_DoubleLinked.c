/********************************************************************************
* 																				*
* ADT List, implemented as double linked list									*
* 																				*
********************************************************************************/

#include "ADT_List_DoubleLinked.h"

void ll_test() {
	int i, element, index;
	ll_List* list = ll_create();
	ll_add(list, 1);
	ll_add(list, 3);
	ll_add(list, 5);
	ll_add(list, 3);
	ll_add(list, 7);
	ll_add(list, 1);


	ll_deleteDup(list);


	for (i = 0; i<ll_size(list); i++) {
		printf("Element at %d is : %d \n", i, ll_get(list, i));
	}

	printf("\n");
	printf("IndexOf %d -> %d \n", 3, ll_indexOf(list, 3));
	printf("LastIndexOf %d -> %d \n", 3, ll_lastIndexOf(list, 3));

	element = 7;
	index = ll_indexOf(list, element);
	printf("Indexof %d is: %d \n", element, index);

	printf("\nDeleting element at %d...\n", index);
	ll_removeAt(list, index);


	printf("\n");
	for(i=0;i<ll_size(list);i++){
		element=ll_get(list, i);
		printf("Element at %d is : %d \n", i, element);
	}

	ll_clear(list);

	ll_add(list,2);
	ll_add(list,4);
	ll_add(list,6);
	ll_add(list,8);

	printf("\n");
	for(i=0;i<ll_size(list);i++){
		element=ll_get(list, i);
		printf("Element at %d is : %d \n", i, element);
	}

	ll_List* rev = ll_reverseRec(list);
	printf("\n");
	for (i = 0; i<ll_size(rev); i++) {
		printf("Element at %d is : %d \n", i, ll_get(rev, i));
	}
}

ll_List* ll_create() {
	ll_List* list = (ll_List*)malloc(sizeof(ll_List));
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	return list;
}

int ll_size(ll_List* list) {
	return list->size;
}

void ll_add(ll_List* list, int element) {
	ll_addAt(list, element, list->size);
}

void ll_addAt(ll_List* list, int element, unsigned int pos) {
	ll_Node* nn;
	ll_Node* cn;
	ll_Node* tmpl;

	if (pos >= 0 && pos <= list->size) {
		nn = ll_createNode(element, NULL, NULL);

		if (list->size == 0) {					/* The list is empty*/
			list->head = nn;
			list->tail = nn;
		}
		else {									/* The list is not empty */
			if (pos == list->size) { 			/* If pos points to the list tail */
				tmpl = list->tail;
				tmpl->next = nn;
				nn->prev = tmpl;
				list->tail = nn;
			}
			else {
				cn = ll_getNodeAt(list, pos);	/* At this point, pos is a valid position */

				if (pos == 0) { 				/* If pos points to the list head */
					cn->prev = nn;
					nn->next = cn;
					list->head = cn;
				}
				else { 							/* Adds to intermediate position */
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

int ll_get(ll_List* list, unsigned int pos) {
	ll_Node* n = ll_getNodeAt(list, pos);
	return n->value;
}

void ll_removeAt(ll_List* list, unsigned int pos) {
	ll_Node* cn;
	ll_Node* cnn;
	ll_Node* cnp;

	if (pos >= 0 && pos < list->size) {
		cn = ll_getNodeAt(list, pos);

		cnp = cn->prev;
		cnn = cn->next;


		if (cnp == NULL) {			/*cn = head (the one with ->prev = NULL)*/
			list->head = cnn;
		}
		else {
			cnp->next = cnn;
		}

		if (cnn == NULL) {			/*cn = trail (the one with ->next = NULL)*/
			list->tail = cnp;
		}
		else {
			cnn->prev = cnp;
		}
		list->size--;
		free(cn);
	}
	else {
		fprintf(stderr, "Invalid list index %d\n", pos);
		exit(EXIT_FAILURE);
	}
}

int ll_indexOf(ll_List* list, int element) {
	int index = 0;
	ll_Node* tmp = list->head;

	while (tmp != NULL) {
		if (tmp->value == element) {
			return index;
		}
		tmp = tmp->next;
		index++;
	}
	return -1;
}

bool ll_contains(ll_List* list, int element) {
	return ll_indexOf(list, element) != -1;
}

void ll_clear(ll_List* list) {
	while (list->size>0) {
		ll_removeAt(list, list->size - 1);
	}
}

int ll_set(ll_List *list, int element, unsigned int pos) {
	ll_Node* n = ll_getNodeAt(list, pos);
	int oldValue = n->value;
	n->value = element;
	return oldValue;
}


/* ADT List, auxiliary functions not in the specification... */

ll_Node* ll_createNode(int element, ll_Node* next, ll_Node* prev) {
	ll_Node* nn = (ll_Node*)malloc(sizeof(ll_Node));
	nn->value = element;
	nn->next = next;
	nn->prev = prev;

	return nn;
}

ll_Node* ll_getNodeAt(ll_List* list, unsigned int pos) {
	ll_Node* tmp;
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

void ll_print(ll_List* list) {
	ll_Node* h = list->head;
	
	while (h!=NULL) {
		printf("%d ", h->value);
		h = h->next;
	}
	printf("\n");
}

/********************************************************************************
* 																				*
* ADT List, extra funtions...													*
* 																				*
********************************************************************************/
int ll_lastIndexOf(ll_List* list, int element) {

	int index;
	for (index = ll_size(list) - 1; index >= 0; index--) {
		if (ll_get(list, index) == element) {
			return index;
		}
	}

	return -1;
}

/*Recursive list reversal*/
ll_List* ll_reverseRec(ll_List* list) {
	ll_List* rev;
	int e;
	if (ll_size(list) == 0) {
		return ll_create();
	}
	else {
		e = ll_get(list, 0);
		ll_removeAt(list, 0);
		rev = ll_reverseRec(list);
		ll_add(rev, e);
		return rev;
	}
}


/*Removing duplicates just with TDA List operations, without sort. Only one instance for element
is retained...*/
void ll_deleteDup(ll_List* list) {
	int i, j;
	for (i = 0; i < ll_size(list) - 1; i++) {
		for (j = ll_size(list) - 1; j > i; j--) {
			if (ll_get(list, i) == ll_get(list, j)) {
				ll_removeAt(list, j);
			}
		}
	}
}

void ll_testAlternate() {
	ll_List* l1 = ll_create();
	ll_List* l2 = ll_create();

	ll_add(l1, 1);
	ll_add(l1, 3);
	//ll_add(l1, 5); 
	//ll_add(l1, 7);

	ll_add(l2, 2);
	ll_add(l2, 4);
	ll_add(l2, 6);
	ll_add(l2, 8);

	ll_List* l3 = ll_alternate(l1, l2);
	ll_print(l3);

}

/* Alternating elements from two lists*/
ll_List* ll_alternate(ll_List* l1, ll_List* l2) {
	ll_List* r = ll_create();

	ll_Node* h1 = l1->head;
	ll_Node* h2 = l2->head;

	while (h1!=NULL && h2!=NULL) {
		ll_add(r, h1->value);
		ll_add(r, h2->value);
		h1 = h1->next;
		h2 = h2->next;
	}

	while (h1 != NULL) {
		ll_add(r, h1->value);
		h1 = h1->next;
	}

	while (h2 != NULL) {
		ll_add(r, h2->value);
		h2 = h2->next;
	}

	return r;
}