#include <iostream>
#include "Aulas.h"
#include <cmath> // Para usar a função sqrt

void CauculadoradeBaskara() 
{
	float a, b, c;
	std::cout << "Digite os valores de a, b e c: ";
	std::cin >> a >> b >> c;
	if (a == 0) {
		std::cout << "O valor de 'a' não pode ser zero." << std::endl;
		return;
	}
	float delta = b * b - 4 * a * c;
	if (delta < 0) {
		std::cout << "Não existem raízes reais." << std::endl;
	}
	else {
		float raiz1 = (-b + sqrt(delta)) / (2 * a);
		float raiz2 = (-b - sqrt(delta)) / (2 * a);
		std::cout << "As raízes são: " << raiz1 << " e " << raiz2 << std::endl;
	}
}