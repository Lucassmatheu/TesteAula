#include <iostream>
#include "Aulas.h"

void multiplos() 
{
	int numero{6}, limite;

	std::cout << "Digite quantos números deseja testar: ";
	std::cin >> limite;
	for (int i = 1; i <= limite; i++) 
	{
		std::cout << "Digite um número: ";
		std::cin >> numero;
		std::cout << "Número digitado: " << numero << std::endl;
		std::cout << "Número digitado: " << numero << std::endl;
		if (i % 3 == 0)
		{
			std::cout << numero << " é múltiplo de 3" << std::endl;

		}
		else if (i % 5 == 0)
		{
			std::cout << numero << " é múltiplo de 5" << std::endl;
		}
		else if (i % 7 == 0)
		{
			std::cout << numero << " é múltiplo de 7" << std::endl;
		}
		else
		{
			std::cout << numero << " não é múltiplo de 3, 5 ou 7" << std::endl;
		}
	}
}