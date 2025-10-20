#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // rand()
#include <ctime>   // time()
#include <algorithm>
using namespace std;

// =============================================
// CLASSE JOGADOR
// =============================================
class Jogador {
private:
    string nome;
    int nivel;
    bool emPartida;
    int partidasJogadas;
    int vitorias;
    int derrotas;
    int mmr; // Matchmaking Rating

public:
    Jogador(string n, int nv)
        : nome(n), nivel(nv), emPartida(false),
        partidasJogadas(0), vitorias(0), derrotas(0), mmr(1000) {
    }

    string getNome() const { return nome; }
    int getNivel() const { return nivel; }
    int getMMR() const { return mmr; }
    bool estaEmPartida() const { return emPartida; }

    void entrarFila() {
        cout << nome << " entrou na fila de matchmaking." << endl;
    }

    void entrarPartida() {
        emPartida = true;
        partidasJogadas++;
    }

    void sairPartida() {
        emPartida = false;
    }

    void adicionarVitoria() {
        vitorias++;
        mmr += 25;
    }

    void adicionarDerrota() {
        derrotas++;
        mmr -= 10;
        if (mmr < 0) mmr = 0;
    }

    void mostrarStatus() const {
        cout << nome << " | Nível: " << nivel << " | MMR: " << mmr
            << " | V: " << vitorias << " | D: " << derrotas << endl;
    }
};

// =============================================
// CLASSE MATCHMAKING
// =============================================
class Matchmaking {
private:
    vector<Jogador> filaDeEspera;
    vector<Jogador> timeA;
    vector<Jogador> timeB;

public:
    void adicionarFila(Jogador j) {
        filaDeEspera.push_back(j);
        j.entrarFila();
    }

    void mostrarFila() const {
        if (filaDeEspera.empty()) {
            cout << "Fila de espera vazia." << endl;
            return;
        }
        cout << "\n=== Jogadores na Fila ===" << endl;
        for (const auto& j : filaDeEspera) {
            j.mostrarStatus();
        }
    }

    void procurarPartida() {
        if (filaDeEspera.size() < 8) {
            cout << "Aguardando mais jogadores... (" << filaDeEspera.size() << "/8)" << endl;
            return;
        }

        // Ordena por MMR (jogadores mais equilibrados)
        sort(filaDeEspera.begin(), filaDeEspera.end(),
            [](const Jogador& a, const Jogador& b) { return a.getMMR() > b.getMMR(); });

        // Monta os times (4 melhores vs 4 seguintes)
        for (int i = 0; i < 4; i++)
            timeA.push_back(filaDeEspera[i]);
        for (int i = 4; i < 8; i++)
            timeB.push_back(filaDeEspera[i]);

        cout << "\n=== Partida Encontrada! ===" << endl;
        cout << "Time A:" << endl;
        for (auto& j : timeA) cout << "- " << j.getNome() << endl;
        cout << "\nTime B:" << endl;
        for (auto& j : timeB) cout << "- " << j.getNome() << endl;

        iniciarPartida();

        // Remove os 8 primeiros da fila
        filaDeEspera.erase(filaDeEspera.begin(), filaDeEspera.begin() + 8);
        timeA.clear();
        timeB.clear();
    }

    void iniciarPartida() {
        cout << "\n=== Iniciando a Partida ===" << endl;
        srand(time(0));
        int pontosA = 0, pontosB = 0;

        for (int i = 1; i <= 3; i++) {
            cout << "\nRodada " << i << "..." << endl;
            bool timeAVence = rand() % 2 == 0;
            if (timeAVence) {
                cout << "Time A venceu a rodada!" << endl;
                pontosA++;
            }
            else {
                cout << "Time B venceu a rodada!" << endl;
                pontosB++;
            }
        }

        cout << "\n=== Resultado Final ===" << endl;
        if (pontosA > pontosB) {
            cout << "🏆 Time A venceu a partida!" << endl;
            for (auto& j : timeA) j.adicionarVitoria();
            for (auto& j : timeB) j.adicionarDerrota();
        }
        else {
            cout << "🏆 Time B venceu a partida!" << endl;
            for (auto& j : timeB) j.adicionarVitoria();
            for (auto& j : timeA) j.adicionarDerrota();
        }
    }
};

// =============================================
// MENU PRINCIPAL
// =============================================
void menuMatchmaking() {
    Matchmaking sistema;
    int opcao;
    do {
        cout << "\n=== Sistema de Matchmaking ===\n";
        cout << "1. Adicionar jogador na fila\n";
        cout << "2. Mostrar fila de espera\n";
        cout << "3. Procurar partida\n";
        cout << "4. Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
        case 1: {
            string nome;
            int nivel;
            cout << "Digite o nome do jogador: ";
            cin >> nome;
            cout << "Digite o nivel do jogador (1-100): ";
            cin >> nivel;
            sistema.adicionarFila(Jogador(nome, nivel));
            break;
        }
        case 2:
            sistema.mostrarFila();
            break;
        case 3:
            sistema.procurarPartida();
            break;
        case 4:
            cout << "Saindo do matchmaking..." << endl;
            break;
        default:
            cout << "Opcao invalida!" << endl;
        }

    } while (opcao != 4);
}


