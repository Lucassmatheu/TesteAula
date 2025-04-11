#include <iostream>
#include "Aulas.h"

void PrecedenciaDeOPeradores() 
{
	int X, Y, W, A, B;
	int C = 10;

	

	std::cout << "Digite o valor de X: ";
	std::cin >> X;	

	std::cout << "Digite o valor de Y: ";
	std::cin >> Y;

	std::cout << "Digite o valor de W: ";
	std::cin >> W;

	std::cout << "Digite o valor de A: ";
	std::cin >> A;
		
	std::cout << "Digite o valor de B: ";
	std::cin >> B;

	std::cout << "Digite o valor de C: ";
	std::cin >> C;
	if (C == B)
	//sempre que for fazer comparação de igualdade usar ==
	{
		std::cout << "C e igual a 10" << std::endl;
	}
	else
	{
		std::cout << "C e diferente de 10" << std::endl;
	} 
	if (A != W)
	//sempre que for fazer comparação de diferença usar !=
	{
		std::cout << "A e diferente de W" << std::endl;
	}
	else
	{
		std::cout << "A e igual a W" << std::endl;
	}
	if (A < C == W)
	//sempre que for fazer comparação de menor que usar <
	{
		std::cout << "A e menor que C e igual a W" << std::endl;
	}
	else
	{
		std::cout << "A nao e menor que C e igual a W" << std::endl;
	}
	int tottal = ((X * Y) * W) + (A * B) + C; 
	//sempre da esquerda paara dirita 
	//primeiro faz a multiplicação de X e Y
	//depois multiplica o resultado de X e Y por W
	//depois soma o resultado de X, Y e W com A
	//depois multiplica o resultado de X, Y, W e A por B
	//depois soma o resultado de X, Y, W, A e B com C
	

	std::cout << "O total da multiplicacao dos numeros e: " << tottal << std::endl;
}