#include <string>
#include <iostream>
#include "Aulas.h"
void desbloqueaHabilidade(std::string habilidadesDisponiveis[5], bool habilidadesAprendidas[5])
{
    // Corrigido: Inicialização do array deve ser feita separadamente
    std::string habilidadesTemp[5] = { "Fogo", "Gelo", "Relâmpago", "Cura", "Barreira" };
    for (int i = 0; i < 5; i++) {
        habilidadesDisponiveis[i] = habilidadesTemp[i];
    }

    // Corrigido: Inicialização do array de habilidades aprendidas
    for (int i = 0; i < 5; i++) {
        habilidadesAprendidas[i] = false;
    }

    int ouro = 100;
    habilidadesAprendidas[0] = true;
    int opcao;
    do 
    {
        std::cout << "===== LOJA DE HABILIDADES =====\n";
        std::cout << "Ouro disponível: " << ouro << "\n";
        std::cout << "Habilidades disponíveis:\n";
        std::cout << "[1] Fogo - já desbloqueada\n";
        std::cout << "[2] Gelo - 25 ouro\n";    
        std::cout << "[3] Relâmpago - 40 ouro\n";
        std::cout << "[4] Cura - 20 ouro\n";
        std::cout << "[5] Barreira - 35 ouro\n";
        std::cout << "[6] Sair\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao; // Adicionado para capturar a entrada do usuário
        switch (opcao)
        {
        case 1:
            std::cout << "Habilidade já desbloqueada: " << habilidadesDisponiveis[0] << "\n";
            break;
        case 2:
            if (!habilidadesAprendidas[0]) {
                std::cout << "Você precisa desbloquear Fogo antes!\n";
            }
            else if (habilidadesAprendidas[1]) {
                std::cout << "Gelo já desbloqueada!\n";
            }
            else if (ouro >= 25) {
                habilidadesAprendidas[1] = true;
                ouro -= 25;
                std::cout << "Você desbloqueou Gelo!\n";
            }
            else {
                std::cout << "Ouro insuficiente!\n";
            }
            break;
        case 3:
            if (!habilidadesAprendidas[1]) {
                std::cout << "Você precisa desbloquear Gelo antes!\n";
            }
            else if (habilidadesAprendidas[2]) {
                std::cout << "Relâmpago já desbloqueada!\n";
            }
            else if (ouro >= 40) {
                habilidadesAprendidas[2] = true;
                ouro -= 40;
                std::cout << "Você desbloqueou Relâmpago!\n";
            }
            else {
                std::cout << "Ouro insuficiente!\n";
            }
            break;
        case 4:
            if (!habilidadesAprendidas[2]) {
                std::cout << "Você precisa desbloquear Relâmpago antes!\n";
            }
            else if (habilidadesAprendidas[3]) {
                std::cout << "Cura já desbloqueada!\n";
            }
            else if (ouro >= 20) {
                habilidadesAprendidas[3] = true;
                ouro -= 20;
                std::cout << "Você desbloqueou Cura!\n";
            }
            else {
                std::cout << "Ouro insuficiente!\n";
            }
            break;
        case 5:
            if (!habilidadesAprendidas[3]) {
                std::cout << "Você precisa desbloquear Cura antes!\n";
            }
            else if (habilidadesAprendidas[4]) {
                std::cout << "Barreira já desbloqueada!\n";
            }
            else if (ouro >= 35) {
                habilidadesAprendidas[4] = true;
                ouro -= 35;
                std::cout << "Você desbloqueou Barreira!\n";
            }
            else {
                std::cout << "Ouro insuficiente!\n";
            }
            break;
        case 6:
            std::cout << "Saindo...\n";
            break;
        default:
            std::cout << "Opção inválida!\n";
            break;
        }

    } while (opcao != 6);
}
void mostrarHabilidades(const std::string* habilidadesDisponiveis, const bool* habilidadesAprendidas, int tamanho) {
    std::cout << "\n===== HABILIDADES =====\n";
    for (int i = 0; i < tamanho; i++) {
        if (habilidadesAprendidas[i]) {
            std::cout << "[" << (i + 1) << "] " << habilidadesDisponiveis[i] << " - Desbloqueada\n";
        } else {
            std::cout << "[" << (i + 1) << "] " << habilidadesDisponiveis[i] << " - Não desbloqueada\n";
        }
    }
    std::cout << "=======================\n";
}