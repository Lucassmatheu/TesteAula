#include <iostream>
#include "Aulas.h"

void soma()
{
    int numero, soma = 0;
    bool continuar;
    int resposta;

    do {
        std::cout << "Digite um número: ";
        std::cin >> numero;
        soma += numero;

        std::cout << "Deseja continuar? (1 = sim / 0 = não): ";
        std::cin >> resposta;
    } while (resposta == 1);

    continuar = soma > 100;

    std::cout << "Soma total: " << soma << std::endl;
    std::cout << "A soma ultrapassou 100: " << std::boolalpha << continuar << std::endl;

	
	
}