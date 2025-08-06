#include <iostream>
#include "Aulas.h"

void batalhasEquipes(int* EquipeA, int* EquipeB)
{
	int somaA = 0, somaB = 0;
	for (int i = 0; i < 5; i++) 
	{
		std::cout << "Informe foça da sua equipe " << (i + 1) << ":\n";
		std::cin >> EquipeA[i];
		somaA += EquipeA[i];	
	}
	for (int j = 0; j < 5; j++) 
	{
		std::cout << "Informe foça da equipe adversaria " << (j + 1) << ":\n";
		std::cin >> EquipeB[j];
		somaB = +EquipeB[j];
	}
	
}
void IndidiceMaisForte(int* EquipeA, int* EquipeB)
{
	int somaA = 0, somaB = 0;
	for (int i = 0; i < 5; i++)
	{
		somaA += EquipeA[i];
	}
	for (int j = 0; j < 5; j++)
	{
		somaB += EquipeB[j];
	}
	if (somaA > somaB) 
	{
		std::cout << "Equipe A venceu com " << somaA << " pontos!\n";
	}
	else if (somaB > somaA) 
	{
		std::cout << "Equipe B venceu com " << somaB << " pontos!\n";
	}
	else 
	{
		std::cout << "Empate! Ambas as equipes tem " << somaA << " pontos!\n";
	}
}