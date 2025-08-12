#include <iostream>
#include <string>
#include "Aulas.h"

void somaElementos() 
{
	int n[6]{};
	int soma = 0;

	for (int i = 0; i < 6; i++) 
	{
		std::cout << "Digite o " << (i + 1) << "º número: ";
		std::cin >> n[i];
		soma += n[i]; // Soma os elementos do vetor
		
		// Exibe o número digitado
		std::cout << "Número " << (i + 1) << ": " << n[i] << std::endl;	
	}
	// Exibe a soma dos elementos
	std::cout << "A soma dos elementos é: " << soma << std::endl;


}