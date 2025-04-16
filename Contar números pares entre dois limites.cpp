#include <iostream>
#include "Aulas.h"

void contador() 
{ 
	/*
	Este programa pede ao usu�rio dois n�meros: um valor inicial e um valor final.
	Ele conta quantos n�meros pares existem entre esses dois valores (inclusive)
	e mostra cada n�mero par encontrado.

	Usamos:
	- La�o while para percorrer de valorInicial at� ValorFinal
	- Verifica��o com (valorInicial % 2 == 0) para identificar pares
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
			std::cout << valorInicial << " � par" << std::endl;
		}
		valorInicial++;
	}
	std::cout << "A quantidade de n�meros pares entre os dois limites �: " << contador << std::endl;



}