#include <iostream>
#include "Aulas.h"

void Multiplosdetres() 
{
    int num;

    std::cout << "Digite um numero: ";
    std::cin >> num;

    for (int i = 1; i <= num; i++)
    {
        if (i % 3 == 0)
        {
            std::cout << i << " é múltiplo de 3" << std::endl;
        }
    }
}