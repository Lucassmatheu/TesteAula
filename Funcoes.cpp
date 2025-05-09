#include <iostream>
#include "Aulas.h"

static int SomaUmNumero(int numero, int NumeroSomado)
{
	return numero + NumeroSomado;
}
static void Mensagem()
{
	std::cout << "Olá, seja bem-vindo ao sistema!" << std::endl;
	return;
}
static void Funcoes()
{
	Mensagem();
	int numero, NumeroSomado,RetornoDaFunção;
	std::cout << "Digite um número: ";
	std::cin >> numero;
	std::cout << "Digite o número que deseja somar: ";
	std::cin >> NumeroSomado;
	int resultado = SomaUmNumero(numero, NumeroSomado);
	RetornoDaFunção = SomaUmNumero(200, -500);
	std::cout << "A soma é: " << resultado << std::endl;
	std::cout << "A soma de 200 com -500: " << RetornoDaFunção << std::endl;

	SomaUmNumero(numero, SomaUmNumero(150, 1400));
}