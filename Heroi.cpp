#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class HeroisDeClasses 
{
	private:
		string nome;
		int vida;
		int ataque;
		int defesa;

	public:
		HeroisDeClasses(string n, int v, int a, int d)
			: nome(n), vida(v), ataque(a), defesa(d) {}

		void receberDano(int dano) {
			vida -= dano;
			if (vida < 0) vida = 0;
		}	
		virtual void atacar(HeroisDeClasses& inimigo) {
			int dano = ataque - inimigo.defesa;
			if (dano < 0) dano = 0;
			inimigo.receberDano(dano);
			cout << nome << " atacou " << inimigo.nome << " causando " << dano << " de dano!" << endl;
		}
		void exibirStatus() const
		{
			cout << "\n[" << nome << "]" << endl;
			cout << "Vida: " << vida << " | Ataque: " << ataque << endl;
		} 
		bool EstaVivo() const {
			return vida > 0;
		}	
		void defesatemporaria(int aumento) {
			defesa += aumento;
			if (defesa < 10) 
			{
				cout << "Defesa muito baixa, ajustando para 10." << endl;
				defesa = 10;
			}
			else 
			{
				cout << "Defesa aumentada para " << defesa << "." << endl;
			}
			cout << nome << " aumentou sua defesa em " << aumento << " temporariamente!" << endl;
		}
		string getNome() const { return nome; }
		int  getVida() const { return vida; }
		int  getAtaque() const { return ataque; }
		int  getDefesa() const { return defesa; }
};

class guerreiro : public HeroisDeClasses
{
	public:
		guerreiro(string n) : HeroisDeClasses(n, 120, 40, 20) {}
		void atacar(HeroisDeClasses& alvo) override {
			cout << getNome() << " desferiu um golpe poderoso!" << endl;
			int dano = getAtaque() - alvo.getDefesa();
			if (dano < 0) dano = 0;
			alvo.receberDano(dano);
		}
		void usarHabilidadeEspecial(HeroisDeClasses& alvo) {
			int dano = 30; // Dano fixo da habilidade especial
			alvo.receberDano(dano);
			cout << getNome() << " usou Habilidade Especial: " << alvo.getNome() << " perdeu " << dano << " de vida!\n";
		}
};

class Arqueiro : public HeroisDeClasses
{
	public:
		Arqueiro(string n) : HeroisDeClasses(n, 100, 45, 15) {}
		void atacar(HeroisDeClasses& alvo) override {
			cout << getNome() << " disparou uma flecha precisa!" << endl;
			int dano = getAtaque() - alvo.getDefesa();
			if (dano < 0) dano = 0;
			alvo.receberDano(dano);
		}
		void usarHabilidadeEspecial(HeroisDeClasses& alvo) {
			int dano = 25; // Dano fixo da habilidade especial
			alvo.receberDano(dano);
			cout << getNome() << " usou Habilidade Especial: " << alvo.getNome() << " perdeu " << dano << " de vida!\n";
		}

};

class mago : public HeroisDeClasses
{
	public:
		mago(string n) : HeroisDeClasses(n, 80, 50, 10) {}
		void atacar(HeroisDeClasses& alvo) override {
			cout << getNome() << " lançou uma bola de fogo!" << endl;
			int dano = getAtaque() - alvo.getDefesa();
			if (dano < 0) dano = 0;
			alvo.receberDano(dano);
		}
		void usarHabilidadeEspecial(HeroisDeClasses& alvo) {
			int dano = 35; // Dano fixo da habilidade especial
			alvo.receberDano(dano);
			cout << getNome() << " usou Habilidade Especial: " << alvo.getNome() << " perdeu " << dano << " de vida!\n";
		}
};

