#include <iostream>
#include "Aulas.h"

void Positivos() 
{
	/*
	Este programa pede que o usuário digite 10 números.
	Ele soma apenas os números positivos, conta quantos foram positivos
	e calcula a média desses números.

	Usamos:
	- Um vetor para armazenar os 10 números
	- Laço for para percorrer as posições do vetor
	- Um if para verificar se o número é positivo
	- Variáveis soma e contagem para cálculo da média
	*/
	float numero[10], soma = 0, media;
	int contagem = 0;
	std::cout << "Digite 10 números: " << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Número " << i + 1 << ": ";
		std::cin >> numero[i];
		if (numero[i] > 0)
		{
			soma += numero[i];
			contagem++;
			
			
		}
	
		
	}
	std::cout << "A soma dos números positivos é: " << soma << std::endl;
	std::cout << "A contagem dos números positivos é: " << contagem << std::endl;

	if (contagem > 0)
	{
		media = soma / contagem;
		std::cout << "A média dos números positivos é: " << media << std::endl;
	}
	else
	{
		std::cout << "Nenhum número positivo foi digitado." << std::endl;
	}
	





}