#include <iostream>
#include "Aulas.h"
#include <string>
/*Voc� passa uma C�PIA do valor.

Muda s� dentro da fun��o.

N�o afeta o original que est� fora.*/
static void cadastroPersonagem(std::string& nome, std::string& classe, int& nivel, int& energia, int& experiencia, int&  ouro)
{
	std::cout << "" << "Digite o nome do personagem: ";
	std::cin >> nome;
	std::cout << "Digite a classe do personagem (Guerreiro / Mago / Arqueiro): ";
	std::cin >> classe;
	std::cout << "Digite o n�vel do personagem (1 a 10): ";
	std::cin >> nivel;
	std::cout << "Digite a energia do personagem (at� 100): ";
	std::cin >> energia;
	ouro = 50; // Definindo um valor inicial para ouro
	if (energia < 0 || energia > 100)
	{
		std::cout << "Energia inv�lida. Deve ser entre 0 e 100.\n";
		return;
	}
	else if (nivel >= 1 && nivel <= 10)
	{
		std::cout << "N�vel v�lido.\n";
	}
	else
	{
		std::cout << "N�vel inv�lido. Deve ser entre 1 e 10.\n";
		return;

	}


}
/*Voc� passa o endere�o usando ponteiro (com o *).

Mexe direto na casa verdadeira!

Mudan�a fica gravada fora da fun��o tamb�m. */
void static VisiteLoja(int* ouro, int* energia)
{
	int opcaoLoja;
	do 
	{
		std::cout << "Bem-vindo � loja!\n";
		std::cout << "Voc� tem " << *ouro << " de ouro.\n";	
		std::cout << "Voc� tem " << *energia << " de energia.\n";
		std::cout << "Escolha uma op��o:\n";
		std::cout << "[1] Po��o de Energia (custa 20 ouro, +30 energia)\n";
		std::cout << "[2] Tomo de Experi�ncia (custa 30 ouro, +40 XP)\n";
		std::cout << "[3] Sair da Loja\n";
		std::cin >> opcaoLoja;
		switch (opcaoLoja)
		{
			case 1:
				if (*ouro >= 20) {
					*ouro -= 20;
					*energia += 30;
					std::cout << "Voc� comprou uma Po��o de Energia! Energia atual: " << *energia << "\n";
				}
				else {
					std::cout << "Ouro insuficiente para comprar Po��o de Energia.\n";
				}
				break;
			case 2:
				if (*ouro >= 30) {
					*ouro -= 30;
					std::cout << "Voc� comprou um Tomo de Experi�ncia! Experi�ncia atual: +40 XP\n";
				}
				else {
					std::cout << "Ouro insuficiente para comprar Tomo de Experi�ncia.\n";
				}
				break;
			case 3:
				std::cout << "Saindo da loja...\n";
				return;
				break;
			default:
				std::cout << "Op��o inv�lida. Tente novamente.\n";
			break;
		}
	} while (opcaoLoja != 3);
	
}
static void Fun��oexplorarTerreno(int* energia, int* experiencia)
{
	int opcaoTerreno;

	do
	{
		int evento = rand() % 3 + 1;
		std::cout << "Explorando terrenos...\n";
		std::cout << "[1] Floresta\n";
		std::cout << "[2] Caverna\n";
		std::cout << "[3] Vila\n";
		std::cout << "[4] Voltar\n";
		std::cin >> opcaoTerreno;
		switch (opcaoTerreno)
		{
		case 1:
			if (evento == 1) {
				*energia -= 15;
				std::cout << "Voc� encontrou um inimigo! Perdeu 15 de energia.\n";
			}
			else if (evento == 2) {
				*experiencia += 20;
				std::cout << "Voc� encontrou um tesouro! Ganhou 20 de experi�ncia.\n";
			}
			else {
				std::cout << "Nada encontrado nessa explora��o.\n";
			}
			break;
		case 2:
			if (evento == 1) {
				*energia -= 20;
				std::cout << "Voc� encontrou um inimigo poderoso! Perdeu 20 de energia.\n";
			}
			else if (evento == 2) {
				*experiencia += 30;
				std::cout << "Voc� encontrou uma rel�quia antiga! Ganhou 30 de experi�ncia.\n";
			}
			else {
				std::cout << "Nada encontrado nessa explora��o.\n";
			}
			break;
		case 3:
			if (evento == 1) {
				*energia -= 10;
				std::cout << "Voc� encontrou um ladr�o! Perdeu 10 de energia.\n";
			}
			else if (evento == 2) {
				*experiencia += 15;
				std::cout << "Voc� ajudou um alde�o! Ganhou 15 de experi�ncia.\n";
			}
			else {
				std::cout << "Nada encontrado nessa explora��o.\n";
			}
			break;
		case 4:
			std::cout << "Voltando ao menu principal...\n";
			return;
		default:
			std::cout << "Op��o inv�lida. Tente novamente.\n";
			break;
		}

	} while (opcaoTerreno != 4);



}
static void statusPersonagem(const std::string& nome, const std::string& classe, int nivel, int energia, int experiencia, int ouro)
{
	std::cout << "Status do Personagem:\n";
	std::cout << "Nome: " << nome << "\n";
	std::cout << "Classe: " << classe << "\n";
	std::cout << "N�vel: " << nivel << "\n";
	std::cout << "Energia: " << energia << "\n";
	std::cout << "Experi�ncia: " << experiencia << "\n";
	std::cout << "Ouro: " << ouro << "\n";
	// Corrigindo o erro de compara��o de tipos
	std::string resultado = (experiencia > 50) ? "FORTE" : "FRACO";
	std::cout << "Voc� � considerado: " << resultado << "\n";
}
static void MenuPrincipalRPG(std::string& nome, std::string& classe, int& nivel, int& energia, int& experiencia, int& ouro)
{
	int op�aoMenuLoja;
	do 
	{
		std::cout << "Bem-vindo ao menu!\n";
		std::cout << "[1] Visitar Loja\n";
		std::cout << "[2] Explorar Terrenos\n";
		std::cout << "[3] Ver Status\n";
		std::cout << "[4] Cadastrar Personagem\n";
		std::cout << "[5] Sair\n";
		std::cin >> op�aoMenuLoja;
		switch (op�aoMenuLoja)
		{
			case 1:
				VisiteLoja(&ouro, &energia);
				break;
			case 2:
				Fun��oexplorarTerreno(&energia, &experiencia);
				break;
			case 3:
				statusPersonagem(nome, classe, nivel, energia, experiencia, ouro);
				break;
			case 4:
				cadastroPersonagem(nome, classe, nivel, energia, experiencia, ouro);
				break;
			case 5:
				std::cout << "Saindo do jogo...\n";
				return;

		}
		

	} while (op�aoMenuLoja != 5);
	
}