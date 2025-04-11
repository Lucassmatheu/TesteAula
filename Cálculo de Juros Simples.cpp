#include <iostream>
#include "Aulas.h"

void calculoJurosSimples()
{
	double capital, taxa, tempoEmMeses, jurosSimples;

	std::cout << "Digite o capital: ";
	std::cin >> capital;
	std::cout << "Digite a taxa de juros (em %): ";
	std::cin >> taxa;
	std::cout << "Digite o tempo (em meses): ";
	std::cin >> tempoEmMeses;
	jurosSimples = (capital * taxa * tempoEmMeses) / 100;
	std::cout << "O valor dos juros simples é: " << jurosSimples << std::endl;
}