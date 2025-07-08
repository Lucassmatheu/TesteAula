#include <iostream>
#include "Aulas.h"

static void contadorPositivoss()
{
/*
  Este programa faz um contador em duas etapas:
  1) Mostra os números do valor inicial até o valor final (ordem crescente)
  2) Depois mostra os números do valor final até o valor inicial (ordem decrescente)

 🧠 Lógica usada:

  - Na primeira parte usamos um laço for:
    for (int i = inicio; i <= fim; i++)
  → O i começa no número inicial e vai subindo (i++) até chegar no valor final

    Exemplo: início = 3, fim = 6
    O for vai imprimir: 3, 4, 5, 6

  - Na segunda parte usamos um laço while:
    int i = fim;
    while (i >= inicio)
   → O i começa no número final e vai descendo (i--) até chegar no início

    Exemplo: início = 3, fim = 6
   O while vai imprimir: 6, 5, 4, 3

  ✅ Ou seja:
  - for → conta pra frente (i++)
  - while → conta pra trás (i--)

    Dica:
    Se quiser, você pode adicionar condições dentro dos laços, como:
  - if (i % 2 == 0) → para mostrar apenas os pares
  - if (i > 0)       → para contar apenas os positivos
*/

	int i, inicio, fim, contador = 0;
	std::cout << "Digite o valor inicial: ";
	std::cin >> inicio;
	std::cout << "Digite o valor final: ";
	std::cin >> fim;
	i = inicio;
	for (i; i <= fim; i++)
	{
		if (i > 0)
		{
			contador++;
		}
		

	}
	i = fim;
	while (i >= inicio)
	{
		if (i > 0)
		{
			contador++;
		}
		i--;
	}
	std::cout << "Total de números positivos entre " << inicio << " e " << fim << ": " << contador << std::endl;
}