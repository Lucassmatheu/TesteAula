#include <iostream>
#include "Aulas.h"

static void verificador()
{
int numero, resposta;

do 
{
	std::cout << "Digite um numero Positivo: ";
	std::cin >> numero;
	if (numero > 0) 
	{
		std::cout << "Numero positivo";
	}
	else if(numero < 0)
	{
		std::cout << "Numero negativo";
	}
	if (numero == 0)
	{
		std::cout << "Numero zero";
	} {}

	std::cout << "Deseja continuar? (1 para sim / 0 para n�o): ";
	std::cin >> resposta;
	
	
} while (resposta == 1); // Adicionado uma condi��o para o loop
//std::cout << "Numero negativo";
//seguidas++;
//std::cout << "Voc� digitou " << seguidas << " n�meros negativos.\n";
}