#include "ADT_HashTable.h"

HashTable* createHashTable(int(*hash) (const void* key),
	int(*comparator)(const void *, const void *),
	void(*destroyer)(const void*)){
	HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
	ht->size = 0;
	ht->tableSize = 16;

	ht->table = (List**)malloc(sizeof(List) * ht->tableSize);
	ht->hashFunction = hash;

	int i;
	for (i = 0; i < ht->tableSize; i++) {
		ht->table[i] = createList(comparator, destroyer);
	}

	return ht;
}

void put(HashTable* ht, void* key, void* value) {
	int index = ht->hashFunction(key) % ht->tableSize;
	List* bucket = ht->table[index];
	Item* ni = (Item*)malloc(sizeof(Item));
	ni->key = key;
	ni->value = value;

	int pos = indexOf(bucket, ni);
	if () {
	
	}
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