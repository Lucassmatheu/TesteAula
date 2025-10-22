﻿#include "Aulas.h"
#include"Online.h"
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <fstream>



using namespace std;

class logEventos 
{
    string nome;
    bool online;
    char horario_completo[9] = "12:44:00";

public:
    logEventos(string n) : nome(n), online(false), horario_completo() {}


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
        horario_completo;
        if (online)
        {
            online = false;
            cout << horario_completo;
            cout << "Servidor foi derrubado!" << endl;
        }
        else
        {
            cout << "Servidor ja estava offline." << endl;
        }
    }

    bool statusServidor() const
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
class Conexcao :public logEventos
{
    vector<JogadorOnline> Jogadores;

public:
    Conexcao() : logEventos("Servidor de Conexao") {}
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
    void tentarReconectar(logEventos& servidor)
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
    void reconexaoDinamica(Servidor& servidor)
    {

        int tentava = 0;

        for (auto& jogador : Jogadores) {
            int tentativas = 1;
            jogador.conectar(servidor); // primeira tentativa fora do loop

            while (!jogador.estaConectado() && tentativas < 3) {
                std::this_thread::sleep_for(std::chrono::seconds(2 * tentativas));
                jogador.conectar(servidor);
                tentativas++;
                if (jogador.estaConectado() >= 3) 
                { 
                    cout << jogador.getNome() << "Conexção perdida" << endl;
                    
                }
            }

            if (!jogador.estaConectado()) {
                cout << jogador.getNome() << " falhou ao reconectar." << endl;
            }
            else {
                cout << jogador.getNome() << " reconectou com sucesso." << endl;
            }
           
        }





    }
  
};
static void menuServidor()
{
    logEventos  servidor("ServidorCentral");
    Conexcao conexao;

    JogadorOnline j1("Lucas", 80);




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
};