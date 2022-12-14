/**
 * @file Main.cc
 * @author Chrystian Melo (meloo.chrys@gmail.com)
 * @brief Classe principal do projeto.
 * @version 0.1
 * @date 2022-12-13
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <string.h>

#include "Dictionary.h"
#include "Tree.h"
#include "Hash.h"

 /**
  * @brief Metodo principal.
  */
int main()
{
	//Dictionary* pTest = new Dictionary(3);

	std::cout << "--------------HASH------------"<< std::endl;
	Hash hash = Hash();

	hash.insert(1, "20");
	hash.insert(2, "70");
	hash.insert(42, "80");
	hash.insert(4, "25");
	hash.insert(12, "44");
	hash.insert(14, "32");
	hash.insert(17, "11");
	hash.insert(13, "78");
	hash.insert(37, "97");

	HashItem* item = hash.search(13);

	if (item != nullptr)
		std::cout << "Element found: " << item->m_data << std::endl;
	else
		std::cout << "Element not found" << std::endl;

	hash.remove(item);
	std::cout << "Element deleted" << std::endl;

	HashItem* ite2m = hash.search(13);

	if (ite2m != nullptr)
		std::cout << "Element found: " << ite2m->m_data << std::endl;
	else
		std::cout << "Element not found" << std::endl;

	std::cout << "-------------TREE------------" << std::endl;

	Tree tree = Tree();

	tree.insert(1, "20");
	tree.insert(2, "70");
	tree.insert(42, "80");
	tree.insert(4, "25");
	tree.insert(12, "44");
	tree.insert(14, "32");
	tree.insert(17, "11");
	tree.insert(13, "78");
	tree.insert(37, "97");

	TreeNode* node = tree.search(13);

	if (node != nullptr)
		std::cout << "Element found: " << node->m_data << std::endl;
	else
		std::cout << "Element not found" << std::endl;

	tree.remove(node);
	std::cout << "Element deleted" << std::endl;

	TreeNode* node2 = tree.search(13);

	if (node2 != nullptr)
		std::cout << "Element found: " << node2->m_data << std::endl;
	else
		std::cout << "Element not found" << std::endl;

	return 0;
}