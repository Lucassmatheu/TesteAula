#include<iostream>
#include "Aulas.h"

void CalcularSomas(int* numeros)
{
	int qtdNumeros;
	int soma = 0;
	int contadorpar = 0;
	int mediaImpares = 0, media{};
	int somaImpares = 0; int qtdImpares = 0;
	std::cout << "Digite a quantidade de n�meros: ";
	std::cin >> qtdNumeros;

	for (int i = 0;i < qtdNumeros; i++) 
	{
		if (qtdNumeros >= 100) 
		{
			std::cout << "Quantidade inv�lida! Digite um n�mero menor ou igual a 100." << std::endl;
			return;
		}
		std::cout << "Digite o " << (i + 1) << "� n�mero: ";
		std::cin >> numeros[i];

		if (numeros[i] % 2 == 0)
		{
			soma += numeros[i];
			contadorpar++;
			std::cout << "N�mero par: " << numeros[i] << std::endl;
		}
		if (qtdImpares > 0)
			std::cout << "M�dia dos �mpares: " << (float)somaImpares / qtdImpares << std::endl;
		else
			std::cout << "Nenhum n�mero �mpar foi digitado.\n";
	}
	std::cout << "A soma dos n�meros pares �: " << soma << std::endl;
	std::cout << "Total de n�meros pares: " << contadorpar << std::endl;
	std::cout << "Total de n�meros �mpares: " << (qtdNumeros - contadorpar) << std::endl;
	std::cout << "A m�dia dos n�meros �mpares �: " << (media / (qtdNumeros - contadorpar)) << std::endl;
	
}