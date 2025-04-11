#include <iostream>
#include "Aulas.h"

void CalculoDeIMC()
{
	float peso, altura, imc; 

	std::cout << "Digite seu peso (em kg): ";
	std::cin >> peso;
	std::cout << "Digite sua altura (em metros): ";
	std::cin >> altura;
	imc = peso / (altura * altura);	
	std::cout << "Seu IMC é: " << imc << std::endl;


}
