#include <iostream>	
#include <string>
#include "Aulas.h"

void CadastroTelefones(std::string* nomes, std::string* telefones, int& qtdTelefones)
{
	std::cout << "===== CADASTRO DE TELEFONES =====\n";
	std::cout << "Digite a quantidade de telefones a cadastrar: ";
	std::cin >> qtdTelefones;

	// Verifica se a quantidade de telefones é válida
	//para evitar overflow do array
	// para int i = 0; i < qtdTelefones; i++
	if (qtdTelefones < 1 || qtdTelefones > 100) 
	{
		std::cout << "Quantidade inválida! Deve ser entre 1 e 100.\n";
		qtdTelefones = 0; // Reseta a quantidade para evitar cadastro
		return;
	}
	for (int i = 0; i < qtdTelefones; i++) 
	{
		std::cout << "Digite o nome do contato " << (i + 1) << ": ";
		std::cin >> nomes[i];
		std::cout << "Digite o telefone do contato " << (i + 1) << ": ";
		std::cin >> telefones[i];
		std::cout << "Contato " << (i + 1) << " cadastrado com sucesso!\n";
	}
}

void BuscaTelefone(std::string* nomes, std::string* telefones, int qtdTelefones)
{
	std::string nomeBusca;
	// Variável para armazenar o nome a ser buscado
	bool encontrado = false;

	std::cout << "===== BUSCA DE TELEFONES =====\n";
	std::cout << "Digite o nome do contato a buscar: ";
	std::cin >> nomeBusca;

	// Verifica se o nome do contato é válido
	for (int i = 0; i < qtdTelefones; i++)
	{
		if (nomes[i] == nomeBusca) // Corrigido: Comparar nomes[i] com nomeBusca
		{
			std::cout << "Telefone encontrado: " << telefones[i] << "\n";
			encontrado = true;
			break; // Interrompe o loop ao encontrar o contato
		}
	}

	if (!encontrado) 
	{
		std::cout << "Nenhum contato encontrado com o nome: " << nomeBusca << "\n";
	}
}

void MostraTodosContatos(std::string* nomes, std::string* telefones, int qtdTelefones)
{
	// Exibe todos os contatos cadastrados
	std::cout << "===== LISTA DE CONTATOS =====\n";
	for (int i = 0; i < qtdTelefones; i++)
	{
		// Verifica se o contato é válido
		std::cout << "Contato " << (i + 1) << ": " << nomes[i] << " - Telefone: " << telefones[i] << "\n";
	}
}

void MenuTelefones()
{
	// Função para exibir o menu de telefones
	int opcao;
	const int MAX_CONTATOS = 100;
	// Vetores para armazenar nomes e telefones
	std::string nomes[MAX_CONTATOS];
	// Vetor para armazenar telefones
	std::string telefones[MAX_CONTATOS];
	int qtdTelefones = 0;

	do {
		std::cout << "===== MENU DE TELEFONES =====\n";
		std::cout << "[1] Cadastrar telefones\n";
		std::cout << "[2] Buscar telefone\n";
		std::cout << "[3] Mostrar todos os contatos\n";
		std::cout << "[0] Sair\n";
		std::cout << "Escolha uma opção: ";
		std::cin >> opcao;

		switch (opcao) {
			case 1:
				// Chama a função de cadastro de telefones
				CadastroTelefones(nomes, telefones, qtdTelefones);
				break;
			case 2:
				// Chama a função de busca de telefone
				BuscaTelefone(nomes, telefones, qtdTelefones);
				break;
			case 3:

				// Chama a função para mostrar todos os contatos
				MostraTodosContatos(nomes, telefones, qtdTelefones);
				break;
			case 0:
				std::cout << "Saindo do menu de telefones.\n";
				break;
			default:
				std::cout << "Opção inválida! Tente novamente.\n";
				break;
		}
		// Verifica se o usuário deseja sair do menu
	} while (opcao != 0);
}