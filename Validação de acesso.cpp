#include <iostream>
#include "Aulas.h"

void ValidadorAcessos()
{
	std::string usuario;
	int senha,  codigoVerificacao;

	std::cout << "Digite o seu usuario: ";
	std::cin >> usuario;
	std::cout << "Digite a sua senha: ";
	std::cin >> senha;
	if(usuario == "Logado" && senha >= 1000)
	{
		std::cout << "Acesso permitido\n";
		do
		{
			std::cout << "Digite o seu codigo de verificação: ";
			std::cin >> codigoVerificacao;
			if (codigoVerificacao >= 100 && codigoVerificacao <= 999) {
				std::cout << "Acesso permitido\n";
				break;
			}
			else {
				std::cout << "Acesso negado\n";
			}
			

			


		} while (codigoVerificacao >= 100 || codigoVerificacao <= 999);
	
	}
	
}