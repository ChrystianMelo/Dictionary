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
	class Meaning
	{
	public:
		std::string content;
		Meaning *next;

		Meaning(std::string c) : content(c), next(nullptr) {}
	};
	class Meanings
	{
	public:
		Meaning *head;
		int size;

		Meanings() : head(nullptr), size(0) {}

		void add(std::string content)
		{
			Meaning *lastUser = head;
			if (size == 0)
				head = new Meaning(content);
			else
			{
				for (int i = 1; i < size; i++)
					lastUser = lastUser->next;
				lastUser->next = new Meaning(content);
			}
			size++;
		}

		Meaning *get(int index)
		{
			Meaning *element = nullptr;

			if (index == 0)
				element = head;
			else
			{
				Meaning *node = head;
				for (int i = 1; i < size; i++)
				{
					node = node->next;
					if (i == index)
						element = node;
				}
			}

			return element;
		}
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
	Verbete(VerbeteType type, std::string word, std::string meaning);

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
	void addMeaning(std::string meaning);
};

#endif