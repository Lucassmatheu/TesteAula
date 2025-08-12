#include <iostream>
#include <string>
#include <algorithm> // para std::count

void PalavraSecreta(std::string palavras[5])
{
    bool acertou[5]{ false };
    std::string tentativa;
    int acertos = 0;

    // Cadastro das palavras secretas
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Digite a palavra secreta " << (i + 1) << ": ";
        std::cin >> palavras[i];
    }

    do
    {
        std::cout << "===== JOGO DE PALAVRAS SECRETAS =====\n";
        std::cout << "Tente adivinhar as 5 palavras secretas!\n";
        std::cout << "Digite '0' para sair.\n";
        std::cout << "Digite sua tentativa: ";
        std::cin >> tentativa;

		// verifica se o jogador quer sair
        if (tentativa == "0")
        {
            std::cout << "Voc� escolheu sair do jogo.\n";
            break;
        }

        bool encontrou = false;
        for (int i = 0; i < 5; i++)
        {
			// Verifica se a palavra j� foi acertada
            if (tentativa == palavras[i] && !acertou[i])
            {
				// se a palavra for correta e n�o tiver sido acertada antes
                acertou[i] = true;
				// incrementa o contador de acertos
                acertos++;
                std::cout << "Parab�ns! Voc� acertou a palavra " << (i + 1) << "!\n";
				// Marca que a palavra foi encontrada
                encontrou = true;
                break; // Se n�o quiser marcar duas vezes no mesmo chute
            }
        }
        if (!encontrou)
        {
            std::cout << "Palavra incorreta ou j� acertada. Tente novamente!\n";
        }

        std::cout << "Voc� j� acertou " << acertos << " de 5 palavras.\n\n";

    } while (acertos < 5);

    if (acertos == 5)
        std::cout << "Parab�ns, voc� acertou todas as palavras!\n";
}
