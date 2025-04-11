#include <iostream>
#include "Aulas.h"
// Função para calcular a soma dos números pares de 1 até um número fornecido pelo usuário
void SomaPares() 
{
	int numero, soma = 0, i = 1;
	std::cout << "Digite um número: ";
	std::cin >> numero;

	// Loop para calcular a soma dos números pares
	while (i <= numero)
		// enquanto i for menor ou igual ao número digitado
	{
		// verifica se i é par
		if (i % 2 == 0)
		{
			// se i for par, adiciona i à soma
			soma += i;
		}
		// se i for par, adiciona i à soma
		i = i + 1; 
	}
	// Exibe a soma dos números pares
	std::cout << "A soma dos números pares de 1 a " << numero << " é: " << soma << std::endl;

}

