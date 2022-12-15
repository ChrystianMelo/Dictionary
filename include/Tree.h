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
 * @brief Nodo da árvore.
 */
class TreeNode
{
private:
	/**
	 * @brief Palavra do dicionario.
	 */
	Verbete verbete;

public:
	/**
	 * @brief Pai do nodo atual
	 */
	TreeNode *parent = nullptr;

	/**
	 * @brief Nodo à esquerda.
	 */
	TreeNode *leftChild = nullptr;

	/**
	 * @brief Nodo à direita.
	 */
	TreeNode *rightChild = nullptr;

public:
	/**
	 * @brief Construtor da classe.
	 */
	TreeNode(VerbeteType type, std::string key, std::string data);

	/**
	 * @brief Define a palabra do dicionario.
	 */
	void setVerbete(Verbete &v);

	/**
	 * @brief Retorna a palavra do dicionario.
	 */
	Verbete &getVerbete();

	/**
	 * @brief Retorna a palavra chave do elemento no dicionario.
	 */
	std::string getKey();

	/**
	 * @brief Retorna o significado da palavra no dicionario.
	 */
	std::string getData();

	/**
	 * @brief Adiciona mais um significado para palavra no dicionario.
	 */
	void addData(std::string meaning);
};

/**
 * @brief Árvore de palavras no dicionario.
 */
class Tree
{
private:
	/**
	 * @brief Raiz da árvore.
	 */
	TreeNode *m_root;

	/**
	 * @brief Quantidade de nodos na árvore.
	 */
	int m_size;

public:
	/**
	 * @brief Construtor da clase.
	 */
	Tree();

	/**
	 * @brief Faz a pesquisa na arvore, a partir da palavra chave.
	 */
	TreeNode *search(std::string key);

	/**
	 * @brief Faz a pesquisa na arvore, a partir da palavra chave e a classe a qual a palavra pertence.
	 */
	TreeNode *search(std::string key, VerbeteType type);

	/**
	 * @brief Insere uma nova palavra e seu significado no dicionario.
	 */
	void insert(VerbeteType type, std::string key, std::string data);

	/**
	 * @brief Remove uma palavra do dicionario.
	 */
	void remove(TreeNode *node);

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