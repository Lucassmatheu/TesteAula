#include <iostream>
#include "Aulas.h"

void contadorDeMultiplos()
{
	int numero, contagem = 0;
	std::cout << "Digite um n�mero: ";
	std::cin >> numero;
	for (int i = 1; i <= 100; i++) {
		if (i % numero == 0) {
			contagem++;
		}
	}
	std::cout << "O n�mero " << numero << " tem " << contagem << " m�ltiplos entre 1 e 100." << std::endl;
}