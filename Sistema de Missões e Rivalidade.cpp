#include"Aulas.h"
#include <iostream>
#include <string>
using namespace std;

class HeroiMissao 
{
	private:
		string nome;
		int nivel;
		int xp;
		bool emMissao;
	public:
		string getNome() const { return nome; }
		int getNivel() const { return nivel; }
		int getXp() const { return xp; }
		bool estaEmMissao() const {
			return emMissao;
		}
		// aqui o construtor esta inicializando o nome e os outros atributos
			HeroiMissao(string n) : nome(n), nivel(1), xp(0), emMissao(false) {}
			void iniciarMissao() {
				if (!emMissao) {
					emMissao = true;
					cout << nome << " iniciou uma missao!" << endl;
				} else {
					cout << nome << " ja esta em uma missao!" << endl;
				}
			}
			void completarMissao(int experiencia)
			{
				if (emMissao) {
					emMissao = false;
					xp += experiencia;
					cout << nome << " completou a missao e ganhou " << experiencia << " XP!" << endl;
					verificarNivel();
				} else {
					cout << nome << " nao esta em uma missao!" << endl;
				}
			}
			void verificarNivel() {
				if (xp >= 100) {
					nivel++;
					xp -= 100;
					cout << nome << " subiu para o nivel " << nivel << "!" << endl;
				}
			}
			bool teMaisxp(const HeroiMissao& outro) const
			{
				this->xp > outro.xp;

			}
			void mostrarStatus() const {
				cout << "Nome: " << nome << ", Nivel: " << nivel << ", XP: " << xp << ", Em Missao: " << (emMissao ? "Sim" : "Nao") << endl;
			}
};
void MenuMissao()
{
	HeroiMissao heroi1("Aragorn");
	HeroiMissao heroi2("Legolas");
	int escolha;
	// faça enquanto escolha for diferente de 6
	do {
		cout << "\nMenu de Missoes:\n1-Iniciar Missao para Aragorn\n2-Completar Missao para Aragorn\n3-Iniciar Missao para Legolas\n4-Completar Missao para Legolas\n5-Mostrar Status\n6-Sair\nEscolha uma opcao: ";
		cin >> escolha;
		switch (escolha) {
			case 1:
				heroi1.iniciarMissao();
				break;
			case 2:
				heroi1.completarMissao(50); // Exemplo de experiencia ganha
				break;
			case 3:
				heroi2.iniciarMissao();
				break;
			case 4:
				heroi2.completarMissao(70); // Exemplo de experiencia ganha
				break;
			case 5:
				heroi1.mostrarStatus();
				heroi2.mostrarStatus();
				break;
			case 6:
				cout << "Saindo do sistema de missoes..." << endl;
				break;
			default:
				cout << "Opcao invalida!" << endl;
		}
	} while (escolha != 6);
}	