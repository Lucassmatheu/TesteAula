#include <iostream>
using namespace std;

void SomaMatrizes()
{
	const int n = 3; // Tamanho da matriz
	int PrimeiraMatrize[n][n]{};
	int SegundaMatrizes[n][n]{}; // Declara a matriz de entrada


	int soma[3][3] = { 0 }; // Inicializa a matriz de soma com zeros

	for (int i = 0; i < n; i++)
	{
		// para inteiro j = 0; j < n; j++
		// Lê os elementos da primeira matriz

		for (int j = 0; j < n; j++) 
		{
			std::cout << "Digite o elemento [" << i + 1 << "][" << j + 1 << "] da primeira matriz: ";
			std::cin >> PrimeiraMatrize[i][j]; // Lê o elemento da primeira matriz
			soma[i][j] += PrimeiraMatrize[i][j]; // Adiciona o elemento à matriz de soma
			std::cout << "Elemento [" << i + 1 << "][" << j + 1 << "] da primeira matriz: " << PrimeiraMatrize[i][j] << "\n"; // Mostra o elemento lido
		}
	}
	//para mostrar a matriz de soma
	std::cout << "\nMatriz de Soma:\n";

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			std::cout << "Digite o elemento [" << i + 1 << "][" << j + 1 << "] da segunda matriz: ";
			std::cin >> SegundaMatrizes[i][j]; // Lê o elemento da segunda matriz
			soma[i][j] += SegundaMatrizes[i][j]; // Adiciona o elemento à matriz de soma
			std::cout << "Elemento [" << i + 1 << "][" << j + 1 << "] da segunda matriz: " << SegundaMatrizes[i][j] << "\n"; // Mostra o elemento lido
		}
	}
	std::cout << "\nMatriz de Soma:\n";
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			std::cout << soma[i][j] << "\t"; // Mostra o elemento da matriz de soma
		}
		std::cout << "\n"; // Nova linha após cada linha da matriz
	}
	std::cout << "Soma das matrizes realizada com sucesso!\n";
	
}