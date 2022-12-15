#include "Hash.h"

#include <algorithm>

namespace
{
	/**
	 * @brief Troca as posi��es do array.
	 *
	 * @param p1 Posi��o de origem
	 * @param p2 Posi��o destino.
	 */
	void swap(HashItem *p1, HashItem *p2)
	{
		HashItem temp = *p1;
		*p1 = *p2;
		*p2 = temp;
	}

	int getOccurrences(std::string* names, int size, std::string word) {
		int count = 0;

		for (int i = 0; i < size; i++) {
			if (names[i].compare(word) == 0)
				count++;
		}

		return count;
	}
}

HashItem::HashItem(VerbeteType type, std::string key, std::string data) : verbete(type, key, data) {}

HashItem::~HashItem() {}

void HashItem::setVerbete(Verbete &v) { verbete = v; }

Verbete &HashItem::getVerbete() { return verbete; }

std::string HashItem::getKey() { return verbete.m_word; }

std::string HashItem::getData()
{
	std::string meaning = *verbete.m_meaning;
	for (int i = 1; i < verbete.m_meaning_size; i++)
		meaning += "," + *(verbete.m_meaning + i);
	return meaning;
}

void HashItem::addData(std::string meaning)
{
	verbete.addMeaning(meaning);
}
Hash::Hash()
{
	HashItem *hashArray = (HashItem *)malloc(0 * sizeof(HashItem));
}
Hash::~Hash()
{
	for (int i = 0; i < hashArraySize; ++i)
		(hashArray + i)->~HashItem(); // This line calls destructors.

	hashArraySize = 0;
	// delete hashArray;
}

HashItem* Hash::search(std::string key, VerbeteType type) {

	for (int i = 0; i < hashArraySize; ++i)
	{
		HashItem* item = hashArray + i;
		if (item->getKey() == key && item->getVerbete().m_type == type)
			return item;
	}

	return nullptr;
}
HashItem *Hash::search(std::string key)
{
	for (int i = 0; i < hashArraySize; ++i)
	{
		HashItem *item = hashArray + i;
		if (item->getKey() == key)
			return item;
	}

	return nullptr;
}

void Hash::insert(VerbeteType type, std::string key, std::string data)
{
	HashItem *item = search(key, type);
	if (item == nullptr || (item != nullptr && type != item->getVerbete().m_type))
	{
		hashArraySize++;
		hashArray = (HashItem *)realloc(hashArray, hashArraySize * sizeof(HashItem));

		new (hashArray + (hashArraySize - 1)) HashItem(type, key, data);
	}
	else
	{
		item->addData(data);
	}
}

void Hash::remove(HashItem *item)
{
	std::string key = item->getKey();

	for (int i = 0; i < hashArraySize; ++i, i %= hashArraySize)
	{
		HashItem *item = hashArray + i;

		if (item->getKey() == key)
		{
			//(hashArray + i)->~HashItem();
			for (int j = i + 1; j < hashArraySize; ++j)
				swap(hashArray + j, hashArray + j - 1);

			hashArraySize--;

			break;
		}
	}
}

void Hash::removeWordsWithMeaning()
{
	for (int i = 0; i < hashArraySize; ++i)
	{
		HashItem *item = (hashArray + i);
		if (item->getVerbete().hasMeaning())
			remove(item);
	}
}

std::string Hash::to_string()
{
	std::string *names;

	names = (std::string *)malloc(hashArraySize * sizeof(std::string));

	for (int i = 0; i < hashArraySize; ++i)
	{
		new (names + i) std::string((hashArray + i)->getKey());
	}

	// Fiz o uso de um algoritmo da stl, não é uma estrutura de dados já imlementadas, o que é proibido.
	std::sort(names, names + hashArraySize);

	HashItem *item = search(*names);
	Verbete v = item->getVerbete();
	std::string output = v.m_word + " " + v.getType();
	if (v.hasMeaning())
		output += "\n" + v.getMeaning();

	for (int i = 1; i < hashArraySize; ++i)
	{
		int count = getOccurrences(names, hashArraySize, search(*(names + i))->getKey());
		i += count-1;
		if (count > 0) {
			auto* node = search(*(names + i), VerbeteType::ADJETIVO);
			if (node != nullptr) {
				Verbete v = node->getVerbete();
				output += "\n";
				output += v.m_word + " " + v.getType();
				if (v.hasMeaning())
					output += "\n" + v.getMeaning();
				count--;
			}
		}

		if (count > 0) {
			auto* node = search(*(names + i), VerbeteType::NOME);
			if (node != nullptr) {
				Verbete v = node->getVerbete();
				output += "\n";
				output += v.m_word + " " + v.getType();
				if (v.hasMeaning())
					output += "\n" + v.getMeaning();
				count--;
			}
		}

		if (count > 0) {
			auto* node = search(*(names + i), VerbeteType::VERBO);
			if (node != nullptr) {
				Verbete v = node->getVerbete();
				output += "\n";
				output += v.m_word + " " + v.getType();
				if (v.hasMeaning())
					output += "\n" + v.getMeaning();
				count--;
			}
		}
	}

	return output;
}

std::string Hash::to_string2() {
	std::string* names;

	names = (std::string*)malloc(hashArraySize * sizeof(std::string));

	for (int i = 0; i < hashArraySize; ++i)
	{
		new (names + i) std::string((hashArray + i)->getKey());
	}

	std::sort(names, names + hashArraySize);

	HashItem* item = search(*names);
	std::string output = "";
	if (!item->getVerbete().hasMeaning()) {
		Verbete v = item->getVerbete();
		output += v.m_word + " " + v.getType();
		if (v.hasMeaning())
			output += "\n" + v.getMeaning();
	}

	for (int i = 1; i < hashArraySize; ++i)
	{
		int count = getOccurrences(names, hashArraySize, search(*(names + i))->getKey());
		i += count - 1;
		if (count > 0) {
			auto* node = search(*(names + i), VerbeteType::ADJETIVO);
			if (node != nullptr && !node->getVerbete().hasMeaning()) {
				Verbete v = node->getVerbete();
				output += "\n";
				output += v.m_word + " " + v.getType();
				if (v.hasMeaning())
					output += "\n" + v.getMeaning();
				count--;
			}
		}

		if (count > 0) {
			auto* node = search(*(names + i), VerbeteType::NOME);
			if (node != nullptr && !node->getVerbete().hasMeaning()) {
				Verbete v = node->getVerbete();
				output += "\n";
				output += v.m_word + " " + v.getType();
				if (v.hasMeaning())
					output += "\n" + v.getMeaning();
				count--;
			}
		}

		if (count > 0) {
			auto* node = search(*(names + i), VerbeteType::VERBO);
			if (node != nullptr && !node->getVerbete().hasMeaning()) {
				Verbete v = node->getVerbete();
				output += "\n";
				output += v.m_word + " " + v.getType();
				if (v.hasMeaning())
					output += "\n" + v.getMeaning();
				count--;
			}
		}
	}

	return output;

}
