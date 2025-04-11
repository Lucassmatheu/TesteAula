#include <iostream>

void PodeEntrar()
{
    bool temConvite, estaNaLista;

    std::cout << "Tem convite? (1 - Sim / 0 - Nao): ";
    std::cin >> temConvite;

    std::cout << "Esta na lista? (1 - Sim / 0 - Nao): ";
    std::cin >> estaNaLista;

    if (temConvite || estaNaLista)
    {
        std::cout << "Entrada liberada!" << std::endl;
    }
    else
    {
        std::cout << "Entrada proibida!" << std::endl;
    }
}
