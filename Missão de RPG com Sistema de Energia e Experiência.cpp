#include "Aulas.h"
#include <iostream>
#include <string>
using namespace std;

class Personagem
{
	private:
	string nome;
	int energia;
	int xp;
	int nivel;
	int Ataque;
	int Defesa;

public: 
	
	// Construtor que inicializa o nome, energia, xp e nivel
	Personagem(string n) : nome(n), energia(100), xp(0), nivel(1) {}
	string getNome() const { return nome; }
	int getEnergia() const { return energia; }
	int getXp() const { return xp; }
	int getNivel() const { return nivel; }
	void explorar() 
	{
		if(energia >= 10)
		{
			energia -= 10;
			// Aqui o personagem ganha 20 de XP por explorar
			xp += 20;
			cout << nome << " explorou e ganhou 20 de XP!" << endl;
			verificarNivel();
		}
		else 
		{
			cout << nome << " está sem energia para explorar!" << endl;
		}
	}
	void atacar() 
	{
		if(energia >= 15)
		{
			energia -= 15;
			xp += 30;
			cout << nome << " atacou e ganhou 30 de XP!" << endl;
			verificarNivel();
		}
		else 
		{
			cout << nome << " está sem energia para atacar!" << endl;
		}
	}
	void defender() 
	{
		if(energia >= 5)
		{
			energia -= 5;
			xp += 10;
			cout << nome << " defendeu e ganhou 10 de XP!" << endl;
			verificarNivel();
		}
		else 
		{
			cout << nome << " está sem energia para defender!" << endl;
		}
	}
	void Batalhar() 
	{
		int acao;
		if(energia >= 20)
		{
			energia -= 30;
			xp += 20;
			Inimigo inimigo("Goblin", 15, 20);	
			inimigo.mostrarInfo();
			inimigo.atacar(*this);
			inimigo.derrotar(*this);
			inimigo.fugir(*this);
			do 
			{
				cout << "Escolha uma acao:\n1-Atacar\n2-Defender\n3-Explorar\n4-Sair\nOpcao: ";
				;
				cin >> acao;
				switch (acao) 
				{
					case 1:
						atacar();
						
						break;
					case 2:
						defender();
						break;
					case 3:
						explorar();
						break;
					case 4:
						cout << "Saindo da batalha..." << endl;
						return;
					default:
						cout << "Acao invalida. Tente novamente." << endl;
				}

			} while (acao != 4 );
			

			
			cout << nome << " batalhou e ganhou 50 de XP!" << endl;
			verificarNivel();
		}
		else 
		{
			cout << nome << " está sem energia para batalhar!" << endl;
		}
	}
	void descansar() 
	{
		energia += 40;
		if(energia > 100) energia = 100;
		cout << nome << " descansou e recuperou energia!" << endl;
	}
	void verificarNivel() 
	{
		if(xp >= 100) 
		{
			nivel++;
			cout << nome << " subiu para o nivel " << nivel << "!" << endl;
		}
	}
};
class mago : public Personagem
{
    public:
	// Construtor que inicializa o nome e chama o construtor da classe base
	mago(string n) : Personagem(n) {}
	void bonusXp()
	{
		if(getXp() % 2 == 0)
		{
			int bonus = 5;
			cout << getNome() << " recebeu um bonus de " << bonus << " XP por ser mago!" << endl;
		}
	}
	void atacar() 
	{
		bonusXp();
		Personagem::atacar();
	}
	void explorar() 
	{
		bonusXp();
		Personagem::explorar();
	}
	void defender() 
	{
		bonusXp();
		Personagem::defender();
	}


};
class guerreiro : public Personagem
{
     public:
	guerreiro(string n) : Personagem(n) {}

	
	void bonusXP()
	{
		if (getXp() % 2 == 0)
		{
			int bonus = 10;
			cout << getNome() << " recebeu um bonus de " << bonus << " energia por ser guerreiro!" << endl;
		}
	}
	void atacar()
	{
		// Aqui você pode adicionar lógica específica para o guerreiro
		getXp();
		Personagem::atacar();
	}
	void explorar()
	{
		getXp();
		Personagem::explorar();
	}
	void descansar()
	{
		getXp();
		Personagem::descansar();
	}
	void defender()
	{
		getXp();
		Personagem::defender();
	}
};
class arqueiro : public Personagem
{
    public:
	arqueiro(string n) : Personagem(n) {}
	void bonusXP()
	{
		if (getXp() % 2 == 0)
		{
			int bonus = 7;
			cout << getNome() << " recebeu um bonus de " << bonus << " energia por ser arqueiro!" << endl;
		}
	}
	void atacar()
	{
		getXp();
		Personagem::atacar();
	}
	void explorar()
	{
		getXp();
		Personagem::explorar();
	}
	void defender()
	{
		getXp();
		Personagem::defender();
	}
};
class Inimigo
{
	private:
	string tipo;
	int forca;
	int xpRecompensa;
 public:
	Inimigo(string t, int f, int xp) : tipo(t), forca(f), xpRecompensa(xp) {}
	int getForca() const { return forca; }
	int getXpRecompensa() const { return xpRecompensa; }
	string getTipo() const { return tipo; }

