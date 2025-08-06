// Corrigindo o erro E0169: esperado uma declara��o
// O problema ocorre porque o c�digo "delete[] inventario;" est� fora de qualquer fun��o ou escopo v�lido.
// Vamos mov�-lo para dentro de uma fun��o apropriada para liberar a mem�ria corretamente.

#include <iostream>
#include <cstring>
#include "Aulas.h"
#include <string>

struct Equipamento {
    std::string nome;
    std::string tipo; // Ex: "Espada", "Escudo", "Po��o"
    int ataque;
    int defesa;
};

bool equipamentoExiste(Equipamento* inventario, int qtd, const std::string& nome) {
    for (int i = 0; i < qtd; i++) {
        if (inventario[i].nome == nome) return true;
    }
    return false;
}

static void adicionarEquipamento(Equipamento* inventario, int& qtdEquipamentos, int tamanhoInventario,
    const std::string& nome, const std::string& tipo, int ataque, int defesa) {
    if (qtdEquipamentos < tamanhoInventario && !equipamentoExiste(inventario, qtdEquipamentos, nome)) {
        inventario[qtdEquipamentos].nome = nome;
        inventario[qtdEquipamentos].tipo = tipo;
        inventario[qtdEquipamentos].ataque = ataque;
        inventario[qtdEquipamentos].defesa = defesa;
        qtdEquipamentos++;
        std::cout << "Equipamento adicionado: " << nome << "\n";
    }
    else if (equipamentoExiste(inventario, qtdEquipamentos, nome)) {
        std::cout << "J� existe um equipamento com esse nome!\n";
    }
    else {
        std::cout << "Invent�rio cheio! N�o foi poss�vel adicionar o equipamento: " << nome << "\n";
    }
}

void removerEquipamento(Equipamento* inventario, int& qtdEquipamentos, const std::string& nome) {
    for (int i = 0; i < qtdEquipamentos; i++) {
        if (inventario[i].nome == nome) {
            inventario[i] = inventario[qtdEquipamentos - 1]; // Move o �ltimo equipamento para c�
            qtdEquipamentos--;
            std::cout << "Equipamento removido: " << nome << "\n";
            return;
        }
    }
    std::cout << "Equipamento n�o encontrado no invent�rio: " << nome << "\n";
}

static void Inventarios() {
    int tamanhoInventario = 0;
    std::cout << "Qual o tamanho do invent�rio? ";
    std::cin >> tamanhoInventario;
    std::cin.ignore();

    Equipamento* inventario = new Equipamento[tamanhoInventario];
    int qtdEquipamentos = 0;
    int opcao;

    do {
        std::cout << "\n===== MENU INVENT�RIO =====\n";
        std::cout << "[1] Adicionar Equipamento\n";
        std::cout << "[2] Remover Equipamento\n";
        std::cout << "[3] Mostrar Invent�rio\n";
        std::cout << "[4] Sair\n";
        std::cout << "Escolha uma op��o: ";

        std::cin >> opcao;
        std::cin.ignore();

        switch (opcao) {
        case 1: {
            std::string nome, tipo;
            int ataque, defesa;
            std::cout << "Digite o nome do equipamento: ";
            std::getline(std::cin, nome);
            std::cout << "Digite o tipo do equipamento: ";
            std::getline(std::cin, tipo);
            std::cout << "Digite o ataque do equipamento: ";
            std::cin >> ataque;
            std::cout << "Digite a defesa do equipamento: ";
            std::cin >> defesa;
            std::cin.ignore();
            adicionarEquipamento(inventario, qtdEquipamentos, tamanhoInventario, nome, tipo, ataque, defesa);
            break;
        }
        case 2: {
            std::string nome;
            std::cout << "Digite o nome do equipamento a ser removido: ";
            std::getline(std::cin, nome);
            removerEquipamento(inventario, qtdEquipamentos, nome);
            break;
        }
        case 3:
            std::cout << "\n===== INVENT�RIO =====\n";
            if (qtdEquipamentos == 0) {
                std::cout << "Invent�rio vazio.\n";
            }
            else {
                for (int i = 0; i < qtdEquipamentos; i++) {
                    std::cout << "Equipamento " << (i + 1) << ": "
                        << inventario[i].nome << ", Tipo: "
                        << inventario[i].tipo
                        << ", Ataque: " << inventario[i].ataque
                        << ", Defesa: " << inventario[i].defesa << "\n";
                }
            }
            std::cout << "=======================\n";
            break;
        case 4:
            std::cout << "Saindo do menu de invent�rio...\n";
            break;
        default:
            std::cout << "Op��o inv�lida! Tente novamente.\n";
        }
    } while (opcao != 4);

    // Libera��o da mem�ria alocada
    delete[] inventario;
}
