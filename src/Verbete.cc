/**
 * @file Verbete.cc
 * @author Chrystian Melo (meloo.chrys@gmail.com)
 * @brief Classe para a palavra do dicionário.
 * @version 0.1
 * @date 2022-12-13
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "Verbete.h"
#include <string>
#include <sstream>

Verbete::Verbete(VerbeteType type, std::string word, std::string meaning) : m_type(type), m_word(word)
{
	if (meaning.empty())
		m_meaning_size = 0;
	else
	{
		m_meaning_size = 1;
		m_meaning = (std::string *)malloc(m_meaning_size * sizeof(std::string));
		new (m_meaning + (m_meaning_size - 1)) std::string(meaning);
	}
}

bool Verbete::hasMeaning()
{
	return m_meaning_size > 0;
}

std::string Verbete::getType()
{
	if (m_type == VerbeteType::ADJETIVO)
		return "(a)";
	if (m_type == VerbeteType::NOME)
		return "(n)";
	if (m_type == VerbeteType::VERBO)
		return "(v)";
}

std::string Verbete::getMeaning()
{
	std::stringstream meaning;
	meaning << "1." << *(m_meaning);
	for (int i = 1; i < m_meaning_size; i++)
	{
		if (!(m_meaning + i)->empty())
		{
			meaning << "\n"
					<< std::to_string(i + 1) << ".";
			meaning << *(m_meaning + i);
		}
	}
	return meaning.str();
}

void Verbete::addMeaning(std::string meaning)
{
	m_meaning_size++;
	if (m_meaning_size == 1)
		m_meaning = (std::string *)malloc(m_meaning_size * sizeof(std::string));
	else
		m_meaning = (std::string *)realloc(m_meaning, m_meaning_size * sizeof(std::string));
	new (m_meaning + (m_meaning_size - 1)) std::string(meaning);
}