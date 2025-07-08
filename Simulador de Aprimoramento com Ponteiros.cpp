#include <iostream>
#include "Aulas.h"

static void CadastroPersonagem(std::string& nome, int& nivel, int& energia, int& experiencia)
{
	int classe = 0;
	std::cout << "Digite o nome do personagem: ";
	std::cin >> nome;
	std::cout << "Digite a energia do personagem: ";
	std::cin >> energia;
	std::cout << "Digite a experi�ncia do personagem: ";
	std::cin >> experiencia;
	if (energia <= 0 || energia >= 100)
	{
		std::cout << "Energia inv�lida. Deve ser entre 0 e 100.\n";
		return;
	}
	do
	{
		std::cout << "Escolha uma classe";
		std::cout << "1. Guerreiro\n";
		std::cout << "2. Mago\n";
		std::cout << "3. Arqueiro\n";
		std::cin >> classe;
	
		switch (classe)
		{
		case 1:
			std::cout << "Voc� escolheu Guerreiro.\n";
			break;
		case 2:
			std::cout << "Voc� escolheu Mago.\n";
			break;
		case 3:
			std::cout << "Voc� escolheu Arqueiro.\n";
			break;
			default:
			std::cout << "Op��o inv�lida. Tente novamente.\n";
			break;

		}


	} while ((classe != 1)&& (classe != 2) && (classe != 3));
	
}
static void treinar(int* energia, int* experiencia)
{
	int opcaoTreinamento;
	do
	{
		std::cout << "\n[1] Treinar For�a: consome 10 energia\n[2] Treinar Agilidade : consome 5 energia\n[3] Descansar : recupera 20 energia(m�ximo 100)\n[4] Sair";
		std::cin >> opcaoTreinamento;
		switch (opcaoTreinamento)
		{
		case 1:
			if (*energia >= 10)
			{
				energia -= 10;
				experiencia += 15;
				std::cout << "Treinamento de For�a conclu�do! Energia: " << energia << ", Experi�ncia: " << experiencia << "\n";
			}
			else
			{
				std::cout << "Energia insuficiente para treinar For�a.\n";
			}
			break;
		case 2:
			if (*energia >= 5)
			{
				energia -= 5;
				experiencia += 10;
				std::cout << "Treinamento de Agilidade conclu�do! Energia: " << energia << ", Experi�ncia: " << experiencia << "\n";
			}
			else
			{
				std::cout << "Energia insuficiente para treinar Agilidade.\n";
			}
			break;
		case 3:
			if (*energia <= 100)
			{
				energia += 20;
				std::cout << "Descanso conclu�do! Energia: " << energia << "\n";
				if (*energia > 100)
				{
					*energia = 100;
					std::cout << "Energia m�xima atingida!\n";
				}
			}
			else
			{
				std::cout << "Energia j� est� cheia!\n";
			}
			break;
		case 4:
			std::cout << "Saindo do treinamento...\n";
			break;
		default:
			std::cout << "Op��o inv�lida. Tente novamente.\n";
			break;
		}
	} while ((opcaoTreinamento != 4));
	
}
static void Lutar(int& energia, int& experiencia, int energiaInimigo)
{
	int acao;
	do
	{
		std::cout << "Qual seria A��o desejada [1] Atacar \n[2] Defender \n[3] Fugir\n[4] Sair ";
		std::cin >> acao;
		switch (acao)
		{
		case 1:
			if (energia >= 10) {
				std::cout << "Voc� atacou o inimigo!\n";
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
				std::cout << "Voc� se defendeu!\n";
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
				std::cout << "Voc� fugiu da batalha!\n";
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
			std::cout << "Op��o inv�lida. Tente novamente.\n";
			break;
		}
		

	} while ((acao != 3 && acao != 4) && energiaInimigo > 0 && energia > 0);
	if (energia <= 0)
	{
		std::cout << "Voc� foi derrotado!\n";
	}
	else if (energiaInimigo <= 0)
	{
		std::cout << "Voc� venceu a batalha!\n";
	}
	else
	{
		std::cout << "Batalha encerrada.\n";
	}

}
static void status(std::string nome, int nivel, int energia, int experiencia)
{
	std::cout << "Status do Jogador:\n";
	std::cout << "Nome: " << nome << "\n";
	std::cout << "N�vel: " << nivel << "\n";
	std::cout << "Energia: " << energia << "\n";
	std::cout << "Experi�ncia: " << experiencia << "\n";

}
 static void menuprincipal(int& energia, int& experiencia)
{
	std::string nomeStatus,nome;
	int classeDeOpocao;
	int energiaInimigo = 0;
	int nivel = 0, energiaTreinamento = 0, experienciaTreinamento = 0;
	int nivelStatus = 0, energiaStatus = 0, experienciaStatus = 0;
	
	int  energiaLuta = 100, experienciaLuta = 0;
	do
	{
		std::cout << "Bem-vindo ao Simulador de Aprimoramento!\n";
		std::cout << "Escolha uma op��o:\n";
		std::cout << "1.Cadastro de personagem\n";
		std::cout << "2. Treinar\n";
		std::cout << "3. Lutar\n";
		std::cout << "4. Ver status\n";
		std::cout << "5. Sair\n";
		std::cin >> classeDeOpocao;
		switch (classeDeOpocao)
		{
		 case 1:
			nome;
			nivel = 0, energia = 0, experiencia = 0;
			CadastroPersonagem(nome, nivel, energia, experiencia);
			break;
		 case 2:
			energiaTreinamento = 100, experienciaTreinamento = 0;
			treinar(&energiaTreinamento, &experienciaTreinamento);
			break;
		 case 3:
			 energiaInimigo = 50; // Energia do inimigo
			 energiaLuta = 100, experienciaLuta = 0;
			Lutar(energiaLuta, experienciaLuta, energiaInimigo);
			break;
		 case 4:
			 status(nome, nivel, energia, experiencia);
			break;
		 case 5:
			std::cout << "Saindo do simulador...\n";
			break;
		 default:
			break;
		}

	} while (classeDeOpocao != 5);
	
}