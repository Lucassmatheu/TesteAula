#include <iostream>
using namespace std;

void multiplicacaoMatrizes() 
{
	const int n = 3; // Tamanho da matriz
	int matrizA[n][n]{}, matrizB[n][n]{}, resultado[n][n] = { 0 };
	int multiplicador;	
	
	// Leitura da primeira matriz
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			std::cout << "Digite o elemento [" << i + 1 << "][" << j + 1 << "] da matriz A: ";
			std::cin >> matrizA[i][j];
			std::cout << "Elemento [" << i + 1 << "][" << j + 1 << "] da matriz A: " << matrizA[i][j] << "\n"; // Mostra o elemento lido

		}
		
	}
	// Leitura da segunda matriz
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			std::cout << "Digite o elemento [" << i + 1 << "][" << j + 1 << "] da matriz B: ";
			std::cin >> matrizB[i][j];
			std::cout << "Elemento [" << i + 1 << "][" << j + 1 << "] da matriz B: " << matrizB[i][j] << "\n"; // Mostra o elemento lido
		}
	}
	// Multiplicação das matrizes
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			for (int k = 0; k < n; k++) 
			{
				resultado[i][j] += matrizA[i][k] * matrizB[k][j];
				std::cout << "Multiplicando A[" << i + 1 << "][" << k + 1 << "] * B[" << k + 1 << "][" << j + 1 << "] = " 
					<< matrizA[i][k] << " * " << matrizB[k][j] << " = " << matrizA[i][k] * matrizB[k][j] << "\n";
			}
		}
	}

	// Exibição do resultado
	std::cout << "\nResultado da multiplicacao das matrizes:\n";
}