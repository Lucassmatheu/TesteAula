#include "Conta.h"
#include <iostream>
#include <string>
using namespace std;

bool Conta:: sacar(double valor)
{
	// se o saldo for menor que o valor do saque

	if (Saldo < valor) 
	{
		// imprime mensagem de saldo insuficiente
		cout << "Saldo insuficiente para saque de " << valor << std::endl;
		cout << "Saldo atual: " << Saldo << std::endl;
		return false;

	}
	else {
		Saldo = valor;
		cout << "Seu Saldo Atual: R$" << consultarSaldo() << endl;
		return true;
	}

}
bool Conta::depositar(double valor)
{
	Saldo += valor;
	cout << "Deposito de R$" << valor << " realizado com sucesso." << endl;
	cout << "Seu Saldo Atual: R$" << consultarSaldo() << endl;
	return true;
}
// A função Recebe como argumento para seus paramentros um objeto do tipo Conta (contaDestino) e um valor do tipo double (valor).
void Conta:: tranferir(Conta& contaDestino, double valor)
{
    if (Saldo < valor) 
    {
        // imprime mensagem de saldo insuficiente
        cout << "Saldo insuficiente para transferencia de " << valor << std::endl;
        cout << "Saldo atual: " << Saldo << std::endl;
    }
    else {
        Saldo -= valor;
        contaDestino.depositar(valor);
        cout << "Transferencia de R$" << valor << " realizada com sucesso." << endl;
		cout << "Titular" << contaDestino.getTitular() << endl;
		cout << "Banco" << contaDestino.getBanco() << endl;
		cout << "Agencia" << contaDestino.getAgencia() << endl;
		cout << "Numero da Conta" << contaDestino.getNumConta() << endl;
		cout << "Seu Saldo Atual: R$" << consultarSaldo() << endl;
    }	
}
void Conta:: setBanco(const std::string& banco)
{
	// se This e um ponteiro para chegar no apontado pelo ponteiro temos 
	// *this, mas como this e um ponteiro para um obejto ele precisa usar 
	// notação ponto. para acessar atributos e executar funçoes do objeto
	// this -> Banco e o mesmo que (*this).Banco
	// contudo no geral  usa-se this -> atributo

	this -> Banco = banco;
}
void Conta:: setAgencia(int agencia)
{
	this -> Agencia = agencia;
}
void Conta:: setTitular(const std::string& titular)
{
	this -> Titular = titular;
}
double Conta:: consultarSaldo() const
{
	return Saldo;
}
string Conta:: getBanco() const
{
	return Banco;
}
int Conta::getAgencia() const {
    return Agencia;
}
int Conta::getNumConta() const {
    return NumConta;
}
std::string Conta::getTitular() const {
    return Titular;
}
