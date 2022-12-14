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

enum NodeFlag {
	LEFT_NODE, RIGHT_NODE
};

/**
 * @brief
 */
class TreeNode {
public:
	int m_key;
	std::string m_data;
	TreeNode* parent;
	TreeNode* leftChild;
	TreeNode* rightChild;

	TreeNode(int key, std::string data);
};

/**
 * @brief
 * -----------> https://www.codigofonte.com.br/wp-content/uploads/legado/codigos/1090/Trabalho.cpp <-----------
 */
class Tree {
private:
	TreeNode* m_root;
public:
	/**
	 * @brief
	 */
	TreeNode* search(int key);

	/**
	 * @brief
	 */

	void insert(int key, std::string data);

	/**
	 * @brief
	 */
	void remove(TreeNode * node);
};
#endif