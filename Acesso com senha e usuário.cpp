#include <iostream>
#include <string>

static void AcessoComSenha()
{
	int senha;
	std::string usuario;

	std::cout << "Digite o usuario: ";
	std::cin >> usuario;

	std::cout << "Digite a senha: ";
	std::cin >> senha;

	if (usuario == "Lucas" && senha == 1234)
	{
		std::cout << "Acesso permitido" << std::endl;
	}
	else
	{
		std::cout << "Acesso negado" << std::endl;
	}
}