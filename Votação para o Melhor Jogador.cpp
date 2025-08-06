#include <iostream>
#include <string>
#include "Aulas.h"

void pedidoVotos()
{
    std::string jogadores[5]{ "Ronaldo", "Messi", "Neymar", "Mbapp�", "Haaland" };
    int votos[5]{ 0 };
    int voto;

    do
    {
        std::cout << "===== VOTA��O PARA O MELHOR JOGADOR =====\n";
        std::cout << "Jogadores dispon�veis:\n";
        for (int i = 0; i < 5; i++)
        {
            std::cout << "[" << (i + 1) << "] " << jogadores[i] << "\n";
        }
        std::cout << "[0] Encerrar vota��o\n";
        std::cout << "Escolha o n�mero do jogador que voc� acha que � o melhor: ";
        std::cin >> voto;
        if (voto >= 1 && voto <= 5)
        {
            votos[voto - 1]++;
            std::cout << "Voto registrado para " << jogadores[voto - 1] << "!\n";
        }
        else if (voto == 0)
        {
            break;
        }
        else
        {
            std::cout << "Op��o inv�lida! Tente novamente.\n";
        }
    } while (true);

    // Mostrar resultado
    std::cout << "\n===== RESULTADO DA VOTA��O =====\n";
    int maisVotado = 0;
    for (int i = 0; i < 5; i++)
    {
        std::cout << jogadores[i] << ": " << votos[i] << " votos\n";
        if (votos[i] > votos[maisVotado])
            maisVotado = i;
    }
    std::cout << "\nO jogador mais votado foi: " << jogadores[maisVotado] << "!\n";
}
