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
	std::cout << "--------------DICTIONARY------------" << std::endl;

	Dictionary* hashDictionary = new Dictionary(DictionaryType::HASH);

	Verbete verbete = Verbete(VerbeteType::VERBO, "1", "20");
	for (int i = 0 ;i < verbete.m_meaning_size; i++)
		std::cout << verbete.getType() << verbete.m_word << " : " << *(verbete.m_meaning + i) << std::endl;

	std::cout << "--------------HASH------------" << std::endl;
	Hash hash = Hash();

	hash.insert(VerbeteType::NOME,"1", "20");
	hash.insert(VerbeteType::NOME,"2", "70");
	hash.insert(VerbeteType::NOME,"42", "80");
	hash.insert(VerbeteType::NOME,"4", "25");
	hash.insert(VerbeteType::NOME,"12", "44");
	hash.insert(VerbeteType::NOME,"14", "32");
	hash.insert(VerbeteType::NOME,"17", "11");
	hash.insert(VerbeteType::NOME,"13", "78");
	hash.insert(VerbeteType::NOME,"13", "segundo elenenteo");
	hash.insert(VerbeteType::NOME,"37", "97");

	HashItem* item = hash.search("13");

	if (item != nullptr)
		std::cout << "Element found: " << item->getData() << std::endl;
	else
		std::cout << "Element not found" << std::endl;

	hash.remove(item);
	std::cout << "Element deleted" << std::endl;

	HashItem* ite2m = hash.search("13");

	if (ite2m != nullptr)
		std::cout << "Element found: " << ite2m->getData() << std::endl;
	else
		std::cout << "Element not found" << std::endl;

	std::cout << "-------------TREE------------" << std::endl;

	Tree tree = Tree();

	tree.insert(VerbeteType::NOME,"1", "20");
	tree.insert(VerbeteType::NOME,"2", "70");
	tree.insert(VerbeteType::NOME,"42", "80");
	tree.insert(VerbeteType::NOME,"4", "25");
	tree.insert(VerbeteType::NOME,"12", "44");
	tree.insert(VerbeteType::NOME,"14", "32");
	tree.insert(VerbeteType::NOME,"17", "11");
	tree.insert(VerbeteType::NOME,"13", "78");
	tree.insert(VerbeteType::NOME,"13", "segundo elemento");
	tree.insert(VerbeteType::NOME,"37", "97");

	TreeNode* node = tree.search("13");

	if (node != nullptr)
		std::cout << "Element found: " << node->getData() << std::endl;
	else
		std::cout << "Element not found" << std::endl;

	tree.remove(node);
	std::cout << "Element deleted" << std::endl;

	TreeNode* node2 = tree.search("13");

	if (node2 != nullptr)
		std::cout << "Element found: " << node2->getData() << std::endl;
	else
		std::cout << "Element not found" << std::endl;

	return 0;
}