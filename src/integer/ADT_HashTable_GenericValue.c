/********************************************************************************
*																				*
* Simple ADT HasthTable with integers key and generic values.					*
* Collisions by chainning														*
* 																				*
********************************************************************************/

#include "ADT_HashTable_GenericValue.h"
#include "ADT_List_DoubleLinked.h"
#include "ADT_Stack_Linked.h";

void htig_test() {

	htig_HashTable* ht = htig_create();
	ll_List* l1 = ll_create();
	ll_add(l1, 1);
	ll_add(l1, 3);
	ll_add(l1, 5);

	ll_List* l2 = ll_create();
	ll_add(l2, 2);
	ll_add(l2, 4);
	ll_add(l2, 6);

	htig_put(ht, 1, l1);
	htig_put(ht, 2, l2);

	ll_List* tmp = (ll_List*) htig_get(ht, 2);
	ll_add(tmp, 8);

	tmp = htig_get(ht, 1);

	int e;
	for (e = 0; e < ll_size(tmp); ++e) {
		printf("%d ", ll_get(tmp, e));
	}
	printf("\n");

	tmp = htig_get(ht, 2);

	for (e = 0; e < ll_size(tmp); ++e) {
		printf("%d ", ll_get(tmp, e));
	}
	printf("\n");

	ll_List* old = (ll_List*) htig_remove(ht, 1);

	htig_remove(ht, 1);
	for (e = 0; e < ll_size(old); ++e) {
		printf("%d ", ll_get(old, e));
	}
	printf("\n");


	htig_HashTable* hts = htig_create();
	sl_Stack* s = sl_create();
	sl_push(s, 1);
	sl_push(s, 2);
	sl_push(s, 3);

	htig_put(hts, 1, s);
	sl_Stack* v = htig_get(hts, 1);

	printf("\n %d", sl_peek(v));

}

htig_HashTable* htig_create() {

	htig_HashTable* ht = (htig_HashTable*)malloc(sizeof(htig_HashTable));
	ht->size = 0;
	ht->tableSize = 13;

	ht->table = (htig_Entry**)malloc(sizeof(htig_Entry*) * ht->tableSize);

	int i;
	for (i = 0; i < ht->tableSize; i++) {
		ht->table[i] = NULL;
	}

	return ht;
}


bool htig_containsKey(htig_HashTable* ht, int key) {
	int index = htig_hashDiv(key, ht->tableSize);
	htig_Entry* entry = ht->table[index];

	while (entry != NULL) {
		if (entry->key == key) {
			return true;
		}
		else {
			entry = entry->next;
		}
	}

	return false;
}

void* htig_get(htig_HashTable* ht, int key) {
	int index = htig_hashDiv(key, ht->tableSize);
	htig_Entry* entry = ht->table[index];
	bool found = false;

	while (entry != NULL && !found) {
		if (entry->key == key) {
			found = true;
		}
		else {
			entry = entry->next;
		}
	}

	if (found) {
		return entry->value;
	}
	else {
		fprintf(stderr, "Key %d not found ...\n", key);
		exit(EXIT_FAILURE);
	}
}

void* htig_put(htig_HashTable* ht, int key, void* value) {
	int index = htig_hashDiv(key, ht->tableSize);
	htig_Entry* entry = ht->table[index];
	void* oldValue = NULL;
	bool found = false;

	while (entry != NULL && !found) {
		/* Checks if the key is already in the hashtable*/
		if (entry->key == key) {
			oldValue = value;
			entry->value = value;
			found = true;
		}
		entry = entry->next;
	}


	if (!found) {
		htig_Entry* en = (htig_Entry*)malloc(sizeof(htig_Entry));
		en->key = key;
		en->value = value;

		/* Updating pointers to put the new <key, value> as first entry in the bucket...*/
		en->prev = NULL;
		en->next = ht->table[index];

		if (ht->table[index] == NULL) { /*First element in the bucket...*/
			ht->table[index] = en;
		}
		else {
			ht->table[index]->prev = en;
			ht->table[index] = en;
		}

		ht->size++;
	}

	return oldValue;
}

void* htig_remove(htig_HashTable* ht, int key) {
	int index = htig_hashDiv(key, ht->tableSize);
	htig_Entry* entry = ht->table[index];
	bool found = false;
	void* value = NULL;

	while (entry != NULL && !found) {
		if (entry->key == key) {
			found = true;
			value = entry->value;
			if (entry->next == NULL && entry->prev == NULL) { /*The only entry in the bucket*/
				ht->table[index] = NULL;
			}
			else {
				/* Updating pointers to remove the entry...*/
				if (entry->next != NULL) {
					entry->next->prev = entry->prev;
				}

				if (entry->prev != NULL) {
					entry->prev->next = entry->next;
				}
			}
			free(entry);
			ht->size--;
		}
		else {
			entry = entry->next;
		}
	}

	return value;
}


int htig_hashDiv(int key, int tableSize) {
	return key % tableSize;
}

