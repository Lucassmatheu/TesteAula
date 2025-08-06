#include <iostream>
#include <string>
#include "Aulas.h"

void pedidoVotos()
{
    std::string jogadores[5]{ "Ronaldo", "Messi", "Neymar", "Mbappé", "Haaland" };
    int votos[5]{ 0 };
    int voto;

    do
    {
        std::cout << "===== VOTAÇÃO PARA O MELHOR JOGADOR =====\n";
        std::cout << "Jogadores disponíveis:\n";
        for (int i = 0; i < 5; i++)
        {
            std::cout << "[" << (i + 1) << "] " << jogadores[i] << "\n";
        }
        std::cout << "[0] Encerrar votação\n";
        std::cout << "Escolha o número do jogador que você acha que é o melhor: ";
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
            std::cout << "Opção inválida! Tente novamente.\n";
        }
    } while (true);

    // Mostrar resultado
    std::cout << "\n===== RESULTADO DA VOTAÇÃO =====\n";
    int maisVotado = 0;
    for (int i = 0; i < 5; i++)
    {
        std::cout << jogadores[i] << ": " << votos[i] << " votos\n";
        if (votos[i] > votos[maisVotado])
            maisVotado = i;
    }
    std::cout << "\nO jogador mais votado foi: " << jogadores[maisVotado] << "!\n";
}
