#include <iostream>
#include "Aulas.h"
void VariavelPonteiro() 
{
	setlocale(LC_ALL, "PORTUGUESE");
	int* ptr;
	int numero = 101;
	/*Aqui vamos colocar endere�o de mem�ria 
	da variavel N�mero. Ou seja onde ela est� 
	carregada  na mem�ria RAM. LEMBRE-SE que o que vai para 
	tela � o primeiro  endere�o  da variavel n�mero 
	pois ela ocupa 4 ender�os pois tem 4 bytes de tamanho 
	*/
	std::cout << "\nEndere�o de numero " << &numero << "\n";

	
	std::cout << "\nEndere�o de ptr " << &ptr << "\n";
	system("PAUSE");
	return;
}