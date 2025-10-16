#include <iostream>
#include <string>
using namespace std;

// Classe base
class Personagem {
public:
    string nome;
    int vida;
    int ataque;
    int defesa;
public:
    Personagem(string n, int v, int a, int d)
        : nome(n), vida(v), ataque(a), defesa(d) {
    }

    virtual void atacar(Personagem& alvo) {
        int dano = ataque - alvo.defesa;
        if (dano < 0) dano = 0;
        alvo.vida -= dano;
        cout << nome << " atacou " << alvo.nome << " causando " << dano << " de dano!" << endl;
    }

    virtual void exibirStatus() const {
        cout << "\n[" << nome << "]" << endl;
        cout << "Vida: " << vida << " | Ataque: " << ataque << " | Defesa: " << defesa << endl;
    }

    bool estaVivo() const {
        return vida > 0;
    }

    string getNome() const {
        return nome;
    }

    virtual void receberDano(int dano) {
        vida -= dano;
    }
};

// Classe derivada Guerreiro
class Guerreiro : public Personagem {
public:
    Guerreiro() : Personagem("Guerreiro", 120, 20, 10) {}

    void atacar(Personagem& alvo) override {
        cout << nome << " usa Espada Poderosa!" << endl;
        Personagem::atacar(alvo);
    }
};

// Classe derivada Mago
class Mago : public Personagem {
private:
    int magiaExtra = 15;
public:
	//Aqui o mago tem menos vida e defesa, mas seu ataque é aumentado por magiaExtra
    Mago() : Personagem("Mago", 80, 30, 5) {}


    void atacar(Personagem& alvo) override {
        cout << nome << " lança uma Bola de Fogo!" << endl;
        int dano = ataque + magiaExtra - alvo.defesa;
        if (dano < 0) dano = 0;
        alvo.receberDano(dano);
    }
};

// Classe derivada Arqueiro
class Arqueiro : public Personagem {
private:
    int chanceCritico = 20;
public:
    Arqueiro() : Personagem("Arqueiro", 100, 25, 7) {}

    void atacar(Personagem& alvo) override {
        cout << nome << " dispara uma flecha precisa!" << endl;
        int dano = ataque + chanceCritico - alvo.defesa;
        if (dano < 0) dano = 0;
        alvo.receberDano(dano);
    }
};

// Função principal
void batalha() {
    Personagem* jogador = nullptr;
    Guerreiro guerreiro;
    Mago mago;
    Arqueiro arqueiro;

    cout << "Escolha seu personagem:\n";
    cout << "[1] Guerreiro\n[2] Mago\n[3] Arqueiro\nOpção: ";
    int escolha;
    cin >> escolha;

    switch (escolha) {
    case 1: jogador = &guerreiro; break;
    case 2: jogador = &mago; break;
    case 3: jogador = &arqueiro; break;
    default: cout << "Opção inválida."; return;
    }

    Personagem inimigo("Goblin", 90, 18, 6);

    int opcao;
    do {
        cout << "\n--- MENU DE BATALHA ---\n";
        cout << "[1] Atacar\n[2] Exibir Status\n[3] Sair\nEscolha: ";
        cin >> opcao;

        switch (opcao) {
        case 1:
            jogador->atacar(inimigo);
            if (!inimigo.estaVivo()) {
                cout << "O inimigo foi derrotado!\n";
                break;
            }
            inimigo.atacar(*jogador);
            if (!jogador->estaVivo()) {
                cout << "Você foi derrotado!\n";
            }
            break;
        case 2:
            jogador->exibirStatus();
            inimigo.exibirStatus();
            break;
        case 3:
            cout << "Saindo da batalha...\n";
            break;
        default:
            cout << "Opção inválida.\n";
        }

    } while (opcao != 3 && jogador->estaVivo() && inimigo.estaVivo());

    return ;
}
