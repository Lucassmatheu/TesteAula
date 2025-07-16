#include <iostream>


void Escolha() 
{
	/*
    Este programa simula um jogo onde o jogador toma uma decisão com base em sua energia.

Passos:
	1. Pergunta ao jogador se ele tem energia (1 = sim, 0 = não)
	2. Se tiver energia:
   - Mostra opções de ação: atacar, defender, fugir ou não fazer nada
   - Usa switch-case para mostrar a resposta da ação
	3. Se não tiver energia:
   - Mostra as mesmas opções, mas qualquer escolha resulta em uma mensagem dizendo que está muito cansado

Técnicas usadas:
	- Estrutura de decisão if / else
	- switch-case para ações
	- Organização de fluxo com base em condições
*/

	int energia, comandos, comandos2;

	std::cout << "Você tem erengia( 1 para sim / 0 para não) \n";
	std::cin >> energia;
	
	if (energia == 1)
	{
		std::cout << "Você tem energia para lutar \n";
		std::cout << "Escolha uma ação: \n";
		std::cout << "1 - ATACAR \n 2 - DEFENDER \n 3 - FUGIR \n 4 - NADA \n";
		std::cout << "Digite o número da ação desejada: ";
		std::cin >> comandos;
		switch (comandos)
		{
		case 1:
			std::cout << "Você atacou o inimigo \n";
			break;
		case 2:
			std::cout << "Você se defendeu \n";
			break;
		case 3:
			std::cout << "Você fugiu da batalha \n";
			break;
		case 4:
			std::cout << "Você não fez nada \n";
			break;

		default:
			break;
		}
	}
	else if (energia == 0)
	{
		std::cout << "1 - ATACAR \n 2 - DEFENDER \n 3 - FUGIR \n";
		std::cin >> comandos2;
			if (comandos2 == 1)
			{
				std::cout << "Você não pode atacar esta muito casado \n";
			}
			else if (comandos2 == 2)
			{
				std::cout << "Você não pode se defender esta muito cansado \n";
			}
			else if (comandos2 == 3)
			{
				std::cout << "Você não pode fugir esta muito cansado \n";
			}
		
	}
	else
	{
		std::cout << "Você não tem energia para lutar \n";
	}
	


	
}