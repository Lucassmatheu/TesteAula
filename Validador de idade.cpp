#include <iostream>
#include "Aulas.h"

void ValidadorIdade()
{
	int idade, seguida = 0;
	do 
	{
		std::cout << "Digite sua idade: ";
		std::cin >> idade;
		if (idade > 0 && idade <= 120)
		{
			std::cout << "Idade v�lida registrada!" << std::endl;
		}
		else
		{
			std::cout << "Idade inv�lida. Tente novamente." << std::endl;
		}

	}
	while (idade <= 0 || idade > 120);
}