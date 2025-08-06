/*#include <iostream>
#include <string>
#include "Aulas.h"


void adicionarItem(std::string* itens, int* quantidade, int& totalItens, int tamanho, const std::string& nome, int qtdNova) 
{
	int idx = buscarIndice(itens, totalItens, nome);
	if (idx != -1) {
		quantidade[idx] += qtdNova;
		std::cout << "Item já existia! Quantidade atualizada para " << quantidade[idx] << ".\n";
	}
	else if (totalItens < tamanho) {
		itens[totalItens] = nome;
		quantidade[totalItens] = qtdNova;
		totalItens++;
		std::cout << "Item adicionado com sucesso!\n";
	}
	else {
		std::cout << "Estoque cheio! Não é possível adicionar mais itens.\n";
	}
}
void removerQuantidade(std::string* itens, int* quantidade, int& totalItens, const std::string& nome, int qtdRemover) 
{
	for (int i = 0; i < totalItens; i++) 
	{
		if (itens[i] == nome) 
		{
			if (quantidade[i] >= qtdRemover) 
			{
				quantidade[i] -= qtdRemover;
				std::cout << "Quantidade de " << nome << " atualizada para " << quantidade[i] << ".\n";
				if (quantidade[i] == 0) 
				{
					for (int j = i; j < totalItens - 1; j++) 
					{
						itens[j] = itens[j + 1];
						quantidade[j] = quantidade[j + 1];
					}
					totalItens--;
				}
			}
			else 
			{
				std::cout << "Quantidade insuficiente para remover.\n";
			}
			return;
		}
	}
	std::cout << "Item não encontrado no estoque.\n";
}
void mostrarEstoque(const std::string* itens, const int* quantidade, int totalItens) 
{
	std::cout << "Itens no estoque:\n";
	for (int i = 0; i < totalItens; i++) 
	{
		std::cout << "- " << itens[i] << ": " << quantidade[i] << "\n";
	}
}
int buscarIndice(const std::string* itens, int totalItens, const std::string& nome) 
{
	for (int i = 0; i < totalItens; i++) 
	{
		if (itens[i] == nome) 
		{
			return i; // Retorna o índice do item encontrado
		}
	}
	return -1; // Retorna -1 se o item não for encontrados
}
void Estoque()
{
	std::string itens[8];
	std::string nomeItem;
	int quantidade[8];
	int opcao;
	int totalItens = 0;
	do
	{
		std::cout << "\n===== MENU DE ESTOQUE =====\n";
		std::cout << "[1] Adicionar Item\n";
		std::cout << "[2] Remover Item\n";
		std::cout << "[3] Mostra quantidade de um item\n";
		std::cout << "[4] Consultar quantidade de um item\n";
		std::cout << "[5] Sair\n";
		std::cout << "Escolha uma opção: ";
		std::cin >> opcao;
		switch (opcao)
		{
		case 1:
			if (totalItens < 8) 
			{
				std::cout << "Informe o nome do item: ";
				std::cin >> nomeItem;
				int qtdNova;
				std::cout << "Informe a quantidade do item: ";
				std::cin >> qtdNova;
				adicionarItem(itens, quantidade, totalItens, 8, nomeItem, qtdNova);
			}
			else 
			{
				std::cout << "Estoque cheio! Não é possível adicionar mais itens.\n";
			}
			break;
		case 2:
			std::cout << "Informe o nome do item a ser removido: ";
			std::cin >> nomeItem;
			int qtdRemover;
			std::cout << "Informe a quantidade a ser removida: ";
			std::cin >> qtdRemover;
			removerQuantidade(itens, quantidade, totalItens, nomeItem, qtdRemover);
			break;
		case 3:
			std::cout << "Informe o nome do item para consultar a quantidade: ";
			std::cin >> nomeItem;
			int indice = buscarIndice(itens, totalItens, nomeItem);
			if (indice != -1) 
			{
				std::cout << "Quantidade de " << itens[indice] << ": " << quantidade[indice] << "\n";
			}
			else 
			{
				std::cout << "Item não encontrado no estoque.\n";
			}
			break;
		case 4:
			mostrarEstoque(itens, quantidade, totalItens);
			break;

		case 5:
			std::cout << "Saindo do sistema de estoque.\n";
			break;
		default:
			std::cout << "Opção inválida! Tente novamente.\n";
			break;
		}

	} while (opcao != 5);
}*/
