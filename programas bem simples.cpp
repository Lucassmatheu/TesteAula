#include <iostream>

static void alterarValores(int* numeros, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        numeros[i] += 5;  // Adiciona 5 em cada elemento
    }
}

void programa()
{
    int numero[3] = { 10, 8, 5 };

    std::cout << "Antes de alterar:\n";
    for (int i = 0; i < 3; i++)
    {
        std::cout << numero[i] << " ";
    }
    std::cout << "\n";

    alterarValores(numero, 3);

    std::cout << "Depois de alterar:\n";
    for (int i = 0; i < 3; i++)
    {
        std::cout << numero[i] << " ";
    }
    std::cout << "\n";
}
