#include <iostream>
#include "Aulas.h"

void SistemaDeAlarme() {
	bool portaAberta;
	bool janelaAberta; 

	std::cout << "A porta est� aberta? (1 - Sim / 0 - N�o): ";
	std::cin >> portaAberta;

	std::cout << "A janela est� aberta? (1 - Sim / 0 - N�o): ";
	std::cin >> janelaAberta;

	if (!(portaAberta || janelaAberta)) {
		std::cout << "Alarme desativado." << std::endl;
	}
	else {
		std::cout << "Alarme ativado!" << std::endl;
	}
}