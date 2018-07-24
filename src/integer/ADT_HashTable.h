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
	struct entry* next;
	struct entry* prev;
} Entry;


typedef struct hashTable{
	int size;
	int tableSize;
	Entry** table;
}HashTable;


HashTable* createHashTable();
bool containsKey(HashTable* ht, int key);
int get(HashTable* ht, int key);
void put(HashTable* ht, int key, int value);
void remove(HashTable* ht, int key);

int hashDiv(int key, int tableSize);


#endif /* ADT_HASHTABLE_H_ */