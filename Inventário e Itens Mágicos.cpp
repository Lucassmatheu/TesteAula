#include <iostream>
#include <string>
#include "Aulas.h"
using namespace std;

class HeroiMagicos {
private:
    string nome;
    int vida;
    int ataque;
    int defesa;

public:
    HeroiMagicos(string n, int v, int a, int d)
        : nome(n), vida(v), ataque(a), defesa(d) {
    }

    void receberDano(int dano) {
        vida -= dano;
        if (vida < 0) vida = 0;
    }

    virtual void atacar(HeroiMagicos& inimigo) {
        int dano = ataque - inimigo.defesa;
        if (dano < 0) dano = 0;
        inimigo.receberDano(dano);
        cout << nome << " atacou " << inimigo.nome << " causando " << dano << " de dano!" << endl;
    }

    virtual void AtaqueMagicos(HeroiMagicos& inimigo) {
        cout << nome << " usou um ataque magico especial!" << endl;
        int dano = ataque + 25;
        inimigo.receberDano(dano);
        cout << nome << " causou " << dano << " de dano magico!" << endl;
    }

    void escudoMistico(int aumento) {
        defesa += aumento;
        cout << nome << " ativou Escudo Mistico! Defesa aumentada para " << defesa << "!" << endl;
    }

    string getNome() const { return nome; }
    int getVida() const { return vida; }
    int getAtaque() const { return ataque; }
    int getDefesa() const { return defesa; }
};

// ----------------------- Classes Derivadas -----------------------

class GuerreiroMagicos : public HeroiMagicos {
public:
    GuerreiroMagicos(string n) : HeroiMagicos(n, 150, 30, 25) {}

    void atacar(HeroiMagicos& alvo) override {
        cout << getNome() << " desferiu um golpe poderoso!" << endl;
        HeroiMagicos::atacar(alvo);
    }

    void AtaqueMagicos(HeroiMagicos& alvo) override {
        cout << getNome() << " concentrou energia e desferiu um ataque magico devastador!" << endl;
        int dano = getAtaque() + 15;
        alvo.receberDano(dano);
        cout << getNome() << " causou " << dano << " de dano magico!" << endl;
    }
};

class MagoMagicos : public HeroiMagicos {
public:
    MagoMagicos(string n) : HeroiMagicos(n, 100, 50, 10) {}

    void atacar(HeroiMagicos& alvo) override {
        cout << getNome() << " lançou uma bola de fogo!" << endl;
        HeroiMagicos::atacar(alvo);
    }

    void AtaqueMagicos(HeroiMagicos& alvo) override {
        cout << getNome() << " conjurou um feitiço explosivo!" << endl;
        int dano = getAtaque() + 30;
        alvo.receberDano(dano);
        cout << getNome() << " causou " << dano << " de dano magico!" << endl;
    }
};

class ArqueiroMagicos : public HeroiMagicos {
public:
    ArqueiroMagicos(string n) : HeroiMagicos(n, 120, 40, 15) {}

    void atacar(HeroiMagicos& alvo) override {
        cout << getNome() << " disparou uma flecha encantada!" << endl;
        HeroiMagicos::atacar(alvo);
    }

    void AtaqueMagicos(HeroiMagicos& alvo) override {
        cout << getNome() << " concentrou energia em sua flecha e disparou um tiro magico!" << endl;
        int dano = getAtaque() + 20;
        alvo.receberDano(dano);
        cout << getNome() << " causou " << dano << " de dano magico!" << endl;
    }
};

// ----------------------- Sistema de Luta -----------------------

 void menuMagicos() {
    int escolha;
    HeroiMagicos inimigo("Goblin", 80, 40, 20);

    cout << "Escolha sua classe magica:\n1-Guerreiro Magico\n2-Mago Magico\n3-Arqueiro Magico\n4-Sair\nOpcao: ";
    cin >> escolha;

    if (escolha == 4) {
        cout << "Saindo do jogo..." << endl;
        return;
    }

    // Criação dinâmica da classe escolhida
    HeroiMagicos* jogador = nullptr;
    if (escolha == 1) jogador = new GuerreiroMagicos("Guerreiro Magico");
    else if (escolha == 2) jogador = new MagoMagicos("Mago Magico");
    else if (escolha == 3) jogador = new ArqueiroMagicos("Arqueiro Magico");
    else {
        cout << "Opcao invalida!" << endl;
        return;
    }

    int opcao;
    do {
        cout << "\nEscolha uma acao:\n1. Atacar\n2. Ataque Magico\n3. Usar Escudo Mistico\n4. Sair\n";
        cin >> opcao;

        switch (opcao) {
        case 1:
            jogador->atacar(inimigo);
            break;
        case 2:
            jogador->AtaqueMagicos(inimigo);
            break;
        case 3:
            jogador->escudoMistico(15);
            break;
        case 4:
            cout << "Saindo da batalha..." << endl;
            break;
        default:
            cout << "Opcao invalida!" << endl;
        }

        cout << "\nVida do inimigo (" << inimigo.getNome() << "): " << inimigo.getVida() << endl;

        if (inimigo.getVida() <= 0) {
            cout << "\n" << inimigo.getNome() << " foi derrotado!" << endl;
            break;
        }

    } while (opcao != 4);

    delete jogador;
}
