 #include <iostream>
#include "Aulas.h"

void VerificarNumeroPrimo()
{
	int numero;
	bool primo = true;
	std::cout << "Digite um n�mero: ";
	std::cin >> numero;
	if (numero < 2)
	{
		primo = false;
	}
	else
	{
		for (int i = 2; i <= numero / 2; i++)
		{
			if (numero % i == 0)
			{
				primo = false;
				break;
			}
		}
	}
	if (primo)
	{
		std::cout << numero << " � um n�mero primo." << std::endl;
	}
	else
	{
		std::cout << numero << " n�o � um n�mero primo." << std::endl;
	}
}