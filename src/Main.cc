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

#include "Dictionary.h"

/**
 * @brief Metodo principal.
 */
int main()
{
    Dictionary *pTest = new Dictionary(3);
    std::cout << "Teste" << std::endl;
    return 0;
}