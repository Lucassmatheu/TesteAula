#include <iostream>
#include <string>
using namespace std;

// Declaração antecipada para uso em métodos de Inimigo
class Personagem;

// Classe Inimigo (declarada antes de Personagem)
class Inimigo {
private:
    string tipo;
    int forca;
    int xpRecompensa;

public:
    Inimigo(string t, int f, int xp) : tipo(t), forca(f), xpRecompensa(xp) {}
    int getForca() const { return forca; }
    int getXpRecompensa() const { return xpRecompensa; }
    string getTipo() const { return tipo; }

    void atacar(Personagem& p);
    void derrotar(Personagem& p);
    void fugir(Personagem& p);
    void mostrarInfo();
};

// Classe Personagem
class Personagem {
private:
    string nome;
    int energia;
    int xp;
    int nivel;

public:
    Personagem(string n) : nome(n), energia(100), xp(0), nivel(1) {}

    string getNome() const { return nome; }
    int getEnergia() const { return energia; }
    int getXp() const { return xp; }
    int getNivel() const { return nivel; }

    void explorar() {
        if (energia >= 10) {
            energia -= 10;
            xp += 20;
            cout << nome << " explorou e ganhou 20 de XP!" << endl;
            verificarNivel();
        }
        else {
            cout << nome << " está sem energia para explorar!" << endl;
        }
    }

    void atacar() {
        if (energia >= 15) {
            energia -= 15;
            xp += 30;
            cout << nome << " atacou e ganhou 30 de XP!" << endl;
            verificarNivel();
        }
        else {
            cout << nome << " está sem energia para atacar!" << endl;
        }
    }

    void defender() {
        if (energia >= 5) {
            energia -= 5;
            xp += 10;
            cout << nome << " defendeu e ganhou 10 de XP!" << endl;
            verificarNivel();
        }
        else {
            cout << nome << " está sem energia para defender!" << endl;
        }
    }

    void descansar() {
        energia += 40;
        if (energia > 100) energia = 100;
        cout << nome << " descansou e recuperou energia!" << endl;
    }

    void verificarNivel() {
        if (xp >= 100) {
            nivel++;
            xp -= 100; // para evitar subir infinitamente com o mesmo XP
            cout << nome << " subiu para o nível " << nivel << "!" << endl;
        }
    }

    void Batalhar() {
        int acao;
        if (energia >= 20) {
            energia -= 30;
            xp += 20;
            Inimigo inimigo("Goblin", 15, 20);
            inimigo.mostrarInfo();
            inimigo.atacar(*this);
            inimigo.derrotar(*this);
            inimigo.fugir(*this);

            do {
                cout << "Escolha uma ação:\n1-Atacar\n2-Defender\n3-Explorar\n4-Sair\nOpção: ";
                cin >> acao;
                switch (acao) {
                case 1: atacar(); break;
                case 2: defender(); break;
                case 3: explorar(); break;
                case 4: cout << "Saindo da batalha..." << endl; return;
                default: cout << "Ação inválida. Tente novamente." << endl;
                }
            } while (acao != 4);

            cout << nome << " batalhou e ganhou 50 de XP!" << endl;
            verificarNivel();
        }
        else {
            cout << nome << " está sem energia para batalhar!" << endl;
        }
    }
};

// Implementações da classe Inimigo que dependem de Personagem
void Inimigo::atacar(Personagem& p) {
    cout << tipo << " atacou " << p.getNome() << " causando " << forca << " de dano!" << endl;
}
void Inimigo::derrotar(Personagem& p) {
    p.explorar();
    cout << p.getNome() << " derrotou o " << tipo << " e ganhou " << xpRecompensa << " de XP!" << endl;
}
void Inimigo::fugir(Personagem& p) {
    cout << p.getNome() << " fugiu do " << tipo << "!" << endl;
}
void Inimigo::mostrarInfo() {
    cout << "Inimigo: " << tipo << ", Força: " << forca << ", XP Recompensa: " << xpRecompensa << endl;
}

// Subclasses dos heróis
class mago : public Personagem {
public:
    mago(string n) : Personagem(n) {}

    void bonusXp() {
        if (getXp() % 2 == 0) {
            int bonus = 5;
            cout << getNome() << " recebeu um bônus de " << bonus << " XP por ser mago!" << endl;
        }
    }

    void atacar() { bonusXp(); Personagem::atacar(); }
    void explorar() { bonusXp(); Personagem::explorar(); }
    void defender() { bonusXp(); Personagem::defender(); }
};

class guerreiro : public Personagem {
public:
    guerreiro(string n) : Personagem(n) {}

    void bonusXP() {
        if (getXp() % 2 == 0) {
            int bonus = 10;
            cout << getNome() << " recebeu um bônus de " << bonus << " energia por ser guerreiro!" << endl;
        }
    }

    void atacar() { getXp(); Personagem::atacar(); }
    void explorar() { getXp(); Personagem::explorar(); }
    void descansar() { getXp(); Personagem::descansar(); }
    void defender() { getXp(); Personagem::defender(); }
};

class arqueiro : public Personagem {
public:
    arqueiro(string n) : Personagem(n) {}

    void bonusXP() {
        if (getXp() % 2 == 0) {
            int bonus = 7;
            cout << getNome() << " recebeu um bônus de " << bonus << " energia por ser arqueiro!" << endl;
        }
    }

    void atacar() { getXp(); Personagem::atacar(); }
    void explorar() { getXp(); Personagem::explorar(); }
    void defender() { getXp(); Personagem::defender(); }
};

// Menu principal de luta
void menuLuta() {
    int escolha;
    do {
        cout << "\nEscolha sua classe:\n1 - Guerreiro\n2 - Mago\n3 - Arqueiro\n4 - Sair\nOpção: ";
        cin >> escolha;

        if (escolha >= 1 && escolha <= 3) {
            string nome;
            cout << "Digite o nome do seu herói: ";
            cin >> nome;

            Personagem* heroi;

            if (escolha == 1) heroi = new guerreiro(nome);
            else if (escolha == 2) heroi = new mago(nome);
            else heroi = new arqueiro(nome);

            int acao;
            do {
                cout << "\nEscolha uma ação:\n1 - Explorar\n2 - Atacar\n3 - Defender\n4 - Batalhar\n5 - Descansar\n6 - Sair\nOpção: ";
                cin >> acao;

                switch (acao) {
                case 1: heroi->explorar(); break;
                case 2: heroi->atacar(); break;
                case 3: heroi->defender(); break;
                case 4: heroi->Batalhar(); break;
                case 5: heroi->descansar(); break;
                case 6: cout << "Saindo do jogo..." << endl; break;
                default: cout << "Opção inválida!" << endl;
                }

            } while (acao != 6);

            delete heroi;
        }
        else if (escolha == 4) {
            cout << "Saindo do jogo..." << endl;
            break;
        }
        else {
            cout << "Opção inválida! Tente novamente." << endl;
        }

    } while (escolha != 4);
}


