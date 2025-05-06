#include <iostream>
#include "Aulas.h"
#include <string>

void uSUARIO()
{
	std::string usuario{};
	int senha{}, tentativas = 0;
	bool acesso = false;

	std::cout << "Digite o seu usuario: ";
	std::cin >> usuario;
	std::cout << "Digite a sua senha: ";
	std::cin >> senha;
	for (int i = 1; i < 3; i++) 
	{
		if (usuario == "Lucas" && senha == 1234) 
		{
			acesso = true;
			std::cout << "Acesso permitido\n";
			break;
		}
		else if (usuario != "Lucas" && senha != 1234)
		{
			acesso = false;
			std::cout << "Usuario e senha incorretos\n";
		}
		else if (usuario != "Lucas")
		{
			acesso = false;
			std::cout << "Usuario incorreto\n";
		}
		else if (senha != 1234)
		{
			acesso = false;
			std::cout << "Senha incorreta\n";
		}
		else
		{
			tentativas++;
			std::cout << "Senha incorreta. Você tem " << 3 - tentativas << " tentativas restantes.\n";
		}
	}


}