#include <iostream>
#include "Aulas.h"
#include <string>

void Idade() 
{
	int idade;
	std::string categoria;

	std::cout << "Digite sua idade: ";
	std::cin >> idade;

	categoria = (idade < 12) ? "Infantil" :
		(idade < 18) ? "Adolescente" :
		(idade < 60) ? "Adulto" : "Idoso";
	std::cout << "Categoria: " << categoria << std::endl;

	if (idade < 12 ) 
	{
		std::cout << "Categoria: Infantil" << std::endl;
	}
	else if (idade < 18)
	{
		std::cout << "Categoria: Adolescente" << std::endl;
	}
	else if (idade < 60)
	{
		std::cout << "Categoria: Adulto" << std::endl;
	}
	else
	{
		std::cout << "Categoria: Idoso" << std::endl;
	}




}