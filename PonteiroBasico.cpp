#include <iostream>

static void PonteiroBasico()
{
	int atribuicao = 10;
	int* ptr = &atribuicao;

	std::cout << "O VALOR DA VARIAVEL. " << atribuicao<< "\n";
	std::cout << " O ENDERE�O DA VARIAVEL " << &atribuicao << "\n";
	std::cout << " O valor armazenado no ponteiro. " << ptr << "\n";
	std::cout << "O conte�do apontado pelo ponteiro. " << *ptr << "\n";
}