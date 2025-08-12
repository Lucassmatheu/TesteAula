#include <iostream>
#include "Aulas.h"

void ControleAlunos(std::string* NomeAluno, int* frequencia) 
{
	int diasAula = 0;
	int totalPresencas = 0;
	int soma = 0;

	std::cout << "===== CONTROLE DE FREQUÊNCIA DE ALUNOS =====\n";
	//para cada aluno i=0; i < 5; i++
	// para cada aluno, pede o nome do aluno e a frequencia do aluno
	// para inteiro i = 0 ; i < 5; i++ 
	for (int i = 0; i < 5; i++) 
	{

		std::cout << "Digite o nome do aluno " << (i + 1) << ": ";
		std::cin >> NomeAluno[i];
		std::cout << "Digite a frequência do aluno (1 para presente / 0 para falta)  " << (i + 1) << ": ";
		std::cin >> frequencia[i];
		// soma as frequencias
		soma += frequencia[i];

		//para cada dia de aula (5 dias), pede a frequencia do aluno
		// para dia = 0; dia < 5; dia++
		// exibe "Dia " + (dia + 1) + ": "
		// pede a frequencia do aluno (1 para presente / 0 para falta)
		for (int *dia = 0; *dia < 5; dia++) {
			std::cout << "Dia " << (dia + 1) << ": ";
			std::cin >> frequencia[i][dia];
		}
		
		// se frequencia[i] for 1, exibe "NomeAluno[i] está presente."
		if (frequencia[i] == 1) 
		{
			
			std::cout << NomeAluno[i] << " está presente." << std::endl;
		}
		//se frequencia[i] for 0, exibe "NomeAluno[i] está ausente."
		else if (frequencia[i] == 0) 
		{
			
			std::cout << NomeAluno[i] << " está ausente." << std::endl;
		}
		// se frequencia[i] for diferente de 1 ou 0, exibe "Valor inválido para frequência. Use 1 para presente e 0 para falta."
		else 
		{
			std::cout << "Valor inválido para frequência. Use 1 para presente e 0 para falta." << std::endl;
		}
	}
	
}

void MostarFrequencia(std::string* NomeAluno, int* frequencia)
{

	std::cout << "===== RELATÓRIO DE FREQUÊNCIA DOS ALUNOS =====\n";
	for (int i = 0; i < 5; i++) 
	{
		std::cout << "Aluno: " << NomeAluno[i] << " - Frequência: "<< frequencia[i];
		if (frequencia[i] >= 3)
		{
		std::cout << " - Status: Aprovado\n";
		}
		else 
		{
			std::cout << " - Status: Reprovado\n";

		}
	}
	

}
void MenuFrequencia() 
{
	// Vetores para armazenar nomes dos alunos e suas frequências
	std::string NomeAluno[5];
	int frequencia[5]{};
	int opcao;
	//enquanto opcao for diferente de 0, exibe o menu
	do {
		std::cout << "===== MENU DE CONTROLE DE FREQUÊNCIA DE ALUNOS =====\n";
		std::cout << "[1] Registrar Frequência\n";
		std::cout << "[2] Mostrar Relatório de Frequência\n";
		std::cout << "[0] Sair\n";
		std::cout << "Escolha uma opção: ";
		std::cin >> opcao;
		// dependendo da opção escolhida, chama a função correspondente
		switch (opcao) {
		case 1:
			ControleAlunos(NomeAluno, frequencia);
			break;
		case 2:
			MostarFrequencia(NomeAluno, frequencia);
			break;
		case 0:
			std::cout << "Saindo do menu.\n";
			break;
		default:
			std::cout << "Opção inválida. Tente novamente.\n";
		}
	} while (opcao != 0);
}	
