/********************************************************************************
* 																				*
* ADT HashTable, implementada con buckets de listas enlazadas					*
* 																				*
********************************************************************************/

#ifndef ADT_HASHTABLE_H_
#define ADT_HASHTABLE_H_

#include "ADT_List_DoubleLinked.h"

typedef struct item{
	void* key;
	void* value;

	int (*hash) (const void* key);
} Item;


typedef struct hashTable{
	int size;
	List** table;
	int tableSize;

	void(*destroyer)(const void*); /* Pointer to a function used to propertly free the data in the list, could be NULL */
}HashTable;


HashTable* createHashTableIntKey();
HashTable* createHashTableStringKey();
void* get(void* key);
void put(void* key, void* value);


int compareItemInt(const void *lhs, const void *rhs);
int compareItemString(const void *lhs, const void *rhs);

#endif /* ADT_HASHTABLE_H_ */