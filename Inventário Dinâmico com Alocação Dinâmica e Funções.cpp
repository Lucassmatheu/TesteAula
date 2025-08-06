#include <iostream>
#include <string>

// Fun��o para checar se o item j� existe
bool itemJaExiste(std::string* inventario, int qtd, const std::string& item) {
    for (int i = 0; i < qtd; i++) {
        if (inventario[i] == item) return true;
    }
    return false;
}

void InventarioDinamico() {
    int tamanho = 0;
    std::cout << "Qual ser� o tamanho do invent�rio: ";
    std::cin >> tamanho;
    std::cin.ignore();

    std::string* inventario = new std::string[tamanho];
    int itensNoInventario = 0;
    int opcao;

    do {
        std::cout << "\n===== MENU INVENT�RIO =====\n";
        std::cout << "[1] Adicionar Item\n";
        std::cout << "[2] Remover Item\n";
        std::cout << "[3] Mostrar Invent�rio\n";
        std::cout << "[4] Sair\n";
        std::cout << "Escolha uma op��o: ";
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
                std::cout << "O item j� existe no invent�rio!\n";
            }
            else {
                std::cout << "Invent�rio cheio! N�o foi poss�vel adicionar o item: " << item << "\n";
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
                    inventario[i] = inventario[itensNoInventario - 1]; // Move o �ltimo item para a posi��o do item removido
                    itensNoInventario--;
                    itemRemovido = true;
                    std::cout << "Item removido: " << item << "\n";
                    break;
                }
            }

            if (!itemRemovido) {
                std::cout << "Item n�o encontrado no invent�rio.\n";
            }
            break;
        }
        case 3: {
            std::cout << "\n===== INVENT�RIO =====\n";
            if (itensNoInventario == 0) {
                std::cout << "Invent�rio vazio.\n";
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
            std::cout << "Saindo do invent�rio...\n";
            break;
        default:
            std::cout << "Op��o inv�lida! Tente novamente.\n";
            break;
        }
    } while (opcao != 4);

    delete[] inventario;
}


