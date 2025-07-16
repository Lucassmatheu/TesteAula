#include <iostream>
#include "Aulas.h"

void static cadastroDeHeroi(std::string* Nome[3], int* classe[3], int* nivel[3], int* energia[3], int* experiencia[3],int* ouro[3])
{
	for (int i = 0; i < 3; i++) 
	{
		std	::cout << "Digite o nome do heroi " << (i + 1) << ": ";
		std::cin >> *Nome[i];
		std::cout << "Digite a classe do heroi " << (i + 1) << ": ";
        std::cout << "1 - Guerreiro\n2 - Mago\n3 - Arqueiro\n";

		std::cin >> *classe[i];
		*energia[i] = 100; 
		*experiencia[i] = 0;
		*ouro[i] = 50; 
	}
}
void static visitarLoja(int* energia[3], int* experiencia[3], int* ouro[3])
{
    std::string itens[2] = { "Poção de Energia (+30 energia)", "Livro de Experiência (+40 XP)" };
    int precos[2] = { 20, 30 };

    for (int i = 0; i < 3; i++)
    {
        std::cout << "Herói " << (i + 1) << " possui " << *ouro[i] << " ouro.\n";
        std::cout << "Itens disponíveis na loja:\n";
        for (int j = 0; j < 2; j++)
        {
            std::cout << j + 1 << ". " << itens[j] << " - " << precos[j] << " ouro\n";
        }
        std::cout << "Escolha o item para comprar (1-2) ou 0 para sair: ";
        int escolha;
        std::cin >> escolha;
        if (escolha == 1) // Poção de Energia
        {
            if (*ouro[i] >= precos[0])
            {
                *ouro[i] -= precos[0];
                *energia[i] += 30;
                std::cout << "Herói " << (i + 1) << " comprou Poção de Energia! Energia atual: " << *energia[i] << "\n";
            }
            else
            {
                std::cout << "Ouro insuficiente!\n";
            }
        }
        else if (escolha == 2) // Livro de Experiência
        {
            if (*ouro[i] >= precos[1])
            {
                *ouro[i] -= precos[1];
                *experiencia[i] += 40;
                std::cout << "Herói " << (i + 1) << " comprou Livro de Experiência! XP atual: " << *experiencia[i] << "\n";
            }
            else
            {
                std::cout << "Ouro insuficiente!\n";
            }
        }
        else
        {
            std::cout << "Saindo da loja...\n";
        }
        std::cout << "\n";
    }
}
static void cacaemGrupo(std::string* Nome[3], int* classe[3], int* nivel[3], int* energia[3], int* experiencia[3], int* ouro[3])
{
    std::srand((unsigned int)std::time(nullptr)); // Inicializa o gerador de números aleatórios

    for (int i = 0; i < 3; i++)
    {
        std::cout << "Herói " << (i + 1) << " (" << *Nome[i] << ") vai caçar!\n";
        if (*energia[i] < 10) {
            std::cout << "Energia insuficiente para caçar!\n\n";
            continue;
        }
        *energia[i] -= 10; // Gasta energia inicial

        int evento = std::rand() % 3; // 0: monstro forte, 1: monstro fraco, 2: nenhum encontro

        if (evento == 0) // Monstro forte
        {
            std::cout << "Encontrou um monstro forte! Gasta +10 energia.\n";
            if (*energia[i] >= 10) {
                *energia[i] -= 10;
                *experiencia[i] += 20;
                std::cout << "Vitória! XP atual: " << *experiencia[i] << "\n";
            }
            else {
                std::cout << "Energia insuficiente para lutar contra o monstro forte!\n";
            }
        }
        else if (evento == 1) // Monstro fraco
        {
            std::cout << "Encontrou um monstro fraco! Gasta +5 energia.\n";
            if (*energia[i] >= 5) {
                *energia[i] -= 5;
                *experiencia[i] += 20;
                std::cout << "Vitória! XP atual: " << *experiencia[i] << "\n";
            }
            else {
                std::cout << "Energia insuficiente para lutar contra o monstro fraco!\n";
            }
        }
        else // Nenhum encontro
        {
            std::cout << "Não encontrou nenhum monstro.\n";
        }
        std::cout << "Energia restante: " << *energia[i] << "\n\n";
    }
}
static void verificarCansacoEvolucao(std::string* Nome[3], int* energia[3], int* experiencia[3])  
{  
    for (int i = 0; i < 3; i++)  
    {  
        std::cout << "Herói " << (i + 1) << " (" << *Nome[i] << "):\n";  
        if (*energia[i] < 20)  
        {  
            std::cout << "-> Está exausto! Energia: " << *energia[i] << "\n";  
        }  
        if (*experiencia[i] > 50)  
        {  
            std::cout << "-> Está forte! Experiência: " << *experiencia[i] << "\n";  
        }  
        if (*energia[i] >= 20 && *experiencia[i] <= 50)  
        {  
            std::cout << "-> Estado normal.\n";  
        }  
        std::cout << "\n";  
    }  
}
 void menuRPG()
{
    std::string nomes[3];
    int classes[3], niveis[3], energias[3], experiencias[3], ouros[3];
    std::string* pNomes[3] = { &nomes[0], &nomes[1], &nomes[2] };
    int* pClasses[3] = { &classes[0], &classes[1], &classes[2] };
    int* pNiveis[3] = { &niveis[0], &niveis[1], &niveis[2] };
    int* pEnergias[3] = { &energias[0], &energias[1], &energias[2] };
    int* pExperiencias[3] = { &experiencias[0], &experiencias[1], &experiencias[2] };
    int* pOuros[3] = { &ouros[0], &ouros[1], &ouros[2] };

    int opcao;
    do
    {
        std::cout << "===== MENU PRINCIPAL =====\n";
        std::cout << "1. Cadastrar Heróis\n";
        std::cout << "2. Ver Status\n";
        std::cout << "3. Treinar Todos\n";
        std::cout << "4. Visitar Loja\n";
        std::cout << "5. Missão de Caça\n";
        std::cout << "6. Verificar Cansaço/Evolução\n";
        std::cout << "7. Sair\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        switch (opcao)
        {
        case 1:
            cadastroDeHeroi(pNomes, pClasses, pNiveis, pEnergias, pExperiencias, pOuros);
            break;
        case 2:
            for (int i = 0; i < 3; i++)
            {
                std::cout << "Herói " << (i + 1) << " (" << nomes[i] << "):\n";
                std::cout << "Classe: " << classes[i] << "\n";
                std::cout << "Nível: " << niveis[i] << "\n";
                std::cout << "Energia: " << energias[i] << "\n";
                std::cout << "Experiência: " << experiencias[i] << "\n";
                std::cout << "Ouro: " << ouros[i] << "\n\n";
            }
            break;
        case 3:
            for (int i = 0; i < 3; i++)
            {
                energias[i] += 10;
                experiencias[i] += 10;
                std::cout << "Herói " << (i + 1) << " treinou! Energia: " << energias[i] << ", XP: " << experiencias[i] << "\n";
            }
            break;
        case 4:
            visitarLoja(pEnergias, pExperiencias, pOuros);
            break;
        case 5:
            cacaemGrupo(pNomes, pClasses, pNiveis, pEnergias, pExperiencias, pOuros);
            break;
        case 6:
            verificarCansacoEvolucao(pNomes, pEnergias, pExperiencias);
            break;
        case 7:
            std::cout << "Saindo...\n";
            break;
        default:
            std::cout << "Opção inválida!\n";
        }
        std::cout << "\n";
    } while (opcao != 7);

    return ;
}