 #include <iostream>
#include "Aulas.h"

void VerificarNumeroPrimo()
{
	int numero;
	bool primo = true;
	std::cout << "Digite um número: ";
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
		std::cout << numero << " é um número primo." << std::endl;
	}
	else
	{
		std::cout << numero << " não é um número primo." << std::endl;
	}
}