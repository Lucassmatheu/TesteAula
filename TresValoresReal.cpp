#include <iostream>
#include "Aulas.h"

void ValoresReal() 
{
	setlocale(LC_ALL, "Portuguese");
	float numero01, numero02, numero03;
	std::cout << "Digite o primeiro numero: ";
	std::cin >> numero01; 
	std::cout << "Digite o sgundo numero: ";
	std::cin >> numero02;
	std::cout << "Digite o terceiro numero: ";
	std::cin >> numero03;
	std::cout << "Números Digitados = " << numero01 << "  " << numero02 <<"  " << numero03 << std::endl;

	float total = (numero01 + numero02 + numero03) / 3 ;

	std::cout << "A media dos numeros e: " << total << std::endl;
}