#include <iostream>
#include "Aulas.h"

static int Autenticidade(std::string usuario, int senha)
{
	if (usuario == "Lucas" && senha >= 1000)
	{
		std::cout << "Acesso permitido\n";
		return 1; // Acesso permitido
	}
	else
	{
		std::cout << "Acesso negado\n";
		return 0; // Acesso negado
	}
}
static int Menu()
{
	std::string nome, cargo;
	int menu, idade;	
	float media, nota1, nota2, nota3;
	
	
	do 
	{
		std::cout << "\n[1] Cadastrar idadeCadastrar dados pessoais (nome, idade, e cargo)\n[2] Avaliar desempenho com 3 notas (de 0 a 10) e calcular a média:\n[3] Sair do sistema\n";
		std::cin >> menu;
		switch (menu)
		{
		case 1:
			std::cout << "Digite seu nome: ";
			std::cin >> nome;
			std::cout << "Digite sua idade: ";
			std::cin >> idade;
			std::cout << "Digite seu cargo: ";
			std::cin >> cargo;
			break;
		case 2:
			std::cout << "Digite a nota 1: ";
			std::cin >> nota1;
			std::cout << "Digite a nota 2: ";
			std::cin >> nota2;
			std::cout << "Digite a nota 3: ";
			std::cin >> nota3;
			media = (nota1 + nota2 + nota3) / 3;
			if (media >= 7) 
			{
				std::cout << "A média é: " << media << " - Bom desempenho\n";
			}
			else if (media >= 5 && media <= 7.9)
			{
				std::cout << "A média é: " << media << " - Desempenho ruim\n";
			}
			break;
		case 3:
			std::cout << "Saindo do sistema...\n";
			break;
			default:
				std::cout << "Opção inválida. Tente novamente.\n";
			break;
		}
	} while (menu != 3);
	return menu;
}
void FuncaoSistemaAcesso()
{
	std::string usuario;
	int senha, menu{}, idade = 0, media = 0, nota1 = 0, nota2 = 0, nota3 = 0;
	bool acesso = false;
	std::cout << "Digite o seu usuario: ";
	std::cin >> usuario;
	std::cout << "Digite a sua senha: ";
	std::cin >> senha;
	if (Autenticidade(usuario, senha) == 1)
	{
		acesso = true;
		std::cout << "Acesso permitido\n";
		Menu();
	}
	else
	{
		std::cout << "Acesso negado\n";
	}
}