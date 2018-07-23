/********************************************************************************
* 																				*
* ADT HashTable, implementada con buckets de listas enlazadas					*
* 																				*
********************************************************************************/

#ifndef ADT_HASHTABLE_H_
#define ADT_HASHTABLE_H_

#include "ADT_List_DoubleLinked.h"

typedef struct entry{
	void* key;
	void* value;
} Entry;


typedef struct hashTable{
	int size;
	List** table;
	int tableSize;
	int(*hashFunction) (const void* key);	/* Pointer to a function to compute the key hash*/
	int(*keyComparator)(const void *, const void *);
	int(*entryComparator)(const void *, const void *);
	void(*destroyer)(const void*);	/* Pointer to a function used to propertly free values, could be NULL */
}HashTable;


HashTable* createHashTable(	int(*hash) (const void* key), 
							int(*keyCmp)(const void *, const void *),
							int(*entryCmp)(const void *, const void *),
							void(*destroyer)(const void*));

void* get(HashTable* ht, void* key);
void* put(HashTable* ht, void* key, void* value);
void* remove(HashTable* ht, void* key);

int hashString(const void *lhs);
int hashInt(const void *lhs);
int compareItemInt(const void *lhs, const void *rhs);
int compareItemString(const void *lhs, const void *rhs);

#endif /* ADT_HASHTABLE_H_ */