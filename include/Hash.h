/**
 * @file Hash.h
 * @author Chrystian Melo (meloo.chrys@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-12-13
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <string.h>
#include "Verbete.h"

/**
 * @brief
 */
class HashItem
{
private:
	/**
	 * @brief
	 */
	Verbete verbete;

public:
	/**
	 * @brief
	 */
	void setVerbete(Verbete &v);

	/**
	 * @brief
	 */
	Verbete &getVerbete();

	/**
	 * @brief
	 */
	std::string getKey();

	/**
	 * @brief
	 */
	std::string getData();

	/**
	 * @brief
	 */
	void addData(std::string meaning);

	/**
	 * @brief
	 */
	HashItem(VerbeteType type, std::string key, std::string data);

	/**
	 * @brief
	 */
	~HashItem();
};

/**
 * @brief
 *
 * 
 */
class Hash
{
private:
	/**
	 * @brief
	 */
	HashItem *hashArray;

	/**
	 * @brief
	 */
	int hashArraySize = 0;

	/**
	 * @brief
	 */
	int hashCode(int key) { return key % hashArraySize; }

public:
	/**
	 * @brief
	 */
	Hash();

	/**
	 * @brief
	 */
	~Hash();

	/**
	 * @brief
	 */
	HashItem *search(std::string key);

	/**
	 * @brief
	 */
	HashItem* search(std::string key, VerbeteType type);

	/**
	 * @brief
	 */
	void insert(VerbeteType type, std::string key, std::string data);

	/**
	 * @brief
	 */
	void remove(HashItem *item);

	/**
	 * @brief
	 */
	void removeWordsWithMeaning();

	/**
	 * @brief
	 */
	std::string to_string();

	/**
	 * @brief
	 */
	std::string to_string2();
};

#endif
