#include <iostream>
#include "Aulas.h"

void FlechaDanoToTal()
{
	int quantidadeFlexa[4]{ 5, 3, 2, 4 };
	int danoFlexa[4]{ 10, 15, 20, 25 };
	int* pQuantidadeFlexa = quantidadeFlexa;
	int* pDanoFlexa = danoFlexa;
	int danoTotal = 0;
	for (int indice = 0; indice < 4; indice++) 
	{
		// Corrigido: Exibe a quantidade e dano da flecha
		//pQuantidadeFlexa + indice sozinho é só o endereço de memória.
		//*(pQuantidadeFlexa + indice) pega o valor na posição indice do array
		std::cout << "Quantidade" << *(pQuantidadeFlexa + indice)
			<< ", Dano" << *(pDanoFlexa + indice) << "\n";
		// Corrigido: danoTotal += pQuantidadeFlexa * pDanoFlexa
		danoTotal += *(pQuantidadeFlexa + indice) * *(pDanoFlexa + indice);
	}
	std::cout << "Dano total das flechas: " << danoTotal << "\n";
}