/**
 * @file Verbete.h
 * @author Chrystian Melo (meloo.chrys@gmail.com)
 * @brief 
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
  * @brief Indica o tipo da verbete (adjetivo, nome ou verbo).
  */
enum VerbeteType {
	ADJETIVO = 'a', NOME= 'n', VERBO='v'
};

/**
 * @brief Defini��o da classe verbete.
 */
class Verbete
{
public:
	/**
	 * @brief Destrutor da classe.
	 */
	VerbeteType m_type;

	/**
	 * @brief
	 */
	std::string m_word;

	/**
	 * @brief
	 */
	std::string* m_meaning;

	/**
	 * @brief
	 */
	int m_meaning_size;

	/**
	 * @brief Contrutor da classe.
	 */
	Verbete(VerbeteType type, std::string word, std::string meaning);

	/**
	 * @brief
	 */
	std::string getType();

	std::string getMeaning();

	/**
	 * @brief
	 */
	void addMeaning(std::string meaning);
};


#endif