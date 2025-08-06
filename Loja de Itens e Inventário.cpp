#include <iostream>
#include <string>

void LojaInventariong(std::string inventario[], int tamanho, int& ouro) {
    std::string ItensLoja[5]{ "Po��o", "Espada", "Armadura", "Anel", "" };
    int Preco[5]{ 10, 25, 30, 40, 50 };
    int op�aoLoja;

    do {
        std::cout << "===== LOJA DE ITENS =====\n";
        std::cout << "Ouro dispon�vel: " << ouro << "\n";
        std::cout << "[1] Po��o - 10 ouro\n[2] Espada - 25 ouro\n[3] Armadura - 30 ouro\n[4] Anel - 40 ouro\n[5] Sair\n";
        std::cout << "Escolha uma op��o: ";
        std::cin >> op�aoLoja;

        switch (op�aoLoja) {
        case 1:
        case 2:
        case 3:
        case 4: {
            int index = op�aoLoja - 1;
            if (ouro >= Preco[index]) {
                inventario[index] = ItensLoja[index];
                ouro -= Preco[index];
                std::cout << "Voc� comprou: " << ItensLoja[index] << "\n";
            }
            else {
                std::cout << "Ouro insuficiente!\n";
            }
            break;
        }
        case 5:
            std::cout << "Saindo da loja...\n";
            break;
        default:
            std::cout << "Op��o inv�lida! Tente novamente.\n";
        }
    } while (op�aoLoja != 5);
}

static void mostrarInventario(const std::string* inventario, int tamanho) {
    std::cout << "\n===== INVENT�RIO =====\n";
    for (int i = 0; i < tamanho; i++) {
        if (!inventario[i].empty()) {
            std::cout << "[" << (i + 1) << "] " << inventario[i] << "\n";
        }
    }
    std::cout << "=======================\n";
}

void MenuLOJAiNVENTARIO() {
    std::string inventario[5]{ "" };
    int tamanhoInventario = sizeof(inventario) / sizeof(inventario[0]);
    int ouro = 100;

    LojaInventariong(inventario, tamanhoInventario, ouro);
    mostrarInventario(inventario, tamanhoInventario);
}
