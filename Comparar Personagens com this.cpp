#include "Conta.h"
#include <iostream>
#include <string>

using namespace std;

class Personagem
{

	string nome;
	int ataque;

public:
	bool temMaisAtaque(const Personagem& outro)
	{
		// compara o ataque do objeto atual (this) com o ataque do outro objeto passado como parmetro
		return this->ataque > outro.ataque;
	}
	// Adicione o construtor para inicializar nome e ataque
	Personagem(string n, int a) : nome(n), ataque(a) {}
	string getNome() const { return nome; }

};
void mostrarDescricao()
{
	Personagem p1("Lucas", 50); // Crie o construtor com nome e ataque
	Personagem p2("Ana", 70); // Crie o construtor com nome e ataque
	if (p1.temMaisAtaque(p2)) {
		cout << p1.getNome() << " tem mais ataque que " << p2.getNome() << endl;
	}
	else {
		cout << p2.getNome() << " tem mais ataque que " << p1.getNome() << endl;
	}
}