void LutarTurno()
{
	int escolha;
	do 
	{
		HeroisDeClasses heroi2("Goblin", 80, 40, 20);
		cout << "Escolha sua classe:\n1-Guerreiro\n2-Mago\n3-Arqueiro\n4-Opcao: ";
	
		cin >> escolha;
		if (escolha == 1) 
		{
			guerreiro heroi1("Guerreiro10");
			heroi1.exibirStatus();
			int opcao;
			cout << "Escolha uma acao:\n";
			cout << "1. Atacar\n";
			cout << "2. Defender\n";
			cout << "3. Sair\n";
			cin >> opcao;
			switch (opcao)
			{
			case 1:
				heroi1.atacar(heroi2);
				if (heroi2.getVida() <= 0) {
					// saia do loop e imprima que o heroi1 venceu
					cout << heroi2.getNome() << " foi derrotado! " << heroi1.getNome() << " venceu a luta!" << endl;
					opcao = 3; // Sai do loop
					break;
				}
				// Se o heroi2 nao for derrotado, ele ataca o heroi1
				// heroi2.atacar(heroi1) aqui esta fazendo o ataque do heroi2 no heroi1
				heroi2.atacar(heroi1);
				if (heroi1.getVida() <= 0) {
					cout << heroi1.getNome() << " foi derrotado! " << heroi2.getNome() << " venceu a luta!" << endl;
					opcao = 3; // Sai do loop
				}
			case 2:
				cout << heroi1.getNome() << " se defende e reduz o dano do proximo ataque!" << endl;
				// Implementar logica de defesa (exemplo: aumentar defesa temporariamente)
				heroi1.defesatemporaria(10); // Aumenta defesa em 10 temporariamente
				break;
			case 3:
				cout << "Saindo da luta..." << endl;
				break;
			default:
				break;
			}
		
			
			
		}
		else if (escolha == 2) 
		{
			mago heroi1("Mago1");
			int opcao;
			do
			{
			
			cout << "Escolha uma acao:\n";
			cout << "1. Atacar\n";
			cout << "2. Defender\n";
			cout << "3. Sair\n";
			cin >> opcao;
			switch (opcao)
			{
			case 1:
				heroi1.atacar(heroi2);
				if (heroi2.getVida() <= 0) {
					// saia do loop e imprima que o heroi1 venceu
					cout << heroi2.getNome() << " foi derrotado! " << heroi1.getNome() << " venceu a luta!" << endl;
					opcao = 3; // Sai do loop
					break;
				}
				// Se o heroi2 nao for derrotado, ele ataca o heroi1
				// heroi2.atacar(heroi1) aqui esta fazendo o ataque do heroi2 no heroi1
				heroi2.atacar(heroi1);
				if (heroi1.getVida() <= 0) {
					cout << heroi1.getNome() << " foi derrotado! " << heroi2.getNome() << " venceu a luta!" << endl;
					opcao = 3; // Sai do loop
				}
			case 2:
				cout << heroi1.getNome() << " se defende e reduz o dano do proximo ataque!" << endl;
				// Implementar logica de defesa (exemplo: aumentar defesa temporariamente)
				heroi1.defesatemporaria(10); // Aumenta defesa em 10 temporariamente
				break;
			case 3:
				cout << "Saindo da luta..." << endl;
				break;
			default:
				break;
			}
		  } while (opcao != 3);
		}
		else if (escolha == 3) 
		{
			// O heroi1 aqui é do tipo Arqueiro que vem da classe derivada Arqueiro 
			Arqueiro heroi1("Arqueiro1");
			int opcao;
			do
			{
			cout << "Escolha uma acao:\n";
			cout << "1. Atacar\n";
			cout << "2. Defender\n";
			cout << "3. Sair\n";
			cin >> opcao;
			switch (opcao)
			{
			case 1:
				heroi1.atacar(heroi2);
				// heroi2.getVida() aqui esta pegando a vida do heroi2 e verificando se é menor ou igual a 0 
				if (heroi2.getVida() <= 0) {
					// saia do loop e imprima que o heroi1 venceu
					// .getNome() aqui esta fazendo que o nome do heroi seja exibido
					cout << heroi2.getNome() << " foi derrotado! " << heroi1.getNome() << " venceu a luta!" << endl;
					opcao = 3; // Sai do loop
					break;
				}
				// Se o heroi2 nao for derrotado, ele ataca o heroi1
				// heroi2.atacar(heroi1) aqui esta fazendo o ataque do heroi2 no heroi1
				heroi2.atacar(heroi1);
				if (heroi1.getVida() <= 0) {
					cout << heroi1.getNome() << " foi derrotado! " << heroi2.getNome() << " venceu a luta!" << endl;
					opcao = 3; // Sai do loop
				}
			case 2:
				cout << heroi1.getNome() << " se defende e reduz o dano do proximo ataque!" << endl;
				// Implementar logica de defesa (exemplo: aumentar defesa temporariamente)
				heroi1.defesatemporaria(10); // Aumenta defesa em 10 temporariamente
				break;
			case 3:
				cout << "Saindo da luta..." << endl;
				break;
			default:
				break;
			}
		  } while (opcao != 3);
		}
		else 
		{
			cout << "Opcao invalida. Tente novamente." << endl;
			continue; // Volta ao inicio do loop
		}

		
		
	

	

		
	} while (4 != escolha);
}


