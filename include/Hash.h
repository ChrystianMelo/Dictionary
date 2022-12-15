/**
 * @file Hash.h
 * @author Chrystian Melo (meloo.chrys@gmail.com)
 * @brief Classe do tipo Hash, para constução do dicionário.
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
 * @brief Nodo da hash
 */
class HashItem
{
private:
	/**
	 * @brief Palavra do dicionario.
	 */
	Verbete verbete;

public:
	/**
	 * @brief Construtor da clase.
	 */
	HashItem(VerbeteType &type, std::string &key, std::string &data);

	/**
	 * @brief Destrutor da classe.
	 */
	~HashItem();

	/**
	 * @brief Define a palavra do dicionario.
	 */
	void setVerbete(Verbete &v);

	/**
	 * @brief Retora a palavra do dicionario.
	 */
	Verbete &getVerbete();

	/**
	 * @brief Retorna a palavra chave do elemento no dicionario.
	 */
	std::string &getKey();

	/**
	 * @brief Adiciona mais um significdo ao elemento no dicionario.
	 */
	void addData(std::string &meaning);
};

/**
 * @brief Definição da classe do tipo Hash, para constução do dicionário.
 */
class Hash
{
private:
	/**
	 * @brief Array com os dados.
	 */
	HashItem *hashArray;

	/**
	 * @brief Tamanho do array.
	 */
	int hashArraySize = 0;

	/**
	 * @brief Retorna o codigo hash do elemnto.
	 */
	int hashCode(int key) { return key % hashArraySize; }

public:
	/**
	 * @brief Construtor da classe.
	 */
	Hash();

	/**
	 * @brief Destrutor da classe.
	 */
	~Hash();

	/**
	 * @brief Faz a pesquisa na arvore, a partir da palavra chave.
	 */
	HashItem *search(std::string &key);

	/**
	 * @brief Faz a pesquisa na arvore, a partir da palavra chave e a classe a qual a palavra pertence.
	 */
	HashItem *search(std::string key, VerbeteType type);

	/**
	 * @brief Insere uma nova palavra e seu significado no dicionario.
	 */
	void insert(VerbeteType &type, std::string &key, std::string &data);

	/**
	 * @brief Remove uma palavra do dicionario.
	 */
	void remove(HashItem *node);

	/**
	 * @brief Retorna um texto com todo o conteudo da arvore, ordenado alfabeticamente.
	 */
	std::string to_string();

	/**
	 * @brief Retorna um texto o conteudo da arvore sem significado definido, ordenado alfabeticamente.
	 */
	std::string to_string2();
};

#endif
