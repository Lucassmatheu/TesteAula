#include <iostream>
#include "Aulas.h"

void sistemaAcesso() 
{
	std::string usuario;
	bool acesso = false;	
	int senha, menu{}, contagem = 0, idade, media, nota1,nota2, nota3, numero1 ;
	std::cout << "Digite o seu usuario: ";
	std::cin >> usuario;
	std::cout << "Digite a sua senha: ";
	std::cin >> senha;
	if (usuario == "Lucas" && senha <= 1000)
	{
		acesso = true;
		std::cout << "Acesso permitido\n";

		std::cout << "\n[1] Cadastrar idade\n[2] Calcular média\n[3] Verificar par/ímpar\n[4] Contar até N\n[5] Sair\n";
		std::cout << "Digite a opção desejada: ";
		std::cin >> menu;
		do 
		{
			switch (menu)
			{
			case 1:
				std::cout << "Qua e a sua idade:";
				std:: cin>> idade;
				
				break;
			case 2:
				std::cout << "Digite a nota 1: ";
				std::cin >> nota1;
				std::cout << "Digite a nota 2: ";
				std::cin >> nota2;
				std::cout << "Digite a nota 3: ";
				std::cin >> nota3;
				media = (nota1 + nota2 + nota3) / 3;
				std::cout << "A média é: " << media << std::endl;				
				break;
			case 3:
				std::cout << "Digite um número: ";
				std::cin >> numero1;
				if (numero1 % 2 == 0)
				{
					std::cout << "O número " << numero1 << " é par." << std::endl;
				}
				else
				{
					std::cout << "O número " << numero1 << " é ímpar." << std::endl;
				}							
				break;
			case 4:
				std::cout << "Digite um número: ";
				std::cin >> numero1;
				for (int i = 0; i <= 0; i++) 
				{
					std::cout << i << std::endl;
					if (i == numero1)
					{
						break;
					}
				}			
				break;
			case 5:
				std::cout << "Saindo...\n";			
			default:
				std::cout << "Opção inválida.\n";
				break;
			}

		} while (menu != 5);

	}
	
	

}