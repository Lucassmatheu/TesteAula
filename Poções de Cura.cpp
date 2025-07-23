#include <iostream>
#include "Aulas.h"

void SomaQuantidadePocaos()
{
	int quantidadePocao[3]{ 1,2,3 };
	int curaCadaTipo[3]{ 10, 20, 30 };
	int* pQuantidadePocao = quantidadePocao;
	int* pCuraCadaTipo = curaCadaTipo;
	int curaTotal = 0;

	for (int i = 0; i < 3; i++)
	{
		curaTotal += *(pQuantidadePocao + i) * *(pCuraCadaTipo + i);
	}
	std::cout << "Quantidade total de cura das poções: " << curaTotal << "\n";

	
}