#include <iostream>
#include "Aulas.h"

void Operadores() 
{
	int numero, limite;
	std::cout << "Digite quantos n�meros deseja testar: ";
	std::cin >> limite;
	for (int i = 0; i < limite; i++) 
	{
		std::cout << "Digite um n�mero: ";
		std::cin >> numero;

		if (numero % 2 == 0)
		{
			std::cout << "O n�mero " << numero << " � par." << std::endl;
		}
		else if (numero % 2 != 0) 
		{
			std::cout << "O n�mero " << numero << " � �mpar." << std::endl;
		}
		else if (numero <= 0) 
		{
			std::cout << "O n�mero " << numero << " � negativo." << std::endl;
		}
		else if (numero > 0)
		{
			std::cout << "O n�mero " << numero << " � positivo." << std::endl;
		}
		else if (numero == 0)
		{
			std::cout << "O n�mero " << numero << " � zero." << std::endl;
		}
		else if  (numero >= 100) {
			std::cout << "O n�mero " << numero << " � maior ou igual a 100." << std::endl;
		}
		else if (numero <= 100)
		{
			std::cout << "O n�mero " << numero << " � menor que 100." << std::endl;
		}

	}
		
	
}