#include <iostream>
#include "Aulas.h"

void OperadoresRelacionais()
{
	/*
Este programa simula a triagem de um processo seletivo.

Regras de aceita��o:
- Idade entre 18 e 35 anos (inclusive)
- A idade n�o pode ser exatamente 27
- Precisa ter experi�ncia ou ensino m�dio completo

Operadores usados:
- Relacionais: >=, <=, !=
- L�gicos: && (E), || (OU)

A resposta exibida depende do resultado da condi��o principal
*/
	// 1. Solicita o nome, idade, se tem ensino m�dio e experi�ncia 
	std::string nome;
	int idade, Ensinomedio, experiencia;

	std::cout << "Digite seu nome: ";
	std::cin >> nome;	
	std::cout << "Digite sua idade: ";
	std::cin >> idade; 
	std::cout << "Voc� tem ensino m�dio completo? (1 para sim, 0 para n�o): ";
	std::cin >> Ensinomedio;
	std::cout << "Experi�ncia voc� tem? (1 para sim, 0 para n�o) ";
	std::cin >> experiencia;
	if (idade >= 18 && idade <= 35 && idade != 27 && (experiencia == 1 || Ensinomedio == 1)) 
	{
		std::cout << "Voc� est� apto para a vaga de emprego." << std::endl;
	}
	else 
	{
		std::cout << "Voc� n�o est� apto para a vaga de emprego." << std::endl;
	}
	


}