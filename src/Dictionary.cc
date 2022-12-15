#include "Dictionary.h"

Dictionary::Dictionary(DictionaryType type) : m_type(type), hash(nullptr), tree(nullptr)
{
	if (m_type == DictionaryType::HASH)
		hash = new Hash();
	else
		tree = new Tree();
}

Dictionary::~Dictionary()
{
	/*
	if (m_type == DictionaryType::HASH)
		delete hash;
	else
		delete tree;*/
}

Verbete &Dictionary::search(std::string word)
{
	if (m_type == DictionaryType::HASH)
	{
		HashItem *item = hash->search(word);
		if (item != nullptr)
			return item->getVerbete();
	}
	else
	{
		TreeNode *item = tree->search(word);
		if (item != nullptr)
			return item->getVerbete();
	}

	throw new std::exception();
}

void Dictionary::insert(VerbeteType type, std::string key, std::string data)
{
	if (m_type == DictionaryType::HASH)
		hash->insert(type, key, data);
	else
		tree->insert(type, key, data);
}

void Dictionary::imprimeDic() {}

void Dictionary::atualizaDic(Verbete *it)
{
	if (m_type == DictionaryType::HASH)
	{
		HashItem *item = hash->search(it->m_word);
		if (item != nullptr)
			item->setVerbete(*it);
		else
			throw new std::exception();
	}
	else
	{
		TreeNode *item = tree->search(it->m_word);
		if (item != nullptr)
			item->setVerbete(*it);
		else
			throw new std::exception();
	}
}

void Dictionary::remove(Verbete &it)
{
	if (m_type == DictionaryType::HASH)
	{
		HashItem *item = hash->search(it.m_word);
		if (item != nullptr)
			hash->remove(item);
		else
			throw new std::exception();
	}
	else
	{
		TreeNode *item = tree->search(it.m_word);
		if (item != nullptr)
			tree->remove(item);
		else
			throw new std::exception();
	}
}

std::string Dictionary::to_string()
{
	if (m_type == DictionaryType::HASH)
		return hash->to_string();
	else
		return tree->to_string();
}