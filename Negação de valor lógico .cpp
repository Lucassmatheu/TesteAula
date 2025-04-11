#include <iostream>
#include "Aulas.h"

void NegacaoDeValorLogico()
{
	bool numero; 
	std::cout << "Digite um valor logico (1 - verdadeiro / 0 - falso): ";
	std::cin >> numero;

	if (numero)
	{
		std::cout << "O valor logico e verdadeiro." << std::endl;
	}
	else
	{
		std::cout << "O valor logico e falso." << std::endl;
	}
}
// Nega��o de valor l�gico
// A nega��o de um valor l�gico � feita com o operador "!".
// Se o valor for verdadeiro (1), a nega��o ser� falsa (0).
// Se o valor for falso (0), a nega��o ser� verdadeira (1).
// Exemplo:
// bool valor = true;
// bool negacao = !valor; // negacao ser� false
