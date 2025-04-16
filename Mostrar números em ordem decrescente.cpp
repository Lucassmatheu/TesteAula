#include <iostream>
#include "Aulas.h"

void MostrarNumerosDecrescentes()
{
	/*
	Este programa lê um número digitado pelo usuário
	e mostra todos os números em ordem decrescente até 0 (ou até 1, se preferir).

	Usamos:
	- while (numero >= 1) para controlar o loop
	- std::cout para exibir o número atual
	- numero-- para diminuir o valor a cada repetição
	*/
	int numero;
	std::cout << "Digite um número: ";
	std::cin >> numero; 
	
	while (numero >= 1) 
	{
		std::cout << numero << std::endl;
		numero--;
	}

	
}