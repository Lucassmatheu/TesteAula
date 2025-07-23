#include <iostream>
#include "Aulas.h"
void ArrayCinco()
{
    int numero[5]{};
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Digite o n�mero " << (i + 1) << ": ";
        std::cin >> numero[i];
    }

    std::cout << "N�meros digitados:\n";
    for (int i = 0; i < 5; i++)
    {
        std::cout << "N�mero " << (i + 1) << ": " << numero[i] << "\n";
    }
}
void ArrayCincoPonteiro()
{
    int numero[5]{};
    int* pNumero = numero;
    int soma = 0;

    for (int j = 0; j < 5; j++)
    {
        std::cout << "Digite o n�mero " << (j + 1) << ": ";
        std::cin >> *(pNumero + j);
        soma += *(pNumero + j);
    }

    std::cout << "N�meros digitados:\n";
    for (int j = 0; j < 5; j++)
    {
		// Corrigido: Exibe o n�mero usando o ponteiro
        std::cout << "N�mero " << (j + 1) << ": " << *(pNumero + j) << "\n";
    }

    std::cout << "Soma total: " << soma << "\n";
}
