#include <iostream> 
#include "Aulas.h"


void verificacaoDeLogin() 
{
    bool logado;
    std::string usuario;

    std::cout << "Voc� est� logado? (1 - Sim / 0 - N�o): ";
    std::cin >> logado;

    std::cout << "Digite seu nome de usu�rio: ";
    std::cin >> usuario;
	
	if (logado)
	{
		std::cout << "Bem-vindo, " << usuario << "!" << std::endl;
	}
	else
	{
		std::cout << "Voc� n�o est� logado." << std::endl;
	}
}