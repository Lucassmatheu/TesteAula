#include <iostream>
#include "Aulas.h"

// Declaração da função resultadoRound
int resultadoRound(int ataque, int defesa);

void ataque() {
    int ataquesJogador[5];
    int defesasInimigo[5];
    int totalVitorias = 0;
    int totalEmpates = 0;
    int totalDerrotas = 0;

    std::cout << "Digite 5 valores para os ataques do jogador:\n";
    for (int i = 0; i < 5; i++) {
        std::cout << "Ataque " << i + 1 << ": ";
        std::cin >> ataquesJogador[i];
    }

    std::cout << "Digite 5 valores para as defesas do inimigo:\n";
    for (int i = 0; i < 5; i++) {
        std::cout << "Defesa " << i + 1 << ": ";
        std::cin >> defesasInimigo[i];
    }

    std::cout << "\nValores digitados:\nAtaques do Jogador: ";
    for (int i = 0; i < 5; i++) {
        std::cout << ataquesJogador[i] << " ";
    }
    std::cout << "\nDefesas do Inimigo: ";
    for (int i = 0; i < 5; i++) {
        std::cout << defesasInimigo[i] << " ";
    }
    std::cout << std::endl;

    // Processar os resultados dos rounds
    for (int i = 0; i < 5; i++) {
        int ataqueAtual = ataquesJogador[i];
        // Switch para o round 3 (índice 2)
        switch (i) {
        case 2: {
            char resposta;
            std::cout << "Round 3! Deseja ativar Bônus de Ataque (+10)? (s/n): ";
            std::cin >> resposta;
            if (resposta == 's' || resposta == 'S') {
                ataqueAtual += 10;
                std::cout << "Bônus ativado! Ataque agora: " << ataqueAtual << std::endl;
            }
            break;
        }
        default:
            break;
        }

        std::cout << "Resultado do round " << (i + 1) << ": ";
        int resultado = resultadoRound(ataqueAtual, defesasInimigo[i]);
        if (resultado == 1) {
            std::cout << "Vitória do Jogador!\n";
            totalVitorias++;
        }
        else if (resultado == 0) {
            std::cout << "Empate!\n";
            totalEmpates++;
        }
        else {
            std::cout << "Vitória do Inimigo!\n";
            totalDerrotas++;
        }
    }

    std::cout << "\nTotal de vitórias do jogador: " << totalVitorias << std::endl;
    std::cout << "Total de empates: " << totalEmpates << std::endl;
    std::cout << "Total de derrotas: " << totalDerrotas << std::endl;

    std::string status = (totalVitorias >= 3) ? "CAMPEÃO" : "DERROTADO";
    std::cout << "Classificação do jogador: " << status << std::endl;
}

int resultadoRound(int ataque, int defesa) {
    if (ataque > defesa)
        return 1;
    else if (ataque == defesa)
        return 0;
    else
        return -1;
}
