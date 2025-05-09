#include <iostream>
#include "Aulas.h"

static bool login()
{
	std::string nome;
	int senha;
	std::cout << "Digite o seu nome: ";
	std::cin >> nome;
	std::cout << "Digite a sua senha: ";
	std::cin >> senha;
	if (nome == "Guerreiro" && senha == 4321)
	{
		std::cout << "Acesso permitido\n";
		return true;
	}
	else
	{
		std::cout << "Acesso negado\n";
		return false;
	}

}
static void MenuDeAcoes()
{
	int opcao;
	int enegiaInimigo = 30;
	int energiaJogador = 10;
	std::cout << "Quanto de energia seu jogador tem: ";
	std::cin >> energiaJogador;
	if (energiaJogador >= 8)
	{
		do
		{
			std::cout << "\n [1] Atacar \n [2] Defender \n [3] Fugir\n [4] Sair ";
			std::cin >> opcao;

			switch (opcao)
			{
			case 1:
				if (enegiaInimigo <= 0)
				{
					std::cout << "Inimigo já foi derrotado!\n";
				}
				else
				{
					std::cout << "Você atacou o inimigo!\n";
					enegiaInimigo -= 20;
					if (enegiaInimigo <= 0)
					{
						enegiaInimigo = 0;
						std::cout << "Inimigo derrotado!\n";
					}
					std::cout << "Energia do inimigo: " << enegiaInimigo << "\n";
				}
				break;
			case 2:				
					std::cout << "Você se defendeu!\n";
					energiaJogador += 5;
					std::cout << "Energia do jogador: " << energiaJogador << "\n";
					if (energiaJogador > 100)
					{
						energiaJogador = 100;
					}
				break;
			case 3:
				std::cout << "Você fugiu do combate!\n";
				break;
			case 4:
				std::cout << "Saindo do jogo...\n";
				break;
			default:
				std::cout << "Opção inválida. Tente novamente.\n";
				break;

			}
		} while (opcao != 4);
	}
	
	
}
void Jogo()
{
	if (login())
	{
		MenuDeAcoes();
	}
}
