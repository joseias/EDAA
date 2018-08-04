

/********************************************************************************
*																				*
* Simple ADT HasthTable with integers key and values. Collisions by chainning   *
* 																				*
********************************************************************************/

#include "ADT_HashTable.h"
void ht_test() {

	ht_HashTable* ht = ht_create();
	ht_put(ht, 2002, 2);
	ht_put(ht, 2012, 12);
	ht_put(ht, 2014, 14);
	ht_put(ht, 2015, 15);

	int key;
	for (key = 2000; key <= 2015; ++key) {
		if (ht_containsKey(ht, key)) {
			printf("Key %d found, value -> %d \n", key, ht_get(ht, key));
		}
		else {
			printf("Key %d not found... \n", key);
		}
	}

	key = 2002;
	printf("\nRemoving key %d ...\n\n", key);
	if (ht_containsKey(ht, key)) {
		ht_remove(ht, key);
	}

	for (key = 2000; key <= 2015; ++key) {
		if (ht_containsKey(ht, key)) {
			printf("Key %d found, value -> %d \n", key, ht_get(ht, key));
		}
		else {
			printf("Key %d not found... \n", key);
		}
	}
}

ht_HashTable* ht_create() {

	ht_HashTable* ht = (ht_HashTable*)malloc(sizeof(ht_HashTable));
	ht->size = 0;
	ht->tableSize = 13;

	ht->table = (ht_Entry**)malloc(sizeof(ht_Entry*) * ht->tableSize);

	int i;
	for (i = 0; i < ht->tableSize; i++) {
		ht->table[i] = NULL;
	}

	return ht;
}


bool ht_containsKey(ht_HashTable* ht, int key) {
	int index = hashDiv(key, ht->tableSize);
	ht_Entry* entry = ht->table[index];

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

int ht_get(ht_HashTable* ht, int key) {
	int index = hashDiv(key, ht->tableSize);
	ht_Entry* entry = ht->table[index];
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

void ht_put(ht_HashTable* ht, int key, int value) {
	int index = hashDiv(key, ht->tableSize);
	ht_Entry* entry = ht->table[index];
	int oldValue;
	bool found = false;

	while (entry != NULL && !found) {
		/* Checks if the key is already in the ht_HashTable*/
		if (entry->key == key) {
			oldValue = value;
			entry->value = value;
			found = true;
		}
		entry = entry->next;
	}


	if (!found) {
		ht_Entry* en = (ht_Entry*)malloc(sizeof(ht_Entry));
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
}

void ht_remove(ht_HashTable* ht, int key) {
	int index = hashDiv(key, ht->tableSize);
	ht_Entry* entry = ht->table[index];
	bool found = false;

	while (entry != NULL && !found) {
		if (entry->key == key) {
			found = true;

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
}


int hashDiv(int key, int tableSize) {
	return key % tableSize;
}

void ht_testKeySet() {
	ht_HashTable* ht = ht_create();
	ht_put(ht, 2002, 2);
	ht_put(ht, 2012, 12);
	ht_put(ht, 2014, 14);
	ht_put(ht, 2015, 15);

	seta_Set* keys = ht_keySet(ht);
	seta_print(keys);
}


seta_Set* ht_keySet(ht_HashTable* ht) {
	seta_Set* keys = seta_create();

	int bucket;

	for (bucket = 0; bucket < ht->tableSize; ++bucket) {
		ht_Entry* entry = ht->table[bucket];

		while (entry != NULL) {
			seta_add(keys, entry->key);
			entry = entry->next;
		}
	}

	return keys;
}


void ht_testContainsValue(){

	ht_HashTable* ht = ht_create();
	ht_put(ht, 1, 2001);
	ht_put(ht, 2, 2002);
	ht_put(ht, 3, 2003);

	int query = 2002;
	if (ht_containsValue(ht, query)) {
		printf("Value %d  found...\n ", query);
	}
	else {
		printf("Value %d not found...\n ", query);
	}
}



bool ht_containsValue(ht_HashTable* ht, int value) {
	int bucket;
	bool found = false;

	for (bucket = 0; bucket < ht->tableSize; ++bucket) {
		ht_Entry* entry = ht->table[bucket];

		while (entry != NULL && !found) {
			if (entry->value == value) {
				found = true;
			}
			else {
				entry = entry->next;
			}
		}
	}

	return found;
}