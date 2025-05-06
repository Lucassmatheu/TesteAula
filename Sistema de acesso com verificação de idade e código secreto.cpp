#include <iostream>
#include "Aulas.h" 

void AcessoIdade() 
{
	std::string usuario;	
	int idade, contador = 0, codigoSecreto, tentativas = 1;
	std::cout << "Digite o seu usuario: ";
	std::cin >> usuario;
	std::cout << "Digite sua idade: ";
	std::cin >> idade;
	if (usuario == "Logado" && idade >= 18 && idade <= 99) {
		do
		{
			std::cout << "Digite o seu codigo secreto: ";
			std::cin >> codigoSecreto;
			if (codigoSecreto >= 1000 && codigoSecreto <= 9999) 
			{
				std::cout << "Acesso permitido\n";
				break;
			}
			else if (codigoSecreto < 1000 || codigoSecreto > 9999)
			{
				std::cout << "Acesso negado\n";
				std::cout << "Você tem " << 3 - tentativas << " tentativas restantes.\n";
				tentativas++;
				
			}
			if (tentativas == 3)
			{
				std::cout << "Acesso Bloqueado Tente Mais Tarde";
			}
			
		


		} while (tentativas <= 3);
		
	}
}