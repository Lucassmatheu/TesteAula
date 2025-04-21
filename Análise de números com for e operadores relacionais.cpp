#include <iostream>
#include "Aulas.h"

void Operadores() 
{
	int numero, limite;
	std::cout << "Digite quantos números deseja testar: ";
	std::cin >> limite;
	for (int i = 0; i < limite; i++) 
	{
		std::cout << "Digite um número: ";
		std::cin >> numero;

		if (numero % 2 == 0)
		{
			std::cout << "O número " << numero << " é par." << std::endl;
		}
		else if (numero % 2 != 0) 
		{
			std::cout << "O número " << numero << " é ímpar." << std::endl;
		}
		else if (numero <= 0) 
		{
			std::cout << "O número " << numero << " é negativo." << std::endl;
		}
		else if (numero > 0)
		{
			std::cout << "O número " << numero << " é positivo." << std::endl;
		}
		else if (numero == 0)
		{
			std::cout << "O número " << numero << " é zero." << std::endl;
		}
		else if  (numero >= 100) {
			std::cout << "O número " << numero << " é maior ou igual a 100." << std::endl;
		}
		else if (numero <= 100)
		{
			std::cout << "O número " << numero << " é menor que 100." << std::endl;
		}

	}
		
	
}