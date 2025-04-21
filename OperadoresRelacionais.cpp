#include <iostream>
#include "Aulas.h"

void OperadoresRelacionais()
{
	/*
Este programa simula a triagem de um processo seletivo.

Regras de aceitação:
- Idade entre 18 e 35 anos (inclusive)
- A idade não pode ser exatamente 27
- Precisa ter experiência ou ensino médio completo

Operadores usados:
- Relacionais: >=, <=, !=
- Lógicos: && (E), || (OU)

A resposta exibida depende do resultado da condição principal
*/
	// 1. Solicita o nome, idade, se tem ensino médio e experiência 
	std::string nome;
	int idade, Ensinomedio, experiencia;

	std::cout << "Digite seu nome: ";
	std::cin >> nome;	
	std::cout << "Digite sua idade: ";
	std::cin >> idade; 
	std::cout << "Você tem ensino médio completo? (1 para sim, 0 para não): ";
	std::cin >> Ensinomedio;
	std::cout << "Experiência você tem? (1 para sim, 0 para não) ";
	std::cin >> experiencia;
	if (idade >= 18 && idade <= 35 && idade != 27 && (experiencia == 1 || Ensinomedio == 1)) 
	{
		std::cout << "Você está apto para a vaga de emprego." << std::endl;
	}
	else 
	{
		std::cout << "Você não está apto para a vaga de emprego." << std::endl;
	}
	


}