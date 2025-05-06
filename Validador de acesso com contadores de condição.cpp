#include <iostream>
#include "Aulas.h"

void Validador() 
{
	int cadastro, logado, email;
	bool acesso = false;
	std::cout << "Você esta Cadastrado (1 - Sim / 0 - não)";
	std::cin >> cadastro;
	std::cout << "Você esta logado (1 - Sim / 0 - não)";
	std::cin >> logado;
	std::cout << "Você tem email (1 - Sim / 0 - não)";
	std::cin >> email;
	if (cadastro == 1 && logado == 1 && email == 1)
	{
		acesso = true;
		std::cout << "Acesso permitido\n";
	}
	else if (cadastro == 1 && logado == 1 && email == 0)
	{
		std::cout << "Acesso negado\n";
	}
	else if (cadastro == 1 && logado == 0 && email == 1)
	{
		std::cout << "Acesso negado\n";
	}
	else if (cadastro == 0 && logado == 1 && email == 1)
	{
		std::cout << "Acesso negado\n";
	}
	else if (cadastro == 0 && logado == 1 && email == 0)
	{
		std::cout << "Acesso negado\n";
	}
	else if (cadastro == 1 && logado == 0 && email == 0)
	{
		std::cout << "Acesso negado\n";
	}
	else if (cadastro == 0 && logado == 0 && email == 0)
	{
		std::cout << "Acesso negado\n";
	}
	else
	{
		std::cout << "Acesso negado\n";
	}
}