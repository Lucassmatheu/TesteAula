#include <iostream>

void FaixadeIdade()
{
	int idade;
	std::cout << "Digite a sua idade: ";
	std::cin >> idade;
	if (idade < 18)
	{
		std::cout << "Voce e menor de idade" << std::endl;
	}
	else if (idade >= 18 && idade < 60)
	{
		std::cout << "Voce e adulto" << std::endl;
	}
	else
	{
		std::cout << "Voce e idoso" << std::endl;
	}
}