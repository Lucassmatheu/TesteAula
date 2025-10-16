#include <iostream>
#include <string>
#include "Aulas.h"
using namespace std;

class GuerriroCla 
{
	private:
		string nome;
		int vida;
		int ataque;
		int defesa;
public:
	GuerriroCla() : nome(""), vida(150), ataque(30), defesa(25) {} 
	
	void receberDano(int dano) {
		this->vida -= dano;
		if (this->vida < 0) this->vida = 0;
	}
	GuerriroCla(string n) : nome(n), vida(150), ataque(30), defesa(25) {}
	void atacar(GuerriroCla& alvo) {
		cout << nome << " desferiu um golpe poderoso!" << endl;
		int dano = ataque - alvo.defesa;
		if (dano < 0) dano = 0;
		alvo.receberDano(dano);
		cout << nome << " atacou " << alvo.nome << " causando " << dano << " de dano!" << endl;
	}
	void AtaqueEspecial(GuerriroCla& alvo) {
		cout << nome << " concentrou energia e desferiu um ataque devastador!" << endl;
		int dano = ataque + 15;
		alvo.receberDano(dano);
		cout << nome << " causou " << dano << " de dano especial!" << endl;
	}
	void defesatemporaria(int aumento) {
		defesa += aumento;
		if (defesa < 10) 
		{
			cout << "Defesa muito baixa, ajustando para 10." << endl;
			defesa = 10;
		}
		else 
		{
			cout << "Defesa aumentada para " << defesa << "." << endl;
		}
		cout << nome << " aumentou sua defesa em " << aumento << " temporariamente!" << endl;
	}
	void reviver(int cura) {
		vida += cura;
		if (vida > 150) vida = 150; // Supondo que a vida maxima seja 150
		cout << nome << " foi revivido e agora tem " << vida << " de vida!" << endl;
	}
	string getNome() const { return nome; }
	int getVida() const { return vida; }
	int getAtaque() const { return ataque; }
	int getDefesa() const { return defesa; }

};
class lobo : public GuerriroCla
{
	public:
		lobo(string n) : GuerriroCla(n) {}
		void atacar(GuerriroCla& alvo) {
			cout << getNome() << " desferiu um golpe poderoso!" << endl;
			int dano = getAtaque() - alvo.getDefesa();
			if (dano < 0) dano = 0;
			alvo.receberDano(dano);
			cout << getNome() << " atacou " << alvo.getNome() << " causando " << dano << " de dano!" << endl;
		}
		void AtaqueEspecial(GuerriroCla& alvo) {
			cout << getNome() << " concentrou energia e desferiu um ataque devastador!" << endl;
			int dano = getAtaque() + 15;
			alvo.receberDano(dano);
			cout << getNome() << " causou " << dano << " de dano especial!" << endl;
		}
};
class serpente : public GuerriroCla
{
	public:
		serpente(string n) : GuerriroCla(n) {}
		void atacar(GuerriroCla& alvo) {
			cout << getNome() << " desferiu um golpe poderoso!" << endl;
			int dano = getAtaque() - alvo.getDefesa();
			if (dano < 0) dano = 0;
			alvo.receberDano(dano);
			cout << getNome() << " atacou " << alvo.getNome() << " causando " << dano << " de dano!" << endl;
		}
		void AtaqueEspecial(GuerriroCla& alvo) {
			cout << getNome() << " concentrou energia e desferiu um ataque devastador!" << endl;
			int dano = getAtaque() + 15;
			alvo.receberDano(dano);
			cout << getNome() << " causou " << dano << " de dano especial!" << endl;
		}
};
class GuerreiroDaEspada: public GuerriroCla
{
	public:
		GuerreiroDaEspada(string n) : GuerriroCla(n) {}
		void atacar(GuerriroCla& alvo) {
			cout << getNome() << " desferiu um golpe poderoso!" << endl;
			int dano = getAtaque() - alvo.getDefesa();
			if (dano < 0) dano = 0;
			alvo.receberDano(dano);
			cout << getNome() << " atacou " << alvo.getNome() << " causando " << dano << " de dano!" << endl;
		}
	
};
class guerreiroDaMachado: public GuerriroCla
{
	public:
		guerreiroDaMachado(string n) : GuerriroCla(n) {}
		void atacar(GuerriroCla& alvo) {
			cout << getNome() << " desferiu um golpe poderoso!" << endl;
			int dano = getAtaque() - alvo.getDefesa();
			if (dano < 0) dano = 0;
			alvo.receberDano(dano);
			cout << getNome() << " atacou " << alvo.getNome() << " causando " << dano << " de dano!" << endl;
		}
};
int contador = 0;
const int maxBatalhas = 3;

static bool podeLutar() {
	if (contador >= maxBatalhas) {
		cout << "Você atingiu o limite de batalhas de hoje." << endl;
		return false;
	}
	contador++;
	return true;
}

