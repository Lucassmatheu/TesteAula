#include<iostream>
#include"Aulas.h"

void cadastrarSenha(std::string* nome, int* senha) 
{
	nome[5];
	senha[5];

	for (int i = 0; i < 5; i++) 
	{
		std::cout << "Nome do usuario ";
		std::cin >> nome[i];

		std::cout << "Informe a senha em numeros";
		std::cin >> senha[i];

		std::cout << "Usuários cadastrados até agora:\n";
		for (int j = 0; j <= i; j++) {
			std::cout << "- " << nome[j] << std::endl;
		}
		std::cout << std::endl;
	

	}
	

}
void VerificarLogin(std::string* nome, int* senha) 
{
	bool verificarLogin = false;
	for (int i = 0; i < 5; i++) 
	{
		std::string usuario;
		int senhaUsuario;
		std::cout << "Informe o nome do usuario: ";
		std::cin >> usuario;
		std::cout << "Informe a senha do usuario: ";
		std::cin >> senhaUsuario;
		if (usuario == nome[i] && senhaUsuario == senha[i]) 
		{
			std::cout << "Login realizado com sucesso!\n";
			verificarLogin = true;
			break;
		}
	}
}
void SistemaDeLogin() 
{
	std::string nome[5];
	int senha[5];
	cadastrarSenha(nome, senha);
	VerificarLogin(nome, senha);
	std::cout << "Sistema de Login finalizado.\n";
}