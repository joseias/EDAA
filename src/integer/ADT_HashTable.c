/********************************************************************************
* 																				*
* ADT HashTable, implementada con buckets de nodos enlazados					*
* 																				*
********************************************************************************/

#include "ADT_HashTable.h"

HashTable* createHashTable(){

	HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
	ht->size = 0;
	ht->tableSize = 13;

	ht->table = (Entry**) malloc(sizeof(Entry*) * ht->tableSize);

	int i;
	for (i = 0; i < ht->tableSize; i++) {
		ht->table[i] = NULL;
	}

	return ht;
}

bool containsKey(HashTable* ht, int key) {
	int index = hashDiv(key, ht->tableSize);
	Entry* entry = ht->table[index];

	while (entry != NULL) {
		if (entry->key == key) {
			return true;
		}
	}

	return false;
}

int get(HashTable* ht, int key) {
	int index = hashDiv(key, ht->tableSize);
	Entry* entry = ht->table[index];

	while (entry != NULL) {
		if (entry->key == key) {
			return entry->value;
		}
		else {
			entry = entry->next;
		}
	}

	return NULL;
}

void put(HashTable* ht, int key, int value) {
	int index = hashDiv(key, ht->tableSize);
	Entry* entry = ht->table[index];
	int oldValue;
	
	while(entry != NULL){
		
		/* Checks if the key is already in the hashtable*/
		if (entry->key == key) {
			oldValue = value;
			entry->value = value;
		}
		entry = entry->next;
	}
	
	Entry* en = (Entry*)malloc(sizeof(Entry));
	en->key = key;
	en->value = value;

	/* Updating pointers to put the new <key, value> as first entry in the bucket...*/
	en->prev = NULL;
	en->next = ht->table[index];
	ht->table[index]->prev = en;

	ht->table[index] = en; 
	ht->size++;
}

void remove(HashTable* ht, int key) {
	int index = hashDiv(key, ht->tableSize);
	Entry* entry = ht->table[index];

	while (entry != NULL) {
		if (entry->key == key) {
			/* Updating pointers to remove the entry...*/
			if (entry->next != NULL) {
				entry->next->prev = entry->prev;
			}

			if (entry->prev != NULL) {
				entry->prev->next = entry->next;
			}

			free(entry);
			entry = NULL;
		}
		else {
			entry = entry->next;
		}
	}

	ht->size--;
}


int hashDiv(int key, int tableSize) {
	return key % tableSize;
}