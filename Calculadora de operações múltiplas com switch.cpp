#include <iostream>
#include "Aulas.h"

void calculadoraMultipla() 
{
	float num1, num2, i = 0;
	int operacao, limite;
	std::cout << "Quantas opere��es deseja realizar ?";
	std::cin >> limite;
	while (i < limite) 
	{
		i++;
		std::cout << "Digite o primeiro numero numero";
		std::cin >> num1;
		std::cout << "Digite o segundo numero numero";
		std::cin >> num2;
		std::cout << "Escolha a opera��o desejada:\n";
		std::cout << "1. Soma\n";
		std::cout << "2. Subtra��o\n";
		std::cout << "3. Multiplica��o\n";
		std::cout << "4. Divis�o\n";
		std::cout << "5. Resto da Divis�o\n";
		std::cout << "6. Pot�ncia\n";
		std::cout << "7. Raiz Quadrada\n";
			std::cin >> operacao;
			switch (operacao) 
			{
			case 1:
				std::cout << "Resultado da soma: " << num1 + num2 << std::endl;
				break;
			case 2:
				std::cout << "Resultado da subtra��o: " << num1 - num2 << std::endl;
				break;
			case 3:
				std::cout << "Resultado da multiplica��o: " << num1 * num2 << std::endl;
				break;
			case 4:
				std::cout << "Resultado da divis�o: " << num1 / num2 << std::endl;
				break;
			case 5:
				std::cout << "Resultado do resto da divis�o: " << (int)num1 % (int)num2 << std::endl;
				break;
			case 6:
				std::cout << "Resultado da pot�ncia: " << pow(num1, num2) << std::endl;
				break;
			case 7:	
				if (num1 >= 0)
				{
					std::cout << "Resultado da raiz quadrada: " << sqrt(num1) << std::endl;
				}
				else
				{
					std::cout << "Erro: Raiz quadrada de n�mero negativo n�o � real." << std::endl;
				}
				break;
			default:
				std::cout << "Opera��o inv�lida." << std::endl;
				break;

			}
	}
	std::cout << "Opera��es conclu�das." << std::endl;
	std::cout << "Deseja realizar mais opera��es? (1 = sim / 0 = n�o): ";
	int resposta;
	std::cin >> resposta;
	if (resposta == 1)
	{
		calculadoraMultipla();
	}
	else if (resposta == 0)
	{
		std::cout << "Opera��o cancelada." << std::endl;
	}
	else
	{
		std::cout << "Op��o inv�lida." << std::endl;
	}

}