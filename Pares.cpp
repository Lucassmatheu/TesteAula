#include <iostream>
#include "Aulas.h"

void Pares()
{
	int numero, limite;
	int contagemPar = 0;
	int contagemImpar = 0;
	std::cout << "Digite quantos números deseja testar: ";
	std::cin >> limite;
	for (int i = 1; i <= limite; i++)
	{
		std::cout << "Digite um número: ";
		std::cin >> numero;
		if (numero % 2 == 0)
		{
			contagemPar++;
		}
		else
		{
			contagemImpar++;
		}
	}
	std::cout << "Pares: " << contagemPar << std::endl;
	std::cout << "Ímpares: " << contagemImpar << std::endl;
}