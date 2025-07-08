#include <iostream>
#include "Aulas.h"


static void Ternario()
{
	double MaiorNumero, num01, num02;

	std::cout << "Digite o primeiro número: ";
	std::cin >> num01; 

	std::cout << "\nDigite o segundo número: \n";
	std::cin >> num02;
	/*/ 
	Neste caso, o operador ternário ? está sendo ultilizado para atribuir um valor a uma 
	variavel se num01 for maior que num02, caso contrário, atribui o valor de num02 a MaiorNumero.	
	*/
	MaiorNumero = (num01 > num02) ? num01 : num02;
	std::cout << "\nO maior número é:\n " << MaiorNumero << std::endl;
	/*
	* Aqui, o operador ternário ? está sendo utilizado para decidir que comando 
	* será executado. Se for true o primeiro comando será executado, caso contrário, o segundo vai para tela.
	*/
	(num01 > num02) ? std::cout << " Primeiro numero e maior que segundo numero " :
		std::cout << " Segundo numero e maior que primeiro numero " << std::endl;
}
