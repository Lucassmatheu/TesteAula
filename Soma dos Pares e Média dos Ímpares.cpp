#include<iostream>
#include "Aulas.h"

void CalcularSomas(int* numeros)
{
	int qtdNumeros;
	int soma = 0;
	int contadorpar = 0;
	int mediaImpares = 0, media{};
	int somaImpares = 0; int qtdImpares = 0;
	std::cout << "Digite a quantidade de números: ";
	std::cin >> qtdNumeros;

	for (int i = 0;i < qtdNumeros; i++) 
	{
		if (qtdNumeros >= 100) 
		{
			std::cout << "Quantidade inválida! Digite um número menor ou igual a 100." << std::endl;
			return;
		}
		std::cout << "Digite o " << (i + 1) << "º número: ";
		std::cin >> numeros[i];

		if (numeros[i] % 2 == 0)
		{
			soma += numeros[i];
			contadorpar++;
			std::cout << "Número par: " << numeros[i] << std::endl;
		}
		if (qtdImpares > 0)
			std::cout << "Média dos ímpares: " << (float)somaImpares / qtdImpares << std::endl;
		else
			std::cout << "Nenhum número ímpar foi digitado.\n";
	}
	std::cout << "A soma dos números pares é: " << soma << std::endl;
	std::cout << "Total de números pares: " << contadorpar << std::endl;
	std::cout << "Total de números ímpares: " << (qtdNumeros - contadorpar) << std::endl;
	std::cout << "A média dos números ímpares é: " << (media / (qtdNumeros - contadorpar)) << std::endl;
	
}