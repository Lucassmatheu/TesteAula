#include <iostream>
#include <iomanip>

void porcentagem() 
{
	float NumeroBase, porcentagem, resultado;
	std::cout << "Digite o valor base: ";
	std::cin >> NumeroBase;
	std::cout << "Digite o valor da porcentagem: ";
	std::cin >> porcentagem;
	resultado = (NumeroBase * porcentagem) / 100;

	std::cout << "O resultado de " << porcentagem << "% de " << NumeroBase << " é: " << resultado << std::endl;

}