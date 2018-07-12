#include "ADT_HashTable.h"

HashTable* createHashTableIntKey() {
	HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
	ht->size = 0;
	ht->tableSize = 16;

	ht->table = (List**)malloc(sizeof(List) * ht->tableSize);

	int i;
	for (i = 0; i < ht->tableSize; i++) {
		ht->table[i] = createList(compareItemInt, NULL);
	}

	return ht;
}


HashTable* createHashTableStringKey() {
	HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
	ht->size = 0;
	ht->tableSize = 16;

	ht->table = (List**)malloc(sizeof(List) * ht->tableSize);

	int i;
	for (i = 0; i < ht->tableSize; i++) {
		ht->table[i] = createList(compareItemString, NULL);
	}

	return ht;
}


void put(void* key, void* value) {

}


int compareItemInt(const void *lhs, const void *rhs){
	const Item *llhs = (const Item*)lhs;
	const Item *lrhs = (const Item*)rhs;

	return compareInt(llhs->key, lrhs->key);
}

int compareItemString(const void *lhs, const void *rhs) {
	const Item *llhs = (const Item*)lhs;
	const Item *lrhs = (const Item*)rhs;

	return strcmp(llhs->key, lrhs->key);
}