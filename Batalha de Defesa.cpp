#include <iostream>
#include <string>
using namespace std;

class Heroi {

private:
	string nome;
	int vida;
	int ataque;
	int defesa;

public:
	Heroi(string n, int v, int a, int d) : nome(n), vida(v),ataque(a), defesa(d) {}
	string getNome() const { return nome; }
	int  getVida() const { return vida; }
	int  getAtaque() const { return ataque; }
	int  getDefesa() const { return defesa; }

	bool temMaisvida(const Heroi& outro) const {
		return this->vida > outro.vida;
	}
	void receberDano(int dano) {
		vida -= dano;
		if (vida < 0) vida = 0;
	}
	void atacar(Heroi& inimigo) {
		int dano = ataque - inimigo.defesa;
		if (dano < 0) dano = 0;
		inimigo.receberDano(dano);
		cout << nome << " atacou " << inimigo.nome << " causando " << dano << " de dano!" << endl;
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
};
void Luta()
{
	string nomeHeroi;
	cout << "Nome do seu heroi";
	cin >> nomeHeroi;
	cout << "Bem vindo, " << nomeHeroi << "!" << endl;

	Heroi heroi1(nomeHeroi, 100, 50, 30);
	Heroi heroi2("Goblin", 80, 40, 20);
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
			// heroi1.atacar(heroi2) aqui esta fazendo o ataque do heroi1 no heroi2
			heroi1.atacar(heroi2);
			// se a vida do heroi2 for menor ou igual a 0, o heroi1 vence
			
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
			break;
		case 2:
			// heroi1.getNome() aqui esta fazendo que o nome do heroi seja exibido
			cout << heroi1.getNome() << " se defende e reduz o dano do proximo ataque!" << endl;
			// Implementar logica de defesa (exemplo: aumentar defesa temporariamente)
			heroi1.defesatemporaria(10); // Aumenta defesa em 10 temporariamente
			break;
		case 3:	
			cout << "Saindo da luta..." << endl;
			break;
		default:
			cout << "Opcao invalida. Tente novamente." << endl;
			break;
		}




	} while (opcao != 3);






};
static void imprimirStatus()
{
	Heroi heroi1("Arus", 100, 50, 30);
	Heroi heroi2("Goblin", 80, 40, 20);
	cout << heroi1.getNome() << " - Vida: " << heroi1.getVida() << ", Ataque: " << heroi1.getAtaque() << ", Defesa: " << heroi1.getDefesa() << endl;
	cout << heroi2.getNome() << " - Vida: " << heroi2.getVida() << ", Ataque: " << heroi2.getAtaque() << ", Defesa: " << heroi2.getDefesa() << endl;
	if (heroi1.temMaisvida(heroi2)) {
		cout << heroi1.getNome() << " tem mais vida que " << heroi2.getNome() << endl;
	}
	else {
		cout << heroi2.getNome() << " tem mais vida que " << heroi1.getNome() << endl;
	}
}
void menuHeroi() 
{
	int opcao;
	do {
		cout << "Menu:\n";
		cout << "1. Iniciar Luta\n";
		cout << "2. Mostrar Status\n";
		cout << "3. Sair\n";
		cin >> opcao;
		if (opcao == 1) {
			Luta();
		}
		else if (opcao == 2) {
			imprimirStatus();
		}
	} while (opcao != 3);
}