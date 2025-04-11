#include <iostream>
#include "Aulas.H"


void OperadoresLogicos() {

	double numero;
	bool maiorQue100;

	std::cout << "Digite um numero: ";
	std::cin >> numero;
	std::cout << "True = 1 e False = 0 " << "\n";
	//std::cout << "O numero digitado e maior que 100: " << (numero >= 100) << std::endl;
	maiorQue100 = ((numero >= 100) && (numero != 0)); 

	std::cout << "O numero digitado e maior que 100: " << maiorQue100 << std :: endl;
	system("pause");

}