#include <iostream>
#include "Aulas.h"

static void Validador()
{
    int limite, numero, anterior;
    bool crescente = true;

    std::cout << "Digite a quantidade de números: ";
    std::cin >> limite;

    std::cout << "Digite o número 1: ";
    std::cin >> anterior;

    for (int i = 2; i <= limite; i++)
    {
        std::cout << "Digite o número " << i << ": ";
        std::cin >> numero;

        if (numero < anterior)
        {
            crescente = false;
        }

        anterior = numero;
    }

    if (crescente)
    {
        std::cout << "Sequência está em ordem crescente.\n";
    }
    else
    {
        std::cout << "Sequência não está em ordem crescente.\n";
    }
}
