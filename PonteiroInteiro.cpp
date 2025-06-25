#include <iostream>

void ponteiroInteiro() 
{
    int numero = 42;
    int* ptr = &numero;  // ptr recebe o endere�o de memoria de numero

    std::cout << "Valor de numero: " << numero << std::endl;
    std::cout << "Endere�o de numero (&numero): " << &numero << std::endl;
    std::cout << "Valor do ponteiro (ptr): " << ptr << std::endl;
    std::cout << "Valor apontado por ptr (*ptr): " << *ptr << std::endl;

    return;
}