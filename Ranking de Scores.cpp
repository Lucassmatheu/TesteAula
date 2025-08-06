#include <iostream>
#include <string>
#include "Aulas.h"

void Ranking(int* scores) 
{
	
	scores[8]={};
	int media = 0;
	std::cout << "Informe as 8 ponbtuações";
	// Cria um array para armazenar as pontuações dos jogadores
		for (int i = 0; i < 8 ; i++)
		{
			// Solicita a pontuação para cada jogador
			std::cout << "Pontuação " << (i + 1) << ": ";
			std::cin >> scores[i];
			// Verifica se a pontuação é válida
			media += scores[i];
			
		}
		int maior = scores[0];
		int menor = scores[0];
		// Inicializa maior e menor com a primeira pontuação
		for (int i = 1; i < 8; i++)
		{
			// Atualiza a maior e menor pontuação
			if (scores[i] > maior) maior = scores[i];
			// Verifica se a pontuação é menor que a menor pontuação atual
			if (scores[i] < menor) menor = scores[i];
		}

		// Calcula a média das pontuações
		for (int i = 0; i < 8; i++)
		{
			media += scores[i];
			// Exibe a pontuação de cada jogador
			std::cout << "Pontuação " << (i + 1) << ": " << scores[i] << std::endl;
		}
		media /= 8; // Calcula a média dividindo pela quantidade de jogadores
		std::cout << "Média das pontuações: " << media << std::endl;
		std::cout << "Maior score: " << maior << std::endl;
		std::cout << "Menor score: " << menor << std::endl;
}