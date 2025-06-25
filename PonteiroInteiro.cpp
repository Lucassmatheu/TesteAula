#include <iostream>

void ponteiroInteiro() 
{
    int numero = 42;
    int* ptr = &numero;  // ptr recebe o endereço de memoria de numero

    std::cout << "Valor de numero: " << numero << std::endl;
    std::cout << "Endereço de numero (&numero): " << &numero << std::endl;
    std::cout << "Valor do ponteiro (ptr): " << ptr << std::endl;
    std::cout << "Valor apontado por ptr (*ptr): " << *ptr << std::endl;

    return;
}