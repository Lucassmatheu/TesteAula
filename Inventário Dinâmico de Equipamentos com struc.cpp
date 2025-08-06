// Corrigindo o erro E0169: esperado uma declaração
// O problema ocorre porque o código "delete[] inventario;" está fora de qualquer função ou escopo válido.
// Vamos movê-lo para dentro de uma função apropriada para liberar a memória corretamente.

#include <iostream>
#include <cstring>
#include "Aulas.h"
#include <string>

struct Equipamento {
    std::string nome;
    std::string tipo; // Ex: "Espada", "Escudo", "Poção"
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
        std::cout << "Já existe um equipamento com esse nome!\n";
    }
    else {
        std::cout << "Inventário cheio! Não foi possível adicionar o equipamento: " << nome << "\n";
    }
}

void removerEquipamento(Equipamento* inventario, int& qtdEquipamentos, const std::string& nome) {
    for (int i = 0; i < qtdEquipamentos; i++) {
        if (inventario[i].nome == nome) {
            inventario[i] = inventario[qtdEquipamentos - 1]; // Move o último equipamento para cá
            qtdEquipamentos--;
            std::cout << "Equipamento removido: " << nome << "\n";
            return;
        }
    }
    std::cout << "Equipamento não encontrado no inventário: " << nome << "\n";
}

static void Inventarios() {
    int tamanhoInventario = 0;
    std::cout << "Qual o tamanho do inventário? ";
    std::cin >> tamanhoInventario;
    std::cin.ignore();

    Equipamento* inventario = new Equipamento[tamanhoInventario];
    int qtdEquipamentos = 0;
    int opcao;

    do {
        std::cout << "\n===== MENU INVENTÁRIO =====\n";
        std::cout << "[1] Adicionar Equipamento\n";
        std::cout << "[2] Remover Equipamento\n";
        std::cout << "[3] Mostrar Inventário\n";
        std::cout << "[4] Sair\n";
        std::cout << "Escolha uma opção: ";

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
            std::cout << "\n===== INVENTÁRIO =====\n";
            if (qtdEquipamentos == 0) {
                std::cout << "Inventário vazio.\n";
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
            std::cout << "Saindo do menu de inventário...\n";
            break;
        default:
            std::cout << "Opção inválida! Tente novamente.\n";
        }
    } while (opcao != 4);

    // Liberação da memória alocada
    delete[] inventario;
}
