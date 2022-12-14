#include "Verbete.h"

Verbete::Verbete(VerbeteType type, std::string word, std::string meaning) : m_type(type), m_word(word) {
	m_meaning_size = 1;
	m_meaning = (std::string*)malloc(m_meaning_size * sizeof(std::string));
	new (m_meaning + (m_meaning_size - 1)) std::string(meaning);
}

std::string Verbete::getType() {
	if (m_type == VerbeteType::ADJETIVO)
		return "(a)";
	if (m_type == VerbeteType::NOME)
		return "(n)";
	if (m_type == VerbeteType::VERBO)
		return "(v)";
}

std::string Verbete::getMeaning() {
	std::string meaning = *m_meaning;
	for (int i = 1; i < m_meaning_size; i++)
		meaning += "," + *(m_meaning + i);
	return meaning;
}

void Verbete::addMeaning(std::string meaning) {
	m_meaning_size++;
	m_meaning = (std::string*)realloc(m_meaning, m_meaning_size * sizeof(std::string));
	new (m_meaning + (m_meaning_size - 1)) std::string(meaning);
}