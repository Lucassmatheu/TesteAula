#include "Aulas.h"
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <chrono>

using namespace std;

// ====================== CLASSE SERVIDOR ======================
class Servidor
{
    string nome;
    bool online;

public:
    Servidor(string n) : nome("Servidor padrão"), online(false) {}

    string getNome() const { return nome; }
    bool EstaOnline() const { return online; }

    void IniciarServidor()
    {
        online = true;
        cout << nome << " iniciado com sucesso!" << endl;

        while (online)
        {
            cout << "Servidor rodando..." << endl;
            this_thread::sleep_for(chrono::seconds(2));
        }

        cout << nome << " foi encerrado." << endl;
    }

    void derrubarServidor()
    {
        if (online)
        {
            online = false;
            cout << "Servidor foi derrubado!" << endl;
        }
        else
        {
            cout << "Servidor ja estava offline." << endl;
        }
    }

    void statusServidor()
    {
        if (online == true)
        {
            cout << "Servidor esta online!" << endl;
        }
        else
        {
            cout << "Servidor esta offline!" << endl;
        }
    }

};

// ====================== CLASSE JOGADOR ======================
class JogadorOnline
{
    string NomeJogador;
    int ping;
    bool conectado;
    int contadorFalhas;


public:
    JogadorOnline(string nome = "Desconhecido", int p = 0)
        : NomeJogador(nome), ping(p), conectado(false), contadorFalhas(0) {
    }
    void incrementarFalhas() {
        contadorFalhas++;
    }


    string getNome() const { return NomeJogador; }
    int getPing() const { return ping; }
    bool isOnline() const { return conectado; }
    int getFalhas() const { return contadorFalhas; }


    void conectar(Servidor& servidor)
    {
        if (servidor.EstaOnline())
        {
            conectado = true;
            cout << NomeJogador << " conectou ao servidor " << servidor.getNome() << " com ping de " << ping << "ms!" << endl;
        }
        else
        {
            contadorFalhas++;
            cout << "Falha ao conectar: o servidor " << servidor.getNome() << " está offline." << endl;
        }
    }

    void desconectar()
    {
        if (conectado)
        {
            conectado = false;
            cout << NomeJogador << " foi desconectado do servidor." << endl;
        }
        else
        {
            cout << NomeJogador << " ja estava desconectado." << endl;
        }
    }

    void atualizarPing(int novoPing)
    {
        ping = novoPing;
        cout << NomeJogador << " atualizou o ping para " << ping << "ms." << endl;
    }
    
};

// ====================== CLASSE GERENCIAMENTO DE CONEXÕES ======================
class GerenciamentoDeConexao
{
private:
    vector<JogadorOnline> Jogadores;

public:
    GerenciamentoDeConexao()
    {
        srand(time(0));
    }

    void adicionarJogador(const JogadorOnline& jogador)
    {
        Jogadores.push_back(jogador);
    }

    void simularFalha()
    {
       


        if (Jogadores.empty())
        {
            cout << "Nenhum jogador conectado." << endl;
            return;
        }
        
        cout << "\nSimulando falhas de conexão..." << endl;

        for (auto& jogador : Jogadores)
        {
            int chanceFalha = rand() % 100; // número de 0 a 99

            if (chanceFalha < 30)
            {
                jogador.desconectar();
                cout << "⚠️  Conexão perdida com " << jogador.getNome() << "!" << endl;
            }
            else
            {
                cout << "✅ " << jogador.getNome() << " continua conectado." << endl;
            }
        }
    }

    void tentarReconectar(Servidor& servidor)
    {
        JogadorOnline* Jogador = nullptr;

        cout << "\nTentando reconectar jogadores..." << endl;
        if (Jogador)
        {
            Jogador->incrementarFalhas();
            if (Jogador->getFalhas() >= 3) {
                cout << Jogador->getNome() << " foi desconectado por excesso de falhas." << endl;
                
            }

           
        }
        for (auto& jogador : Jogadores)
        {
            if (!jogador.isOnline())
            {
                int chance = rand() % 100;
                if (chance < 50)
                {
                    jogador.conectar(servidor);
                    cout << "🔄 " << jogador.getNome() << " reconectou ao servidor!" << endl;
                }
                else
                {
                    cout << "❌ " << jogador.getNome() << " falhou ao reconectar." << endl;
                }
            }
        }
    }

    void mostrarStatusJogadores()
    {
        cout << "\n=== STATUS DOS JOGADORES ===" << endl;
        for (auto& jogador : Jogadores)
        {
            cout << jogador.getNome() << " - Ping: " << jogador.getPing()
                << "ms - " << (jogador.isOnline() ? "🟢 Online" : "🔴 Offline") << endl;
        }
    }
};

// ====================== FUNÇÃO PRINCIPAL ======================
static void menuServidor()
{
    Servidor servidor("ServidorCentral");
    GerenciamentoDeConexao conexao;

    JogadorOnline j1("Lucas", 80);
    JogadorOnline j2("Arthur", 120);
    JogadorOnline j3("Ana", 250);
    JogadorOnline j4("Carlos", 50);

    conexao.adicionarJogador(j1);
    conexao.adicionarJogador(j2);
    conexao.adicionarJogador(j3);
    conexao.adicionarJogador(j4);

    int opcao;
    do
    {
        cout << "\n=== MENU DO SERVIDOR DEDICADO ===" << endl;
        cout << "1. Iniciar Servidor" << endl;
        cout << "2. Simular Falhas de Conexao" << endl;
        cout << "3. Tentar Reconectar Jogadores" << endl;
        cout << "4. Mostrar Status dos Jogadores" << endl;
        cout << "5. Derrubar Servidor" << endl;
        cout << "6. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            servidor.IniciarServidor();
            break;
        case 2:
            conexao.simularFalha();
            break;
        case 3:
            conexao.tentarReconectar(servidor);
            break;
        case 4:
            conexao.mostrarStatusJogadores();
            break;
        case 5:
            servidor.derrubarServidor();
            break;
        case 6:
            cout << "Encerrando sistema..." << endl;
            break;
        default:
            cout << "Opcao invalida!" << endl;
            break;
        }

    } while (opcao != 6);
}


