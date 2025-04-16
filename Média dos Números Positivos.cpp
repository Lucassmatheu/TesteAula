#include <iostream>
#include "Aulas.h"

void Positivos() 
{
	/*
	Este programa pede que o usu�rio digite 10 n�meros.
	Ele soma apenas os n�meros positivos, conta quantos foram positivos
	e calcula a m�dia desses n�meros.

	Usamos:
	- Um vetor para armazenar os 10 n�meros
	- La�o for para percorrer as posi��es do vetor
	- Um if para verificar se o n�mero � positivo
	- Vari�veis soma e contagem para c�lculo da m�dia
	*/
	float numero[10], soma = 0, media;
	int contagem = 0;
	std::cout << "Digite 10 n�meros: " << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "N�mero " << i + 1 << ": ";
		std::cin >> numero[i];
		if (numero[i] > 0)
		{
			soma += numero[i];
			contagem++;
			
			
		}
	
		
	}
	std::cout << "A soma dos n�meros positivos �: " << soma << std::endl;
	std::cout << "A contagem dos n�meros positivos �: " << contagem << std::endl;

	if (contagem > 0)
	{
		media = soma / contagem;
		std::cout << "A m�dia dos n�meros positivos �: " << media << std::endl;
	}
	else
	{
		std::cout << "Nenhum n�mero positivo foi digitado." << std::endl;
	}
	





}