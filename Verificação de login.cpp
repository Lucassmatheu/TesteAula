#include <iostream> 
#include "Aulas.h"


void verificacaoDeLogin() 
{
    bool logado;
    std::string usuario;

    std::cout << "Você está logado? (1 - Sim / 0 - Não): ";
    std::cin >> logado;

    std::cout << "Digite seu nome de usuário: ";
    std::cin >> usuario;
	
	if (logado)
	{
		std::cout << "Bem-vindo, " << usuario << "!" << std::endl;
	}
	else
	{
		std::cout << "Você não está logado." << std::endl;
	}
}