#include <iostream>
#include <string>
#include "Aulas.h"

const int MAX_CONTATOS = 15;

int BuscarIndice(const std::string nomes[], int total, const std::string& nome) {
	for (int i = 0; i < total; ++i) {
		if (nomes[i] == nome) return i;
	}
	return -1;
}
void CadastrarContatos(std::string nomes[], std::string telefones[], int& total)
{

	std::string nome, telefone;
	for (int i = 0; i < 15; i++) 
	{
		if (total >= MAX_CONTATOS) {
			std::cout << "Limite de contatos atingido.\n";
			return;
		}

		std::string nome, telefone;
		std::cout << "Digite o nome do contato: ";
		std::cin >> nome;

		if (BuscarIndice(nomes, total, nome) != -1) {
			std::cout << "Contato ja cadastrado.\n";
			return;
		}

		std::cout << "Digite o telefone do contato: ";
		std::cin >> telefone;

		nomes[total] = nome;
		telefones[total] = telefone;
		++total;
		std::cout << "Contato cadastrado com sucesso!\n";
	
	}
}
void ListarContatos(const std::string nomes[], const std::string telefones[], int total) {
	if (total == 0) {
		std::cout << "Nenhum contato cadastrado." << std::endl;
		return;
	}
	for (int i = 0; i < total; ++i) {
		std::cout << "Contato " << i + 1 << ": " << nomes[i] << ", Telefone: " << telefones[i] << std::endl;
	}
}
void BuscarContato(const std::string nomes[], const std::string telefones[], int total) {
	std::string nome;
	std::cout << "Digite o nome do contato a ser buscado: ";
	std::cin >> nome;
	int indice = BuscarIndice(nomes, total, nome);
	if (indice != -1) {
		std::cout << "Contato encontrado: " << nomes[indice] << ", Telefone: " << telefones[indice] << std::endl;
	} else {
		std::cout << "Contato nao encontrado." << std::endl;
	}
}
void atualizarContato(std::string nomes[], std::string telefones[], int total) {
	std::string nome, novoTelefone;
	std::cout << "Digite o nome do contato a ser atualizado: ";
	std::cin >> nome;
	int indice = BuscarIndice(nomes, total, nome);
	if (indice != -1) {
		std::cout << "Digite o novo telefone: ";
		std::cin >> novoTelefone;
		telefones[indice] = novoTelefone;
		std::cout << "Contato atualizado com sucesso!" << std::endl;
	} else {
		std::cout << "Contato nao encontrado." << std::endl;
	}
}
void removerContato(std::string nomes[], std::string telefones[], int& total) {
	std::string nome;
	std::cout << "Digite o nome do contato a ser removido: ";
	std::cin >> nome;
	int indice = BuscarIndice(nomes, total, nome);
	if (indice != -1) {
		for (int i = indice; i < total - 1; ++i) {
			nomes[i] = nomes[i + 1];
			telefones[i] = telefones[i + 1];
		}
		total--;
		std::cout << "Contato removido com sucesso!" << std::endl;
	} else {
		std::cout << "Contato nao encontrado." << std::endl;
	}
}	
void MENUTelefonico() 
{

	std::string nomes[MAX_CONTATOS];
	std::string telefones[MAX_CONTATOS];
	int total = 0;
	int opcao;
	do {
		std::cout << "\nMenu Telefonico:\n";
		std::cout << "1. Cadastrar Contato\n";
		std::cout << "2. Listar Contatos\n";
		std::cout << "3. Buscar Contato\n";
		std::cout << "4. Atualizar Contato\n";
		std::cout << "5. Remover Contato\n";
		std::cout << "6. Sair\n";
		std::cout << "Escolha uma opcao: ";
		std::cin >> opcao;
		switch (opcao) {
			case 1:
				CadastrarContatos(nomes, telefones, total);
				break;
			case 2:
				ListarContatos(nomes, telefones, total);
				break;
			case 3:
				BuscarContato(nomes, telefones, total);
				break;
			case 4:
				atualizarContato(nomes, telefones, total);
				break;
			case 5:
				removerContato(nomes, telefones, total);
				break;
			case 6:
				std::cout << "Saindo do menu." << std::endl;
				break;
			default:
				std::cout << "Opcao invalida. Tente novamente." << std::endl;
		}
	} while (opcao != 6);

}