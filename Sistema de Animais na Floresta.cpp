#include <iostream>
#include <string>
#include "Aulas.h"
#include <memory>
using namespace std;

class Animal 
{
	public:
	string nome;
	int idade;
	string especie;
	Animal(string n, int i, string e)
		: nome(n), idade(i), especie(e) {
	}
	virtual void emitirSom() const {
		cout << nome << " faz um som gen�rico." << endl;
	}
	virtual void exibirInfo() const {
		cout << "Nome: " << nome << ", Idade: " << idade << ", Esp�cie: " << especie << endl;
	}
	virtual void comer() const {
		cout << nome << " est� se alimentando." << endl;
	}

};
class Leao : public Animal 
{
	public:
	Leao(string n, int i) : Animal(n, i, "Le�o") {}
	void emitirSom() const override {
		cout << nome << " ruge: Rooooar!" << endl;
	}
	void exibirInfo() const override {
		cout << "Nome: " << nome << ", Idade: " << idade << ", Esp�cie: " << especie << " (Rei da Selva)" << endl;
	}
};
class Lobo : public Animal 
{
	public:
	Lobo(string n, int i) : Animal(n, i, "Lobo") {}
	void emitirSom() const override {
		cout << nome << " uiva: Auuuu!" << endl;
	}
	void exibirInfo() const override {
		cout << "Nome: " << nome << ", Idade: " << idade << ", Esp�cie: " << especie << " (Ca�ador Noturno)" << endl;
	}
	void comer() const override {
		cout << nome << " est� ca�ando sua presa." << endl;
	}
};
class passaro : public Animal 
{
	public:
	passaro(string n, int i) : Animal(n, i, "P�ssaro") {}
	void emitirSom() const override {
		cout << nome << " canta: Chirp Chirp!" << endl;
	}
	void exibirInfo() const override {
		cout << "Nome: " << nome << ", Idade: " << idade << ", Esp�cie: " << especie << " (Mensageiro do Vento)" << endl;
	}
	void comer() const override {
		cout << nome << " est� bicando sementes." << endl;
	}
};
int main() 
{
	unique_ptr<Animal> animais[3];
	animais[0] = make_unique<Leao>("Simba", 5);
	animais[1] = make_unique<Lobo>("Akela", 3);
	animais[2] = make_unique<passaro>("Piu-Piu", 1);
	for (const auto& animal : animais) 
	{
		animal->exibirInfo();
		animal->emitirSom();
		cout << endl;
	}
	return 0;
}