#include <iostream>
#include "Aulas.h"

void Armazonamento(std::string* nomes) 
{
	for (int i =0; i<7; i++ ) 
	{
		std::cout << "Digite 7 nomes po vez ";
		std::cin >> nomes[i];
	
	}
}
// Exibe o menu de opções para o usuário
void buscarNomes(std::string* nomes) 
{
	std::string Nomebusca;
	bool encontrado = false;	
	std::cout << "Digite o nome que deseja buscar: ";
	std::cin >> Nomebusca;
	// Verifica se o nome digitado está no vetor de nomes
	for (int i = 0; i < 7; i++) 
	{
		// Se o nome for encontrado, exibe uma mensagem e interrompe o loop
		if (nomes[i] == Nomebusca) 
		{
			encontrado = true;
			std::cout << "Nome encontrado: " << nomes[i] << std::endl;
			break; 
		}
		
	
	}
	if (!encontrado) 
	{
		std::cout << "Nenhum nome encontrado com o nome: " << Nomebusca << std::endl;
	}


}
void menuNomes() 
{
	std::string nomes[7]; // Vetor para armazenar os nomes
	int opcao;
	do {
		std::cout << "===== MENU DE BUSCA DE NOMES =====\n";
		std::cout << "[1] Armazenar Nomes\n";
		std::cout << "[2] Buscar Nome\n";
		std::cout << "[0] Sair\n";
		std::cout << "Escolha uma opção: ";
		std::cin >> opcao;
		switch (opcao) {
			case 1:
				Armazonamento(nomes);
				break;
			case 2:
				buscarNomes(nomes);
				break;
			case 0:
				std::cout << "Saindo do menu.\n";
				break;
			default:
				std::cout << "Opção inválida! Tente novamente.\n";
				break;
		}
	} while (opcao != 0);
}