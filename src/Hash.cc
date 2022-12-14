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

HashItem::HashItem(VerbeteType type, std::string key, std::string data) : verbete(type, key, data){}

HashItem::~HashItem() {}

std::string HashItem::getKey() { return verbete.m_word; }

std::string HashItem::getData() {
	std::string meaning = *verbete.m_meaning;
	for (int i = 1; i < verbete.m_meaning_size; i++)
		meaning += "," + *(verbete.m_meaning + i);
	return meaning;
}

void HashItem::addData(std::string meaning) {
	verbete.addMeaning(meaning);
}
Hash::Hash() {
	HashItem* hashArray = (HashItem*) malloc (0 * sizeof (HashItem));
}
Hash::~Hash() {
	for (int i = 0; i < hashArraySize; ++i) 
		(hashArray+i)->~HashItem(); // This line calls destructors.
	
	hashArraySize = 0;
	delete hashArray;
}

HashItem* Hash::search(std::string key) {
	for (int i = 0; i < hashArraySize; ++i) {
		HashItem* item = hashArray + i;
		if (item->getKey() == key)
			return item;
	}

	return nullptr;
}

void Hash::insert(VerbeteType type, std::string key, std::string data) {
	HashItem *item = search(key);
	if (item == nullptr) {
		hashArraySize++;
		hashArray = (HashItem*)realloc(hashArray, hashArraySize * sizeof(HashItem));

		new (hashArray + (hashArraySize - 1)) HashItem(type, key, data);
	}
	else {
		item->addData(data);
	}
}

void Hash::remove(HashItem* item) {
	std::string key = item->getKey();

	for (int i = 0; i < hashArraySize; ++i, i %= hashArraySize) {
		HashItem* item = hashArray + i;

		if (item->getKey() == key) {
			(hashArray + i)->~HashItem();
			for (int j = i+1; j < hashArraySize; ++j)
				swap(hashArray + j, hashArray+j-1);

			hashArraySize--;
			
			break;
		}

	}
}
