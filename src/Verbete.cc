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
#include "msgassert.h"

Verbete::Verbete(VerbeteType type, std::string word, std::string meaning) : m_type(type), m_word(word)
{
	m_meaning = Meanings();
	if (!meaning.empty())
		m_meaning.add(meaning);
}

bool Verbete::hasMeaning()
{
	return m_meaning.size > 0;
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
	for (int i = 0; i < m_meaning.size; i++)
	{
		Meaning *m = m_meaning.get(i);
		if (!m->content.empty())
		{
			if (i != 0)
				meaning << "\n";
			meaning << std::to_string(i + 1) << ". ";
			meaning << m->content;
		}
	}
	return meaning.str();
}

void Verbete::addMeaning(std::string meaning)
{
	m_meaning.add(meaning);
}