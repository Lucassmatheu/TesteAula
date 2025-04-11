#include <iostream>
#include "Aulas.h"

void VerificadorDeNumerosPositivos()
{
	int NumeroUm,NumeroDois, NumeroTres, NumeroQuatro, NumeroCinco;
	bool positivo;
	std::cout << "Digite um numero: ";
	std::cin >> NumeroUm;
	std::cout << "Digite outro numero: ";
	std::cin >> NumeroDois;
	std::cout << "Digite outro numero: ";
	std::cin >> NumeroTres;
	std::cout << "Digite outro numero: ";
	std::cin >> NumeroQuatro;
	std::cout << "Digite outro numero: ";
	std::cin >> NumeroCinco;

	for (int i = 1; i <= 5; i++)
	{
		if (i == 1)
		{
			positivo = NumeroUm > 0;
			std::cout << "O numero " << NumeroUm << " e positivo: " << positivo << std::endl;
		}
		else if (i == 2)
		{
			positivo = NumeroDois > 0;
			std::cout << "O numero " << NumeroDois << " e positivo: " << positivo << std::endl;
		}
		else if (i == 3)
		{
			positivo = NumeroTres > 0;
			std::cout << "O numero " << NumeroTres << " e positivo: " << positivo << std::endl;
		}
		else if (i == 4)
		{
			positivo = NumeroQuatro > 0;
			std::cout << "O numero " << NumeroQuatro << " e positivo: " << positivo << std::endl;
		}
		else if (i == 5)
		{
			positivo = NumeroCinco > 0;
			std::cout << "O numero " << NumeroCinco << " e positivo: " << positivo << std::endl;
		}

	}
}