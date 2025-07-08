#include <iostream>
#include "Aulas.h"

static void cadastroPersonagem(std::string& nome, std::string& classe, int& nivel, int& energia, int& experiencia)
{
    std::cout << "Digite o nome do personagem: ";
    std::cin >> nome;
    std::cout << "Digite a classe do personagem: ";
    std::cin >> classe;
    std::cout << "Digite o n�vel do personagem: ";
    std::cin >> nivel;
    std::cout << "Digite a energia do personagem: ";
    std::cin >> energia;

    if (nivel >= 1 && nivel <= 10)
    {
        std::cout << "N�vel v�lido.\n";
    }
    else
    {
        std::cout << "N�vel inv�lido. Deve ser entre 1 e 10.\n";
        return;
    }
}

static void Fun��oexplorarTerreno(int* energia, int* experiencia)
{
    int opcaoTerreno;

    do
    {
        int evento = rand() % 3 + 1;
        std::cout << "Explorando terrenos...\n";
        std::cout << "[1] Floresta\n";
        std::cout << "[2] Caverna\n";
        std::cout << "[3] Vila\n";
        std::cout << "[4] Voltar\n";
        std::cin >> opcaoTerreno;

        switch (opcaoTerreno)
        {
        case 1:
            if (evento == 1) {
                *energia -= 15;
                std::cout << "Voc� encontrou um inimigo! Perdeu 15 de energia.\n";
            }
            else if (evento == 2) {
                *experiencia += 20;
                std::cout << "Voc� encontrou um tesouro! Ganhou 20 de experi�ncia.\n";
            }
            else {
                std::cout << "Nada encontrado nessa explora��o.\n";
            }
            break;

        case 2:
            if (evento == 1) {
                *energia -= 20;
                std::cout << "Voc� encontrou um inimigo poderoso! Perdeu 20 de energia.\n";
            }
            else if (evento == 2) {
                *experiencia += 30;
                std::cout << "Voc� encontrou uma rel�quia antiga! Ganhou 30 de experi�ncia.\n";
            }
            else {
                std::cout << "Nada encontrado nessa explora��o.\n";
            }
            break;

        case 3:
            if (evento == 1) {
                *energia -= 10;
                std::cout << "Voc� encontrou um ladr�o! Perdeu 10 de energia.\n";
            }
            else if (evento == 2) {
                *experiencia += 15;
                std::cout << "Voc� ajudou um alde�o! Ganhou 15 de experi�ncia.\n";
            }
            else {
                std::cout << "Nada encontrado nessa explora��o.\n";
            }
            break;

        case 4:
            std::cout << "Voltando ao menu principal...\n";
            return;

        default:
            std::cout << "Op��o inv�lida. Tente novamente.\n";
            break;
        }

    } while (opcaoTerreno != 4);
}

static void cumprirMisssao(int* nivel, int* experiencia, int* energia)
{
    std::cout << "Cumprindo miss�es...\n";

    if (*nivel >= 5 && *experiencia >= 5)
    {
        *energia -= 10;
        *experiencia += 30;
        std::cout << "Voc� pode cumprir miss�es!\n";
        std::cout << "Miss�o cumprida! Ganhou 30 de experi�ncia e perdeu 10 de energia.\n";
    }
    else
    {
        std::cout << "Voc� n�o tem n�vel ou experi�ncia suficiente para cumprir miss�es.\n";
    }
}

static void statusPersonagem(const std::string& nome, const std::string& classe, int nivel, int energia, int experiencia)
{
    std::cout << "Status do Personagem:\n";
    std::cout << "Nome: " << nome << "\n";
    std::cout << "Classe: " << classe << "\n";
    std::cout << "N�vel: " << nivel << "\n";
    std::cout << "Energia: " << energia << "\n";
    std::cout << "Experi�ncia: " << experiencia << "\n";

    std::string resultado = (experiencia > 50) ? "FORTE" : "FRACO";
    std::cout << "Voc� � considerado: " << resultado << "\n";
}

static void MenuPrincipal(std::string& nome, std::string& classe, int& nivel, int& energia, int& experiencia)
{
    int opcaomenu;
    do
    {
        std::cout << "Bem-vindo ao Simulador de Explora��o e Miss�es!\n";
        std::cout << "Escolha uma op��o:\n";
        std::cout << "[1] Explorar Terrenos\n";
        std::cout << "[2] Cumprir Miss�o\n";
        std::cout << "[3] Ver Status\n";
        std::cout << "[4] Cadastrar Personagem\n";
        std::cout << "[5] Sair\n";
        std::cin >> opcaomenu;

        switch (opcaomenu)
        {
        case 1:
            Fun��oexplorarTerreno(&energia, &experiencia);
            break;

        case 2:
            cumprirMisssao(&nivel, &experiencia, &energia);
            break;

        case 3:
            statusPersonagem(nome, classe, nivel, energia, experiencia);
            break;

        case 4:
            cadastroPersonagem(nome, classe, nivel, energia, experiencia);
            break;

        case 5:
            std::cout << "Saindo do jogo...\n";
            return;

        default:
            std::cout << "Op��o inv�lida. Tente novamente.\n";
            break;
        }

    } while (opcaomenu != 5);
}
