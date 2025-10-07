#include <iostream>
#include <string>
#include "Aulas.h"
#include <memory>
using namespace std;

class Personagem
{
public:
	string nome;
	int vida;
	int ataque; // Corrigido de 'atacar' para 'ataque'
	int defesa;

	public:
	Personagem(string n, int v, int a, int d)
		: nome(n), vida(v), ataque(a), defesa(d) {
	}


	void exibirStatus() const
	{
		cout << "\n[" << nome << "]" << endl;
		cout << "Vida: " << vida << " | Ataque: " << ataque << " | Defesa: " << defesa << endl;
	}
	virtual  void usarHabilidadeEspecial() 
	{

	}
	// Adicione o método atacar para Personagem base
	virtual void atacar(Personagem& alvo) {
		int dano = ataque - alvo.defesa;
		if (dano < 0) dano = 0;
		alvo.vida -= dano;
		cout << nome << " atacou " << alvo.nome << " causando " << dano << " de dano!" << endl;
	}
    // Adicione o método receberDano para compatibilidade com Mago/Arqueiro
    virtual void receberDano(int dano) {
        vida -= dano;
    }
};
// Classe derivada Guerreiro
class Guerreiro : public Personagem {
public:
    Guerreiro(string n) : Personagem(n, 130, 22, 15) {}

    void atacar(Personagem& alvo) override {
        cout << nome << " usa Espada Poderosa!" << endl;
        Personagem::atacar(alvo);
    }

    void usarHabilidadeEspecial() override {
        defesa += 10;
        cout << nome << " usou Habilidade Especial: Defesa aumentada para " << defesa << "!\n";
    }
};

// Classe derivada Mago
class Mago : public Personagem {
private:
    int magiaExtra = 15;
public:
    Mago(string n) : Personagem(n, 85, 28, 6) {}

    void atacar(Personagem& alvo) override {
        cout << nome << " lança uma Bola de Fogo!" << endl;
        int dano = ataque + magiaExtra - alvo.defesa;
        if (dano < 0) dano = 0;
        alvo.receberDano(dano);
    }

    void usarHabilidadeEspecial(Personagem& alvo) {
        int dano = 25;
        alvo.receberDano(dano);
        cout << nome << " usou Habilidade Especial: " << alvo.nome << " perdeu " << dano << " de vida!\n";
    }
};

// Classe derivada Arqueiro
class Arqueiro : public Personagem {
private:
    int chanceCritico = 20;
public:
	// Aqui o ataque base é 27
    
    Arqueiro(string n) : Personagem(n, 95, 27, 8) {}

	// Ataque com chance de crítico
    void atacar(Personagem& alvo) override {
		// Simula um ataque com chance de crítico
        cout << nome << " dispara uma flecha precisa!" << endl;
		// Adiciona chance de crítico ao ataque
        int dano = ataque + chanceCritico - alvo.defesa;
        if (dano < 0) dano = 0;
        alvo.receberDano(dano);
    }

    void usarHabilidadeEspecial() override {
        cout << nome << " usou Habilidade Especial: Ataque dobrado! (" << ataque * 2 << " de ataque neste turno)\n";
    }
};

bool estaVivo(const Personagem* p) {
    return p->vida > 0;
}

int main() {
    // Exemplo: escolha polimórfica dos personagens
    unique_ptr<Personagem> p1, p2;
    int escolha;

    cout << "Escolha a classe do Jogador 1:\n1-Guerreiro 2-Mago 3-Arqueiro\nOpcao: ";
    cin >> escolha;
    if (escolha == 1) p1 = make_unique<Guerreiro>("Guerreiro1");
    else if (escolha == 2) p1 = make_unique<Mago>("Mago1");
    else p1 = make_unique<Arqueiro>("Arqueiro1");

    cout << "Escolha a classe do Jogador 2:\n1-Guerreiro 2-Mago 3-Arqueiro\nOpcao: ";
    cin >> escolha;
    if (escolha == 1) p2 = make_unique<Guerreiro>("Guerreiro2");
    else if (escolha == 2) p2 = make_unique<Mago>("Mago2");
    else p2 = make_unique<Arqueiro>("Arqueiro2");

    int turno = 1;
    while (estaVivo(p1.get()) && estaVivo(p2.get())) {
        cout << "\n--- Turno " << turno << " ---\n";
        p1->exibirStatus();
        p2->exibirStatus();

        // Jogador 1
        cout << "\nJogador 1 (" << p1->nome << "), escolha: 1-Atacar 2-Habilidade: ";
        cin >> escolha;
        if (escolha == 1) p1->atacar(*p2);
        else {
            // Para Mago, habilidade especial precisa de alvo
            Mago* mago = dynamic_cast<Mago*>(p1.get());
            if (mago) mago->usarHabilidadeEspecial(*p2);
            else p1->usarHabilidadeEspecial();
        }
        if (!estaVivo(p2.get())) break;

        // Jogador 2
        cout << "\nJogador 2 (" << p2->nome << "), escolha: 1-Atacar 2-Habilidade: ";
        cin >> escolha;
        if (escolha == 1) p2->atacar(*p1);
        else {
            Mago* mago = dynamic_cast<Mago*>(p2.get());
            if (mago) mago->usarHabilidadeEspecial(*p1);
            else p2->usarHabilidadeEspecial();
        }
        turno++;
    }

    cout << "\n--- FIM DE JOGO ---\n";
    if (estaVivo(p1.get()))
        cout << p1->nome << " venceu!\n";
    else
        cout << p2->nome << " venceu!\n";

    return 0;
}