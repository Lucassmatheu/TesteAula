#include "Aulas.h"
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

// ========================================
// CLASSE MENSAGEM
// ========================================
class Mensagem {
private:
    string remetente;
    string texto;

public:
    Mensagem(string r, string t) : remetente(r), texto(t) {}

    void exibir() const {
        cout << "[" << remetente << "]: " << texto << endl;
    }
};

// ========================================
// CLASSE CHAT
// ========================================
class Chat {
private:
    vector<Mensagem> mensagens;

public:
    void enviarMensagem(string remetente) {
        string texto;
        cout << "Digite a mensagem: ";
        cin.ignore(); // limpar buffer
        getline(cin, texto);

        mensagens.push_back(Mensagem(remetente, texto));
        cout << "Mensagem enviada com sucesso!" << endl;
    }

    void mostrarMensagens() const {
        if (mensagens.empty()) {
            cout << "\nNenhuma mensagem no chat ainda.\n";
            return;
        }

        cout << "\n=== Histórico de Mensagens ===\n";
        for (const auto& msg : mensagens)
            msg.exibir();
    }
};

// ========================================
// CLASSE REPLAY
// ========================================
class Replay {
private:
    vector<string> eventos;

public:
    void registrarEvento(string descricao) {
        eventos.push_back(descricao);
        cout << "Evento registrado: " << descricao << endl;
    }

    void mostrarReplay() const {
        cout << "\n=== REPLAY DA PARTIDA ===\n";
        for (const auto& e : eventos)
            cout << "- " << e << endl;
    }
};

// ========================================
// CLASSE PARTIDA
// ========================================
class Partida {
private:
    vector<string> timeA;
    vector<string> timeB;
    Chat chat;
    Replay replay;
    bool partidaAtiva = false;

public:
    void adicionarJogadorTimeA(string nome) {
        if (timeA.size() < 4) {
            timeA.push_back(nome);
            cout << nome << " entrou no Time A.\n";
        }
        else {
            cout << "Time A está cheio!\n";
        }
    }

    void adicionarJogadorTimeB(string nome) {
        if (timeB.size() < 4) {
            timeB.push_back(nome);
            cout << nome << " entrou no Time B.\n";
        }
        else {
            cout << "Time B está cheio!\n";
        }
    }

    void enviarMensagemTimeA() {
        if (timeA.empty()) {
            cout << "Time A ainda não tem jogadores.\n";
            return;
        }

        string nome;
        cout << "Quem está enviando a mensagem (Time A)? ";
        cin >> nome;
        chat.enviarMensagem(nome);
        replay.registrarEvento(nome + " enviou uma mensagem (Time A)");
    }

    void enviarMensagemTimeB() {
        if (timeB.empty()) {
            cout << "Time B ainda não tem jogadores.\n";
            return;
        }

        string nome;
        cout << "Quem está enviando a mensagem (Time B)? ";
        cin >> nome;
        chat.enviarMensagem(nome);
        replay.registrarEvento(nome + " enviou uma mensagem (Time B)");
    }

    void simularEventoCombate() {
        if (!partidaAtiva) {
            cout << "A partida ainda não foi iniciada!\n";
            return;
        }

        srand(time(0));
        int vencedor = rand() % 2;
        string evento;

        if (vencedor == 0) {
            evento = "Time A dominou a área central!";
        }
        else {
            evento = "Time B eliminou um inimigo!";
        }

        replay.registrarEvento(evento);
    }

    void iniciarPartida() {
        if (timeA.size() < 2 || timeB.size() < 2) {
            cout << "É necessário pelo menos 2 jogadores em cada time para iniciar.\n";
            return;
        }

        partidaAtiva = true;
        replay.registrarEvento("Partida iniciada!");
        cout << "\n=== Partida Iniciada ===\n";
    }

    void mostrarReplayFinal() const {
        replay.mostrarReplay();
    }

    void mostrarChat() const {
        chat.mostrarMensagens();
    }
};

// ========================================
// MENU PRINCIPAL
// ========================================
void menuChatReplay() {
    Partida partida;
    int opcao;
    do {
        cout << "\n=== Simulador Multiplayer com Chat e Replay ===\n";
        cout << "1. Adicionar jogador no Time A\n";
        cout << "2. Adicionar jogador no Time B\n";
        cout << "3. Enviar mensagem (Time A)\n";
        cout << "4. Enviar mensagem (Time B)\n";
        cout << "5. Iniciar partida\n";
        cout << "6. Simular evento de combate\n";
        cout << "7. Mostrar chat\n";
        cout << "8. Mostrar replay final\n";
        cout << "9. Sair\n";
        cout << "Escolha: ";
        cin >> opcao;

        switch (opcao) {
        case 1: {
            string nome;
            cout << "Nome do jogador: ";
            cin >> nome;
            partida.adicionarJogadorTimeA(nome);
            break;
        }
        case 2: {
            string nome;
            cout << "Nome do jogador: ";
            cin >> nome;
            partida.adicionarJogadorTimeB(nome);
            break;
        }
        case 3:
            partida.enviarMensagemTimeA();
            break;
        case 4:
            partida.enviarMensagemTimeB();
            break;
        case 5:
            partida.iniciarPartida();
            break;
        case 6:
            partida.simularEventoCombate();
            break;
        case 7:
            partida.mostrarChat();
            break;
        case 8:
            partida.mostrarReplayFinal();
            break;
        case 9:
            cout << "Encerrando sistema..." << endl;
            break;
        default:
            cout << "Opção inválida!\n";
        }
    } while (opcao != 9);
}

// ========================================
// FUNÇÃO PRINCIPAL
// ========================================

