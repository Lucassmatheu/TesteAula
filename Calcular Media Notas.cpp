#include <iostream>
#include "Aulas.h"  

void CalcularMediaNotas()
{
	float nota1, nota2, nota3, media;
	std::cout << "Digite a primeira nota: ";
	std::cin >> nota1;
	std::cout << "Digite a segunda nota: ";
	std::cin >> nota2;
	std::cout << "Digite a terceira nota: ";
	std::cin >> nota3;
	media = (nota1 + nota2 + nota3) / 3;
	std::cout << "A média das notas é: " << media << std::endl;
	if (media >= 6.0)
	{
		std::cout << "Aprovado!" << std::endl;
	}
	else
	{
		std::cout << "Reprovado." << std::endl;
	}



}
