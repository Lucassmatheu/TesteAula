#pragma once


#pragma once
#include <string>
using namespace std;

class Servidor {
public:
    Servidor(string n);
    void IniciarServidor();
    void derrubarServidor();
    void statusServidor();
};
class JogadorOnline
{
    string NomeJogador;
    int ping;
    bool conectado;
    int falhas = 0; // para o controle de reconexões

public:
    JogadorOnline(string nome = "Desconhecido", int p = 0)
        : NomeJogador(nome), ping(p), conectado(false) {}

    string getNome() const { return NomeJogador; }
    int getPing() const { return ping; }
    bool isOnline() const { return conectado; }

    void conectar(Servidor& servidor);
    void desconectar();

    // novos métodos usados no seu código
    void incrementarFalhas() { falhas++; }
    int getFalhas() const { return falhas; }
    bool estaConectado() const { return conectado; }
};