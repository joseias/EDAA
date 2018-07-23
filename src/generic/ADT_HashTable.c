#include "ADT_HashTable.h"

HashTable* createHashTable(int(*hash) (const void* key),
	int(*keyCmp)(const void *, const void *),
	int(*entryCmp)(const void *, const void *),
	void(*destroyer)(const void*)){

	HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
	ht->size = 0;
	ht->tableSize = 16;

	ht->table = (List**)malloc(sizeof(List) * ht->tableSize);
	ht->hashFunction = hash;
	ht->keyComparator = keyCmp;
	ht->entryComparator = entryCmp;

	int i;
	for (i = 0; i < ht->tableSize; i++) {
		ht->table[i] = createList(entryCmp, destroyer);
	}

	return ht;
}

void* get(HashTable* ht, void* key) {
	int index = ht->hashFunction(key) % ht->tableSize;
	List* bucket = ht->table[index];

	int pos;
	for (pos = 0; pos < size_list(bucket); ++pos) {
		Entry* entry = (Entry*)get(bucket, pos);

		/*Search if the key is present. Note that this is an inefficient implementation
		since the list need to be traversed several times. However, this implementation
		of HashTable is intended to illustrate also the application of List ADT (without List Iterator)*/

		if (ht->keyComparator(entry->key, key) == 0) {
			return entry->value;
		}
	}

	return NULL;
}

void* put(HashTable* ht, void* key, void* value) {
	int index = ht->hashFunction(key) % ht->tableSize;
	List* bucket = ht->table[index];
	void* oldValue;
	
	/*Search if the key is present. Note that this is an inefficient implementation
	since the list need to be traversed several times. However, this implementation
	of HashTable is intended to illustrate also the application of List ADT (without List Iterator)*/
	int pos;
	for (pos = 0; pos < size_list(bucket); ++pos) {
		Entry* entry = (Entry*) get(bucket, pos);

		if (ht->keyComparator(entry->key, key) == 0) {
			oldValue = entry->value;
			entry->value = value;
			return oldValue;
		}
	}

	Entry* en = (Entry*)malloc(sizeof(Entry));
	en->key = key;
	en->value = value;
	add(bucket, en);
	ht->size++;
	return NULL;
}

void remove(HashTable* ht, void* key) {
	int index = ht->hashFunction(key) % ht->tableSize;
	List* bucket = ht->table[index];

	/*Search if the key is present. Note that this is an inefficient implementation
	since the list need to be traversed several times. However, this implementation
	of HashTable is intended to illustrate also the application of List ADT (without List Iterator)*/
	int pos;
	for (pos = 0; pos < size_list(bucket); ++pos) {
		Entry* entry = (Entry*)get(bucket, pos);

		if (ht->keyComparator(entry->key, key) == 0) {
			remove_at(bucket, pos);
		}
	}


	ht->size--;
}

int compareEntryInt(const void *lhs, const void *rhs){
	const Entry *llhs = (const Entry*)lhs;
	const Entry *lrhs = (const Entry*)rhs;

	return compareInt(llhs->key, lrhs->key);
}

int compareEntryString(const void *lhs, const void *rhs) {
	const Entry *llhs = (const Entry*)lhs;
	const Entry *lrhs = (const Entry*)rhs;

	return strcmp(llhs->key, lrhs->key);
}