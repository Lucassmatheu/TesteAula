#include <iostream>
#include "Aulas.h"

void controleEstoqueLivros(std::string* nomesDosLivros, int * qtdLivros)
{
	int cadastrar = 0;
	std::cout << "===== CONTROLE DE ESTOQUE DE LIVROS =====\n";
	std::cout << "Digite a quantidade de livros a cadastrar: ";
	std::cin >> cadastrar;
	// Verifica se a quantidade de livros é válida
	// se qtdlivros + cadastrar for maior que 10, limita a 10
	if (*qtdLivros + cadastrar > 10) {
		// Limita a quantidade máxima de livros a 10
		std::cout << "Limite de 10 livros! Você só pode cadastrar " << (10 - *qtdLivros) << " livros.\n";
		// Ajusta a quantidade para o máximo permitido
		cadastrar = 10 - *qtdLivros;
	}
	// para cada livro  i=0; i < qtdlivros, pede o nome do livro ate maximo de 10
	for (int i = 0; i < cadastrar; i++)
	{
		// Solicita ao usuário que insira os nomes dos livros
		std::cout << "Digite nome do livro "<<(i+1);
		// Verifica se o vetor de nomesDosLivros está cheio
		std::cin >> nomesDosLivros[*qtdLivros];


		std::cout << "Livro " << (i + 1) << " cadastrado com sucesso!\n";

		
	}
}
void BuscarLivros(std::string* nomesDosLivros, int* qtdLivros) 
{
	std::string nomeBusca;
	bool encontrado = false;

	std::cout << "===== BUSCA DE LIVROS =====\n";
	std::cout << "Digite o nome do livro a buscar: ";
	std::cin >> nomeBusca;
	// para cada livro i=0; i < qtdlivros, verifica se o nome do livro é igual ao nomeBusca
	for (int i = 0; i < 10; i++) 
	{
		// se (NomesDosLivros[i] igual nomeBuscar)
		// exibe "Livro encontrado: " + NomesDosLivros[i]
		if (nomesDosLivros[i] == nomeBusca) 
		{
			std::cout << "Livro encontrado: " << nomesDosLivros[i] << "\n";
			// marca encontrado como true
			encontrado = true;
			// interrompe o loop
			break;
		}
		
	}
	// se não encontrou nenhum livro com o nomeBusca, exibe "Nenhum livro encontrado com o nome: " + nomeBusca
	// se (encontrado == false)
	// exibe "Nenhum livro encontrado com o nome: " + nomeBusca
	if (encontrado == false) 
	{
		std::cout << "Nenhum livro encontrado com o nome: " << nomeBusca << "\n";
	}
}
void MostrarTodosLivros(std::string* nomesDosLivros, int* qtdLivros) 
{
	std::cout << "===== LISTA DE LIVROS =====\n";
	for (int i = 0; i < *qtdLivros; i++) 
	{
		std::cout << "Livro " << (i + 1) << ": " << nomesDosLivros[i] << "\n";
	}
}
void Menulivro() 
{
	// Vetor para armazenar os nomes dos livros
	std::string nomesDosLivros[10]; // Vetor para armazenar os nomes dos livros
	// Variável para controlar a quantidade de livros cadastrados
	int qtdLivros = 0;
	int opcao;
	do 
	{
		std::cout << "===== MENU DE LIVROS =====\n";
		std::cout << "[1] Cadastrar Livros\n";
		std::cout << "[2] Buscar Livro\n";
		std::cout << "[3] Mostrar Todos os Livros\n";
		std::cout << "[0] Sair\n";
		std::cout << "Escolha uma opção: ";
		std::cin >> opcao;
		switch (opcao)
		{
			// para cada caso, chama a função correspondente
			case 1:
			controleEstoqueLivros(nomesDosLivros, &qtdLivros);
			break;
			// chama a função de busca de livros
			case 2:
				BuscarLivros(nomesDosLivros, &qtdLivros);
				break;
			case 3:
				MostrarTodosLivros(nomesDosLivros, &qtdLivros);
				break;
			case 0:
				std::cout << "Saindo do menu.\n";
				break;
		default:
			std::cout << "Opção inválida. Tente novamente.\n";
			break;
		}
	} while (opcao != 0);
}