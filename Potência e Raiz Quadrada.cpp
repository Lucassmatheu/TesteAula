#include <iostream>
#include <cmath>
#include "Aulas.h"

void PotenciaERaizQuadrada() 
{
	float numero, potencia, raizQuadrada;

	std::cout << "Digite um numero: ";
	std::cin >> numero;
	potencia = (numero * numero);
	raizQuadrada = sqrt(numero);
	// sqrt() � uma fun��o da biblioteca cmath que calcula a raiz quadrada de um n�mero

	std::cout << "A potencia de " << numero << " e: " << potencia << std::endl;
	std::cout << "A raiz quadrada de " << numero << " e: " << raizQuadrada << std::endl;

}