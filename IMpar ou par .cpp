#include <iostream>
#include "Aulas.h"

bool Ispar(int num);

void numeropares() 
{
	int numero;
	std::cout << "Digite um numero: ";
	std::cin >> numero;
	if (Ispar(numero))
	{
		std::cout << "O numero " << numero << " é par\n";
	}
	else
	{
		std::cout << "O numero " << numero << " é impar\n";
	}
	return;
	
} 
bool Ispar(int num) {
	if (num % 2 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}