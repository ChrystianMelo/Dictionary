#include "Hash.h"

#include <iostream>
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
Hash::Hash() {}

HashItem* Hash::search(int m_key) {
	for (int i = hashCode(m_key); i < hashArraySize; ++i) {
		HashItem* item = hashArray + i;
		if (item->m_key == m_key)
			return item;
	}

	return nullptr;
}

void Hash::insert(int key, int data) {
	hashArraySize++;
	hashArray = (HashItem*)realloc(hashArray, hashArraySize * sizeof(HashItem));

	*(hashArray + (hashArraySize - 1)) = HashItem(data, key);
}

void Hash::remove(HashItem* item) {
	int key = item->m_key;

	for (int i = hashCode(key); i < hashArraySize; ++i, i %= hashArraySize) {
		HashItem* item = hashArray + i;

		if (item->m_key == key) {

			for (int j = i+1; j < hashArraySize; ++j)
				swap(hashArray + j, hashArray+j-1);

			hashArraySize--;
			
			break;
		}

	}
}
