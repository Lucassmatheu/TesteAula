#include <iostream>
#include "Aulas.h"
void InventarioArmaDano()
{
	// Vetor de inteiros para armazenar a quantidade e dano das armas
	int quantidadeArmas[4]{ 2, 1, 3, 0 };
	int danoArmas[4]{ 10, 20, 5, 0 };
	// Ponteiros para os vetores de inteiros
	int* pQuantidadeArmas = quantidadeArmas;
	int* pDanoArmas = danoArmas;


	for (int i = 0; i < 4; i++) 
	{
		/*std::cout << "Digite a quantidade da arma " << (i + 1) << ": ";
		std::cin >> *(pQuantidadeArmas + i);
		std::cout << "Digite o dano da arma " << (i + 1) << ": ";
		std::cin >> *(pDanoArmas + i);*/
		// Exibe os dados da arma                                 // Corrigido: Exibe a quantidade e dano da arma
		std::cout << "Quantidade da arma " << (i + 1) << ": " << *(pQuantidadeArmas + i) << "\n";
		// Exibe o dano da arma                            // Corrigido: Exibe o dano da arma
		std::cout << "Dano da arma " << (i + 1) << ": " << *(pDanoArmas + i) << "\n";
	}
	int danoTotal = 0;
	for (int i = 0; i < 4; i++) 
	{
		// Corrigido: DanosTotal += pQuantidadeArmas * pDanoArmas
									/*i		quantidadeArmas[i]		danoArmas[i]	quantidade * dano
									  0				2					10				20
									  1				1					20				20
									  2				3					5				15
									  3				0					0				 0*/
		danoTotal += *(pQuantidadeArmas + i) * *(pDanoArmas + i);
	}
	std::cout << "Dano total das armas: " << danoTotal << "\n";
}