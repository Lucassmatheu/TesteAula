#include <iostream>
#include "Aulas.h"

void TextoECaractere()
{

	char caractere('X');
	std::string texto("Ol� mundo");
	std::cout << "O tamanho de char �: " << sizeof(caractere) << " bytes" << std::endl;
	std::cout << "O tamanho de string �: " << sizeof(texto) << " bytes" << std::endl;
	std::cout << "O tamanho de string �: " << texto.size() << " bytes" << std::endl;
	// texto.size() retorna o tamanho da string em Bytes 
	// texto.length() retorna o tamanho da string em caracteres
}