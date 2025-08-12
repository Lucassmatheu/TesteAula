#include <iostream>
#include "Aulas.h"

void adicionarProduto(std::string* nomesProduto, int* quantidades, int& total) 
{
	
	for (int i = 0; i < 10; i++) 
	{
		std::cout << "Digite o nome do produto " << (i + 1) << ": ";
		std::cin >> nomesProduto[i];
		std::cout << "Digite a quantidade do produto " << (i + 1) << ": ";
		std::cin >> quantidades[i];
		std::cout << "Produto " << (i + 1) << " adicionado com sucesso!\n";
		std::cout << "-----------------------------\n";
		std::cout << "Deseja adicionar outro produto? (s/n): ";
		char escolha;
		std::cin >> escolha;
		if (escolha == 'n' || escolha == 'N') 
		{
			total = i + 1; // Atualiza o total de produtos adicionados
			break;
		}
		
	
	
		
	}
	
	
}
static void removerProduto(std::string* nomesProduto, int* quantidades, int& total)
{
	bool encontrado = false;
	std::string nomeRemover;
	
	std::cout << "Digite o nome do produto que deseja remover: ";
	std::cin >> nomeRemover;
	//para cada produto i=0; i < total, verifica se o nome do produto é igual ao nomeRemover
	for (int i = 0; i < total; i++)
	{
		
		//se (nomesProduto[i] igual nomeRemover)
		// exibe "Produto removido com sucesso!"
		if(nomesProduto[i] == nomeRemover)
		
		{
			// Move o último produto para o lugar do removido
			nomesProduto[i] = nomesProduto[total - 1]; // Move último pro lugar
			// Atualiza a quantidade do produto removido
			quantidades[i] = quantidades[total - 1];
			// Limpa o último produto
			total--;

			encontrado = true;
			
			std::cout << "Produto removido com sucesso!\n";
			break;
		}
		
		
	}
	if(!encontrado)
	{
		std::cout << "Produto não encontrado no carrinho.\n";
	}
}
void mostrarCarrinho(const std::string* nomesProduto, const int* quantidades, int total)
{
	for (int i = 0; i < 10; i++) 
	{
		std::cout << "Produto: " << nomesProduto[i] << " - Quantidade: " << quantidades[i] << std::endl;
	}
}