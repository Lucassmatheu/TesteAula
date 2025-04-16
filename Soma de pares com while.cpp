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
	/*
		Supondo que o número digitado seja 10:

		while (i <= 10)
		i começa em 1

		1 <= 10? → Sim
		→ if (1 % 2 == 0) → 1 é par? Não
		→ então incrementa: i = 2

		2 <= 10? → Sim
		→ if (2 % 2 == 0) → 2 é par? Sim
		→ soma += 2 → soma = 0 + 2 = 2
		→ incrementa: i = 3

	    3 <= 10? → Sim
      → 3 é par? Não
      → i = 4

        4 é par? Sim
      → soma += 4 → soma = 2 + 4 = 6

        E assim vai...

        Até chegar no i = 10:
      → 10 é par? Sim
      → soma += 10 → soma final = 30

      O programa soma todos os números pares entre 1 e 10.
     */

	{
		i = i + 1;

		// verifica se i é par
		if (i % 2 == 0)
		{
			// se i for par, adiciona i à soma
			soma += i;
		}
		// se i for par, adiciona i à soma
		 
	}
	// Exibe a soma dos números pares
	std::cout << "A soma dos números pares de 1 a " << numero << " é: " << soma << std::endl;

}

