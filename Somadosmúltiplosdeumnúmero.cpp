#include <iostream>
#include "Aulas.h"

void SomaDosMultiplos() 
{
	int numero, soma = 0,  i = 1;
	// Solicita ao usu�rio um n�mero
	std::cout << "Digite um n�mero: ";
	std::cin >> numero;
	// Verifica se o n�mero � maior que zero
	for (i = 1; i <= 100; i++) 
	{
		// Verifica se o n�mero digitado � maior que zero
		if (i % numero == 0)
		{
			soma += i;
		} 

	}
	std::cout << "A soma dos m�ltiplos de " << numero << " �: " << soma << std::endl;
}