#include <iostream>
#include "Aulas.h"



 class casa
{
	/*
	* Public: significa que tudo o que estiver abaixo disso ser� publico
	*/
	public:
	// Estes s�o atributos, as propriedadee e s�o representados por variaveis.
	// este atributo sr�o a s caracteristicas de cada objeto criado dessa classe
	/* 
	Quando p programa estiver sente execultyado be queremos
	saver qual ea situa��o do objeto em rela��o ao valor de seus atributos 
	*/ 
	/*
	* Por padr�o em uma classe a visibilidade � privada, ou seja,
	* se n�o for indicado benhuma visibilidade o pad�o e ser private(privado)
	*/
	//private:

	int NumQuartos{4};
	float tamanhao{90.0f};

	// No geral voc� coloca b na frente de uma varealvel  bool para indicar que � booleano	
	bool TemSuite{true};
	/*
	* Estas s�o opera�oes da classe, ou metodos ou as fun��es que o objeto poder� execultar quando 
	for criado(instanciado) a partir dessa classe
	*/
	void mostrarTamanho();
	int obtenhaNumeroQuartos();
	bool temSuite();



};

// Construtor da classe casa 
// Inicializa os atributos da casa
void casa::mostrarTamanho()
{

	std::cout << "O tamanho da casa �: " << tamanhao << " metros quadrados.\n";
}

// Retorna true se a casa tem su�te, false caso contr�rio
int casa::obtenhaNumeroQuartos()
{
	// Retorna o n�mero de quartos da casa
	return NumQuartos;
}

// Retorna true se a casa tem su�te, false caso contr�rio
bool casa::temSuite()
{
	// Retorna true se a casa tem su�te, false caso contr�rio
	return TemSuite;
}
void CriandoClasse()
{
	casa CasadePraia{};
	CasadePraia.mostrarTamanho();	
	std::cout << "A casa tem " << CasadePraia.obtenhaNumeroQuartos() << " quartos.\n";
	std::cout << "A casa tem su�te? " << (CasadePraia.temSuite() ? "Sim" : "N�o") << "\n";
	std::cout << "-----------------------------------\n";
	/*
	* Para acessar os membros da calsse casa usamos o operador ponto (.)
	* para acessar os atributos e metodos
	* nomeDoObjeto.nomeDoAtributo ou nomeDoObjeto.nomeDoMetodo() ou fun��o 
	* ou seja o nome do objeto seguido de um ponto e o nome do atributo ou metodo
	*/

}