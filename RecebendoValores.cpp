#include <iostream>
#include "Aulas.h"

void RecebendoValore() 
{
	int numero01, numero02, numero03;
	std::cout << "Digite o primeiro numero: ";
	std::cin >> numero01;
	std::cout << "Numero01 = " << numero01 << std::endl;
	
	std::cout << "Digite o segundo numero: ";
	std::cin >> numero02;
	std::cout << "Numero02 = " << numero02 << std::endl;
	
	std::cout << "Digite o terceiro numero: ";
	std::cin >> numero03;
	std::cout << "Numero03 = " << numero03 << std::endl;
	//system("pause");

	int total = numero01 % numero02 % numero03;

	

	std::cout << "O total da soma dos numeros e: " << (numero01 + numero02 + numero03 ) << std::endl;	
	std::cout << "O total da subtracao dos numeros e: " << (numero01 - numero02 - numero03) << std::endl;
	std::cout << "O total da multiplicacao dos numeros e: " << (numero01 * numero02 * numero03) << std::endl;
	std::cout << "O total da divisao dos numeros e: " << (numero01 / numero02 / numero03) << std::endl;	
	std::cout << "O total da media dos numeros e: " << (numero01 + numero02 + numero03) / 3 << std::endl;

	
	
}
