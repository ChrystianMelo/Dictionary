/**
 * @file Verbete.h
 * @author Chrystian Melo (meloo.chrys@gmail.com)
 * @brief Classe para a palavra do dicionário.
 * @version 0.1
 * @date 2022-12-13
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef VERBETE_H
#define VERBETE_H

#include <iostream>
#include <string.h>

/**
 * @brief Flag indicando o tipo da verbete (adjetivo, nome ou verbo).
 */
enum VerbeteType
{
	ADJETIVO,
	NOME,
	VERBO
};

/**
 * @brief Definição da classe para a palavra do dicionário.
 */
class Verbete
{
private:
	/**
	 * @brief Definição do nodo da lista de significados
	 */
	class Meaning
	{
	public:
		/**
		 * @brief Conteudo do nodo.
		 */
		std::string content;
		/**
		 * @brief Proximo nodo.
		 */
		Meaning *next;

		/**
		 * @brief Construtor da classe
		 */
		Meaning(std::string &c);
	};

	/**
	 * @brief Definição da lista de significados
	 */
	class Meanings
	{
	public:
		/**
		 * @brief Celula cabeça da lista.
		 */
		Meaning *head;
		/**
		 * @brief Tamanho da lista.
		 */
		int size;

		/**
		 * @brief Construtor da classe.
		 */
		Meanings();

		/**
		 * @brief Adiciona uma celula na lista.
		 */
		void add(std::string &content);

		/**
		 * @brief Retorna a celula no index procurado.
		 */
		Meaning *get(int index);
	};

public:
	/**
	 * @brief Flag indicando o tipo da verbete (adjetivo, nome ou verbo).
	 */
	VerbeteType m_type;

	/**
	 * @brief Palavra chave.
	 */
	std::string m_word;

	/**
	 * @brief Array com os significados da palavra.
	 */
	Meanings m_meaning;

	/**
	 * @brief Contrutor da classe.
	 */
	Verbete(VerbeteType &type, std::string &word, std::string &meaning);

	/**
	 * @brief Verifica se a palavra possui algum significado definido.
	 */
	bool hasMeaning();

	/**
	 * @brief Retorna a classe de palabra que a palavra chave está.
	 */
	std::string getType();

	/**
	 * @brief Retorna um texto com todos os significados da palavra.
	 */
	std::string getMeaning();

	/**
	 * @brief Adiciona mais um significado para a palavra.
	 */
	void addMeaning(std::string &meaning);
};

#endif