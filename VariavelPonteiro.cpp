#include <iostream>
#include "Aulas.h"
void VariavelPonteiro() 
{
	setlocale(LC_ALL, "PORTUGUESE");
	int* ptr;
	int numero = 101;
	/*Aqui vamos colocar endereço de memória 
	da variavel Número. Ou seja onde ela está 
	carregada  na memória RAM. LEMBRE-SE que o que vai para 
	tela é o primeiro  endereço  da variavel número 
	pois ela ocupa 4 enderços pois tem 4 bytes de tamanho 
	*/
	std::cout << "\nEndereço de numero " << &numero << "\n";

	
	std::cout << "\nEndereço de ptr " << &ptr << "\n";
	system("PAUSE");
	return;
}