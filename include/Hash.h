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

 /**
  * @brief
  */
class HashItem {
public:
	int m_data;
	int m_key;
	/**
 * @brief
 */
	HashItem(int data, int key) : m_data(data), m_key(key) {};
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
	HashItem* search(int m_key);

	/**
	 * @brief
	 */
	void insert(int key, int data);

	/**
	 * @brief
	 */
	void remove(HashItem* item);
};

#endif

