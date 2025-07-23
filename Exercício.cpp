#include <iostream>
#include "Aulas.h"
void ArrayCinco()
{
    int numero[5]{};
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Digite o número " << (i + 1) << ": ";
        std::cin >> numero[i];
    }

    std::cout << "Números digitados:\n";
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Número " << (i + 1) << ": " << numero[i] << "\n";
    }
}
void ArrayCincoPonteiro()
{
    int numero[5]{};
    int* pNumero = numero;
    int soma = 0;

    for (int j = 0; j < 5; j++)
    {
        std::cout << "Digite o número " << (j + 1) << ": ";
        std::cin >> *(pNumero + j);
        soma += *(pNumero + j);
    }

    std::cout << "Números digitados:\n";
    for (int j = 0; j < 5; j++)
    {
		// Corrigido: Exibe o número usando o ponteiro
        std::cout << "Número " << (j + 1) << ": " << *(pNumero + j) << "\n";
    }

    std::cout << "Soma total: " << soma << "\n";
}
