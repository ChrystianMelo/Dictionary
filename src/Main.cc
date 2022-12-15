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

	Dictionary hash = Dictionary(DictionaryType::HASH);

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
	
	std::cout << hash.to_string();
	try {
		Verbete& item = hash.search("13");

		std::cout << "Element found: " << item.getMeaning() << std::endl;

		hash.remove(item);
		std::cout << "Element deleted" << std::endl;

		item = hash.search("13");

		std::cout << "Element found: " << item.getMeaning() << std::endl;
	}
	catch (...) {
		std::cout << "Element not found" << std::endl;
	}

	std::cout << "-------------TREE------------" << std::endl;

	Dictionary tree = Dictionary(DictionaryType::HASH);

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

	std::cout << tree.to_string();

	try {
		Verbete& item = tree.search("13");

		std::cout << "Element found: " << item.getMeaning() << std::endl;

		tree.remove(item);
		std::cout << "Element deleted" << std::endl;

		item = tree.search("13");

		std::cout << "Element found: " << item.getMeaning() << std::endl;
	}
	catch (...) {
		std::cout << "Element not found" << std::endl;
	}


	

	return 0;
}