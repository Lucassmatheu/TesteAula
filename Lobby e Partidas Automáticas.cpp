#include "Aulas.h"
#include <iostream>
#include <string>
#include "Simulador de Servidor Multiplayer.cpp"
using namespace std;

class LobbyServidores : public Servidor 
{
	bool partidaEmnAndamento;
	int Numconctados;
	int ping;
	string TimeA[2];
	string TimeB[2];
	string jogadores;
	
	JogadorOnline JogadorOnline[4];
      
public:
	void setPing(int novoPing) {
		ping = novoPing;
	}

	
	void iniciarPartida() {
		if (Numconctados < 4) {
			cout << "Ainda nao ha jogadores suficientes para iniciar a partida." << endl;
			return;
		}

		partidaEmnAndamento = true;
		cout << "\n=== Partida Iniciada ===" << endl;
		cout << "Time A: " << TimeA[0] << " e " << TimeA[1] << endl;
		cout << "Time B: " << TimeB[0] << " e " << TimeB[1] << endl;

		for (int rodada = 1; rodada <= 5; rodada++) {
			cout << "\nRodada " << rodada << "!" << endl;
			bool timeAAtaca = (rand() % 2 == 0);

			if (timeAAtaca)
				cout << "Time A atacou primeiro!" << endl;
			else
				cout << "Time B atacou primeiro!" << endl;

			reduzirPing(); // simula lag e ataques
		}

		encerrarPartida();
	}
	void encerrarPartida() 
	{
		partidaEmnAndamento = false;
		cout << "Partida encerrada." << endl;
		

	}	
	void mostrarStatusServidor()
	{
		cout << "Número de jogadores conectados: " << Numconctados << endl;
		cout << "Partidas em andamento: " << (partidaEmnAndamento ? "Sim" : "Não") << endl;

	}
	
	void SimularParidas() 
	{
		
		for (int i = 0; i < 5; i++)
		{
			iniciarPartida();
			cout << "Partida " << i + 1 << " iniciada entre Time A e Time B." << endl;
			encerrarPartida();
		}
	}
	void reduzirPing() {
		for (int i = 0; i < Numconctados; ++i) {
			
		    
			
			JogadorOnline[i].setPing(JogadorOnline[i].getPing() - 10);

		}
	}


	
};
void menuLobby() {
	LobbyServidores lobby;
	int opcao;

	do {
		cout << "\n=== Lobby Multiplayer ===\n";
		cout << "1. Adicionar jogador\n2. Mostrar status\n3. Iniciar partida\n4. Encerrar partida\n5. Sair\nOpcao: ";
		cin >> opcao;

		switch (opcao) {
		case 1: {
			string nome;
			int ping;
			cout << "Nome: ";
			cin >> nome;
			cout << "Ping inicial: ";
			cin >> ping;
			lobby.adicionarJogador(nome, ping);
			break;
		}
		case 2:
			lobby.mostrarStatusServidor();
			break;
		case 3:
			lobby.iniciarPartida();
			break;
		case 4:
			lobby.encerrarPartida();
			break;
		case 5:
			cout << "Saindo do lobby..." << endl;
			break;
		default:
			cout << "Opcao invalida!" << endl;
		}
	} while (opcao != 5);
}