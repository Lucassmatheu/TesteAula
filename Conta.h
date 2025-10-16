#pragma once
#include <iostream>
#include <string>

// este e o arquivo .h é onde existem apenas as declarações dos atributos e métodos da classe.
// Aqui não existem as definções , implementações das funções, 
// pois estas devem ser feitas no arquivo .cpp correspondente. e a ceparação do O quê (.h) do Como (.cpp) é um dos princípios do encapsulamento em POO.

class Conta
{
	// indica que acesso  a este membro abaixo de private:
	// só de do codigo da classe Conta
private:
		std::string	Banco;
		int Agencia;
		int NumConta;
		std::string	Titular;
		double Saldo{0.0};

		// indica que acesso  a este membro abaixo de public:
		// pode ser feito de qualquer parte do codigo  fora da classe Conta
public:
	bool sacar(double valor);
	bool depositar(double valor);
	//neste caso o parametro contaDestino recebe apena uma copia do valor do objeto. Ele não tem como alterar o onbejto pois só recebeu uma copia do valor.
	// Logo podemos usar o conceito de referencia para passar a referencia do obejeto pois será realzada uma passagem de argumentos por referencia e não por valor.
	void tranferir(Conta &contaDestino, double valor);	
	double consultarSaldo() const;	
	std::string	getBanco() const;
	int getAgencia() const;
	int getNumConta() const;
	std::string getTitular() const;
	void setBanco(const std::string& banco);
	void setAgencia(int agencia);
	void setTitular(const std::string& titular);	

};