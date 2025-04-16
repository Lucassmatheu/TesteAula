#include <iostream>
#include "Aulas.h"

void contadorPositivos()
{
	int numero, limite;
	int contagemPositivo = 0;
	int contagemNegativo = 0;
	int contagemZero = 0;

	std::cout << "Digite quantos números deseja testar: ";
	std::cin >> limite;

	for (int i = 1; i <= limite; i++)
	{
		std::cout << "Digite um número: ";
		std::cin >> numero;

		if (numero > 0)
		{
			contagemPositivo++;
		}
		else if (numero < 0)
		{
			contagemNegativo++;
		}
		else
		{
			contagemZero++;
		}
	}

	std::cout << "Positivos: " << contagemPositivo << std::endl;
	std::cout << "Negativos: " << contagemNegativo << std::endl;
	std::cout << "Zeros: " << contagemZero << std::endl;
}
