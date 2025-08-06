#include<iostream>
#include "Aulas.h"

void atualizarStatus(int* energia, int* experiencia) {
    int deltaEnergia, deltaExperiencia;
    std::cout << "Informe a variação de energia (pode ser negativo): ";
    std::cin >> deltaEnergia;
    std::cout << "Informe a variação de experiência (pode ser negativo): ";
    std::cin >> deltaExperiencia;
    *energia += deltaEnergia;
    *experiencia += deltaExperiencia;
}

int personagemMaisForte(int* energia, int* experiencia, int tamanho) {
    int maior = energia[0] + experiencia[0];
    int indice = 0;
    for (int i = 1; i < tamanho; i++) {
        int soma = energia[i] + experiencia[i];
        if (soma > maior) {
            maior = soma;
            indice = i;
        }
    }
    return indice;
}

void energiaEsperiencia(int* energia[5], int* experiencia[5])
{
    int rodadas;
    std::cout << "Quantas rodadas deseja jogar? ";
    std::cin >> rodadas;

    for (int r = 0; r < rodadas; r++) {
        int idx;
        std::cout << "\nRodada " << r+1 << ": Escolha o personagem (0 a 4): ";
        std::cin >> idx;
        if (idx < 0 || idx > 4) {
            std::cout << "Índice inválido!\n";
            continue;
        }
        atualizarStatus(energia[idx], experiencia[idx]);
    }

    int maisForte = personagemMaisForte(*energia, *experiencia, 5);
    std::cout << "\nO personagem mais forte é o de índice " << maisForte
              << " (Energia: " << *energia[maisForte]
              << ", Experiência: " << *experiencia[maisForte] << ")\n";
}

void n() {
    int energia[5] = {0};
    int experiencia[5] = {0};
    int* pEnergia[5];
    int* pExperiencia[5];
    for (int i = 0; i < 5; i++) {
        pEnergia[i] = &energia[i];
        pExperiencia[i] = &experiencia[i];
    }
    energiaEsperiencia(pEnergia, pExperiencia);
    return;
}