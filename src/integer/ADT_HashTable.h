/********************************************************************************
*																				*
* Simple ADT HasthTable with integers key and values. Collisions by chainning   *
* 																				*
********************************************************************************/

#ifndef ADT_HASHTABLE_H_
#define ADT_HASHTABLE_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "ADT_Set_Array.h"

typedef struct ht_entry{
	int key;
	int value;
	struct ht_entry* prev;
	struct ht_entry* next;
} ht_Entry;


typedef struct ht_hashTable{
	int size;
	int tableSize;
	ht_Entry** table;
}ht_HashTable;

void ht_test();
ht_HashTable* ht_create();
bool ht_containsKey(ht_HashTable* ht, int key);
int ht_get(ht_HashTable* ht, int key);
void ht_put(ht_HashTable* ht, int key, int value);
void ht_remove(ht_HashTable* ht, int key);

int hashDiv(int key, int tableSize);


void ht_testKeySet();
seta_Set* ht_keySet(ht_HashTable* ht);

void ht_testContainsValue();
bool ht_containsValue(ht_HashTable* ht, int value);
#endif /* ADT_HASHTABLE_H_ */