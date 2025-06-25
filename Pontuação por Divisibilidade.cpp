#include  <iostream>
#include "Aulas.h"

static void Pontuacao()
{
	int numero, pontos;
	std::cout << "Digite um número: ";
	std::cin >> numero;
	if (numero % 2 == 0 && numero % 3 == 0 && numero % 5 == 0 ) 
	{
		std::cout << "O número " << numero << " é divisível por 2, 3 e 5." << std::endl;
		pontos = 45;
	}
	else if (numero % 2 && numero % 3)
	{
		std::cout << "O número " << numero << " é divisível por 2 e 3." << std::endl;
		pontos = 30;
	}
	else if (numero % 2 && numero % 5)
	{
		std::cout << "O número " << numero << " é divisível por 2 e 5." << std::endl;
		pontos = 20;
	}
	else if (numero % 3 && numero % 5)
	{
		std::cout << "O número " << numero << " é divisível por 3 e 5." << std::endl;
		pontos = 10;
	}
	else if (numero % 2)
	{
		std::cout << "O número " << numero << " é divisível apenas por 2." << std::endl;
		pontos = 5;
	}
	else if (numero % 3)
	{
		std::cout << "O número " << numero << " é divisível apenas por 3." << std::endl;
		pontos = 3;
	}
	else if (numero % 5)
	{
		std::cout << "O número " << numero << " é divisível apenas por 5." << std::endl;
		pontos = 1;
	}
	else
	{
		std::cout << "O número " << numero << " não é divisível por nenhum dos números." << std::endl;
		pontos = -1;
	}

}