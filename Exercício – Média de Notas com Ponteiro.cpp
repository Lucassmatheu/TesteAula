#include <iostream>
#include "Aulas.h"

void NotasMedia()
{
    float notas[4]{};
    float* pNotas = notas;
    float media = 0.0f;
    float soma = 0.0f;

    std::cout << "Digite as notas dos alunos (4 notas):\n";
    for (int i = 0; i < 4; i++)
    {
        std::cout << "Nota " << (i + 1) << ": ";
        std::cin >> *(pNotas + i);
        soma += *(pNotas + i);
    }

    media = soma / 4;
    std::cout << "\nNotas digitadas:\n";
    for (int i = 0; i < 4; i++)
    {
        std::cout << "Nota " << (i + 1) << ": " << *(pNotas + i) << "\n";
    }

    std::cout << "A média das notas é: " << media << "\n";

    if (media >= 7)
        std::cout << "Aprovado!\n";
    else
        std::cout << "Reprovado!\n";
}
