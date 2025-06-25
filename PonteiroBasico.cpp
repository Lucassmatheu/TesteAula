#include <iostream>

static void PonteiroBasico()
{
	int atribuicao = 10;
	int* ptr = &atribuicao;

	std::cout << "O VALOR DA VARIAVEL. " << atribuicao<< "\n";
	std::cout << " O ENDEREÇO DA VARIAVEL " << &atribuicao << "\n";
	std::cout << " O valor armazenado no ponteiro. " << ptr << "\n";
	std::cout << "O conteúdo apontado pelo ponteiro. " << *ptr << "\n";
}