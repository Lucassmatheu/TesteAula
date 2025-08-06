#include <iostream>
#include <cstring>
#include "Aulas.h"
#include <string>
struct Equipamento {
    std::string nome;
    std::string tipo;
    int ataque = 0; // Inicializa��o padr�o
    int defesa = 0; // Inicializa��o padr�o
};
struct Jogador {
    std::string nome;
    Equipamento* inventario;
    int tamanhoInventario;
    int qtdEquipamentos;
};

static bool equipamentoExiste(Equipamento* inventario, int qtd, const std::string& nome) {
    for (int i = 0; i < qtd; i++) {
        if (inventario[i].nome == nome) return true;
    }
    return false;
}
static void adicionarEquipamento(Jogador* jogadores, int& nJogadores, int& tamanhoInventario, int& qtdEquipamento, const std::string& nome) {
    if (qtdEquipamento < nJogadores && !equipamentoExiste(jogadores[qtdEquipamento].inventario, jogadores[qtdEquipamento].qtdEquipamentos, nome)) {
        jogadores[qtdEquipamento].nome = nome;
        jogadores[qtdEquipamento].inventario = new Equipamento[tamanhoInventario];
        jogadores[qtdEquipamento].tamanhoInventario = tamanhoInventario;
        jogadores[qtdEquipamento].qtdEquipamentos = 0;
        qtdEquipamento++;
        std::cout << "Jogador adicionado: " << nome << "\n";
    } else if (equipamentoExiste(jogadores[qtdEquipamento].inventario, jogadores[qtdEquipamento].qtdEquipamentos, nome)) {
        std::cout << "J� existe um jogador com esse nome!\n";
    } else {
        std::cout << "Invent�rio cheio! N�o foi poss�vel adicionar o jogador: " << nome << "\n";
    }
}
void RemoverItens(Jogador* jogadores, int& qtdEquipamentos, const std::string& nome) 
{
    for (int i = 0; i < qtdEquipamentos; i++) {
        if (jogadores[i].nome == nome) {
            delete[] jogadores[i].inventario; // Libera a mem�ria do invent�rio
            jogadores[i] = jogadores[qtdEquipamentos - 1]; // Move o �ltimo jogador para c�
            qtdEquipamentos--;
            std::cout << "Jogador removido: " << nome << "\n";
            return;
        }
    }
	std::cout << "Jogador n�o encontrado no invent�rio: " << nome << "\n";
}
void mostrarInventario(Jogador* jogadores, int nJogadores) {
    std::cout << "\n===== INVENT�RIO =====\n";
    if (nJogadores == 0) {
        std::cout << "Invent�rio vazio.\n";
        return;
    }
    for (int i = 0; i < nJogadores; i++) {
        std::cout << "Jogador " << (i + 1) << ": " << jogadores[i].nome << "\n";
        std::cout << "Equipamentos:\n";
        for (int j = 0; j < jogadores[i].qtdEquipamentos; j++) {
            std::cout << " - " << jogadores[i].inventario[j].nome 
                      << ", Tipo: " << jogadores[i].inventario[j].tipo 
                      << ", Ataque: " << jogadores[i].inventario[j].ataque 
                      << ", Defesa: " << jogadores[i].inventario[j].defesa << "\n";
        }
    }
    std::cout << "=======================\n";
}
void NomeJogador(Jogador* jogadores, int& nJogadores, int& tamanhoInventario, int& qtdEquipamento)
{
    std::cout << "Qual e o tamanho do inventario";
    std::cin >> nJogadores;

    int opcao;
    do 
    {
        std::cout << "\n===== MENU INVENT�RIO =====\n";
        std::cout << "[1] Adicionar Jogador\n";
        std::cout << "[2] Remover Jogador\n";
        std::cout << "[3] Mostrar Invent�rio\n";
        std::cout << "[4] Sair\n";
        std::cout << "Escolha uma op��o: ";
        std::cin >> opcao;
        std::cin.ignore(); // Limpa o buffer de entrada
        switch (opcao) {
            case 1: {
                std::string nome;
                std::cout << "Digite o nome do jogador a ser adicionado: ";
                std::getline(std::cin, nome);
                adicionarEquipamento(jogadores, nJogadores, tamanhoInventario, qtdEquipamento, nome);
                break;
            }
            case 2: {
                std::string nome;
                std::cout << "Digite o nome do jogador a ser removido: ";
                std::getline(std::cin, nome);
                RemoverItens(jogadores, qtdEquipamento, nome);
                break;
            }
            case 3:
                mostrarInventario(jogadores, nJogadores);
                break;
            case 4:
                std::cout << "Saindo do menu de invent�rio...\n";
                break;
            default:
                std::cout << "Op��o inv�lida! Tente novamente.\n";
        }
        
    } while (opcao != 4);

    for (int i = 0; i < nJogadores; i++)
        delete[] jogadores[i].inventario;

    return;
}