static void Limitebatalha()
{

	for (int i = 0; i < 3; i++) 
	{
		if (!podeLutar()) 
		{
			break;
		}
		else 
		{
			cout << "Você pode lutar! Batalhas restantes: " << (maxBatalhas - contador) << endl;
			break;
		}
	}
	
}
void MenuLutaCla()
{
	int escolha;
	do
	{
		GuerriroCla heroi2("Goblin");

		
		cout << "Escolha sua class\n1-Guerreiro da Espada\n2-Guerreiro da Machado\n3-Opcao: ";
		int opcao;
		cin >> escolha;
		if (escolha == 1)
		{ 
			if (!podeLutar()) {
				return;
			}
			do 
			{
				lobo heroi1("Guerreiro da Espada");
				heroi1.getVida();

				string invocar;
				cout << "Escolha uma acao:\n";
				cout << "1. Atacar\n";
				cout << "2. Defender\n";
				cout << "3. Sair\n";
				cin >> opcao;
				switch (opcao)
				{

				case 1:
					heroi1.atacar(heroi2);
					cout << "Pretende Envocar o Lobo ou a cobra ?";
					cin >> invocar;

					if (invocar == "Lobo")
					{
						lobo heroi3("Lobo");
						heroi3.atacar(heroi2);
					}
					else if (invocar == "Cobra")
					{
						serpente heroi4("Serpente");
						cout << "\nCobra Invocada com sucesso!" << endl;
						cout << "\nCobra Atacando!" << endl;
						cout << "\nCobra Atacou!" << endl;
						// Aqui o heroi4 (Cobra) ataca o heroi2 (Goblin)
						heroi4.atacar(heroi2);

					}
					if (heroi2.getVida() <= 0) {
						// saia do loop e imprima que o heroi1 venceu
						cout << heroi2.getNome() << " foi derrotado! " << heroi1.getNome() << " venceu a luta!" << endl;
						opcao = 3; // Sai do loop
						break;
					}
					// Se o heroi2 nao for derrotado, ele ataca o heroi1
					// heroi2.atacar(heroi1) aqui esta fazendo o ataque do heroi2 no heroi1
					heroi2.atacar(heroi1);
					if (heroi1.getVida() <= 0) {
						cout << heroi1.getNome() << " foi derrotado! " << heroi2.getNome() << " venceu a luta!" << endl;
						opcao = 3; // Sai do loop
					}

				case 2:
					cout << heroi1.getNome() << " se defende e reduz o dano do proximo ataque!" << endl;
					// Implementar logica de defesa (exemplo: aumentar defesa temporariamente)
					heroi1.defesatemporaria(10); // Aumenta defesa em 10 temporariamente
					break;
				case 3:
					cout << "Saindo da luta..." << endl;
					break;
				default:
					break;
				}

			} while ((opcao != 3));
			
			
			
		}
		if (escolha == 2)
		{
			if (!podeLutar()) {
				return;
			}		  
		  
			string invocar;
			// O heroi1 aqui é do tipo Arqueiro que vem da classe derivada Arqueiro
			serpente heroi1("Guerreiro da Machado");
			int opcao;
			do
			{
				cout << "Escolha uma acao:\n";
				cout << "1. Atacar\n";
				cout << "2. Defender\n";
				cout << "3. Sair\n";
				cin >> opcao;
				switch (opcao)
				{
				case 1:
					heroi1.atacar(heroi2);
					cout << "Pretende Envocar o Lobo ou a cobra ?";
					cin >> invocar;

					if (invocar == "Lobo")
					{
						lobo heroi3("Lobo");
						heroi3.atacar(heroi2);
					}
					else if (invocar == "Cobra")
					{
						serpente heroi4("Serpente");
						heroi4.atacar(heroi2);
					}
					if (heroi2.getVida() <= 0) {
						// saia do loop e imprima que o heroi1 venceu
						cout << heroi2.getNome() << " foi derrotado! " << heroi1.getNome() << " venceu a luta!" << endl;
						opcao = 3; // Sai do loop
						break;
					}
					// Se o heroi2 nao for derrotado, ele ataca o heroi1
					// heroi2.atacar(heroi1) aqui esta fazendo o ataque do heroi2 no heroi1
					heroi2.atacar(heroi1);
					if (heroi1.getVida() <= 0) {
						cout << heroi1.getNome() << " foi derrotado! " << heroi2.getNome() << " venceu a luta!" << endl;
						opcao = 3; // Sai do loop
					}
				case 2:
					cout << heroi1.getNome() << " se defende e reduz o dano do proximo ataque!" << endl;
					// Implementar logica de defesa (exemplo: aumentar defesa temporariamente)
					heroi1.defesatemporaria(10); // Aumenta defesa em 10 temporariamente
					break;
				case 3:
					cout << "Saindo da luta..." << endl;
					break;
				default:
					break;
				}
			} while (opcao != 3);
		}
		
	} while (escolha != 3);
	
}
