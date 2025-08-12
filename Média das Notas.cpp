#include <iostream>	
#include <iomanip>
#include "Aulas.h"
using namespace std;

void Media(float* notas, std::string* nome)
{
    float soma = 0.0;
    std::cout << "===== C�LCULO DA M�DIA DAS NOTAS =====\n";
    int qtdalunos;
    std::cout << "Digite a quantidade de alunos: ";
    std::cin >> qtdalunos;

	// Verifica se a quantidade de alunos � v�lida
    for (int i = 0; i < qtdalunos; i++) {
        std::cout << "Digite o nome do aluno " << (i + 1) << ": ";
        std::cin >> nome[i];// Verifica se o nome do aluno � v�lido

		
        std::cout << "Digite a nota do aluno " << nome[i] << ": ";
		std::cin >> notas[i];// Verifica se a nota do aluno � v�lida
        
		// soma as notas dos alunos 
		soma += notas[i];
    }

    float maior = notas[0];
    float menor = notas[0];
	// verifica se a nota � maior ou menor que as demais
    for (int i = 1; i < qtdalunos; i++) {
		// Atualiza a soma, maior e menor nota
        if (notas[i] > maior) maior = notas[i];
        if (notas[i] < menor) menor = notas[i];
    }

    float media = soma / qtdalunos;

    std::cout << "\n=== Notas dos alunos ===\n";
	// verifica se a nota � v�lida
    for (int i = 0; i < qtdalunos; i++) {
		// Exibe o nome do aluno e a nota formatada
        std::cout << nome[i] << ": " << std::fixed << std::setprecision(2) << notas[i] << std::endl;
    }
    std::cout << "Maior nota: " << maior << std::endl;
    std::cout << "Menor nota: " << menor << std::endl;
    std::cout << "M�dia da turma: " << std::fixed << std::setprecision(2) << media << std::endl;
}
void menuAlunos()
{
	// Fun��o para exibir o menu de alunos
	int opcao;
	float notas[100];
	std::string nome[100];
	do {
		std::cout << "===== MENU DE ALUNOS =====\n";
		std::cout << "[1] Calcular m�dia das notas\n";
		std::cout << "[0] Sair\n";
		std::cout << "Escolha uma op��o: ";
		std::cin >> opcao;
		switch (opcao) {
			case 1:
				Media(notas, nome);
				break;
			case 0:
				std::cout << "Saindo do menu de alunos...\n";
				break;
			default:
				std::cout << "Op��o inv�lida! Tente novamente.\n";
				break;
		}
	} while (opcao != 0);
}