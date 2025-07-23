#include <iostream>
#include "Aulas.h"

void IventarioComPrecos() 
{
	int quantidadeitens[5];
	int precosItens[5];
	int* pQuantidadeItens = quantidadeitens;
	int* pPrecosItens = precosItens;
	int soma = 0;	
	// Solicita ao usuário a quantidade e o preço de cada item
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Digite a quantidade do item " << (i + 1) << ": ";
		// Corrigido: Lê a quantidade do item
        std::cin >> *(pQuantidadeItens + i);

        std::cout << "Digite o preço do item " << (i + 1) << ": ";
		// Corrigido: Lê o preço do item
        std::cin >> *(pPrecosItens + i);

        // Mostra os dados do item
        std::cout << "Quantidade do item " << (i + 1) << ": " << *(pQuantidadeItens + i) << "\n";
        std::cout << "Preço do item " << (i + 1) << ": " << *(pPrecosItens + i) << "\n";

        // Corrigido: soma += quantidade * preço
        soma += *(pQuantidadeItens + i) * *(pPrecosItens + i);
    }

    std::cout << "Valor total do inventário: " << soma << "\n";

}