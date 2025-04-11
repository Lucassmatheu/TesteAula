#include <iostream>
#include "Aulas.h"

void calculadoraSimples()
{
	float num1, num2, resultadoSoma, ResultadoSubtracao, ResultadoMultilicao, ResultadoDivisao, ResultadoResto, resposta ;
	

	std::cout << "Digite o primeiro numero: ";
	std::cin >> num1;
	std::cout << "Digite o segundo numero: ";
	std::cin >> num2;
	resultadoSoma = num1 + num2;
	ResultadoSubtracao = num1 - num2;
	ResultadoMultilicao = num1 * num2;
	ResultadoDivisao = num1 / num2;
	ResultadoResto = ((int)num2 * (num1)) / 100;

	if (num2 == 0) {
		std::cout << "Erro: Divisao por zero!" << std::endl;
		return;
	}
	if (num1 && num2) {
		std::cout << "O primerio numero e: " << num1 << std::endl;
		std::cout << "O segundo numero e: " << num2 << std::endl;
		std::cout << "Deseja continuar? (1 = sim / 0 = não): ";
		std::cin >> resposta;

		if (resposta == 1) 
		{
			std::cout << "Resultado da soma: " << resultadoSoma << std::endl;
			std::cout << "Resultado da subtracao: " << ResultadoSubtracao << std::endl;
			std::cout << "Resultado da multiplicacao: " << ResultadoMultilicao << std::endl;
			std::cout << "Resultado da divisao: " << ResultadoDivisao << std::endl;
			std::cout << "Resultado do resto: " << ResultadoResto << std::endl;
			if (resultadoSoma == 0 && ResultadoSubtracao == 0 || ResultadoMultilicao == 0)
			{
				std::cout << "Resultado da soma e igual a zero." << resultadoSoma << std::endl;
				std::cout << "Resultado da subtracao e igual a zero." << ResultadoSubtracao << std::endl;
				std::cout << "Resultado da multiplicacao e igual a zero." << ResultadoMultilicao << std::endl;
			}
			if (resultadoSoma != 0 && ResultadoSubtracao != 0 || ResultadoMultilicao != 0)
			{
				std::cout << "Resultado da soma e diferente de zero." << resultadoSoma << std::endl << std::endl;
				std::cout << "Resultado da subtracao e diferente de zero." << ResultadoSubtracao << std::endl << std::endl;
				std::cout << "Resultado da multiplicacao e diferente de zero." << ResultadoMultilicao << std::endl << std::endl;

			}
			
		
			
		}
		else if (resposta == 0)
		{
			std::cout << "Operacao cancelada." << std::endl;
		}
		else
		{
			std::cout << "Opcao invalida." << std::endl;
		} 
		
		
	}




}