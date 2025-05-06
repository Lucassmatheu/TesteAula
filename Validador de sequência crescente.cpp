#include <iostream>
#include "Aulas.h"

static void Validador()
{
    int limite, numero, anterior;
    bool crescente = true;

    std::cout << "Digite a quantidade de n�meros: ";
    std::cin >> limite;

    std::cout << "Digite o n�mero 1: ";
    std::cin >> anterior;

    for (int i = 2; i <= limite; i++)
    {
        std::cout << "Digite o n�mero " << i << ": ";
        std::cin >> numero;

        if (numero < anterior)
        {
            crescente = false;
        }

        anterior = numero;
    }

    if (crescente)
    {
        std::cout << "Sequ�ncia est� em ordem crescente.\n";
    }
    else
    {
        std::cout << "Sequ�ncia n�o est� em ordem crescente.\n";
    }
}
