#include "Hash.h"


namespace {
	/**
	 * @brief Troca as posições do array.
	 * 
	 * @param p1 Posição de origem
	 * @param p2 Posição destino.
	 */
	void swap(HashItem* p1, HashItem* p2)
	{
		HashItem temp = *p1;
		*p1 = *p2;
		*p2 = temp;
	}
}

HashItem::HashItem(std::string key, std::string data) : m_key(key), m_data(data) {}

HashItem::~HashItem() {}

Hash::Hash() {
	HashItem* hashArray = (HashItem*) malloc (0 * sizeof (HashItem));
}
Hash::~Hash() {
	for (int i = 0; i < hashArraySize; ++i) 
		(hashArray+i)->~HashItem(); // This line calls destructors.
	
	hashArraySize = 0;
	delete hashArray;
}

HashItem* Hash::search(std::string m_key) {
	for (int i = 0; i < hashArraySize; ++i) {
		HashItem* item = hashArray + i;
		if (item->m_key == m_key)
			return item;
	}

	return nullptr;
}

void Hash::insert(std::string key, std::string data) {
	hashArraySize++;
	hashArray = (HashItem*)realloc(hashArray, hashArraySize * sizeof(HashItem));

	new (hashArray + (hashArraySize - 1)) HashItem(key, data);
}

void Hash::remove(HashItem* item) {
	std::string key = item->m_key;

	for (int i = 0; i < hashArraySize; ++i, i %= hashArraySize) {
		HashItem* item = hashArray + i;

		if (item->m_key == key) {
			(hashArray + i)->~HashItem();
			for (int j = i+1; j < hashArraySize; ++j)
				swap(hashArray + j, hashArray+j-1);

			hashArraySize--;
			
			break;
		}

	}
}
