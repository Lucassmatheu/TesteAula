#include "Aulas.h"
#include <iostream>
#include <string>
using namespace std;

class Heroi 
{
	private:
		string nome;
		int energia;
		int xp;
		int nivel;

	public:
		Heroi(string n) : nome(n), energia(100), xp(0), nivel(1) {}
		string getNome() const { return nome; }
		int getEnergia() const { return energia; }
		int getXp() const { return xp; }
		int getNivel() const { return nivel; }

		void UsarMagia() 
		{
		  	 
			usarFlechaGelo();
			usarTeleporte();
			CuraRapida();
			InvocarEsqueleto();
			RoubarVida();
			BolaDeFogo();

		
		
		}
		void Descansar() 
		{
			energia += 40;
			if(energia > 100) energia = 100;
			cout << nome << " descansou e recuperou energia!" << endl;
		}
		void VerificarNivel() 
		{
			if(xp >= 100) 
			{
				nivel++;
				cout << nome << " subiu para o nivel " << nivel << "!" << endl;
			}
		}
		void MostrarStatus() 
		{
			cout << "Nome: " << nome << ", Energia: " << energia << ", XP: " << xp << ", Nivel: " << nivel << endl;
		}
		void usarFlechaGelo() 
		{
			int QuantidadeFlechas = 10; // Exemplo de quantidade inicial
			// para (int i = 0; i < 10; i++)
			// Usar flecha de gelo 10 vezes ou ate acabar as flechas
			for (int i = 0; i < 10; i++) 
			{
				if (QuantidadeFlechas > 0) 
				{
					QuantidadeFlechas--;
					energia -= 5; // Cada uso consome 5 de energia
					xp += 5;
					cout << "Flecha de gelo usada! Flechas restantes: " << QuantidadeFlechas << endl;
				} 
				else 
				{
					cout << "Sem flechas de gelo restantes!" << endl;
					break; // Sai do loop se nao houver mais flechas
				}
			}
			
		}
		void usarTeleporte() 
		{
			int DistanciaMaxima = 100; // Exemplo de distancia maxima
			int TempodeUso = 40; // Exemplo de tempo de uso em segundos
			int DistanciaPercorrida = 0;
			int TempoDeRecarga = 0;

			// enquanto a distancia percorrida for menor que a maxima e houver energia
			while (DistanciaPercorrida < DistanciaMaxima && energia >=20)
			{
				DistanciaPercorrida += 20; // Exemplo de distancia percorrida por uso
				energia -= 15; // Cada uso consome 15 de energia
				xp += 10;
				cout << "Teleporte usado! Distancia percorrida: " << DistanciaPercorrida << " metros" << endl;
				TempoDeRecarga += 5; // Exemplo de tempo de recarga

			}


		}
		void CuraRapida() 
		{
			if (energia <= 80) 
			{
				energia += 30; // Cura rapida recupera 30 de energia
				xp += 5;
				cout << nome << " usou Cura Rapida e recuperou 20 de energia!" << endl;
			} 
			else 
			{
				cout << nome << " tem energia suficiente, nao precisa usar Cura Rapida!" << endl;
			}
		}
		void InvocarEsqueleto() 
		{
			int NumeroDeEsqueletos = 1; // Exemplo de numero inicial de esqueletos
			int tempoDeInvocacao = 30; // Exemplo de tempo de invocacao em segundos
			int TempoDeRecarga = 0;

			if (energia >= 25) 
			{
				
				for (int i = 0; i < 5; i++) 
				{
					NumeroDeEsqueletos++;
					TempoDeRecarga += 5; // Exemplo de tempo de recarga
				}
				energia -= 25; // Cada invocacao consome 25 de energia
				xp += 15;
				cout << nome << " invocou um esqueleto! Numero total de esqueletos: " << NumeroDeEsqueletos << endl;
			} 
			else 
			{
				cout << nome << " nao tem energia suficiente para invocar um esqueleto!" << endl;
			}
			
		}
		void RoubarVida() 
		{
			if (energia >= 20) 
			{
				energia += 20; // Roubar vida recupera 20 de energia
				xp += 10;
				cout << nome << " usou Roubar Vida e recuperou 20 de energia!" << endl;
			} 
			else 
			{
				cout << nome << " nao tem energia suficiente para usar Roubar Vida!" << endl;
			}


		}
		void BolaDeFogo()
		{
			int LimiteDeBolas = 3; // Exemplo de limite de bolas de fogo	
			int TempoDeRecarga = 0;
			int BolasUsadas = 0;

			while (BolasUsadas < LimiteDeBolas && energia >=30) 
			{
				BolasUsadas++;
				energia -= 30; // Cada uso consome 30 de energia
				xp += 20;
				cout << "Bola de fogo usada! Bolas restantes: " << (LimiteDeBolas - BolasUsadas) << endl;
				TempoDeRecarga += 10; // Exemplo de tempo de recarga
			}

		}
	
		

};

