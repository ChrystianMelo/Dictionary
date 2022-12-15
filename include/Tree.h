/**
 * @file Tree.h
 * @author Chrystian Melo (meloo.chrys@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-12-13
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <string.h>
#include "Verbete.h"

/**
 * @brief
 */
enum NodeFlag
{
	LEFT_NODE,
	RIGHT_NODE
};

/**
 * @brief
 */
class TreeNode
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
	TreeNode *parent;

	/**
	 * @brief
	 */
	TreeNode *leftChild;

	/**
	 * @brief
	 */
	TreeNode *rightChild;

public:
	/**
	 * @brief Construtor da classe.
	 */
	TreeNode(VerbeteType type, std::string key, std::string data);

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
};

/**
 * @brief
 * -----------> https://www.codigofonte.com.br/wp-content/uploads/legado/codigos/1090/Trabalho.cpp <-----------
 */
class Tree
{
private:
	/**
	 * @brief
	 */
	TreeNode *m_root;

	/**
	 * @brief
	 */
	int m_size;

public:
	/**
	 * @brief
	 */
	Tree();
	/**
	 * @brief
	 */
	TreeNode *search(std::string key);

	/**
	 * @brief
	 */
	void insert(VerbeteType type, std::string key, std::string data);

	/**
	 * @brief
	 */
	void remove(TreeNode *node);

	/**
	 * @brief
	 */
	void removeWordsWithMeaning();

	/**
	 * @brief
	 */
	std::string to_string();
};
#endif