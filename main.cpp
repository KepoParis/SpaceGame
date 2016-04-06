/*!
 * \file   main.cpp
 * \brief  Code Principale
 * \author Kevin & Dieu-nel
 * \date   17 Janvier 2014
 * \version 1.0
 */

#include "Univers.hpp"

int main(int, char const**)
{
    srand(time(NULL));
    Univers jeu;
    jeu.Run();
    
    return EXIT_SUCCESS;
}
