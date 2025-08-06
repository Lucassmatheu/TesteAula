#include<iostream>
#include "Aulas.h"

void ControleNotas(float* Notas, int tamanho) // Corrigido o parâmetro "tamnaho" para "tamanho"
{
    for (int i = 0; i < tamanho; i++) // Usando o parâmetro "tamanho" corretamente
    {
        std::cout << "Informe a nota do aluno " << (i + 1) << ": ";
        std::cin >> Notas[i];
    }
}

void MostrarNotas(float* Notas, int tamanho) // Corrigido o parâmetro "tamnaho" para "tamanho"
{
    std::cout << "\nNotas dos alunos:\n";
    for (int i = 0; i < tamanho; i++) // Usando o parâmetro "tamanho" corretamente
    {
        std::cout << "Aluno " << (i + 1) << ": " << Notas[i] << "\n";
    }
}

void mostrarmenornota(float* Notas, int tamanho)
{
    float menor = *Notas;
    for (int i = 1; i < tamanho; i++)
    {
        if (*(Notas + i) < menor)
        {
            menor = *(Notas + i);
        }
    }
    std::cout << "A menor nota é: " << menor << "\n";
}

void mostrarmediadasnotas(float* Notas, int tamanho)
{
    float soma = 0.0f;
    for (int i = 0; i < tamanho; i++)
    {
        soma += *(Notas + i);
    }
    float media = soma / tamanho;
    std::cout << "A média das notas é: " << media << "\n";
}

void mostrarMaiorNota(float* Notas, int tamanho) 
{
    float maior = *Notas;
    for (int i = 1; i < tamanho; i++)
    {
        if (*(Notas + i) > maior)
        {
            maior = *(Notas + i);
        }
    }
    std::cout << "A maior nota é: " << maior << "\n";
}

void mostrarNotasAcimaMedia(float* Notas, int tamanho, float media) // Adicionada a função para evitar erro de chamada
{
    std::cout << "Notas acima da média (" << media << "):\n";
    for (int i = 0; i < tamanho; i++)
    {
        if (*(Notas + i) > media)
        {
            std::cout << "Aluno " << (i + 1) << ": " << *(Notas + i) << "\n";
        }
    }
}

void Media()
{
    float notas[10];
    ControleNotas(notas, 10);

    MostrarNotas(notas, 10);

    mostrarmediadasnotas(notas, 10);

    mostrarmenornota(notas, 10);
    mostrarMaiorNota(notas, 10);
    mostrarNotasAcimaMedia(notas, 10, 0.0f); // Passando 0.0f como valor inicial para evitar erro
}