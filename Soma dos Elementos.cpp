#include <iostream>
#include <string>
#include "Aulas.h"

void somaElementos() 
{
	int n[6]{};
	int soma = 0;

	for (int i = 0; i < 6; i++) 
	{
		std::cout << "Digite o " << (i + 1) << "� n�mero: ";
		std::cin >> n[i];
		soma += n[i]; // Soma os elementos do vetor
		
		// Exibe o n�mero digitado
		std::cout << "N�mero " << (i + 1) << ": " << n[i] << std::endl;	
	}
	// Exibe a soma dos elementos
	std::cout << "A soma dos elementos �: " << soma << std::endl;


}