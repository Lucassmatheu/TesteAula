#include <iostream>
using namespace std;

void MatrizDiagonal() {
    const int N = 4;                 // tamanho da matriz
    int matriz[N][N];
    int somaPrincipal = 0;
    int somaSecundaria = 0;

    // Leitura
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << "Digite o elemento [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matriz[i][j];
        }
    }

    // Mostra matriz
    cout << "\nMatriz " << N << "x" << N << ":\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << matriz[i][j] << '\t';
        }
        cout << '\n';
    }

    // Diagonal principal
    cout << "\nDiagonal principal: ";
    for (int i = 0; i < N; ++i) {
        cout << matriz[i][i] << ' ';
        somaPrincipal += matriz[i][i];
    }
    cout << "\nSoma da diagonal principal: " << somaPrincipal << '\n';

    // Diagonal secundária
    cout << "Diagonal secundaria: ";
    for (int i = 0; i < N; ++i) {
        cout << matriz[i][N - 1 - i] << ' ';
        somaSecundaria += matriz[i][N - 1 - i];
    }
    cout << "\nSoma da diagonal secundaria: " << somaSecundaria << '\n';

    // Soma total das duas diagonais (ajuste se N for ímpar)
    int somaTotal = somaPrincipal + somaSecundaria;
    if (N % 2 == 1) { // evita contar o centro duas vezes em matrizes ímpares
        somaTotal -= matriz[N / 2][N / 2];
    }
    cout << "Soma total (duas diagonais): " << somaTotal << '\n';
}
