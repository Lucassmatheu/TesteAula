#include <iostream>
#include "Aulas.h"
// Fun��o para calcular a soma dos n�meros pares de 1 at� um n�mero fornecido pelo usu�rio
void SomaPares() 
{
	int numero, soma = 0, i = 1;
	std::cout << "Digite um n�mero: ";
	std::cin >> numero;

	// Loop para calcular a soma dos n�meros pares
	while (i <= numero)
		// enquanto i for menor ou igual ao n�mero digitado
	{
		// verifica se i � par
		if (i % 2 == 0)
		{
			// se i for par, adiciona i � soma
			soma += i;
		}
		// se i for par, adiciona i � soma
		i = i + 1; 
	}
	// Exibe a soma dos n�meros pares
	std::cout << "A soma dos n�meros pares de 1 a " << numero << " �: " << soma << std::endl;

}

