#include <iostream>
#include <string>

// Definição de variáveis globais para corrigir os erros
const int tamanhoInventario = 10; // Tamanho máximo do inventário
std::string inventario[tamanhoInventario]; // Array para armazenar os itens do inventário
int itensNoInventario = 0; 

// Funções existentes
static void adicionarItem(std::string* inventario, int tamanho, const std::string& item, int& itensNoInventario)
{
    if (itensNoInventario < tamanho)
    {
        inventario[itensNoInventario] = item;
        itensNoInventario++;
        std::cout << "Item adicionado: " << item << "\n";
    }
    else
    {
        std::cout << "Inventário cheio! Não foi possível adicionar o item: " << item << "\n";
    }
}

static void removerItem(std::string* inventario, int tamanho, const std::string& item, int& itensNoInventario)
{
    for (int i = 0; i < itensNoInventario; i++)
    {
        if (inventario[i] == item)
        {
            inventario[i] = inventario[itensNoInventario - 1]; // Move o último item para a posição do item removido
            inventario[itensNoInventario - 1].clear(); // Limpa o último item
            itensNoInventario--;
            std::cout << "Item removido: " << item << "\n";
            return;
        }
    }
    std::cout << "Item não encontrado no inventário: " << item << "\n";
}

static void mostrarInventario(const std::string* inventario, int tamanho, int itensNoInventario)
{
    std::cout << "\n===== INVENTÁRIO =====\n";
    if (itensNoInventario == 0)
    {
        std::cout << "Inventário vazio.\n";
        return;
    }
    for (int i = 0; i < itensNoInventario; i++)
    {
        std::cout << "[" << (i + 1) << "] " << inventario[i] << "\n";
    }
    std::cout << "=======================\n";
}

static void mostrarInventario()
{
    int opcao;
    do
    {
        std::cout << "===== MENU INVENTÁRIO =====\n";
        std::cout << "[1] Adicionar Item\n";
        std::cout << "[2] Remover Item\n";
        std::cout << "[3] Mostrar Inventário\n";
        std::cout << "[4] Sair\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;
        switch (opcao)
        {
            case 1: {
                std::string item;
                std::cout << "Digite o nome do item a ser adicionado: ";
                std::cin >> item;
                    adicionarItem(inventario, tamanhoInventario, item, itensNoInventario);
                break;
            }
            case 2: {
                std::string item;
                std::cout << "Digite o nome do item a ser removido: ";
                std::cin >> item;
                removerItem(inventario, tamanhoInventario, item, itensNoInventario);
                break;
            }
            case 3:
                mostrarInventario(inventario, tamanhoInventario, itensNoInventario);
                break;
            case 4:
                std::cout << "Saindo do menu...\n";
                break;
            default:
                std::cout << "Opção inválida! Tente novamente.\n";
        }
    } while (opcao != 4);
}

