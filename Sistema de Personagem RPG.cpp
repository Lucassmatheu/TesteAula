#include <iostream>
using std::cout;
using std::endl;
using std::cin; 

#include "Aulas.h"

class Personagem
{
private:
    std::string nome;
    int vida;
    int ataque;
    int defesa;
    int defesaOriginal; // Para restaurar defesa após defesa temporária

public:
    // Construtor
    Personagem(const std::string& nome, int vida, int ataque, int defesa)
        : nome(nome), vida(vida), ataque(ataque), defesa(defesa), defesaOriginal(defesa) {}

    // Exibe os atributos do personagem
    void exibirStatus() const {
        cout << "Nome: " << nome << endl;
        cout << "Vida: " << vida << endl;
        cout << "Ataque: " << ataque << endl;
        cout << "Defesa: " << defesa << endl;
    }

    // Ataca outro personagem
    void atacar(Personagem& alvo) {
        int dano = ataque - alvo.defesa;
        if (dano > 0) {
            alvo.vida -= dano;
            cout << nome << " atacou " << alvo.nome << " causando " << dano << " de dano!" << endl;
        } else {
            cout << nome << " atacou " << alvo.nome << " mas não causou dano." << endl;
        }
    }

    // Verifica se está vivo
    bool estaVivo() const {
        return vida > 0;
    }

    // Retorna o nome do personagem
    std::string getNome() const {
        return nome;
    }

    // Aumenta temporariamente a defesa para o próximo ataque
    void defenderTemporariamente() {
        defesa += 10;
        cout << nome << " está defendendo! Defesa aumentada temporariamente." << endl;
    }

    // Após ser atacado, restaura a defesa original
    void restaurarDefesa() {
        defesa = defesaOriginal;
    }
};

int main() {
    Personagem heroi("Lucas", 100, 30, 10);
    Personagem inimigo("Orc", 80, 25, 5);

    int opcao;

    do {
        cout << "\n=== Batalha RPG ===" << endl;
        cout << "[1] Atacar\n[2] Defender\n[3] Exibir Status\n[4] Sair\nEscolha: ";
        cin >> opcao;

        switch (opcao) {
        case 1:
            heroi.atacar(inimigo);
            if (!inimigo.estaVivo()) {
                cout << inimigo.getNome() << " foi derrotado!" << endl;
                break;
            }
            inimigo.atacar(heroi);
            if (!heroi.estaVivo()) {
                cout << heroi.getNome() << " foi derrotado!" << endl;
            }
            break;

        case 2:
            heroi.  defenderTemporariamente();
            inimigo.atacar(heroi);
            heroi.restaurarDefesa(); // Restaura defesa após ataque
            break;

        case 3:
            heroi.exibirStatus();
            inimigo.exibirStatus();
            break;

        case 4:
            cout << "Saindo da batalha..." << endl;
            break;

        default:
            cout << "Opcao invalida!" << endl;
        }
    } while (opcao != 4 && heroi.estaVivo() && inimigo.estaVivo());

    return 0;
}
