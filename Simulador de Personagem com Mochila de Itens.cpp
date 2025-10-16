#include <iostream>
#include <string>
using namespace std;

// Classe abstrata Item
class Personagem;

// Classe base
class Item {
public:
    virtual void usar(Personagem& p) = 0;
    virtual string nome() const = 0;
    virtual ~Item() {}
};

// Classes derivadas
class PocaoCura : public Item {
public:
    void usar(Personagem& p) override;
    string nome() const override { return "Pocao de Cura"; }
};

class PocaoForca : public Item {
public:
    void usar(Personagem& p) override;
    string nome() const override { return "Pocao de Forca"; }
};

// Classe Personagem
class Personagem {
    string nome;
    int vida;
    int ataque;
    int defesa;
    Item* mochila[3];
public:
    Personagem(string n, int v, int a, int d) : nome(n), vida(v), ataque(a), defesa(d) {
        for (int i = 0; i < 3; ++i) mochila[i] = nullptr;
    }
    ~Personagem() {
        for (int i = 0; i < 3; ++i) delete mochila[i];
    }
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
    void exibirStatus() const {
        cout << "Nome: " << nome << "\nVida: " << vida << "\nAtaque: " << ataque << "\nDefesa: " << defesa << endl;
        cout << "Mochila: ";
        for (int i = 0; i < 3; ++i) {
            if (mochila[i]) cout << "[" << i << "] " << mochila[i]->nome() << "  ";
        }
        cout << endl;
    }
    // Métodos para modificar atributos
    void curar(int v) { vida += v; cout << nome << " curou " << v << " de vida!\n"; }
    void aumentarForca(int v) { ataque += v; cout << nome << " ganhou +" << v << " de ataque!\n"; }
};

// Implementação dos métodos usar()
void PocaoCura::usar(Personagem& p) { p.curar(20); }
void PocaoForca::usar(Personagem& p) { p.aumentarForca(10); }

// Exemplo de uso
void ain() {
    Personagem p("Lucas", 100, 20, 10);
    p.inserirItem(new PocaoCura());
    p.inserirItem(new PocaoForca());
    p.exibirStatus();
    p.usarItem(0);
    p.exibirStatus();
    p.usarItem(1);
    p.exibirStatus();
    return ;
}