	void atacar(Personagem& p) 
	{
		cout << tipo << " atacou " << p.getNome() << " causando " << forca << " de dano!" << endl;
	}
	void derrotar(Personagem& p) 
	{
		p.explorar(); // Ganha XP ao derrotar
		cout << p.getNome() << " derrotou o " << tipo << " e ganhou " << xpRecompensa << " de XP!" << endl;
	}
	void fugir(Personagem& p) 
	{
		cout << p.getNome() << " fugiu do " << tipo << "!" << endl;
	}
	void mostrarInfo() 
	{
		cout << "Inimigo: " << tipo << ", Forca: " << forca << ", XP Recompensa: " << xpRecompensa << endl;
	}
};
void menuLuta() 
{
	Inimigo inimigos[] = {
		Inimigo("Goblin", 15, 20),
		Inimigo("Orc", 25, 30),
		Inimigo("Troll", 35, 50)
	};
	int escolha;
	do 
	{
		cout << "Escolha um Personagem Heroi";
		cout << "Escolha sua class\n1-Guerreiro\n2- Mago\n3- Arqueiro\n 4-Opcao: ";
		cin >> escolha;
		if (escolha == 1) 
		{
			string nome;
			cout << "Digite o nome do seu guerreiro: ";
			cin >> nome;
			guerreiro heroi(nome);
			int acao;
			do 
			{
				cout << "\nEscolha uma acao:\n1-Explorar\n2-Atacar\n3-Defender\n4-Batalhar\n5-Descansar\n6-Sair\nOpcao: ";
				cin >> acao;
				switch (acao) 
				{
					case 1:
						heroi.explorar();
						break;
					case 2:
						heroi.atacar();
						break;
					case 3:
						heroi.defender();
						break;
					case 4:
						heroi.Batalhar();
						break;
					case 5:
						heroi.descansar();
						break;
					case 6:
						cout << "Saindo do jogo..." << endl;
						break;
					default:
						cout << "Opcao invalida!" << endl;
				}
			} while (acao != 6);
		}
		else if (escolha == 2) 
		{
			string nome;
			cout << "Digite o nome do seu mago: ";
			cin >> nome;
			mago heroi(nome);
			int acao;
			do 
			{
				cout << "\nEscolha uma acao:\n1-Explorar\n2-Atacar\n3-Defender\n4-Batalhar\n5-Descansar\n6-Sair\nOpcao: ";
				cin >> acao;
				switch (acao) 
				{
					case 1:
						heroi.explorar();
						break;
					case 2:
						heroi.atacar();
						break;
					case 3:
						heroi.defender();
						break;
					case 4:
						heroi.Batalhar();
						break;
					case 5:
						heroi.descansar();
						break;
					case 6:
						cout << "Saindo do jogo..." << endl;
						break;
					default:
						cout << "Opcao invalida!" << endl;
				}
			} while (acao != 6);
		}
		else if (escolha == 3) 
		{
			string nome;
			cout << "Digite o nome do seu arqueiro: ";
			cin >> nome;
			arqueiro heroi(nome);
			int acao;
			do 
			{
				cout << "\nEscolha uma acao:\n1-Explorar\n2-Atacar\n3-Defender\n4-Batalhar\n5-Descansar\n6-Sair\nOpcao: ";
				cin >> acao;
				switch (acao) 
				{
					case 1:
						heroi.explorar();
						break;
					case 2:
						heroi.atacar();
						break;
					case 3:
						heroi.defender();
						break;
					case 4:
						heroi.Batalhar();
						break;
					case 5:
						heroi.descansar();
						break;
					case 6:
						cout << "Saindo do jogo..." << endl;
						break;
					default:
						cout << "Opcao invalida!" << endl;
				}
			} while (acao != 6);
		}
		else if (escolha == 4) 
		{
			cout << "Saindo do jogo..." << endl;
			break;
		}
		else 
		{
			cout << "Opcao invalida! Tente novamente." << endl;
		}
		
		



	} while (escolha != 4);
	


}