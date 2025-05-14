#include <iostream>
#include "Aulas.h"
#include <string>

static bool LoginPerson(std::string nome, int senha)
{
	
	std::string NomeCorreto = "Lucas";
	int SenhaCorreta = 1000;
	if (nome == NomeCorreto && senha >= SenhaCorreta)
	{
		std::cout << "Login realizado com sucesso!\n";
	
		return true;
	}
	else
	{
		std::cout << "Login falhou. Tente novamente.\n";
		return false;
	}
}
void iniciarTreino(int& energia, int& experiencia);
void iniciarBatalha(int& energia, int& experiencia);

static void cadastrarPersonagem(std::string& nome, int& nivel, int& energia, int& experiencia)
{
	std::cout << "Digite o nome do personagem: ";
	std::cin >> nome;
	std::cout << "Digite o nivel do personagem 1 até 10: ";
	std::cin >> nivel;
	std::cout << "Digite a energia do personagem: ";
	std::cin >> energia;
	std::cout << "Digite a experiencia do personagem: ";
	std::cin >> experiencia;

	if (nivel >= 1 && nivel <= 10) 
	{
		std::cout << "Personagem cadastrado com sucesso!\n";
	}
	else if (experiencia < 0)
	{
		std::cout << "Experiencia inválida. Tente novamente.\n";
	}
	else
	{
		std::cout << "Nivel inválido. Tente novamente.\n";
	}
}
static void menuPrincipal()
{
	int opcao;
	int energia = 100;
	int experiencia = 0;
	int  energiaInimigo = 40;
	while (true)
	{
		std::cout << "[1] Iniciar Treinamento\n[2] Iniciar Batalha\n[3] Ver status\n[4] Sair";
		std::cin >> opcao;
		switch (opcao)
		{
		case 1:
			iniciarTreino(energia, experiencia);
			break;
		case 2:
			iniciarBatalha(energia, energiaInimigo);
			break;
		case 3:
			std::cout << "Energia: " << energia << "\nExperiencia: " << experiencia << "\n";
			break;
		case 4:
			std::cout << "Saindo do jogo...\n";
			return;

		default:
			std::cout << "Opção inválida. Tente novamente.\n";
			break;
		}

	}

}
void iniciarTreino(int& energia, int& experiencia) 
{
	int opcaoTreinamento;
	do 
	{
		std::cout << "\n[1] Treinar Força: consome 10 energia, ganha 15 XP\n[2] Treinar Agilidade : consome 5 energia, ganha 10 XP\n[3] Descansar : recupera 20 energia(máximo 100)\n[4] Sair";
		std::cin >> opcaoTreinamento;
		switch (opcaoTreinamento)
		{
		case 1:
			if (energia >= 10)
			{
				energia -= 10;
				experiencia += 15;
				std::cout << "Treinamento de Força concluído! Energia: " << energia << ", Experiência: " << experiencia << "\n";
			}
			else
			{
				std::cout << "Energia insuficiente para treinar Força.\n";
			}
			break;
		case 2:
			if (energia >= 5)
			{
				energia -= 5;
				experiencia += 10;
				std::cout << "Treinamento de Agilidade concluído! Energia: " << energia << ", Experiência: " << experiencia << "\n";
			}
			else
			{
				std::cout << "Energia insuficiente para treinar Agilidade.\n";
			}
			break;
		case 3:
			if (energia <= 100)
			{
				energia += 20;
				std::cout << "Descanso concluído! Energia: " << energia << "\n";
				if (energia > 100)
				{
					energia == 100;
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
void iniciarBatalha(int& energia,int& experiencia)
{
	int Ataque;
	int energiaInimigo = 40;
	do 
	{
		std::cout << "[1] Atacar (consome 10 energia, causa 15 de dano no inimigo)\n[2] Defender(recupera 5 energia)\n[3] Fugir(sai da batalha)\n[4] Sair";
		std::cin >> Ataque;
		switch (Ataque)
		{
		case 1:
			if (energia >= 10)
			{
				energia -= 10;
				experiencia += 15;
				std::cout << "Ataque realizado! Energia: " << energia << ", Experiência: " << experiencia << "\n";
				energiaInimigo -= 15;
				std::cout << "Energia do inimigo: " << energiaInimigo << "\n";
			}
			else
			{
				std::cout << "Energia insuficiente para atacar.\n";
			}
			break;
		case 2:
			if (energia <= 100)
			{
				energia += 5;
				std::cout << "Defesa realizada! Energia: " << energia << "\n";

				if (energia > 100)
				{
					energia = 100;
					std::cout << "Energia máxima atingida!\n";
				}
			}
			else
			{
				std::cout << "Energia já está cheia!\n";
			}
			break;
		case 3:
			if (energia >= 5)
			{
				energia -= 5;
				std::cout << "Fugindo da batalha! Energia: " << energia << "\n";
			}
			else
			{
				std::cout << "Energia insuficiente para fugir.\n";
			}
			break;
		case 4:
			std::cout << "Saindo da batalha...\n";
			break;

		default:
			std::cout << "Opção inválida. Tente novamente.\n";
			break;
		}
		if (energia <= 0)
		{
			std::cout << "Você foi derrotado!\n";
			break;
		}
		else if (experiencia >= 100)
		{
			std::cout << "Você ganhou a batalha!\n";
			break;
		}
		
	} while ((Ataque != 3 && Ataque != 4) && energia > 0);
	if (energiaInimigo <= 0)
	{
		std::cout << "Inimigo derrotado!\n";
	}
	else
	{
		std::cout << "Você perdeu a batalha!\n";
	}
}
void menuJogo() 
{
   std::string nome;
   int senha;

   std::cout << "Digite seu nome: ";
   std::cin >> nome;
   std::cout << "Digite sua senha: ";
   std::cin >> senha;

   if (LoginPerson(nome, senha)) 
   {
       menuPrincipal();
   }
}
