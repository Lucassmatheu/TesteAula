#include <iostream>
#include "Aulas.h"

void ClassificarTriangulo()
{


	int lado1, lado2, lado3;

	std::cout << "Digite o primeiro lado: ";
	std::cin >> lado1;

	std::cout << "Digite o segundo lado: ";
	std::cin >> lado2;

	std::cout << "Digite o terceiro lado: ";
	std::cin >> lado3;
	if (lado1 == lado2 && lado2 == lado3)
	{
		std::cout << "Tri�ngulo equil�tero" << std::endl;
	}
	else if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3)
	{
		std::cout << "Tri�ngulo is�sceles" << std::endl;
	}
	else
	{
		std::cout << "Tri�ngulo escaleno" << std::endl;


	}

}