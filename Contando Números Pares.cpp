#include <iostream>
#include "Aulas.h"

void ContadorPares() 
{
	int numeros[8]{};
	int contador = 0;	

	// Solicita ao usu�rio que insira 8 n�meros inteiros
	for (int i = 0; i < 8; i++) 
	{
		std::cout << "Digite o " << (i + 1) << "� n�mero: ";
		std::cin >> numeros[i];
		if (numeros[i] % 2 == 0) 
		{
			contador++;
			std::cout << numeros[i] << " � par." << std::endl;
		} 
		else 
		{
			std::cout << numeros[i] << " � �mpar." << std::endl;
		}
		std::cout << "Total de n�meros pares at� agora: " << contador << std::endl;

	}
}