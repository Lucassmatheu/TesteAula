#include "Conta.h"
#include <iostream>
#include <string>

using namespace std;

void Banco() {
	// como esta dessa forma obejto seria criado usando o construtor padrao automatico 
	// conhecido como contrutor padrão ou construtor default
	Conta ContaCliente01("Itau",222,5555,"Marcos",10000);
	Conta ContraCliente02;
	ContaCliente01.setBanco("Banco do Brasil");
	ContaCliente01.setAgencia(1234);
	ContaCliente01.setTitular("Joao da Silva");
	ContaCliente01.depositar(1000);
	ContaCliente01.sacar(500);
	ContaCliente01.tranferir(ContraCliente02, 200);
	
	ContaCliente01.tranferir(ContraCliente02, 400);
	


	
	
}