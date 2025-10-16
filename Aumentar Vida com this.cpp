#include <iostream>
#include <string>
using namespace std;

class Personagem
{

	string nome;
	int vida;

public: // Torna o método acessível fora da classe
	void cura(int quantidade)
	{
		this->vida += quantidade;
		cout << this->nome << " agora tem " << this->vida << " de vida." << endl;
	}
	
		// Adicione o construtor para inicializar nome e vida
		Personagem(string n, int v) : nome(n), vida(v) {}
};
void menu() 
{
	Personagem p("Lucas", 100); // Crie o construtor com nome e vida
	int opcao;
	do {
		menu();
		cin >> opcao;
		if (opcao == 1) {
			p.cura(20); // Aumenta 20 de vida
		}
	} while (opcao != 2);

}

