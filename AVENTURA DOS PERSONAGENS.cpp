#include <iostream>
#include <string>
#include "Aulas.h"
#include <memory>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

class Personagem
{
public:
	string nome;
	int vida;
	int ataque;
	int defesa;
	Item* mochila[3]{};

	Personagem(string n, int v, int a, int d)
		: nome(n), vida(v), ataque(a), defesa(d)
	{
		for (int i = 0; i < 3; ++i) mochila[i] = nullptr;
	}

	virtual ~Personagem() {
		for (int i = 0; i < 3; ++i) delete mochila[i];
	}

	int receberDano(int dano) {
		vida -= dano;
		return vida;
	}
	void exibirStatus() const
	{
		cout << "\n[" << nome << "]" << endl;
		cout << "Vida: " << vida << " | Ataque: " << ataque << endl;
		cout << "Mochila: ";
		for (int i = 0; i < 3; ++i) {
			if (mochila[i]) cout << "[" << i << "] " << mochila[i]->nome() << "  ";
		}
		cout << endl;
	}
	// Torne o método virtual e use o nome correto
	virtual void atacar(Personagem& alvo) {
		int dano = ataque;
		if (dano < 0) dano = 0;
		alvo.receberDano(dano);
		cout << nome << " atacou " << alvo.nome << " causando " << dano << " de dano!" << endl;
	}

	// Adicione este método virtual à classe base Personagem
	virtual void usarHabilidadeEspecial(Personagem& /*alvo*/) {
		cout << nome << " não possui habilidade especial!\n";
	}

	// Métodos de mochila
	void inserirItem(Item* item) {
		for (int i = 0; i < 3; ++i) {
			if (!mochila[i]) {
				mochila[i] = item;
				cout << "Item " << item->nome() << " inserido na posicao " << i << endl;
				return;
			}
		}
		cout << "Mochila cheia!\n";
		delete item;
	}
	void usarItem(int pos) {
		if (pos < 0 || pos >= 3 || !mochila[pos]) {
			cout << "Posicao invalida!\n";
			return;
		}
		mochila[pos]->usar(*this);
		delete mochila[pos];
		mochila[pos] = nullptr;
	}
};
// Classe derivada Guerreiro
class Guerreiro : public Personagem{
public:
	Guerreiro(string n) : Personagem(n, 130, 22, 15) {}

	void atacar(Personagem& alvo) override {
		cout << nome << " usa Espada Poderosa!" << endl;
		Personagem::atacar(alvo);
	}
	
};
// Classe derivada Mago
class Mago : public Personagem
{
public:
	Mago(string n) : Personagem(n, 85, 28, 6) {}
	void atacar(Personagem& alvo) override {
		cout << nome << " lança uma Bola de Fogo!" << endl;
		int dano = ataque - alvo.defesa;
		if (dano < 0) dano = 0;
		alvo.receberDano(dano);
	}
	void usarHabilidadeEspecial(Personagem& alvo) 
	{
		int dano = 25;
		alvo.receberDano(dano);
		cout << nome << " usou Habilidade Especial: " << alvo.nome << " perdeu " << dano << " de vida!\n";
	}

};
// Classe derivada Arqueiro
class Arqueiro : public Personagem
{
	Arqueiro(string n) : Personagem(n, 95, 27, 8) {}
	void atacar(Personagem& alvo) override {
		cout << nome << " dispara uma flecha precisa!" << endl;
		int dano = ataque - alvo.defesa;
		if (dano < 0) dano = 0;
		alvo.receberDano(dano);
	}
	// Substitua o método AtaqueCritico por um método não-override, pois não existe na base
	void AtaqueCritico(Personagem& alvo) {
		// Simula um ataque com chance de crítico
		cout << nome << " dispara uma flecha precisa!" << endl;
		int dano = ataque + 10 - alvo.defesa;
		if (dano < 0) dano = 0;
		alvo.receberDano(dano);
		cout << nome << " atacou " << alvo.nome << " causando " << dano << " de dano!" << endl;
	}
};
// Classe abstrata Item
class Item {
public:
	virtual void usar(Personagem& p) = 0;
	virtual std::string nome() const = 0;
	virtual ~Item() {}
};

