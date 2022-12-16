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
#include <string>
#include <algorithm>
#include <fstream>

#include "msgassert.h"
#include "Dictionary.h"
#include "Tree.h"
#include "Hash.h"

/**
 * @brief Le as opcoes da linha de comando e inicializa variaveis
 *      -i "nome do arquivo de entrada" (entrada em formato .ppm)
 *      -o "nome do arquivo de saída" (saída em formato .pgm)
 *      -t tipo de estrutura de dado usada (arv ou hash)
 *
 * @param argv Argumentos passados na execução.
 * @param argc Quantidade de argumentos.
 */
void parse_args(char **argv, int argc, std::string *inputFilename, std::string *outputFilename, DictionaryType *type)
{
	for (int i = 0; i < argc; i++)
	{
		std::string arg(argv[i]);

		if (arg.compare("-i") == 0)
		{
			erroAssert(argc > i, "Erro: Os argumentos passados não são suficientes.");
			std::string arg(argv[i + 1]);
			*inputFilename = arg;

			i++;
		}
		else if (arg.compare("-o") == 0)
		{
			erroAssert(argc > i, "Erro: Os argumentos passados não são suficientes.");
			std::string arg(argv[i + 1]);
			*outputFilename = arg;

			i++;
		}
		else if (arg.compare("-t") == 0)
		{
			erroAssert(argc > i, "Erro: Os argumentos passados não são suficientes.");
			std::string arg(argv[i + 1]);
			if (arg.compare("arv") == 0)
				*type = DictionaryType::TREE;
			else
				*type = DictionaryType::HASH;

			i++;
		}
	}
}

/**
 * @brief Metodo principal.
 *
 * @param argv Argumentos passados na execução.
 * @param argc Quantidade de argumentos.
 */
int main(int argc, char *argv[])
{
	// Por padrão, se espera 4 entradas.
	erroAssert(argc > 2, "Numero de argumentos minimo para execução não atingido.");

	// Processa os argumentos de entrada.
	std::string inputFilename;
	std::string outputFilename;
	DictionaryType dictionaryType = DictionaryType::HASH;

	// Le os argumentos de entrada do programa.
	parse_args(argv, argc, &inputFilename, &outputFilename, &dictionaryType);

	// Trata possiveis erros com as entradas.
	erroAssert(!inputFilename.empty(), "O arquivo de entrada não é válido.");
	erroAssert(!outputFilename.empty(), "O arquivo de saida não é válido.");
	erroAssert(dictionaryType == DictionaryType::HASH || dictionaryType == DictionaryType::TREE, "O tipo de estrutura escolhido é invalido.");

	Dictionary dictionary = Dictionary(dictionaryType);

	// Inicia a leitura do arquivo de entrada.
	std::ifstream myfileInput(inputFilename);
	erroAssert(myfileInput.is_open(), "O arquivo não pôde ser lido.");

	std::string line("");
	while (getline(myfileInput, line))
	{
		// std::cout << "in[";
		auto pos = line.find(' ');
		std::string type(line.substr(0, pos));
		line = line.substr(pos + 1, line.size() - 1);

		VerbeteType vType;
		if (type.compare("a") == 0)
			vType = VerbeteType::ADJETIVO;
		else if (type.compare("n") == 0)
			vType = VerbeteType::NOME;
		else
			vType = VerbeteType::VERBO;

		pos = line.find(']');
		std::string word(line.substr(1, pos - 1)); // ignora os colchetes
		line = line.substr(pos + 1, line.size());
		if (!line.empty())
			line = line.substr(1, line.size());

		std::string meaning(line);

		meaning.erase(std::remove(meaning.begin(), meaning.end(), '\n'), meaning.end());
		meaning.erase(std::remove(meaning.begin(), meaning.end(), '\r'), meaning.end());
		meaning.erase(std::remove(meaning.begin(), meaning.end(), '\0'), meaning.end());

		// std::cout << "'" << type << "' '" << word << "' '" << meaning << "']out" << std::endl;

		dictionary.insert(vType, word, meaning);
	}
	myfileInput.close();

	// Inicia a escrita do arquivo de saida.
	std::ofstream myfile;
	myfile.open(outputFilename);
	myfile << dictionary.to_string();

	myfile << dictionary.to_string2() << "\n";
	myfile.close();

	return 0;
}
