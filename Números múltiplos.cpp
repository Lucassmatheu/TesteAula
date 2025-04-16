#include <iostream>	
#include "Aulas.h"


void NumerosMultiplos() 
{ 
	int numero, contagem = 0;
	std::cout << "Digite um n�mero: ";
	std::cin >> numero;
	
	for (int i = 1; i <= 100; i++) 
		/*
			Explica��o do for:

			for (int i = 3; i <= 100; i += 3)

			- Esse for come�a com i valendo 3
			- A condi��o i <= 100 diz que ele vai continuar enquanto i for menor ou igual a 100
			- O i += 3 significa que a cada volta do loop, o i vai somar 3 (3, 6, 9, 12, ...)

			� igual a fazer:
			int i = 3;
			while (i <= 100) {
			// bloco de c�digo
			i += 3;
			}

			Se eu quiser ir de 1 em 1, uso i++
			Se quiser ir de 2 em 2 (s� pares), uso i += 2
			Se quiser ir de n�mero em n�mero direto (tipo m�ltiplos), posso usar i += numero

			Tamb�m posso usar if (i % numero == 0) dentro do for para verificar se o i � m�ltiplo do n�mero que o usu�rio digitou.

			Esse tipo de for � bom quando eu j� sei o ponto de partida, o fim e o passo que quero dar a cada volta.
		*/
	{
		
		if (i % numero == 0) {
			contagem++;
			std::cout << i << " � m�ltiplo de " << numero << std::endl;
		}
		if (numero <= 0) {
			std::cout << "Digite um n�mero maior que zero!" << std::endl;
			return;
		}
		
	}
} 