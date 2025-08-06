#include <iostream>
#include <string>
#include "Aulas.h"

void Ranking(int* scores) 
{
	
	scores[8]={};
	int media = 0;
	std::cout << "Informe as 8 ponbtua��es";
	// Cria um array para armazenar as pontua��es dos jogadores
		for (int i = 0; i < 8 ; i++)
		{
			// Solicita a pontua��o para cada jogador
			std::cout << "Pontua��o " << (i + 1) << ": ";
			std::cin >> scores[i];
			// Verifica se a pontua��o � v�lida
			media += scores[i];
			
		}
		int maior = scores[0];
		int menor = scores[0];
		// Inicializa maior e menor com a primeira pontua��o
		for (int i = 1; i < 8; i++)
		{
			// Atualiza a maior e menor pontua��o
			if (scores[i] > maior) maior = scores[i];
			// Verifica se a pontua��o � menor que a menor pontua��o atual
			if (scores[i] < menor) menor = scores[i];
		}

		// Calcula a m�dia das pontua��es
		for (int i = 0; i < 8; i++)
		{
			media += scores[i];
			// Exibe a pontua��o de cada jogador
			std::cout << "Pontua��o " << (i + 1) << ": " << scores[i] << std::endl;
		}
		media /= 8; // Calcula a m�dia dividindo pela quantidade de jogadores
		std::cout << "M�dia das pontua��es: " << media << std::endl;
		std::cout << "Maior score: " << maior << std::endl;
		std::cout << "Menor score: " << menor << std::endl;
}