#include <iostream>
#include "Aulas.h"

void Sistemas() 
{
	char letra;
	int pontos = 0, limite;

	std::cout << "Digite o limite de a��es: ";
	std::cin >> limite;
	for (int i = 1; i < limite; i++) 
	{
		std::cout << "Digite a letra da a��o (A, B, C ou D): ";
		std::cin >> letra;
		std::cout << "A��o digitada: " << letra << std::endl;
		switch (letra)
		{
		case 'A':
			std::cout << "A��o A: +10 pontos\n";
			pontos += 10;
			break;
		case 'B':
			std::cout << "A��o B: +20 pontos\n";
			pontos += 20;
			break;
		case 'C':
			std::cout << "A��o C: +30 pontos\n";
			pontos += 30;
			break;
		case 'D':
			std::cout << "A��o D: +40 pontos\n";
			pontos += 40;
			break;
		default:
			std::cout << "A��o inv�lida\n";
			break;

		}
	}

	std::cout << "Pontua��o total: " << pontos << " pontos.\n";



	
}