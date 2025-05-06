#include <iostream> 
#include "Aulas.h"

static void Idade()
{
	int idade, limite, cont12 = 0, cont18_25 = 0, cont26_35 = 0, cont36_45 = 0, cont46_55 = 0, cont56_65 = 0, cont66 = 0;
	std::cout << "Digite a quantidade de pessoas: ";
	std::cin >> limite;

	for (int i = 1; i <= limite; i++) 
	{
		std::cout << "Digite a idade da pessoa " << i << ": ";
		std::cin >> idade;
		if (idade <= 12) 
		{
			std::cout << "Criança ate 12 anos ";
			cont12++;

		}
		else if (idade >= 13 && idade <= 17) 
		{
			std::cout << "Adolescente de 13 a 17 anos ";
			cont18_25++;
		}
		else if (idade >= 18 && idade <= 25)
		{
			std::cout << "Jovem de 18 a 25 anos ";
			cont26_35++;
		}
		else if (idade >= 26 && idade <= 35)
		{
			std::cout << "Adulto de 26 a 35 anos ";
			cont36_45++;
		}
		else if (idade >= 36 && idade <= 45)
		{
			std::cout << "Adulto de 36 a 45 anos ";
			cont46_55++;
		}
		else if (idade >= 46 && idade <= 55)
		{
			std::cout << "Adulto de 46 a 55 anos ";
			cont56_65++;
		}
		else if (idade >= 56 && idade <= 65)
		{
			std::cout << "Adulto de 56 a 65 anos ";
			cont66++;
		}
	}
	std::cout << "Total de crianças: " << cont12 << std::endl;
	std::cout << "Total de adolescentes: " << cont18_25 << std::endl;
	std::cout << "Total de jovens: " << cont26_35 << std::endl;
	std::cout << "Total de adultos: " << cont36_45 << std::endl;
	
}

