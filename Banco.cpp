#include "Conta.h"
#include <iostream>
#include <string>

using namespace std;

void Banco() {
	Conta ContaCliente01;
	Conta ContraCliente02;
	ContaCliente01.setBanco("Banco do Brasil");
	ContaCliente01.setAgencia(1234);
	ContaCliente01.setTitular("Joao da Silva");
	ContaCliente01.depositar(1000);
	ContaCliente01.sacar(500);
	ContaCliente01.tranferir(ContraCliente02, 200);
	
	ContaCliente01.tranferir(ContraCliente02, 400);
	


	
	
}