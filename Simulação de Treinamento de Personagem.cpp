#include <iostream>
#include "Aulas.h"
#include <string>

static void iniciarTreino(int& energia, int& experiencia);
static bool LoginPerson(std::string nome, int nivel, int energia)
{
	bool acesso = false;
	std::cout << "Digite seu nome: ";
	std::cin >> nome;
	std::cout << "Digite seu nivel: ";
	std::cin >> nivel;
	std::cout << "Digite sua energia: ";
	std::cin >> energia;
	if (nome == "Heroi" && nivel >= 5 && energia >= 30) 
	{
		acesso = true;
		std::cout << "Acesso permitido\n";
		iniciarTreino(energia, nivel);
		
		
	}
	else
	{
		std::cout << "Acesso negado\n";
	}
	return acesso;
}
static void MenuTreinamento(int& energiaJogador, int& experiencia)
{
	int acao;
		std::cout << "Qual seria A��o desejada [1] Treinar For�a \n[2] Treinar Agilidade \n[3] Descansar \n[4] Sair\n";
		std::cin >> acao;
		switch (acao)
		{
		case 1:
			if (energiaJogador >= 10) 
			{
				experiencia += 15;
				std::cout << "Voc� treinou sua for�a!\n";
				std::cout << "Experi�ncia adquirida: " << experiencia << "\n";
			}
			else
			{
				std::cout << "Energia insuficiente para treinar!\n";
			}
			break;
		case 2:
			if (energiaJogador >= 5)
			{
				experiencia += 10;
				std::cout << "Voc� treinou sua agilidade!\n";
				std::cout << "Experi�ncia adquirida: " << experiencia << "\n";
			}
			else
			{
				std::cout << "Energia insuficiente para treinar!\n";
			}
			break;
		case 3:
			if (energiaJogador < 100)
			{
				std::cout << "Voc� descansou!\n";
				energiaJogador += 20;
				std::cout << "Energia recuperada: " << energiaJogador << "\n";
				if (energiaJogador > 100)
				{
					energiaJogador = 100;
					std::cout << "Energia m�xima atingida!\n";
				}
			}
			else
			{
				std::cout << "Voc� n�o precisa descansar agora!\n";
			}
			break;
		case 4:
			std::cout << "Saindo do treinamento...\n";
			break;

		default:
			std::cout << "A��o inv�lida! Tente novamente.\n";
			break;
		}
			
}
static void iniciarTreino(int& energia, int& experiencia)
{
	do 
	{
		MenuTreinamento(energia, experiencia);
		std::cout << "Energia do jogador: " << energia << "\n";
		std::cout << "Experi�ncia do jogador: " << experiencia << "\n";

	} while (energia > 0 && experiencia < 100);

	std::string Experiencia;
	Experiencia = (experiencia >= 100) ? "Voc� � um mestre!" :
		(experiencia >= 75) ? "Voc� est� quase l�!" :
		(experiencia >= 50) ? "Voc� est� evoluindo!" :
		(experiencia >= 25) ? "Continue treinando!" :
		(experiencia >= 10) ? "Voc� est� come�ando!" :
		(experiencia >= 5) ? "Voc� precisa treinar mais!" :
		(experiencia >= 1) ? "Voc� � um novato!" :
		(experiencia >= 50) ? "Voc� est� evoluindo!" : "Continue treinando.";
}
 void SiJogado()
{
	std::string nome;
	int nivel = 0, energia = 0, experiencia = 0;
	bool acesso = LoginPerson(nome, nivel, energia);
	if (acesso)
	{
		iniciarTreino(energia, experiencia);
	}
	else
	{
		std::cout << "Acesso negado. Tente novamente.\n";
	}
}