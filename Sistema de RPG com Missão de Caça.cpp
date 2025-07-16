#include <iostream>
#include "Aulas.h"


void CadastroPersonagem(std::string& nome, std::string& classe, int& nivel, int& energia, int& experiencia,int& ouro) 
{
	ouro = 50;
	experiencia = 0;
	std::cout << "Digite o nome do personagem: ";
	std::cin >> nome;
	std::cout << "Digite a classe do personagem: ";
	std::cin >> classe;
	std::cout << "Digite o nível do personagem: ";
	std::cin >> nivel;
	std::cout << "Digite a energia do personagem: ";
	std::cin >> energia;
	if (nivel >= 1 && nivel <= 10) 
	{
		std::cout << "Nível válido.\n";
	}
	else 
	{
		std::cout << "Nível inválido. Deve ser entre 1 e 10.\n";
		return;
	}
	
}
void CacarMonstros(int* energia,int* experiencia) 
{
	int encontro = rand() % 3 + 1;	
	*energia -= 10; // Consome energia ao caçar
	*experiencia += 20; // Ganha experiência ao caçar
	if (encontro == 1) {
		*energia -= 10;
		std::cout << "Você encontrou um monstro FORTE! Gastou +10 de energia!\n";
	}
	else if (encontro == 2) {
		*energia -= 5;
		std::cout << "Você encontrou um monstro FRACO! Gastou +5 de energia!\n";
	}
	else {
		std::cout << "Nenhum monstro encontrado.\n";
	}

}
static void Descansar(int* energia)
{
	if (*energia < 100) {
		*energia += 20; // Recupera energia ao descansar
		if (*energia > 100) {
			*energia = 100; // Limita a energia máxima a 100
		}
		std::cout << "Você descansou e recuperou energia! Energia atual: " << *energia << "\n";
	}
	else {
		std::cout << "Sua energia já está cheia!\n";
	}
}
static void Loja(int* energia, int* experiencia, int* ouro)
{
	int opcaoLoja;
	do
	{
		std::cout << "Bem-vindo à loja!\n";
		std::cout << "Você tem " << *ouro << " de ouro.\n";
		std::cout << "Você tem " << *energia << " de energia.\n";
		std::cout << "Compra Poção (20 ouro -> +30 energia)\n";
		std::cout << "Compra Livro de XP (30 ouro -> +40 XP)\n";
		std::cout << "Escolha uma opção:\n";
		std::cout << "[1] Poção de Energia\n";
		std::cout << "[2] Livro de Experiência\n";
		std::cout << "[3] Sair da Loja\n";
		std::cin >> opcaoLoja;

		switch (opcaoLoja)
		{
		case 1:
			if (*ouro >= 20) {
				*ouro -= 20;
				*energia += 30;
				std::cout << "Você comprou uma Poção de Energia! Energia atual: " << *energia << "\n";
			}
			else {
				std::cout << "Ouro insuficiente para comprar Poção de Energia.\n";
			}
			break;

		case 2:
			if (*ouro >= 30) {
				*ouro -= 30;
				*experiencia += 40;
				std::cout << "Você comprou um Livro de Experiência! Experiência atual: " << *experiencia << "\n";
			}
			else {
				std::cout << "Ouro insuficiente para comprar Livro de Experiência.\n";
			}
			break;

		case 3:
			std::cout << "Saindo da loja...\n";
			return;

		default:
			std::cout << "Opção inválida. Tente novamente.\n";
			break;
		}
	} while (opcaoLoja != 3);
}

static void statusPersonagem(const std::string& nome, const std::string& classe, int nivel, int energia, int experiencia, int ouro)
{
	std::cout << "Status do Personagem:\n";
	std::cout << "Nome: " << nome << "\n";
	std::cout << "Classe: " << classe << "\n";
	std::cout << "Nível: " << nivel << "\n";
	std::cout << "Energia: " << energia << "\n";
	std::cout << "Experiência: " << experiencia << "\n";
	std::cout << "Ouro: " << ouro << "\n";
	// Corrigindo o erro de comparação de tipos
	std::string resultado = (experiencia > 50) ? "FORTE" : "FRACO";
	std::cout << "Você é considerado: " << resultado << "\n";
}
static void MenuPrincipalRPG(std::string& nome, std::string& classe, int& nivel, int& energia, int& experiencia, int& ouro)
{
	int opçaoMenuLoja;
	do 
	{
		std::cout << "Bem-vindo ao menu!\n";
		std::cout << "[1] Visitar Loja\n";
		std::cout << "[2] Caçar Monstros\n";
		std::cout << "[3] Descansar\n";
		std::cout << "[4] Ver Status\n";
		std::cout << "[5] Cadastrar Personagem\n";
		std::cout << "[6] Sair\n";
		std::cin >> opçaoMenuLoja;
		switch (opçaoMenuLoja)
		{
			case 1:
				Loja(&energia, &experiencia, &ouro);
				break;
			case 2:
				CacarMonstros(&energia, &experiencia);
				break;
			case 3:
				Descansar(&energia);
				break;
			case 4:
				statusPersonagem(nome, classe, nivel, energia, experiencia, ouro);
				break;
			case 5:
				CadastroPersonagem(nome, classe, nivel, energia, experiencia, ouro);
				break;
			case 6:
				std::cout << "Saindo do jogo...\n";
				return;
			default:
				std::cout << "Opção inválida. Tente novamente.\n";
				break;
		}
	} while (opçaoMenuLoja != 6);
}