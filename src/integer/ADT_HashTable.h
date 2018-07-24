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

typedef struct entry{
	int key;
	int value;
	struct entry* prev;
	struct entry* next;
} Entry;


typedef struct hashTable{
	int size;
	int tableSize;
	Entry** table;
}HashTable;

void ht_test();
HashTable* ht_create();
bool ht_containsKey(HashTable* ht, int key);
int ht_get(HashTable* ht, int key);
void ht_put(HashTable* ht, int key, int value);
void ht_remove(HashTable* ht, int key);

int hashDiv(int key, int tableSize);

#endif /* ADT_HASHTABLE_H_ */