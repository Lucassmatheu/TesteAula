#include <iostream>
#include "Aulas.h"

void IventarioComPrecos() 
{
	int quantidadeitens[5];
	int precosItens[5];
	int* pQuantidadeItens = quantidadeitens;
	int* pPrecosItens = precosItens;
	int soma = 0;	
	// Solicita ao usu�rio a quantidade e o pre�o de cada item
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Digite a quantidade do item " << (i + 1) << ": ";
		// Corrigido: L� a quantidade do item
        std::cin >> *(pQuantidadeItens + i);

        std::cout << "Digite o pre�o do item " << (i + 1) << ": ";
		// Corrigido: L� o pre�o do item
        std::cin >> *(pPrecosItens + i);

        // Mostra os dados do item
        std::cout << "Quantidade do item " << (i + 1) << ": " << *(pQuantidadeItens + i) << "\n";
        std::cout << "Pre�o do item " << (i + 1) << ": " << *(pPrecosItens + i) << "\n";

        // Corrigido: soma += quantidade * pre�o
        soma += *(pQuantidadeItens + i) * *(pPrecosItens + i);
    }

    std::cout << "Valor total do invent�rio: " << soma << "\n";

}