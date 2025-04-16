#include <iostream>
#include "Aulas.h"

void MostrarNumerosDecrescentes()
{
	/*
	Este programa l� um n�mero digitado pelo usu�rio
	e mostra todos os n�meros em ordem decrescente at� 0 (ou at� 1, se preferir).

	Usamos:
	- while (numero >= 1) para controlar o loop
	- std::cout para exibir o n�mero atual
	- numero-- para diminuir o valor a cada repeti��o
	*/
	int numero;
	std::cout << "Digite um n�mero: ";
	std::cin >> numero; 
	
	while (numero >= 1) 
	{
		std::cout << numero << std::endl;
		numero--;
	}

	
}