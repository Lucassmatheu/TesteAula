#include "Aulas.h"
#include <iostream>

using namespace std;

class JogadorOnline
{
 private:
	string nome;
	int ping;
	bool Online;

public:
	string getNome() { return nome; }
	int getPing() { return ping; }
	bool isOnline() { return Online; }

	void setPing(int novoPing) {
		ping = novoPing;
	}


	JogadorOnline()
	{
		nome = "Desconhecido";
		ping = 0;
		Online = false;
	}
	void conectar(string n, int p)
	{
		nome = n;
		ping = p;
		Online = true;
		cout << nome << " conectou com ping de " << ping << "ms." << endl;
	}
	void desconectar()
	{
		// aqui poderia ter uma animação de desconexão
		// aqui esta verificando se o jogador esta online
		Online = false;
		cout << nome << " desconectou." << endl;
	}
	void atualizarPing(int p)
	{
		ping = p;
		cout << nome << " atualizou o ping para " << ping << "ms." << endl;
	}
	void mostrarStatus()
	{
		if (Online)
		{
			cout << nome << " está online com ping de " << ping << "ms." << endl;
		}
		else
		{
			cout << nome << " está offline." << endl;
		}
	}
};

class Servidor 
{
	// aqui e um atributo para saber quantos jogadores estao conectados
	// aqui esta sendo feito um array de objetos da classe JogadorOnline
	JogadorOnline jogadores[4];
	int numConectados;

public:
	void adicionarJogador(string nome, int ping) 
	{
		if (numConectados < 4) 
		{
			jogadores[numConectados].conectar(nome, ping);
			numConectados++;
		} 
		else 
		{
			cout << "Servidor cheio! Nao e possivel adicionar mais jogadores." << endl;
		}
	}
	void removerJogador(string nome) 
	{
		// para i = 0; i < numConectados; i++
		// percorrer o array de jogadores para encontrar o jogador com o nome passado como parametro
		for (int i = 0; i < numConectados; i++) 
		{
			// se o nome do jogador for igual ao nome passado como parametro
			if (jogadores[i].getNome() == nome) 
			{
				// jogadores[i] esta desconectando o jogador
				jogadores[i].desconectar();
				// aqui esta removendo o jogador do array
				for (int j = i; j < numConectados - 1; j++) 
				{
					jogadores[j] = jogadores[j + 1];
				}
				// decrementa o numero de jogadores conectados
				numConectados--;
				//retorna para sair do metodo
				return;
			}
		}
		cout << "Jogador " << nome << " nao encontrado no servidor." << endl;
	}
	void atulizarPingJogador(string nome, int ping) 
	{
		for (int i = 0; i < numConectados; i++) 
		{
			if (jogadores[i].getNome() == nome) 
			{
				jogadores[i].atualizarPing(ping);
				return;
			}
		}
		cout << "Jogador " << nome << " nao encontrado no servidor." << endl;
	}
	// metodo para mostrar o status de todos os jogadores conectados
	bool serviddorCheio() const
	{
		// retorna verdadiro se o numero de jogadores conectados for maior ou igual a 4
		return numConectados >= 4;
	}

};
void menuServidores() 
{
	int opcao;
	cout << "=== Menu do Servidor Multiplayer ===" << endl;
	Servidor servidor;
	cout << "1. Adicionar Jogador" << endl;
	cout << "2. Remover Jogador" << endl;
	cout << "3. Atualizar Ping do Jogador" << endl;
	cout << "4. Verificar se o Servidor esta Cheio" << endl;
	cout << "5. Sair" << endl;
	cin >> opcao;
	while (opcao != 5) 
	{
		switch (opcao) 
		{
		case 1: 
		{
			string nome;
			int ping;
			cout << "Digite o nome do jogador: ";
			cin >> nome;
			cout << "Digite o ping do jogador (ms): ";
			cin >> ping;
			// aqui esta adicionando o jogador ao servidor
			// servidor.adicionarJogador(nome, ping); esta transferindo os valores para o metodo adicionarJogador
			servidor.adicionarJogador(nome, ping);
			break;
		}
		case 2: 
		{
			string nome;
			cout << "Digite o nome do jogador a ser removido: ";
			cin >> nome;
			servidor.removerJogador(nome);
			break;
		}
		case 3: 
		{
			string nome;
			int ping;
			cout << "Digite o nome do jogador para atualizar o ping: ";
			cin >> nome;
			cout << "Digite o novo ping (ms): ";
			cin >> ping;
			servidor.atulizarPingJogador(nome, ping);
			break;
		}
		case 4:
		{
			if (servidor.serviddorCheio()) 
			{
				cout << "O servidor esta cheio!" << endl;
			} 
			else 
			{
				cout << "O servidor ainda tem vagas!" << endl;
			}
			break;
		}
		default:
			cout << "Opcao invalida! Tente novamente." << endl;
			break;
		}
	
	}
	
 
}
