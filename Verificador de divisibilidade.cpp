#include <iostream>
#include "Aulas.h"

void verificador()
{
	int numero;

	std::cout << "Digite um n�mero: ";
	std::cin >> numero;
    if (numero % 2 == 0 && numero % 3 == 0 && numero % 5 == 0)
    {
        std::cout << "O n�mero " << numero << " � divis�vel por 2, 3 e 5." << std::endl;
    }
    else if (numero % 2 == 0 && numero % 3 == 0)
    {
        std::cout << "O n�mero " << numero << " � divis�vel por 2 e 3." << std::endl;
    }
    else if (numero % 2 == 0 && numero % 5 == 0)
    {
        std::cout << "O n�mero " << numero << " � divis�vel por 2 e 5." << std::endl;
    }
    else if (numero % 3 == 0 && numero % 5 == 0)
    {
        std::cout << "O n�mero " << numero << " � divis�vel por 3 e 5." << std::endl;
    }
    else if (numero % 2 == 0)
    {
        std::cout << "O n�mero " << numero << " � divis�vel apenas por 2." << std::endl;
    }
    else if (numero % 3 == 0)
    {
        std::cout << "O n�mero " << numero << " � divis�vel apenas por 3." << std::endl;
    }
    else if (numero % 5 == 0)
    {
        std::cout << "O n�mero " << numero << " � divis�vel apenas por 5." << std::endl;
    }
    else
    {
        std::cout << "O n�mero " << numero << " n�o � divis�vel por 2, 3 ou 5." << std::endl;
    }
	std::cout << "Fim do programa." << std::endl;
	std::cout << "Pressione Enter para sair...";
	std::cin.ignore();
	std::cin.get();


}