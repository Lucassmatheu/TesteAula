#include <iostream>  

  



void Case()  
{  
	int Num1, Num2;
    char Opercao;

	std::cout << "Digite um numero: ";
	std::cin >> Num1;
	std::cout << "Digite outro numero: ";
	std::cin >> Num2;
	std::cout << "Digite a opera��o desejada (+, -, *, /): ";
	std::cin >> Opercao;
	switch (Opercao) 
	{
	  case '+':
		std::cout << "Resultado: " << Num1 + Num2 << std::endl;
		break;
	  case '-':
		std::cout << "Resultado: " << Num1 - Num2 << std::endl;
		break;
	  case '*':
		std::cout << "Resultado: " << Num1 * Num2 << std::endl;
		break;
	  case '/':
		if (Num2 != 0) {
			std::cout << "Resultado: " << Num1 / Num2 << std::endl;
		}
		else {
			std::cout << "Erro: Divis�o por zero!" << std::endl;
		}
		break;
	  default:
		std::cout << "Opera��o inv�lida!" << std::endl;
		break;
	}

}