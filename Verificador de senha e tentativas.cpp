#include <iostream>
#include "Aulas.h"

void static tentativas() 
{
	bool acesso = false;
	int senha, tentativas = 0;
	std::string usuario;
	std::cout << "Digite o seu usuario: ";
	std::cin >> usuario;
	std::cout << "Digite a sua senha: ";
	std::cin >> senha;
	if (usuario == "LUCAS" && senha == 1234) 
	{
		acesso = true;

	}
	else 
	{
		for (int i = 0; i < 3; i++) 
		{
			std::cout << "Tentativa " << i << " - Digite sua senha: ";
			std::cin >> senha;
			

			if (senha == 1234)
			{
				acesso = true;
				break;
			}
			else
			{
				tentativas++;
				std::cout << "Senha incorreta. Você tem " << 3 - tentativas << " tentativas restantes.\n";
			}
			
			
		}
	}

}