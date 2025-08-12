#include <iostream>
#include <string>
#include "Aulas.h"

const int MAX_PRODUTOS = 10;    
static int BuscarIndice(const std::string produto[], int total, const std::string& nome)
{
    for (int i = 0; i < total; ++i) {
        if (produto[i] == nome) return i;
    }
    return -1;
}
void CadastrarProduto(std::string produto[], int& total) 
{
    std::string nome;
    for (int i = 0; i < 10; i++) 
    {
        if (total >= MAX_PRODUTOS) {
            std::cout << "Limite de produtos atingido." << std::endl;
            return;
		}

        std::cout << "Digite o nome do produto: ";
        std::cin >> nome;


        if (BuscarIndice(produto, total, nome) != -1) {
            std::cout << "Produto ja cadastrado.\n";
            return;
        }

     
        //se o produto nao existe, cadastra
        produto[i] = nome;
        total++;
        std::cout << "Produto cadastrado com sucesso!" << std::endl;
		return;
    }

}
