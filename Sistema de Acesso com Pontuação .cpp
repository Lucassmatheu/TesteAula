#include <iostream>
#include "Aulas.h"

void SistemaPontuacao()
{
	int codigo{}, pontos = 0;
	while (codigo !=4)
	{
		std::cout << "Digite cdigo de ação (1-4)\n";
		std::cin >> codigo;
		switch (codigo)
		{
		case 1:
			std::cout << "Ação 1: +10 pontos\n";
			pontos += 10;
			break;
		case 2:	
			std::cout << "Ação 2: +20 pontos\n";
			pontos += 20;
			break;
		case 3:
			std::cout << "Codigo invalido\n";
			
			break;
		case 4:
			std::cout << "Saindo do sistema...\n";
			break;

		default:
			break; 
			
			system("pause");
		}
	}
	std::cout << "Pontuação total: " << pontos << " pontos.\n";
}