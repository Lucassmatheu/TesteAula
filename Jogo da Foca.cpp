#include <iostream>
#include <cstring>
#include "Aulas.h"

static void CadastraRPalavra(char* palavra, int& tamanho)
{
    std::cout << "Digite a palavra para adivinhar: ";
    std::cin >> palavra;

    tamanho = strlen(palavra);
    std::cout << "A palavra tem " << tamanho << " letras.\n";

    // Mostrando a palavra letra a letra para conferência
    std::cout << "Palavra cadastrada: ";
    for (int i = 0; i < tamanho; i++)
    {
        std::cout << palavra[i] << " ";
    }
    std::cout << "\n";
}

static void mostrarEstado(char* palavra, char* progresso, int tamanho)
{
    std::cout << "Palavra: ";
    for (int i = 0; i < tamanho; i++)
    {
        std::cout << palavra[i] << " ";
    }
    std::cout << "\nProgresso: ";
    for (int i = 0; i < tamanho; i++)
    {
        std::cout << progresso[i] << " ";
    }
    std::cout << "\n";
}

static bool tentarLetra(char letra, char* palavra, char* progresso, int tamanho)
{
    std::cout << "Tentando a letra: " << letra << "\n";
    bool acertou = false;
    for (int i = 0; i < tamanho; i++)
    {
        if (palavra[i] == letra)
        {
            progresso[i] = letra;
            acertou = true;
        }
    }
    return acertou;
}

static bool venceu(char* progresso, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (progresso[i] == '_')
        {
            return false;
        }
    }
    return true;
}

void jogar()
{
    char palavra[100]{};
    int tamanho{};
    CadastraRPalavra(palavra, tamanho);

    char progresso[100]{};
    for (int i = 0; i < tamanho; i++)
    {
        progresso[i] = '_';
    }

    while (true)
    {
        mostrarEstado(palavra, progresso, tamanho);

        char entrada[100];
        std::cout << "Digite UMA letra: ";
        std::cin >> entrada;

        // Validar se digitou mais de 1 letra
        if (strlen(entrada) != 1)
        {
            std::cout << "Por favor, digite apenas UMA letra!\n";
            continue;
        }

        char letra = entrada[0];

        if (tentarLetra(letra, palavra, progresso, tamanho))
        {
            std::cout << "Você acertou a letra!\n";
        }
        else
        {
            std::cout << "Letra não encontrada.\n";
        }

        if (venceu(progresso, tamanho))
        {
            std::cout << "Parabéns! Você venceu!\n";
            break;
        }
    }
}
