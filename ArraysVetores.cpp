#include <iostream>
#include "Aulas.h"

void Vetores()
{
	float notas[5]{}, OpcaoNotas, media{}, soma{};
	
	std::cout << "Digite as notas dos alunos (6 notas):\n";
	std::cin >> OpcaoNotas;
	// Preenchendo o vetor com as notas
	for (int i = 0; i < 5; i++) // Alterado para começar de 0 e ir até 5
	{
		std::cout << "\nDigite a nota " << (i + 1) << ": ";
		std::cin >> notas[i];
		// Precisamos de uma variável que acumule a soma das notas!
		soma = soma + notas[i];
		system("CLS");
	}
	media = soma / 6; // Calculando a média
	std::cout << "Notas dos alunos:\n";
	for (int i = 0; i < 5; i++) // Alterado para começar de 0 e ir até 5
	{
		std::cout << "Nota " << (i + 1) << ": " << notas[i] << "\n";
	}
	// Exibindo a média
	std::cout << "A média das notas é: " << media << "\n";
	system("Pause");
	return;
}