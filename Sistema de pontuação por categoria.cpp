#include <iostream>
#include "Aulas.h"

void Sistemas() 
{
	char letra;
	int pontos = 0, limite;

	std::cout << "Digite o limite de ações: ";
	std::cin >> limite;
	for (int i = 1; i < limite; i++) 
	{
		std::cout << "Digite a letra da ação (A, B, C ou D): ";
		std::cin >> letra;
		std::cout << "Ação digitada: " << letra << std::endl;
		switch (letra)
		{
		case 'A':
			std::cout << "Ação A: +10 pontos\n";
			pontos += 10;
			break;
		case 'B':
			std::cout << "Ação B: +20 pontos\n";
			pontos += 20;
			break;
		case 'C':
			std::cout << "Ação C: +30 pontos\n";
			pontos += 30;
			break;
		case 'D':
			std::cout << "Ação D: +40 pontos\n";
			pontos += 40;
			break;
		default:
			std::cout << "Ação inválida\n";
			break;

		}
	}

	std::cout << "Pontuação total: " << pontos << " pontos.\n";



	
}