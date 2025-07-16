#include <iostream>


void Escolha() 
{
	/*
    Este programa simula um jogo onde o jogador toma uma decis�o com base em sua energia.

Passos:
	1. Pergunta ao jogador se ele tem energia (1 = sim, 0 = n�o)
	2. Se tiver energia:
   - Mostra op��es de a��o: atacar, defender, fugir ou n�o fazer nada
   - Usa switch-case para mostrar a resposta da a��o
	3. Se n�o tiver energia:
   - Mostra as mesmas op��es, mas qualquer escolha resulta em uma mensagem dizendo que est� muito cansado

T�cnicas usadas:
	- Estrutura de decis�o if / else
	- switch-case para a��es
	- Organiza��o de fluxo com base em condi��es
*/

	int energia, comandos, comandos2;

	std::cout << "Voc� tem erengia( 1 para sim / 0 para n�o) \n";
	std::cin >> energia;
	
	if (energia == 1)
	{
		std::cout << "Voc� tem energia para lutar \n";
		std::cout << "Escolha uma a��o: \n";
		std::cout << "1 - ATACAR \n 2 - DEFENDER \n 3 - FUGIR \n 4 - NADA \n";
		std::cout << "Digite o n�mero da a��o desejada: ";
		std::cin >> comandos;
		switch (comandos)
		{
		case 1:
			std::cout << "Voc� atacou o inimigo \n";
			break;
		case 2:
			std::cout << "Voc� se defendeu \n";
			break;
		case 3:
			std::cout << "Voc� fugiu da batalha \n";
			break;
		case 4:
			std::cout << "Voc� n�o fez nada \n";
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
				std::cout << "Voc� n�o pode atacar esta muito casado \n";
			}
			else if (comandos2 == 2)
			{
				std::cout << "Voc� n�o pode se defender esta muito cansado \n";
			}
			else if (comandos2 == 3)
			{
				std::cout << "Voc� n�o pode fugir esta muito cansado \n";
			}
		
	}
	else
	{
		std::cout << "Voc� n�o tem energia para lutar \n";
	}
	


	
}