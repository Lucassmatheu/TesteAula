#include <string>
#include <iostream>
#include "Aulas.h"
void desbloqueaHabilidade(std::string habilidadesDisponiveis[5], bool habilidadesAprendidas[5])
{
    // Corrigido: Inicializa��o do array deve ser feita separadamente
    std::string habilidadesTemp[5] = { "Fogo", "Gelo", "Rel�mpago", "Cura", "Barreira" };
    for (int i = 0; i < 5; i++) {
        habilidadesDisponiveis[i] = habilidadesTemp[i];
    }

    // Corrigido: Inicializa��o do array de habilidades aprendidas
    for (int i = 0; i < 5; i++) {
        habilidadesAprendidas[i] = false;
    }

    int ouro = 100;
    habilidadesAprendidas[0] = true;
    int opcao;
    do 
    {
        std::cout << "===== LOJA DE HABILIDADES =====\n";
        std::cout << "Ouro dispon�vel: " << ouro << "\n";
        std::cout << "Habilidades dispon�veis:\n";
        std::cout << "[1] Fogo - j� desbloqueada\n";
        std::cout << "[2] Gelo - 25 ouro\n";    
        std::cout << "[3] Rel�mpago - 40 ouro\n";
        std::cout << "[4] Cura - 20 ouro\n";
        std::cout << "[5] Barreira - 35 ouro\n";
        std::cout << "[6] Sair\n";
        std::cout << "Escolha uma op��o: ";
        std::cin >> opcao; // Adicionado para capturar a entrada do usu�rio
        switch (opcao)
        {
        case 1:
            std::cout << "Habilidade j� desbloqueada: " << habilidadesDisponiveis[0] << "\n";
            break;
        case 2:
            if (!habilidadesAprendidas[0]) {
                std::cout << "Voc� precisa desbloquear Fogo antes!\n";
            }
            else if (habilidadesAprendidas[1]) {
                std::cout << "Gelo j� desbloqueada!\n";
            }
            else if (ouro >= 25) {
                habilidadesAprendidas[1] = true;
                ouro -= 25;
                std::cout << "Voc� desbloqueou Gelo!\n";
            }
            else {
                std::cout << "Ouro insuficiente!\n";
            }
            break;
        case 3:
            if (!habilidadesAprendidas[1]) {
                std::cout << "Voc� precisa desbloquear Gelo antes!\n";
            }
            else if (habilidadesAprendidas[2]) {
                std::cout << "Rel�mpago j� desbloqueada!\n";
            }
            else if (ouro >= 40) {
                habilidadesAprendidas[2] = true;
                ouro -= 40;
                std::cout << "Voc� desbloqueou Rel�mpago!\n";
            }
            else {
                std::cout << "Ouro insuficiente!\n";
            }
            break;
        case 4:
            if (!habilidadesAprendidas[2]) {
                std::cout << "Voc� precisa desbloquear Rel�mpago antes!\n";
            }
            else if (habilidadesAprendidas[3]) {
                std::cout << "Cura j� desbloqueada!\n";
            }
            else if (ouro >= 20) {
                habilidadesAprendidas[3] = true;
                ouro -= 20;
                std::cout << "Voc� desbloqueou Cura!\n";
            }
            else {
                std::cout << "Ouro insuficiente!\n";
            }
            break;
        case 5:
            if (!habilidadesAprendidas[3]) {
                std::cout << "Voc� precisa desbloquear Cura antes!\n";
            }
            else if (habilidadesAprendidas[4]) {
                std::cout << "Barreira j� desbloqueada!\n";
            }
            else if (ouro >= 35) {
                habilidadesAprendidas[4] = true;
                ouro -= 35;
                std::cout << "Voc� desbloqueou Barreira!\n";
            }
            else {
                std::cout << "Ouro insuficiente!\n";
            }
            break;
        case 6:
            std::cout << "Saindo...\n";
            break;
        default:
            std::cout << "Op��o inv�lida!\n";
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
            std::cout << "[" << (i + 1) << "] " << habilidadesDisponiveis[i] << " - N�o desbloqueada\n";
        }
    }
    std::cout << "=======================\n";
}