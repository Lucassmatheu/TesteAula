#include <iostream>
#include <string>
#include "Aulas.h"

static void cadastraProdutos(std::string* NomeProduto, int qtdProdutos, float pre�oUnitario, int& total)
{
	char escolha;
	
	// para cada produto de 0 a 20
	// solicita o nome, quantidade e pre�o unit�rio
	for(int i = 0; i < 20; i++)
	{
		std::cout << "Digite o nome do produto " << (i + 1) << ": ";
		std::cin >> NomeProduto[i];
		std::cout << "Digite a quantidade do produto " << (i + 1) << ": ";
		std::cin >> qtdProdutos;
		std::cout << "Digite o pre�o unit�rio do produto " << (i + 1) << ": ";
		std::cin >> pre�oUnitario;
		std::cout << "Deseja cadastrar outro produto? (n/n): ";
		std::cin >> escolha;
		if (qtdProdutos > 20) 
		{
			std::cout << "Quantidade m�xima de produtos cadastrados atingida.\n";
			break;
		}
		// se a escolha for 'n' ou 'N', sai do loop
		else if (escolha == 'n' || escolha == 'N')
		{
			total = i + 1; // Atualiza o total de produtos adicionados
			
		}
		else
		{
			std::cout << "Produto " << (i + 1) << " cadastrado com sucesso!\n";
			std::cout << "-----------------------------\n";
		}
	}
}
static void RemoverProduto(std::string* NomeProduto, int qtdProdutos, float pre�oUnitario, int& total)
{
	std::string DigiteNomeProduto;

	std::cout << "Digite o nome do produto que deseja remover: ";
	std::cin >> DigiteNomeProduto;
	for (int i = 0; i < total; i++) 
	{
		if (NomeProduto[i] == DigiteNomeProduto) 
		{
			// Move o �ltimo produto para o lugar do removido
			NomeProduto[i] = NomeProduto[total - 1]; // Move �ltimo pro lugar
			// Atualiza a quantidade do produto removido
			qtdProdutos = qtdProdutos - 1;
			// Limpa o �ltimo produto
			total--;
			std::cout << "Produto removido com sucesso!\n";
			break;
		}
		else 
		{
			std::cout << "Produto n�o encontrado.\n";
		}
	}

}
static void MOSTRAPrRODUTO(std::string* NomeProduto, int qtdProdutos, float pre�oUnitario, int& total)

{
	for (int i = 0; i < total; i++) 
	{
		std::cout << "Produto: " << NomeProduto[i] << " - Quantidade: " << qtdProdutos << " - Pre�o Unit�rio: R$" << pre�oUnitario << std::endl;
	}
}

static void BuscarProduto(std::string* NomeProduto, int qtdProdutos, float pre�oUnitario, int& total)
{
	std::string DigiteNomeProduto;

	std::cout << "Digite o nome do produto que deseja buscar: ";
	std::cin >> DigiteNomeProduto;
	for (int i = 0; i < total; i++)
	{
		if (NomeProduto[i] == DigiteNomeProduto)
		{
			std::cout << "Produto encontrado: " << NomeProduto[i] << " - Quantidade: " << qtdProdutos << " - Pre�o Unit�rio: R$" << pre�oUnitario << std::endl;
			break;
		}
		else
		{
			std::cout << "Produto n�o encontrado.\n";
		}
	}
}

static void  registrarVenda(std::string* NomeProduto, int qtdProdutos, float pre�oUnitario, int& total, float &soma)
{
	std::string nomeProdutoVenda;
	int quantidadeVendida;
	std::cout << "Digite o nome do produto que deseja vender: ";
	std::cin >> nomeProdutoVenda;
	std::cout << "Digite a quantidade vendida: ";
	std::cin >> quantidadeVendida;
	for( int i = 0; i < total; i++) 
	{
		if (NomeProduto[i] == nomeProdutoVenda) 
		{
			if (qtdProdutos >= quantidadeVendida) 
			{
				qtdProdutos -= quantidadeVendida;
				soma += quantidadeVendida * pre�oUnitario;
				std::cout << "Venda registrada com sucesso!\n";
				std::cout << "Total da venda: R$" << quantidadeVendida * pre�oUnitario << std::endl;
			} 
			else 
			{
				std::cout << "Quantidade insuficiente em estoque.\n";
			}
			break;
		} 
		else 
		{
			std::cout << "Produto n�o encontrado.\n";
		}
	}
	

}
static void RelatorioVendas(float soma)
{
	std::cout << "Relat�rio de Vendas:\n";
	std::cout << "Total vendido: R$" << soma << std::endl;
}
void MenuMercado(std::string* NomeProduto, int qtdProdutos, float pre�oUnitario, int& total)
{

	
	int opcao;

	do 
	{
		std::cout << "Menu de Mercado:\n";
		std::cout << "1. Cadastrar Produtos\n";
		std::cout << "2. Remover Produto\n";
		std::cout << "3. Mostrar Produtos\n";
		std::cout << "4. Buscar Produto\n";
		std::cout << "5. Registrar Venda\n";
		std::cout << "6. Relat�rio de Vendas\n";
		std::cout << "7. Sair\n";
		std::cout << "Escolha uma op��o: ";	
		std::cin >> opcao;
		
		switch (opcao)
		{
			case 1:
			{
				
				
				cadastraProdutos(NomeProduto, qtdProdutos, pre�oUnitario, total);
				break;
			case 2:
			{
			
				RemoverProduto(NomeProduto, qtdProdutos, pre�oUnitario, total);
				break;
		}
			case 3:
			{
			;
				MOSTRAPrRODUTO(NomeProduto, qtdProdutos, pre�oUnitario, total);
				break;
			}
			case 4:
			{
				
				BuscarProduto(NomeProduto, qtdProdutos, pre�oUnitario, total);
				break;
			}
			case 5:
			{
				
				float soma = 0.0f;
				registrarVenda(NomeProduto, qtdProdutos, pre�oUnitario, total, soma);
				break;
			}
			case 6:
			{
				float soma = 0.0f;
				RelatorioVendas(soma);
				break;
			}
			case 7:
				std::cout << "Saindo do menu...\n";
				return; // Sair do menu
		}
		default:
			std::cout << "Op��o inv�lida. Tente novamente.\n";
			break;
		}
	} while (opcao != 7);
	

	

}