#include <iostream>
#include "Aulas.h"

void Iventario() 
{
	// Vetor de inteiros para armazenar a quantidade de itens
	int intens[4]{};
	// Ponteiro para o vetor de inteiros
	int* pIntens = intens;
	// Vari�vel para armazenar a soma dos itens
	int soma = 0;
	// Solicita ao usu�rio a quantidade de cada item
	for (int i = 0; i < 4; i++) 
	{
		// Solicita a quantidade do item
		std::cout << "Digite a quantidade do item " << (i + 1) << ": ";
		// L� a quantidade e armazena no vetor usando o ponteiro
		std::cin >> *(pIntens + i);
		// Soma a quantidade ao total
		soma += *(pIntens + i);
		// Exibe a quantidade do item
		std::cout << "Quantidade do item " << (i + 1) << ": " << *(pIntens + i) << "\n";
	}
	std::cout << "\nInvent�rio:\n";
	// Exibe o invent�rio e a soma total dos itens
	for (int i = 0; i < 5; i++)
	{
		// Exibe a quantidade de cada item
		std::cout << "Item " << (i + 1) << ": " << *(pIntens + i) << "\n";
	}
		
	// Exibe a soma total dos itens
	std::cout << "Total de itens no invent�rio: " << soma << "\n";


}