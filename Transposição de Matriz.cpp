#include <iostream>
using namespace std;

void TransposicaoMatriz()
{
    const int n = 3; // Tamanho da matriz
    int matriz[n][n];
    int transposta[n][n];

    // Leitura da matriz original
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Digite o elemento [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matriz[i][j];
        }
    }

    // Criação da matriz transposta
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            transposta[j][i] = matriz[i][j];
        }
    }

    // Mostra matriz original
    cout << "\nMatriz Original:\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << matriz[i][j] << '\t';
        }
        cout << '\n';
    }

    // Mostra matriz transposta
    cout << "\nMatriz Transposta:\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << transposta[i][j] << '\t';
        }
        cout << '\n';
    }

    cout << "Transposicao realizada com sucesso!\n";
}
