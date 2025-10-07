#include <iostream>
#include "Aulas.h"



 class casa
{
	/*
	* Public: significa que tudo o que estiver abaixo disso será publico
	*/
	public:
	// Estes são atributos, as propriedadee e são representados por variaveis.
	// este atributo srão a s caracteristicas de cada objeto criado dessa classe
	/* 
	Quando p programa estiver sente execultyado be queremos
	saver qual ea situação do objeto em relação ao valor de seus atributos 
	*/ 
	/*
	* Por padrão em uma classe a visibilidade é privada, ou seja,
	* se não for indicado benhuma visibilidade o padão e ser private(privado)
	*/
	//private:

	int NumQuartos{4};
	float tamanhao{90.0f};

	// No geral você coloca b na frente de uma varealvel  bool para indicar que é booleano	
	bool TemSuite{true};
	/*
	* Estas são operaçoes da classe, ou metodos ou as funções que o objeto poderá execultar quando 
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

	std::cout << "O tamanho da casa é: " << tamanhao << " metros quadrados.\n";
}

// Retorna true se a casa tem suíte, false caso contrário
int casa::obtenhaNumeroQuartos()
{
	// Retorna o número de quartos da casa
	return NumQuartos;
}

// Retorna true se a casa tem suíte, false caso contrário
bool casa::temSuite()
{
	// Retorna true se a casa tem suíte, false caso contrário
	return TemSuite;
}
void CriandoClasse()
{
	casa CasadePraia{};
	CasadePraia.mostrarTamanho();	
	std::cout << "A casa tem " << CasadePraia.obtenhaNumeroQuartos() << " quartos.\n";
	std::cout << "A casa tem suíte? " << (CasadePraia.temSuite() ? "Sim" : "Não") << "\n";
	std::cout << "-----------------------------------\n";
	/*
	* Para acessar os membros da calsse casa usamos o operador ponto (.)
	* para acessar os atributos e metodos
	* nomeDoObjeto.nomeDoAtributo ou nomeDoObjeto.nomeDoMetodo() ou função 
	* ou seja o nome do objeto seguido de um ponto e o nome do atributo ou metodo
	*/

}