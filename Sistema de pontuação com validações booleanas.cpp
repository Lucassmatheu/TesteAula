#include <iostream>
#include "Aulas.h"

void Pontuacas() 
{
	int senha = 1234, pontos = 0, acao;
	std::string usuario;	
	bool acesso = false;
	std::cout << "Digite o seu usuario: ";
	std::cin >> usuario;
	std::cout << "Digite a sua senha: ";
	std::cin >> senha;
	if (usuario == "Lucas" && senha == 1234)
	{
		acesso = true;
		for (int i = 1; i <= 5; i++)
		{
			std::cout << "Digite o codigo de a��o (1-4): ";
			std::cin >> acao;
			switch (acao)
			{
			case 1:
				std::cout << "A��o 1: +10 pontos\n";
				pontos += 10;
				break;
			case 2:
				std::cout << "A��o 2: +20 pontos\n";
				pontos += 20;
				break;
			case 3:
				std::cout << "C�digo inv�lido\n";
				break;
			case 4:
				std::cout << "Saindo do sistema...\n";
				break;
			default:
				std::cout << "C�digo inv�lido\n";
				break;
			}
		}
	}
	else
	{
		std::cout << "Acesso negado\n";
		return;
	}
	std::cout << "Pontua��o total: " << pontos << " pontos.\n";
}