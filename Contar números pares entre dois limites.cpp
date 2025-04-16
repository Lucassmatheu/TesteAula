#include <iostream>
#include "Aulas.h"

void contador() 
{ 
	/*
	Este programa pede ao usuário dois números: um valor inicial e um valor final.
	Ele conta quantos números pares existem entre esses dois valores (inclusive)
	e mostra cada número par encontrado.

	Usamos:
	- Laço while para percorrer de valorInicial até ValorFinal
	- Verificação com (valorInicial % 2 == 0) para identificar pares
	- Um contador para acumular o total de pares
	*/

	
	int valorInicial, ValorFinal, contador = 0;

	std::cout << "Digite o valor inicial: ";
	std::cin >> valorInicial;
	std::cout << "Digite o valor final: ";
	std::cin >> ValorFinal;

	while (valorInicial <= ValorFinal) 
	{
		if (valorInicial % 2 == 0)
		{
			contador++;
			std::cout << valorInicial << " é par" << std::endl;
		}
		valorInicial++;
	}
	std::cout << "A quantidade de números pares entre os dois limites é: " << contador << std::endl;



}