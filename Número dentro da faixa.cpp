#include <iostream>
#include "Aulas.h"

 void NumerosDentroDaFaixa() {
	int numero;
	std::cout << "Digite um numero: ";
	std::cin >> numero;
	if (!(numero >= 1 && numero <= 10)) {
		std::cout << "O numero esta fora da faixa de 1 a 10." << std::endl;
	}
	else {
		std::cout << "O numero esta dentro da faixa de 1 a 10." << std::endl;
	}
}