#include <iostream>
#include "Aulas.h"

static int SomaUmNumero(int numero, int NumeroSomado)
{
	return numero + NumeroSomado;
}
static void Mensagem()
{
	std::cout << "Ol�, seja bem-vindo ao sistema!" << std::endl;
	return;
}
static void Funcoes()
{
	Mensagem();
	int numero, NumeroSomado,RetornoDaFun��o;
	std::cout << "Digite um n�mero: ";
	std::cin >> numero;
	std::cout << "Digite o n�mero que deseja somar: ";
	std::cin >> NumeroSomado;
	int resultado = SomaUmNumero(numero, NumeroSomado);
	RetornoDaFun��o = SomaUmNumero(200, -500);
	std::cout << "A soma �: " << resultado << std::endl;
	std::cout << "A soma de 200 com -500: " << RetornoDaFun��o << std::endl;

	SomaUmNumero(numero, SomaUmNumero(150, 1400));
}