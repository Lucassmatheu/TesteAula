#include <iostream>
#include "Aulas.h"

void multiplos() 
{
	int numero{6}, limite;

	std::cout << "Digite quantos n�meros deseja testar: ";
	std::cin >> limite;
	for (int i = 1; i <= limite; i++) 
	{
		if (i % 3 == 0)
		{
			std::cout << numero << " � m�ltiplo de 3" << std::endl;

		}
		else if (i % 5 == 0)
		{
			std::cout << numero << " � m�ltiplo de 5" << std::endl;
		}
		else if (i % 7 == 0)
		{
			std::cout << numero << " � m�ltiplo de 7" << std::endl;
		}
		else
		{
			std::cout << numero << " n�o � m�ltiplo de 3, 5 ou 7" << std::endl;
		}
	}
}