class mago : public Heroi
{
public:
	// Construtor que inicializa o nome e chama o construtor da classe base
	mago(string n) : Heroi(n) {}
	int opcao;
	void UsarMagia()
	{
		cout << "Escolha uma magia para usar:\n1-Teleporte\n2-Bola de Fogo\nOpcao: ";
		cin >> opcao;
		switch (opcao) 
		{
			case 1:
				usarTeleporte();
				break;
			case 2:
				BolaDeFogo();
				break;
			default:
				cout << "Magia invalida!" << endl;
		}

	}

	
};
class Elfo : public Heroi
{
	public:
	Elfo(string n) : Heroi(n) {}

	int opcao;
	void UsarMagia()
	{
		cout << "Escolha uma magia para usar:\n1-Flecha de Gelo\n2-Cura Rapida\nOpcao: ";
		cin >> opcao;
		switch (opcao) 
		{
			case 1:
				usarFlechaGelo();
				break;
			case 2:
				CuraRapida();
				break;
			default:
				cout << "Magia invalida!" << endl;
		}
	}
};
class Necromante : public Heroi
{
 public:
	Necromante(string n) : Heroi(n) {}
	int opcao;
	void UsarMagia()
	{
		cout << "Escolha uma magia para usar:\n1-Invocar Esqueleto\n2-Roubar Vida\nOpcao: ";
		cin >> opcao;
		switch (opcao) 
		{
			case 1:
				InvocarEsqueleto();
				break;
			case 2:
				RoubarVida();
				break;
			default:
				cout << "Magia invalida!" << endl;
		}
	}
};	
void menuMagia()
{
	int escolha;
	cout << "Escolha sua classe:\n1-Mago\n2-Elfo\n3-Necromante\nOpcao: ";
	cin >> escolha;
	if (escolha == 1)
	{
		string nome;
		cout << "Digite o nome do seu mago: ";
		cin >> nome;
		mago heroi(nome);
		int acao;
		do
		{
			cout << "\nEscolha uma acao:\n1-Usar Magia\n2-Descansar\n3-Mostrar Status\n4-Sair\nOpcao: ";
			cin >> acao;
			switch (acao)
			{
			case 1:
				heroi.UsarMagia();
				break;
			case 2:
				heroi.Descansar();
				break;
			case 3:
				heroi.MostrarStatus();
				break;
			case 4:
				cout << "Saindo do jogo..." << endl;
				break;
			default:
				cout << "Opcao invalida!" << endl;
			}
		} while (acao != 4);
	}
	else if (escolha == 2)
	{
		
		string nome;
		cout << "Digite o nome do seu elfo: ";
		cin >> nome;
		// aqui o codigo esta fazendo a instanciacao do objeto elfo
		Elfo heroi(nome);
		int acao;
		// faça enquanto acao for diferente de 4
		do
		{
			cout << "\nEscolha uma acao:\n1-Usar Magia\n2-Descansar\n3-Mostrar Status\n4-Sair\nOpcao: ";
			cin >> acao;
			switch (acao)
			{
			case 1:
				heroi.UsarMagia();
				break;
			case 2:
				heroi.Descansar();
				break;
			case 3:
				heroi.MostrarStatus();
				break;
			case 4:
				cout << "Saindo do jogo..." << endl;
				break;
			default:
				cout << "Opcao invalida!" << endl;
			}
		// enquanto acao for diferente de 4
		} while (acao != 4);
	}
	else if (escolha == 3)
	{
		string nome;
		cout << "Digite o nome do seu necromante: ";
		cin >> nome;
		Necromante heroi(nome);
		int acao;
		do
		{
			cout << "\nEscolha uma acao:\n1-Usar Magia\n2-Descansar\n3-Mostrar Status\n4-Sair\nOpcao: ";
			cin >> acao;
			switch (acao)
			{
			case 1:
				heroi.UsarMagia();
				break;
			case 2:
				heroi.Descansar();
				break;
			case 3:
				heroi.MostrarStatus();
				break;
			case 4:
				cout << "Saindo do jogo..." << endl;
				break;
			default:
				cout << "Opcao invalida!" << endl;
			}
		} while (acao != 4);
	}
}



