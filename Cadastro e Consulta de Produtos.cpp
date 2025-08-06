#include <iostream>
#include <string>
#include "Aulas.h"

void cadastroDeProduto(std::string* NomeDoproduto, float* preçoProduto) 
{
	int quantidadeProdutos;
	std::cout << "Quantos produtos deseja cadastrar? ";
	std::cin >> quantidadeProdutos;
	for (int i = 0; i < quantidadeProdutos; i++) 
	{
		std:: cout << "Informe o nome do produto " << (i + 1) << ": ";
		std::cin >> NomeDoproduto[i];
		std::cout << "Informe o preço do produto " << (i + 1) << ": ";
		std::cin >> preçoProduto[i];
		std::cout << "Produto cadastrado: " << NomeDoproduto[i] << " com preço R$" << preçoProduto[i] << "\n";
	}

}
void consultaDeProduto(std::string* NomeDoproduto, float* preçoProduto, int quantidadeProdutos) 
{
	std::string produtoConsulta;
	std::cout << "Informe o nome do produto a ser consultado: ";
	std::cin >> produtoConsulta;
	bool encontrado = false;
	for (int i = 0; i < quantidadeProdutos; i++) 
	{
		if (NomeDoproduto[i] == produtoConsulta) 
		{
			std::cout << "Produto encontrado: " << NomeDoproduto[i] << " com preço R$" << preçoProduto[i] << "\n";
			encontrado = true;
			break;
		}
	}
	if (!encontrado) 
	{
		std::cout << "Produto não encontrado.\n";
	}
}
void cadastroEConsultaDeProdutos()
{
    const int QTD_PRODUTOS = 5;
    std::string NomeDoproduto[QTD_PRODUTOS];
    float precoProduto[QTD_PRODUTOS];

    // Cadastro dos 5 produtos (fora do menu)
    for (int i = 0; i < QTD_PRODUTOS; i++) {
        std::cout << "Informe o nome do produto " << (i + 1) << ": ";
        std::cin >> NomeDoproduto[i];
        std::cout << "Informe o preço do produto " << (i + 1) << ": ";
        std::cin >> precoProduto[i];
    }

    int opcao;
	// Menu de consulta de produtos
    do
    {
        std::cout << "\n===== MENU DE CONSULTA DE PRODUTOS =====\n";
        std::cout << "[1] Consultar Produto\n";
        std::cout << "[2] Listar todos os Produtos\n";
        std::cout << "[3] Sair\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;
        switch (opcao)
        {
        case 1: {
            std::string nomeConsulta;
            std::cout << "Digite o nome do produto: ";
            std::cin >> nomeConsulta;
            bool encontrado = false;
			// Percorre o array de produtos para encontrar o nome consultado
			// e exibe o preço se encontrado
            for (int i = 0; i < QTD_PRODUTOS; i++) {
                if (NomeDoproduto[i] == nomeConsulta) {
                    std::cout << "Preço do produto " << NomeDoproduto[i] << ": R$" << precoProduto[i] << "\n";
                    encontrado = true;
                    break;
                }
            }
			// Se não encontrar o produto, exibe mensagem
            if (!encontrado)
				// Se não encontrar o produto, exibe mensagem
                std::cout << "Produto não encontrado.\n";
            break;
        }
        case 2:
            std::cout << "Lista de produtos e preços:\n";
			// Exibe todos os produtos e seus preços
            for (int i = 0; i < QTD_PRODUTOS; i++) {
                std::cout << "- " << NomeDoproduto[i] << ": R$" << precoProduto[i] << "\n";
            }
            break;
        case 3:
            std::cout << "Saindo do sistema...\n";
            break;
        default:
            std::cout << "Opção inválida! Tente novamente.\n";
            break;
        }
    } while (opcao != 3);
}

void menuCadastroConsultaProdutos() 
{
	std::cout << "===== MENU DE CADASTRO E CONSULTA DE PRODUTOS =====\n";
	std::cout << "[1] Cadastro de Produtos\n";
	std::cout << "[2] Consulta de Produtos\n";
	std::cout << "[3] Sair\n";
	std::cout << "Escolha uma opção: ";
	int opcao;
	std::cin >> opcao;
	switch (opcao) 
	{
	case 1:
		cadastroEConsultaDeProdutos();
		break;
	case 2:
		cadastroEConsultaDeProdutos();
		break;
	case 3:
		std::cout << "Saindo...\n";
		break;
	default:
		std::cout << "Opção inválida!\n";
		break;
	}
}