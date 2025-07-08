#include <iostream>
#include "Aulas.h"


static void Ternario()
{
	double MaiorNumero, num01, num02;

	std::cout << "Digite o primeiro n�mero: ";
	std::cin >> num01; 

	std::cout << "\nDigite o segundo n�mero: \n";
	std::cin >> num02;
	/*/ 
	Neste caso, o operador tern�rio ? est� sendo ultilizado para atribuir um valor a uma 
	variavel se num01 for maior que num02, caso contr�rio, atribui o valor de num02 a MaiorNumero.	
	*/
	MaiorNumero = (num01 > num02) ? num01 : num02;
	std::cout << "\nO maior n�mero �:\n " << MaiorNumero << std::endl;
	/*
	* Aqui, o operador tern�rio ? est� sendo utilizado para decidir que comando 
	* ser� executado. Se for true o primeiro comando ser� executado, caso contr�rio, o segundo vai para tela.
	*/
	(num01 > num02) ? std::cout << " Primeiro numero e maior que segundo numero " :
		std::cout << " Segundo numero e maior que primeiro numero " << std::endl;
}
