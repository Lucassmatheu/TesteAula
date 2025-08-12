#include <iostream>
#include "Aulas.h"

void ContadorPares() 
{
	int numeros[8]{};
	int contador = 0;	

	// Solicita ao usuário que insira 8 números inteiros
	for (int i = 0; i < 8; i++) 
	{
		std::cout << "Digite o " << (i + 1) << "º número: ";
		std::cin >> numeros[i];
		if (numeros[i] % 2 == 0) 
		{
			contador++;
			std::cout << numeros[i] << " é par." << std::endl;
		} 
		else 
		{
			std::cout << numeros[i] << " é ímpar." << std::endl;
		}
		std::cout << "Total de números pares até agora: " << contador << std::endl;

	}
}