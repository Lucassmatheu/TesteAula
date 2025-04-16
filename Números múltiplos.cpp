#include <iostream>	
#include "Aulas.h"


void NumerosMultiplos() 
{ 
	int numero, contagem = 0;
	std::cout << "Digite um número: ";
	std::cin >> numero;
	
	for (int i = 1; i <= 100; i++) 
		/*
			Explicação do for:

			for (int i = 3; i <= 100; i += 3)

			- Esse for começa com i valendo 3
			- A condição i <= 100 diz que ele vai continuar enquanto i for menor ou igual a 100
			- O i += 3 significa que a cada volta do loop, o i vai somar 3 (3, 6, 9, 12, ...)

			É igual a fazer:
			int i = 3;
			while (i <= 100) {
			// bloco de código
			i += 3;
			}

			Se eu quiser ir de 1 em 1, uso i++
			Se quiser ir de 2 em 2 (só pares), uso i += 2
			Se quiser ir de número em número direto (tipo múltiplos), posso usar i += numero

			Também posso usar if (i % numero == 0) dentro do for para verificar se o i é múltiplo do número que o usuário digitou.

			Esse tipo de for é bom quando eu já sei o ponto de partida, o fim e o passo que quero dar a cada volta.
		*/
	{
		
		if (i % numero == 0) {
			contagem++;
			std::cout << i << " é múltiplo de " << numero << std::endl;
		}
		if (numero <= 0) {
			std::cout << "Digite um número maior que zero!" << std::endl;
			return;
		}
		
	}
} 