#include <iostream>
#include "Aulas.h"

void RecebendoValore() 
{
	int numero01, numero02, numero03;
	bool comparacao;
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
	//= e comando de atribuição
	comparacao = numero01 == numero02;
    //== e comando de comparação de igualdade
	std::cout << "O numero01 e igual ao numero02: " << comparacao << std::endl;
	std::cout << "O numero01 e diferente do numero02: " << (numero01 != numero02) << std::endl;
	std::cout << "O numero01 e maior que o numero02: " << (numero01 > numero02) << std::endl;
	std::cout << "O numero01 e menor que o numero02: " << (numero01 < numero02) << std::endl;

	int total = numero01 % numero02 % numero03;

	std::cout << "O total da soma dos numeros e: " << (numero01 + numero02 + numero03 ) << std::endl;	
	std::cout << "O total da subtracao dos numeros e: " << (numero01 - numero02 - numero03) << std::endl;
	std::cout << "O total da multiplicacao dos numeros e: " << (numero01 * numero02 * numero03) << std::endl;
	std::cout << "O total da divisao dos numeros e: " << (numero01 / numero02 / numero03) << std::endl;	
	std::cout << "O total da media dos numeros e: " << (numero01 + numero02 + numero03) / 3 << std::endl;

	

}
