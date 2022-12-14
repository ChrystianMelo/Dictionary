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
#include<algorithm>

 /**
  * @brief
  */
class HashItem {
public:
	std::string m_key;
	std::string m_data;

	/**
	 * @brief
	 */
	HashItem(std::string key, std::string data);

	/**
	 * @brief
	 */
	~HashItem();

	bool operator<(const HashItem& b) {
		const char * thisData = m_data.c_str();
		const char * otherData = b.m_data.c_str();
		return std::lexicographical_compare(thisData, thisData + m_data.size(), otherData, otherData+ b.m_data.size());
	}

	bool operator>(const HashItem& b) {
		const char* thisData = m_data.c_str();
		const char* otherData = b.m_data.c_str();
		return !std::lexicographical_compare(thisData, thisData + m_data.size(), otherData, otherData + b.m_data.size());
	}

	bool operator==(const HashItem& b) {
		return m_data.compare(b.m_data) == 0;
	}

	bool operator<=(const HashItem& b) {
		const char* thisData = m_data.c_str();
		const char* otherData = b.m_data.c_str();
		return std::lexicographical_compare(thisData, thisData + m_data.size(), otherData, otherData + b.m_data.size()) || m_data.compare(b.m_data) == 0;
	}
};

/**
 * @brief
 *
 * --------> https ://www.tutorialspoint.com/data_structures_algorithms/hash_table_program_in_c.htm <------------------
 */
class Hash {
private:
	HashItem* hashArray;
	int hashArraySize = 0;

	/**
	 * @brief
	 */
	int hashCode(int m_key) { return m_key % hashArraySize; }

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
	HashItem* search(std::string m_key);

	/**
	 * @brief
	 */
	void insert(std::string key, std::string data);

	/**
	 * @brief
	 */
	void remove(HashItem* item);
};

#endif

