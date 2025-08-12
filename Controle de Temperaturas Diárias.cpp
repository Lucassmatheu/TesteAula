#include <iostream>
#include <string>
#include "Aulas.h"

void ControleTemperaturasDiarias()
{
	const int dias = 7;
	float temperaturas[dias];
	float soma = 0.0f;
	float maior = -1000.0f; // Inicializa com um valor muito baixo
	float menor = 1000.0f;  // Inicializa com um valor muito alto
	std::cout << "===== CONTROLE DE TEMPERATURAS DIÁRIAS =====\n";
	// Solicita a temperatura de cada dia
	for (int i = 0; i < dias; i++)
	{
		std::cout << "Digite a temperatura do dia " << (i + 1) << ": ";
		std::cin >> temperaturas[i];
		// Verifica se a temperatura é válida
		soma += temperaturas[i];
		// Atualiza o maior e menor valor de temperatura
		if (temperaturas[i] > maior)
			maior = temperaturas[i];
		if (temperaturas[i] < menor)
			menor = temperaturas[i];
	}
	float media = soma / dias;
	std::cout << "\n=== RESULTADOS ===\n";
	std::cout << "Temperatura média: " << media << "\n";
	std::cout << "Maior temperatura: " << maior << "\n";
	std::cout << "Menor temperatura: " << menor << "\n";
}