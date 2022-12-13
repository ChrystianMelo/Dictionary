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

/**
 * @brief Definição da classe verbete.
 *
 */
class Verbete
{
};

/**
 * @brief Definição da classe dicionário.
 *
 */
class Dictionary
{
public:
    /**
     * @brief Construtor da classe.
     */
    Dictionary(int n);

    /**
     * @brief Destrutor da classe.
     */
    ~Dictionary();

    /**
     * @brief Metodo de pesquisa no dicionário.
     */
    int pesquisaDic(Verbete *it);
    /**
     * @brief Metodo de insere no dicionário.
     */
    int insereDic(Verbete *it);
    /**
     * @brief Metodo de imprime o dicionário.
     */
    int imprimeDic();
    /**
     * @brief Metodo de atualiza um verbete presente no dicionário.
     */
    int atualizaDic(Verbete *it);
    /**
     * @brief Metodo de remove um verbete do dicionário.
     */
    int removeDic(Verbete *it);
};
#endif