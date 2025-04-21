#include <iostream>
#include "Aulas.h"

void ClassificadorNumeros()
{
	int numero;
	std::cout << "Digite um número: ";	
	std::cin >> numero;
	while ( numero != -1)
	{
		switch (numero / 10) {
		case 0: std::cout << "Muito baixo"; break;
		case 1: std::cout << "Baixo"; break;
		case 2:std::cout << "Baixo"; break;
		case 3:std::cout << "Médio"; break;
		case 4:std::cout << "Médio"; break;
		case 5: std::cout << "Médio"; break;
		default: if (numero > 50) std::cout << "Alto"; break;
		}

	}
	std::cout << "Digite -1 para sair\n";
	std::cin >> numero;
}

