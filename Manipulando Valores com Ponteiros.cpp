#include <iostream>
#include "Aulas.h"

static void ManipulandoPonteiro()
{
	int valorA = 0, valorB;
int* ponteiroA = &valorA;  // Ponteiro aponta para o endere�o de valorA

std::cout << "Digite o valor de A: ";
std::cin >> valorA;
std::cout << "Digite o valor de B: ";
std::cin >> valorB;


*ponteiroA = valorA + valorB; // Altera diretamente o valor de valorA atrav�s do ponteiro

std::cout << "O novo valor de A " << valorA << "\n";
std::cout << "O novo valor de B (Sem Alter��es) " << valorB << "\n";
std::cout << "O endere�o de A. " << &valorA << "\n";
std::cout << "Conte�do de ptrA: " << ponteiroA << "\n";
std::cout << "O conte�do apontado por ptrA: " << *ponteiroA << "\n";




}