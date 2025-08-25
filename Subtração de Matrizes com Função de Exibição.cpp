#include <iostream>
using namespace std;

// Função para imprimir uma matriz 3x3
void imprimeMatriz(const int M[3][3], const char* titulo)
{
    cout << "\n" << titulo << ":\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j)
            cout << M[i][j] << '\t';
        cout << '\n';
    }
}

// Leitura de uma matriz
void lerMatriz(int M[3][3], const char* nome)
{
	// para evitar a repetição de código, usamos um loop para ler os elementos  
    for (int i = 0; i < 3; ++i) {
		// para cada linha, lemos 3 elementos
        for (int j = 0; j < 3; ++j) {
            cout << "Digite o elemento [" << i + 1 << "][" << j + 1 << "] da " << nome << ": ";
            cin >> M[i][j];
        }
    }
}

// Subtração das matrizes
void subtracaoMatrizes(const int A[3][3], const int B[3][3], int resultado[3][3])
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            resultado[i][j] = A[i][j] - B[i][j];
        }
    }
}

void mostraMatrizes()
{
    int matrizA[3][3], matrizB[3][3], resultado[3][3];
    lerMatriz(matrizA, "matriz A");
    lerMatriz(matrizB, "matriz B");

    subtracaoMatrizes(matrizA, matrizB, resultado);

    imprimeMatriz(matrizA, "Matriz A");
    imprimeMatriz(matrizB, "Matriz B");
    imprimeMatriz(resultado, "Resultado da Subtração");
}
