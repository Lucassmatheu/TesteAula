#include <iostream>
#include <climits> 
#include "Aulas.h"

void MaiorMenor()
{
    const int N = 3;
    int matriz[N][N];
    int maior = INT_MIN, menor = INT_MAX;
    int lMaior = 0, cMaior = 0, lMenor = 0, cMenor = 0;

    // Leitura e cálculo
    for (int i = 0; i < N; i++)
    {
		// para inteiro j = 0; j < N; j++
	    
        for (int j = 0; j < N; j++)
        {   
			//std::cout << "Digite o elemento [" << i + 1 << "][" << j + 1 << "]: ";

            std::cout << "Digite o elemento [" << i + 1 << "][" << j + 1 << "]: ";
			std::cin >> matriz[i][j]; // lê o elemento da matriz
			// se for maior ou menor
			// se for maior ou menor, atualiza

            if (matriz[i][j] > maior) { maior = matriz[i][j]; lMaior = i; cMaior = j; }
            if (matriz[i][j] < menor) { menor = matriz[i][j]; lMenor = i; cMenor = j; }
        }
    }

    // Mostra a matriz
    std::cout << "\nMatriz:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            std::cout << matriz[i][j] << "\t";
        std::cout << "\n";
    }

    // Resultado
    std::cout << "\nMaior elemento: " << maior
        << " (linha " << lMaior + 1 << ", coluna " << cMaior + 1 << ")\n";
    std::cout << "Menor elemento: " << menor
        << " (linha " << lMenor + 1 << ", coluna " << cMenor + 1 << ")\n";
}