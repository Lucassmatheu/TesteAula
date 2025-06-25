#include <iostream>
#include "Aulas.h"

static void ManipulandoPonteiro()
{
	int valorA = 0, valorB;
int* ponteiroA = &valorA;  // Ponteiro aponta para o endereço de valorA

std::cout << "Digite o valor de A: ";
std::cin >> valorA;
std::cout << "Digite o valor de B: ";
std::cin >> valorB;


*ponteiroA = valorA + valorB; // Altera diretamente o valor de valorA através do ponteiro

std::cout << "O novo valor de A " << valorA << "\n";
std::cout << "O novo valor de B (Sem Alterções) " << valorB << "\n";
std::cout << "O endereço de A. " << &valorA << "\n";
std::cout << "Conteúdo de ptrA: " << ponteiroA << "\n";
std::cout << "O conteúdo apontado por ptrA: " << *ponteiroA << "\n";




}