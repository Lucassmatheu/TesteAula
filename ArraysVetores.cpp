#include <iostream>
#include "Aulas.h"

void Vetores()
{
	float notas[5]{}, OpcaoNotas, media{}, soma{};
	
	std::cout << "Digite as notas dos alunos (6 notas):\n";
	std::cin >> OpcaoNotas;
	// Preenchendo o vetor com as notas
	for (int i = 0; i < 5; i++) // Alterado para come�ar de 0 e ir at� 5
	{
		std::cout << "\nDigite a nota " << (i + 1) << ": ";
		std::cin >> notas[i];
		// Precisamos de uma vari�vel que acumule a soma das notas!
		soma = soma + notas[i];
		system("CLS");
	}
	media = soma / 6; // Calculando a m�dia
	std::cout << "Notas dos alunos:\n";
	for (int i = 0; i < 5; i++) // Alterado para come�ar de 0 e ir at� 5
	{
		std::cout << "Nota " << (i + 1) << ": " << notas[i] << "\n";
	}
	// Exibindo a m�dia
	std::cout << "A m�dia das notas �: " << media << "\n";
	system("Pause");
	return;
}