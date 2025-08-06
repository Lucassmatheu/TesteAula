#include <iostream>
#include "Aulas.h"

void estacionamento() 
{
	int vagas[10] = { 0 }; // Inicializa todas as vagas como vazias (0)
	int opcao;
	int vaga;

	do 
	{
		// Exibe o menu de opções
		std::cout << "\n===== MENU DE ESTACIONAMENTO =====\n";
		std::cout << "[1] Estacionar carro \n";
		std::cout << "[2] Remover carro \n";
		std::cout << "[3] Mostrar vagas \n";
		std::cout << "[4] Sair \n";
		std::cout << "Escolha uma opção: ";
		std::cin >> opcao;
		switch (opcao)
		{
			// Verifica a opção escolhida
		case 1: // Estacionar na primeira vaga livre
		{
			bool estacionado = false;
			// Procura a primeira vaga livre
			for (int i = 0; i < 10; i++) {
				if (vagas[i] == 0) {
					vagas[i] = 1;
					std::cout << "Carro estacionado na vaga " << i << ".\n";
					estacionado = true;
					break;
				}
			}
			if (!estacionado)
				std::cout << "Estacionamento lotado!\n";
			break;
		}
		case 2: // Remover carro de uma vaga
			std::cout << "Informe o número da vaga (0-9) para remover o carro: ";
			std::cin >> vaga;
			if (vaga < 0 || vaga >= 10) 
			{
				std::cout << "Número de vaga inválido. Tente novamente.\n";
			}
			else if (vagas[vaga] == 0) 
			{
				std::cout << "Vaga já está vazia.\n";
			}
			else 
			{
				vagas[vaga] = 0; // Marca a vaga como vazia
				std::cout << "Carro removido da vaga " << vaga << ".\n";
			}
			break;
		case 3: // Mostrar todas as vagas
			std::cout << "Vagas ocupadas: ";
			for (int i = 0; i < 10; i++) 
			{
				if (vagas[i] == 1) 
				{
					std::cout << i << " "; // Mostra as vagas ocupadas
				}
			}
			std::cout << "\n";
			break;
		case 4:
			std::cout << "Saindo do sistema de estacionamento.\n";
			break;
		default:
			std::cout << "Opção inválida! Tente novamente.\n";
			break;
		}
	} while (opcao != 4);
}