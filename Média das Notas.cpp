#include <iostream>	
#include <iomanip>
#include "Aulas.h"
using namespace std;

void Media(float* notas, std::string* nome)
{
    float soma = 0.0;
    std::cout << "===== CÁLCULO DA MÉDIA DAS NOTAS =====\n";
    int qtdalunos;
    std::cout << "Digite a quantidade de alunos: ";
    std::cin >> qtdalunos;

	// Verifica se a quantidade de alunos é válida
    for (int i = 0; i < qtdalunos; i++) {
        std::cout << "Digite o nome do aluno " << (i + 1) << ": ";
        std::cin >> nome[i];// Verifica se o nome do aluno é válido

		
        std::cout << "Digite a nota do aluno " << nome[i] << ": ";
		std::cin >> notas[i];// Verifica se a nota do aluno é válida
        
		// soma as notas dos alunos 
		soma += notas[i];
    }

    float maior = notas[0];
    float menor = notas[0];
	// verifica se a nota é maior ou menor que as demais
    for (int i = 1; i < qtdalunos; i++) {
		// Atualiza a soma, maior e menor nota
        if (notas[i] > maior) maior = notas[i];
        if (notas[i] < menor) menor = notas[i];
    }

    float media = soma / qtdalunos;

    std::cout << "\n=== Notas dos alunos ===\n";
	// verifica se a nota é válida
    for (int i = 0; i < qtdalunos; i++) {
		// Exibe o nome do aluno e a nota formatada
        std::cout << nome[i] << ": " << std::fixed << std::setprecision(2) << notas[i] << std::endl;
    }
    std::cout << "Maior nota: " << maior << std::endl;
    std::cout << "Menor nota: " << menor << std::endl;
    std::cout << "Média da turma: " << std::fixed << std::setprecision(2) << media << std::endl;
}
void menuAlunos()
{
	// Função para exibir o menu de alunos
	int opcao;
	float notas[100];
	std::string nome[100];
	do {
		std::cout << "===== MENU DE ALUNOS =====\n";
		std::cout << "[1] Calcular média das notas\n";
		std::cout << "[0] Sair\n";
		std::cout << "Escolha uma opção: ";
		std::cin >> opcao;
		switch (opcao) {
			case 1:
				Media(notas, nome);
				break;
			case 0:
				std::cout << "Saindo do menu de alunos...\n";
				break;
			default:
				std::cout << "Opção inválida! Tente novamente.\n";
				break;
		}
	} while (opcao != 0);
}