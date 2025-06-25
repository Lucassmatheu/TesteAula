#include <iostream>
#include "Aulas.h"



static void cadastrarPersonagem(std::string& nome, int& nivel, int& energia, int& experiencia)
{
	
	std::cout << "Digite o nome do personagem: ";
	std::cin >> nome;
	std::cout << "Digite o nivel do personagem (1 a 10): ";
	std::cin >> nivel;
	std::cout << "Digite a energia do personagem: ";
	std::cin >> energia;
	std::cout << "Digite a experiência do personagem: ";
	std::cin >> experiencia;
	if (nivel >= 1 && nivel <= 10)
	{
		std::cout << "Personagem cadastrado com sucesso!\n";
	}
	else if (experiencia < 0)
	{
		std::cout << "Experiência inválida. Tente novamente.\n";
	}
	else
	{
		std::cout << "Nível inválido. Tente novamente.\n";
	}
	
}
static void iniciarTreinamento(int* energia, int* experiencia)
{
	int opcaoTreinamento;
	do
	{
		std::cout << "\n[1] Treinar Força: consome 10 energia, ganha 15 XP\n[2] Treinar Agilidade : consome 5 energia, ganha 10 XP\n[3] Descansar : recupera 20 energia(máximo 100)\n[4] Sair";
		std::cin >> opcaoTreinamento;
		switch (opcaoTreinamento)
		{
		case 1:
			if (*energia >= 10)
			{
				*energia -= 10;
				*experiencia += 15;
				std::cout << "Treinamento de Força concluído! Energia: " << *energia << ", Experiência: " << *experiencia << "\n";
			}
			else
			{
				std::cout << "Energia insuficiente para treinar Força.\n";
			}
			break;
		case 2:
			if (*energia >= 5)
			{
				*energia -= 5;
				*experiencia += 10;
				std::cout << "Treinamento de Agilidade concluído! Energia: " << *energia << ", Experiência: " << *experiencia << "\n";
			}
			else
			{
				std::cout << "Energia insuficiente para treinar Agilidade.\n";
			}
			break;
		case 3:
			if (*energia <= 100)
			{
				*energia += 20;
				std::cout << "Descanso concluído! Energia: " << *energia << "\n";
				if (*energia > 100)
				{
					*energia = 100;
					std::cout << "Energia máxima atingida!\n";
				}
			}
			else
			{
				std::cout << "Energia já está cheia!\n";
			}
			break;
		case 4:
			std::cout << "Saindo do treinamento...\n";
			break;
		default:
			std::cout << "Opção inválida. Tente novamente.\n";
			break;
		}

	} while (opcaoTreinamento != 4);
}

static void iniciarBatalha(int& energia, int& energiaInimigo)
{
	int acao;
	do
	{
		std::cout << "Qual seria Ação desejada [1] Atacar \n[2] Defender \n[3] Fugir\n[4] Sair ";
		std::cin >> acao;
		switch (acao)
		{
		case 1:
			if (energia >= 10) {
				std::cout << "Você atacou o inimigo!\n";
				energiaInimigo -= 15;
				if (energiaInimigo <= 0)
				{
					energiaInimigo = 0;
					std::cout << "Inimigo derrotado!\n";
				}
				std::cout << "Energia do inimigo: " << energiaInimigo << "\n";
			}
			else
			{
				std::cout << "Energia insuficiente para atacar!\n";
			}
			break;
		case 2:
			if (energia >= 5) {
				std::cout << "Você se defendeu!\n";
				energia += 5;
				std::cout << "Energia do jogador: " << energia << "\n";
				if (energia > 100)
				{
					energia = 100;
				}
			}
			else
			{
				std::cout << "Energia insuficiente para defender!\n";
			}
			break;
		case 3:
			if (energia >= 8) {
				std::cout << "Você fugiu da batalha!\n";
				energia -= 5;
				std::cout << "Energia do jogador: " << energia << "\n";
			}
			else
			{
				std::cout << "Energia insuficiente para fugir!\n";
			}
			break;
		case 4:
			std::cout << "Saindo do jogo...\n";
			break;
		default:
			std::cout << "Opção inválida. Tente novamente.\n";
			break;
		}

	} while ((acao != 3 && acao != 4) && energiaInimigo > 0 && energia > 0);
}
static void verStatus(int energia, int experiencia)
{
	std::cout << "Status do Jogador:\n";
	std::cout << "Energia: " << energia << "\n";
	std::cout << "Experiência: " << experiencia << "\n";
}

static void MenuPrincipal()
{
int energia = 0, experiencia = 0, opcao = 0, energiaInimigo = 0; 
std::string nome; // Adicionado para armazenar o nome do personagem
int nivel = 0;    // Adicionado para armazenar o nível do personagem
do
{
	std::cout << "[1] Cadastrar personagem \n[2] Treinar para ganhar experiência \n";
	std::cout << "[3] Participar de batalhas\n[4] Ver seu status \n[5] Sair do jogo\n";
	std::cin >> opcao;

	switch (opcao)
	{
	case 1:
		cadastrarPersonagem(nome, nivel, energia, experiencia); 
		break;
	case 2:
		energia = 100;
		experiencia = 0;
		iniciarTreinamento(&energia, &experiencia);
		break;
	case 3:
		energia = 100;
		energiaInimigo = 40;
		iniciarBatalha(energia, energiaInimigo);
		break;
	case 4:
		verStatus(energia, experiencia);
		break;
	case 5:
		std::cout << "Saindo do jogo...\n";
		return;
	default:
		std::cout << "Opção inválida. Tente novamente.\n";
		break;
	}

} while (opcao != 5);
}

