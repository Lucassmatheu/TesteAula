#include <iostream>
#include "Aulas.h"

void SistemaDeAlarme() {
	bool portaAberta;
	bool janelaAberta; 

	std::cout << "A porta está aberta? (1 - Sim / 0 - Não): ";
	std::cin >> portaAberta;

	std::cout << "A janela está aberta? (1 - Sim / 0 - Não): ";
	std::cin >> janelaAberta;

	if (!(portaAberta || janelaAberta)) {
		std::cout << "Alarme desativado." << std::endl;
	}
	else {
		std::cout << "Alarme ativado!" << std::endl;
	}
}