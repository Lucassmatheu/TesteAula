#include <iostream>
#include "Aulas.h"

void VariosNumero() 
{
	int limite, numeros{}, totalpontos = 0;
	std::cout << "quantos numeros vc deseja digitar";
	std::cin >> limite;

	for (int i = 1; i <= limite; i++) 
	{
		std::cout << "Digite um número: ";
		std::cin >> numeros;
		if (numeros % 2 == 0) {
			std::cout << "Divisível por 2 (+10 pontos)" << std::endl;
			totalpontos += 10;
		}
		if (numeros % 3 == 0) {
			std::cout << "Divisível por 3 (+15 pontos)" << std::endl;
			totalpontos += 15;
		}
		if (numeros % 5 == 0) {
			std::cout << "Divisível por 5 (+20 pontos)" << std::endl;
			totalpontos += 20;
		}
		
	}
	std::cout << "Pontuação total: " << totalpontos << " pontos." << std::endl;


	
	
}