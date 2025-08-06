#include <iostream>
#include <string>

// Função para checar se o item já existe
bool itemJaExiste(std::string* inventario, int qtd, const std::string& item) {
    for (int i = 0; i < qtd; i++) {
        if (inventario[i] == item) return true;
    }
    return false;
}

void InventarioDinamico() {
    int tamanho = 0;
    std::cout << "Qual será o tamanho do inventário: ";
    std::cin >> tamanho;
    std::cin.ignore();

    std::string* inventario = new std::string[tamanho];
    int itensNoInventario = 0;
    int opcao;

    do {
        std::cout << "\n===== MENU INVENTÁRIO =====\n";
        std::cout << "[1] Adicionar Item\n";
        std::cout << "[2] Remover Item\n";
        std::cout << "[3] Mostrar Inventário\n";
        std::cout << "[4] Sair\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;
        std::cin.ignore();

        switch (opcao) {
        case 1: {
            std::string item;
            std::cout << "Digite o nome do item a ser adicionado: ";
            std::getline(std::cin, item);

            if (itensNoInventario < tamanho && !itemJaExiste(inventario, itensNoInventario, item)) {
                inventario[itensNoInventario] = item;
                itensNoInventario++;
                std::cout << "Item adicionado: " << item << "\n";
            }
            else if (itemJaExiste(inventario, itensNoInventario, item)) {
                std::cout << "O item já existe no inventário!\n";
            }
            else {
                std::cout << "Inventário cheio! Não foi possível adicionar o item: " << item << "\n";
            }
            break;
        }
        case 2: {
            std::string item;
            std::cout << "Digite o nome do item a ser removido: ";
            std::getline(std::cin, item);

            bool itemRemovido = false;
            for (int i = 0; i < itensNoInventario; i++) {
                if (inventario[i] == item) {
                    inventario[i] = inventario[itensNoInventario - 1]; // Move o último item para a posição do item removido
                    itensNoInventario--;
                    itemRemovido = true;
                    std::cout << "Item removido: " << item << "\n";
                    break;
                }
            }

            if (!itemRemovido) {
                std::cout << "Item não encontrado no inventário.\n";
            }
            break;
        }
        case 3: {
            std::cout << "\n===== INVENTÁRIO =====\n";
            if (itensNoInventario == 0) {
                std::cout << "Inventário vazio.\n";
            }
            else {
                for (int i = 0; i < itensNoInventario; i++) {
                    std::cout << "[" << (i + 1) << "] " << inventario[i] << "\n";
                }
            }
            std::cout << "=======================\n";
            break;
        }
        case 4:
            std::cout << "Saindo do inventário...\n";
            break;
        default:
            std::cout << "Opção inválida! Tente novamente.\n";
            break;
        }
    } while (opcao != 4);

    delete[] inventario;
}