// Poção de Cura: recupera vida
class PocaoCura : public Item {
public:
	void usar(Personagem& p) override {
		p.vida += 20;
		cout << p.nome << " usou Poção de Cura e recuperou 20 de vida!\n";
	}
	std::string nome() const override { return "Poção de Cura"; }
};

// Poção de Força: aumenta o ataque
class PocaoForca : public Item {
public:
	void usar(Personagem& p) override {
		p.ataque += 10;
		cout << p.nome << " usou Poção de Força e ganhou +10 de ataque!\n";
	}
	std::string nome() const override { return "Poção de Força"; }
}; 
   
int main() {
	// Escolha das classes
	unique_ptr<Personagem> p1, p2;
	int escolha;
	cout << "Jogador 1, escolha sua classe:\n1-Guerreiro 2-Mago 3-Arqueiro\nOpcao: ";
	cin >> escolha;
	if (escolha == 1) p1 = make_unique<Guerreiro>("Guerreiro1");
	else if (escolha == 2) p1 = make_unique<Mago>("Mago1");
	else p1 = make_unique<Arqueiro>("Arqueiro1");

	cout << "Jogador 2, escolha sua classe:\n1-Guerreiro 2-Mago 3-Arqueiro\nOpcao: ";
	cin >> escolha;
	if (escolha == 1) p2 = make_unique<Guerreiro>("Guerreiro2");
	else if (escolha == 2) p2 = make_unique<Mago>("Mago2");
	else p2 = make_unique<Arqueiro>("Arqueiro2");

	// Adiciona itens de exemplo na mochila
	p1->inserirItem(new PocaoCura());
	p1->inserirItem(new PocaoForca());
	p2->inserirItem(new PocaoCura());
	p2->inserirItem(new PocaoForca());

	int turno = 1;

	// Loop principal do jogo
	// O loop continua enquanto ambos os personagens estiverem vivos
	while (p1->vida > 0 && p2->vida > 0) {
		// aqui exibe o status de ambos os personagens
		cout << "\n--- Turno " << turno << " ---\n";
		p1->exibirStatus();
		p2->exibirStatus();

		// Jogador 1
		cout << "\nJogador 1 (" << p1->nome << "), escolha:\n1-Atacar\n2-Habilidade Especial\n3-Usar Item\nOpcao: ";
		cin >> escolha;
		if (escolha == 1) {
			p1->atacar(*p2);
		}
		else if (escolha == 2) {
			Mago* mago = dynamic_cast<Mago*>(p1.get());
			if (mago) mago->usarHabilidadeEspecial(*p2);
			else p1->usarHabilidadeEspecial(*p2);
		}
		else if (escolha == 3) {
			p1->exibirStatus();
			cout << "Escolha a posição do item para usar (0-2): ";
			int pos; cin >> pos;
			p1->usarItem(pos);
		}

		if (p2->vida <= 0) break;

		// Jogador 2
		cout << "\nJogador 2 (" << p2->nome << "), escolha:\n1-Atacar\n2-Habilidade Especial\n3-Usar Item\nOpcao: ";
		cin >> escolha;
		if (escolha == 1) {
			p2->atacar(*p1);
		}
		else if (escolha == 2) {
			Mago* mago = dynamic_cast<Mago*>(p2.get());
			if (mago) mago->usarHabilidadeEspecial(*p1);
			else p2->usarHabilidadeEspecial(*p1);
		}
		else if (escolha == 3) {
			p2->exibirStatus();
			cout << "Escolha a posição do item para usar (0-2): ";
			int pos; cin >> pos;
			p2->usarItem(pos);
		}

		turno++;
	}

	cout << "\n--- FIM DE JOGO ---\n";
	if (p1->vida > 0)
		cout << p1->nome << " venceu!\n";
	else
		cout << p2->nome << " venceu!\n";
	return 0;
}
