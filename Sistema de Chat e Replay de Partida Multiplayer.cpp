#include "Aulas.h"
#include <iostream>
#include <vector>
#include <string>
#include"Sistema de Matchmaking Multiplayer.cpp"
using namespace std;

class Mensagem {
private:
    string remetente;
    string texto;

public:
    Mensagem(string r, string t) : remetente(r), texto(t) {}

    void exibir() const {
        cout << remetente << ": " << texto << endl;
    }
};

class Chat {
private:
    vector<Mensagem> mensagens;

public:
    void enviarMensagem(string remetente) {
        string texto;
        cout << "Digite a mensagem: ";
        cin.ignore(); // limpa o buffer
        getline(cin, texto);

        Mensagem novaMensagem(remetente, texto);
        mensagens.push_back(novaMensagem);

        cout << "Mensagem enviada com sucesso!" << endl;
    }

    void mostrarMensagens() {
        if (mensagens.empty()) {
            cout << "Nenhuma mensagem no chat ainda." << endl;
            return;
        }

        cout << "\n=== Histórico de mensagens ===" << endl;
        for (const auto& msg : mensagens) {
            msg.exibir();
        }
    }
};
class replay
{
    vector<string>Eventos;

    void registrarEventos(string descricao)
    {
        Eventos.push_back(descricao);
        cout << "Evento registrado: " << descricao << endl;


    }
    void MostrarReplay()
    {
        cout << "Replay";
     }
};
class Partida : public Matchmaking
{

    void EnviarMensagemTimeA(string nome, string texto)
    {
        cout << "Digite seu nome";
        cin >> nome;
        getline(cin, nome);
        cout << "Digite a mensagem: ";
        cin.ignore(); // limpa o buffer
        getline(cin, texto);

    }
    void EnviarMensagemTimeA(string nome, string texto)
    {
        cout << "Digite seu nome";
        cin >> nome;
        getline(cin, nome);
        cout << "Digite a mensagem: ";
        cin.ignore(); // limpa o buffer
        getline(cin, texto);


    
    
};

