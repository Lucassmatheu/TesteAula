#include"Aulas.h"
#include <iostream>
#include <string>
using namespace std;

class GuerreiroBase 
{
private:
	string nome;
	int  energia = 100;
	int ataque;
	int defesa;
public:
	GuerreiroBase(string n) : nome(n), energia(100), ataque(0), defesa(0) {}
	string getNome() const { return nome; }
	int getEnergia() const { return energia; }
	int getAtaque() const { return ataque; }
	int getDefesa() const { return defesa; }
	
	void reduzirEnergia(int valor) 
	{
		energia -= valor;
		if (energia < 0) energia = 0;
	}
	void Atacar(GuerreiroBase& inimigo) 
	{
		int dano = ataque - inimigo.defesa;
		if (dano > 0) {
			inimigo.energia -= dano;
			if (inimigo.energia < 0) inimigo.energia = 0;
			cout << nome << " atacou " << inimigo.nome << " causando " << dano << " de dano!" << endl;
		} else {
			cout << nome << " tentou atacar " << inimigo.nome << " mas o ataque foi bloqueado!" << endl;
		}
	}
	void Defender() 
	{
		defesa += 10;
		if (defesa > 50) defesa = 50; // Limite maximo de defesa
		cout << nome << " aumentou sua defesa para " << defesa << "!" << endl;
	}
	bool estaVivo() const {
		return energia > 0;
	}
	virtual void HabilidadeEspecial(GuerreiroBase& inimigo) = 0; // Metodo virtual puro
	
	void descansar() 
	{
		energia += 15;
		if (energia > 100) energia = 100;
		cout << nome << " descansou e recuperou energia!" << endl;
	}

};
class samurai : public GuerreiroBase
{
	public:
	samurai(string n) : GuerreiroBase(n) 
	{
	}
	void HabilidadeEspecial(GuerreiroBase& inimigo) override 
	{
		if (getEnergia() >= 30) 
		{
			int dano = 40 - inimigo.getDefesa();
			if (dano > 0) {
				 dano;
				if (getEnergia() >=30) inimigo.reduzirEnergia(dano);
				cout << getNome() << " usou Corte Rápido em " << inimigo.getNome() << " causando " << dano << " de dano!" << endl;
			} else {
				cout << getNome() << " tentou usar Corte Rápido em " << inimigo.getNome() << " mas o ataque foi bloqueado!" << endl;
			}
			int novaEnergia = getEnergia() - 30;
			// Reduz a energia
			this->reduzirEnergia(30);
		} else {
			cout << getNome() << " nao tem energia suficiente para usar Corte Rápido!" << endl;
		}
	}

};
class barbaro : public GuerreiroBase
{
	public:
	barbaro(string n) : GuerreiroBase(n) 
	{
	}
	void HabilidadeEspecial(GuerreiroBase& inimigo) override 
	{
		if (getEnergia() >= 40) 
		{
			int dano = 50 - inimigo.getDefesa();
			if (dano > 0) {
				dano;
				if (getEnergia() >= 30) inimigo.reduzirEnergia(dano);
				cout << getNome() << " usou Golpe Brutal em " << inimigo.getNome() << " causando " << dano << " de dano!" << endl;
			} else {
				cout << getNome() << " tentou usar Golpe Brutal em " << inimigo.getNome() << " mas o ataque foi bloqueado!" << endl;
			}
			int novaEnergia = getEnergia() - 40;
			this->reduzirEnergia(40); // Reduz a energia
		} else {
			cout << getNome() << " nao tem energia suficiente para usar Golpe Brutal!" << endl;
		}
	}
};	
void menu() 
{
	barbaro jogador1("Conan");
	samurai jogador2("Musashi");
	int acao;
	while (jogador1.estaVivo() && jogador2.estaVivo())
	{
	  cout<< "\n 1 Ataca\n 2 defender\n 3 descansar "
		  " \n 4 Habilidade Especial\nEscolha uma acao: ";
	  cin >> acao;
	  switch (acao) 
	  {
		  case 1:
			  jogador1.Atacar(jogador2);
			  break;
		  case 2:
			  jogador1.Defender();
			  break;
		  case 3:
			  jogador1.descansar();
			  break;
		  case 4:
			  jogador1.HabilidadeEspecial(jogador2);
			  break;
		  default:
			  cout << "Acao invalida!" << endl;
	  }
	  if (!jogador2.estaVivo()) 
	  {
		  cout << jogador2.getNome() << " foi derrotado!" << endl;
		  break;
	  }
	  // Turno do jogador 2
	  cout<< "\n 1 Ataca\n 2 defender\n 3 descansar "
		  " \n 4 Habilidade Especial\nEscolha uma acao: ";
	  cin >> acao;
	  switch (acao) 
	  {
		  case 1:
			  jogador2.Atacar(jogador1);
			  break;
		  case 2:
			  jogador2.Defender();
			  break;
		  case 3:
			  jogador2.descansar();
			  break;
		  case 4:
			  jogador2.HabilidadeEspecial(jogador1);
			  break;
		  default:
			  cout << "Acao invalida!" << endl;
	  }
	}
}
