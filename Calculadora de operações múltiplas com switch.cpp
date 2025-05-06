#include <iostream>
#include "Aulas.h"

void calculadoraMultipla() 
{
	float num1, num2, i = 0;
	int operacao, limite;
	std::cout << "Quantas opereções deseja realizar ?";
	std::cin >> limite;
	while (i < limite) 
	{
		i++;
		std::cout << "Digite o primeiro numero numero";
		std::cin >> num1;
		std::cout << "Digite o segundo numero numero";
		std::cin >> num2;
		std::cout << "Escolha a operação desejada:\n";
		std::cout << "1. Soma\n";
		std::cout << "2. Subtração\n";
		std::cout << "3. Multiplicação\n";
		std::cout << "4. Divisão\n";
		std::cout << "5. Resto da Divisão\n";
		std::cout << "6. Potência\n";
		std::cout << "7. Raiz Quadrada\n";
			std::cin >> operacao;
			switch (operacao) 
			{
			case 1:
				std::cout << "Resultado da soma: " << num1 + num2 << std::endl;
				break;
			case 2:
				std::cout << "Resultado da subtração: " << num1 - num2 << std::endl;
				break;
			case 3:
				std::cout << "Resultado da multiplicação: " << num1 * num2 << std::endl;
				break;
			case 4:
				std::cout << "Resultado da divisão: " << num1 / num2 << std::endl;
				break;
			case 5:
				std::cout << "Resultado do resto da divisão: " << (int)num1 % (int)num2 << std::endl;
				break;
			case 6:
				std::cout << "Resultado da potência: " << pow(num1, num2) << std::endl;
				break;
			case 7:	
				if (num1 >= 0)
				{
					std::cout << "Resultado da raiz quadrada: " << sqrt(num1) << std::endl;
				}
				else
				{
					std::cout << "Erro: Raiz quadrada de número negativo não é real." << std::endl;
				}
				break;
			default:
				std::cout << "Operação inválida." << std::endl;
				break;

			}
	}
	std::cout << "Operações concluídas." << std::endl;
	std::cout << "Deseja realizar mais operações? (1 = sim / 0 = não): ";
	int resposta;
	std::cin >> resposta;
	if (resposta == 1)
	{
		calculadoraMultipla();
	}
	else if (resposta == 0)
	{
		std::cout << "Operação cancelada." << std::endl;
	}
	else
	{
		std::cout << "Opção inválida." << std::endl;
	}

}