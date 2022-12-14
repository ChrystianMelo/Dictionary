/**
 * @file Dictionary.h
 * @author Chrystian Melo (meloo.chrys@gmail.com)
 * @brief Classe dicionário. Esta dicionário deve
 * permitir consultas, inserções, retiradas, impressão
 * ordenada e atualização de uma entrada.
 * @version 0.1
 * @date 2022-12-13
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <string.h>
#include "Verbete.h"
#include "Hash.h"
#include "Tree.h"

/**
 * @brief Tipo da classe dicionário.
 *
 */
enum DictionaryType {
	HASH, TREE
};

/**
 * @brief Definição da classe dicionário.
 *
 */
class Dictionary
{
private: 
	/**
	 * @brief
	 */
	DictionaryType m_type;

	/**
	 * @brief
	 */
	Hash* hash;

	/**
	 * @brief
	 */
	Tree *tree;
public:
	/**
	 * @brief Construtor da classe.
	 */
	Dictionary(DictionaryType type);

	/**
	 * @brief Destrutor da classe.
	 */
	~Dictionary();

	/**
	 * @brief Metodo de pesquisa no dicionário.
	 */
	Verbete& search(std::string word);

	/**
	 * @brief Metodo de insere no dicionário.
	 */
	void insert(VerbeteType type, std::string key, std::string data);

	/**
	 * @brief Metodo de imprime o dicionário.
	 */
	void imprimeDic();

	/**
	 * @brief Metodo de atualiza um verbete presente no dicionário.
	 */
	void atualizaDic(Verbete* it);

	/**
	 * @brief Metodo de remove um verbete do dicionário.
	 */
	void remove(Verbete& it);
};
#endif