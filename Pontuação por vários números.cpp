#include <iostream>
#include "Aulas.h"

void VariosNumero() 
{
	int limite, numeros{}, totalpontos = 0;
	std::cout << "quantos numeros vc deseja digitar";
	std::cin >> limite;

	for (int i = 1; i <= limite; i++) 
	{
		std::cout << "Digite um n�mero: ";
		std::cin >> numeros;
		if (numeros % 2 == 0) {
			std::cout << "Divis�vel por 2 (+10 pontos)" << std::endl;
			totalpontos += 10;
		}
		if (numeros % 3 == 0) {
			std::cout << "Divis�vel por 3 (+15 pontos)" << std::endl;
			totalpontos += 15;
		}
		if (numeros % 5 == 0) {
			std::cout << "Divis�vel por 5 (+20 pontos)" << std::endl;
			totalpontos += 20;
		}
		
	}
	std::cout << "Pontua��o total: " << totalpontos << " pontos." << std::endl;


	
	
}