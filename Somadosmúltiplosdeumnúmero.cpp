#include <iostream>
#include "Aulas.h"

void SomaDosMultiplos() 
{
	int numero, soma = 0,  i = 1;
	// Solicita ao usuário um número
	std::cout << "Digite um número: ";
	std::cin >> numero;
	// Verifica se o número é maior que zero
	for (i = 1; i <= 100; i++) 
	{
		// Verifica se o número digitado é maior que zero
		if (i % numero == 0)
		{
			soma += i;
		} 

	}
	std::cout << "A soma dos múltiplos de " << numero << " é: " << soma << std::endl;
}