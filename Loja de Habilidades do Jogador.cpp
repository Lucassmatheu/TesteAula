#include <iostream>
#include "Aulas.h"

void lojaHabilidade() 
{
	std::string HabilidadesDisponiveis[5] = { "Fogo", "Gelo", "Relâmpago", "Cura", "Invisibilidade"};
	int PrecoHabilidades[5] = { 30, 25, 40, 20, 35 };
	std::string habilidadesAprendidas[5]{};
	int ouro = 100; // Ouro disponível para o jogador
	int opcao;
	do 
	{
		std::cout << "===== LOJA DE HABILIDADES =====\n";
		std::cout << "Ouro disponível: " << ouro << "\n";
		std::cout << "Habilidades disponíveis:\n";
		std::cout << "[1] Fogo - 30 ouro\n";
		std::cout << "[2] Gelo - 25 ouro\n";
		std::cout << "[3] Relâmpago - 40 ouro\n";
		std::cout << "[4] Cura - 20 ouro\n";
		std::cout << "[5] Invisibilidade - 35 ouro\n";
		std::cout << "[6] Sair\n";
		std::cout << "Escolha uma opção: ";
		
		std::cin >> opcao;
		switch (opcao)
		{	
		case 1:
			if (ouro >= PrecoHabilidades[0]) {
				habilidadesAprendidas[0] = HabilidadesDisponiveis[0];
				ouro -= PrecoHabilidades[0];
				std::cout << "Você aprendeu a habilidade: " << habilidadesAprendidas[0] << "\n";
			} else {
				std::cout << "Ouro insuficiente!\n";
			}
			if (habilidadesAprendidas[0] != "") {
				std::cout << "Habilidade já aprendida: " ;
			}
			break;
		case 2:
			if (ouro >= PrecoHabilidades[1]) {
				habilidadesAprendidas[1] = HabilidadesDisponiveis[1];
				ouro -= PrecoHabilidades[1];
				std::cout << "Você aprendeu a habilidade: " << habilidadesAprendidas[1] << "\n";
			} else {
				std::cout << "Ouro insuficiente!\n";
			}
			if (habilidadesAprendidas[1] != "") {
				std::cout << "Habilidade já aprendida: " ;
			}
			break;
		case 3:
			if (ouro >= PrecoHabilidades[2]) {
				habilidadesAprendidas[2] = HabilidadesDisponiveis[2];
				ouro -= PrecoHabilidades[2];
				std::cout << "Você aprendeu a habilidade: " << habilidadesAprendidas[2] << "\n";
			} else {
				std::cout << "Ouro insuficiente!\n";
			}
			if (habilidadesAprendidas[2] != "") {
				std::cout << "Habilidade já aprendida: ";
			}
			break;
		case 4:
			if (ouro >= PrecoHabilidades[3]) {
				habilidadesAprendidas[3] = HabilidadesDisponiveis[3];
				ouro -= PrecoHabilidades[3];
				std::cout << "Você aprendeu a habilidade: " << habilidadesAprendidas[3] << "\n";
			} else {
				std::cout << "Ouro insuficiente!\n";
			}
			if (habilidadesAprendidas[3] != "") {
				std::cout << "Habilidade já aprendida: ";
			}
			break;
		case 5:
			if (ouro >= PrecoHabilidades[4]) {
				habilidadesAprendidas[4] = HabilidadesDisponiveis[4];
				ouro -= PrecoHabilidades[4];
				std::cout << "Você aprendeu a habilidade: " << habilidadesAprendidas[4] << "\n";
			} else {
				std::cout << "Ouro insuficiente!\n";
			}
			if (habilidadesAprendidas[4] != "") {
				std::cout << "Habilidade já aprendida: ";
			}
			break;
		case 6:
			std::cout << "Saindo da loja...\n";
			for (int i = 0; i < 5; i++) {
				std::cout << "Habilidade " << (i + 1) << ": " << habilidadesAprendidas[i] << "\n";
			}
			break;
		default:
			std::cout << "Opção inválida! Tente novamente.\n";
			break;
		}

	} while (opcao != 6);
	
}