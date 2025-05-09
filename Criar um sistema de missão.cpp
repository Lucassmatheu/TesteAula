#include <iostream>
#include "Aulas.h"

bool AcessoMissao(std::string nome, int nivel, int energia, bool ItemEspecia) 
{
	int numero;
		std::cout << "Você e o Lucas (1 - sim/ 0 - não).\n";
		std::cin >> numero;
		if (numero == 1) 
		{
			if (nivel >= 5 && energia <= 20) 
			{
				ItemEspecia = true;
				return true;	
			}
		}
		else if (numero == 0) 
		{
			std::cout << "Você não pode fazer a missão com o Lucas.\n";
			return false;
		}
		else 
		{
			std::cout << "Opção inválida.\n";
			return false;
		}



}
static void ExecutarMissao(int dificuldade, int energia)
{
	do
	{
		if (dificuldade == 10) 
		{
			energia -=10;
		}
		else if (dificuldade == 20)
		{
			energia -= 20;
		}
		else if (dificuldade == 30)
		{
			energia -= 30;
		}
		else
		{
			std::cout << "Dificuldade inválida.\n";
			break;
		}
	} while (energia > 0);
	
	
}
 void sistemaPrincipal()
{
	std::string nome;
	int nivel;
	int energia,missao;
	bool ItemEspecia = false;
	std::cout << "Digite o seu nome: ";
	std::cin >> nome;
	std::cout << "Digite o seu nivel: ";
	std::cin >> nivel;
	std::cout << "Digite a sua energia: ";
	std::cin >> energia;
	
        if (AcessoMissao(nome, nivel, energia, ItemEspecia))
		{
			std::cout << "Escolha a missão (1, 2 ou 3): ";
			std::cin >> missao;
			switch (missao)
			{
			case 1:
				std::cout << "Você escolheu a missão 1.\n";
				ExecutarMissao(10, energia);
				break;
			case 2:
				std::cout << "Você escolheu a missão 2.\n";
				ExecutarMissao(20, energia);
				break;
			case 3:
				std::cout << "Você escolheu a missão 3.\n";
				ExecutarMissao(30, energia);
				break;

			default:
				std::cout << "Opção inválida.\n";
				break;
			}
		}
	
	


}
