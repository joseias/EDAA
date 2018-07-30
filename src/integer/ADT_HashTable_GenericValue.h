/********************************************************************************
*																				*
* Simple ADT HasthTable with integers key and generic values.					*
* Collisions by chainning														*
* 																				*
********************************************************************************/

#ifndef ADT_HASHTABLE_H_
#define ADT_HASHTABLE_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "ADT_Set_Array.h"

typedef struct htig_entry {
	int key;
	void* value;
	struct htig_entry* prev;
	struct htig_entry* next;
} htig_Entry;


typedef struct htig_hashTable {
	int size;
	int tableSize;
	htig_Entry** table;
}htig_HashTable;

void htig_test();
htig_HashTable* htig_create();
bool htig_containsKey(htig_HashTable* ht, int key);
void* htig_get(htig_HashTable* ht, int key);
void* htig_put(htig_HashTable* ht, int key, void* value);
void* htig_remove(htig_HashTable* ht, int key);

int htig_hashDiv(int key, int tableSize);

#endif /* ADT_HASHTABLE_H_ */