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
} Item;


typedef struct hashTable{
	int size;
	List** table;
	int tableSize;
	int(*hashFunction) (const void* key);	/* Pointer to a function to compute the key hash*/
	int(*keyComparator)(const void *, const void *);
	void(*destroyer)(const void*);	/* Pointer to a function used to propertly free values, could be NULL */
}HashTable;


HashTable* createHashTable(	int(*hash) (const void* key), 
							int(*comparator)(const void *, const void *),
							void(*destroyer)(const void*));
void* get(void* key);
void put(void* key, void* value);

int hashString(const void *lhs);
int hashInt(const void *lhs);
int compareItemInt(const void *lhs, const void *rhs);
int compareItemString(const void *lhs, const void *rhs);

#endif /* ADT_HASHTABLE_H_ */