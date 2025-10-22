#include "Aulas.h"
#include "Online.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
   
/*M�todo	                      Fun��o	                                          Retorno / A��o
  empty()	              Verifica se o vetor est� vazio	                           true ou false
  push_back()	          Adiciona um novo elemento no vetor	                   insere o objeto no final
* 
*/
class Matchmaking {
private:
    vector<JogadorOnline> jogadoresOnline;
    int capacidade;

public:
    // Construtor que define o n�mero m�ximo de jogadores na fila
    Matchmaking(int max) : capacidade(max) {}

    // Adiciona um jogador � fila de matchmaking
    void adicionarJogador(const JogadorOnline& j) {
        if (jogadoresOnline.size() < capacidade) {

            // Adiciona o jogador 'j' ao final do vetor 'jogadoresOnline'
           // push_back() insere novos elementos dinamicamente na lista

            jogadoresOnline.push_back(j);
            cout << j.getNome() << " foi adicionado � fila de matchmaking!" << endl;
        }
        else {
            cout << "Fila cheia! Aguarde para entrar em uma nova partida." << endl;
        }
    }

    // Exibe todos os jogadores que est�o na fila
    void mostrarFila() {
        // Verifica se o vetor 'jogadoresOnline' est� vazio (sem jogadores na fila)
        // Retorna true se estiver vazio, evitando mostrar uma lista vazia
        if (jogadoresOnline.empty()) {
            cout << "Nenhum jogador na fila." << endl;
            return;
        }

        cout << "\n=== Jogadores na fila ===" << endl;
        for (const auto& jogador : jogadoresOnline) {
            cout << "Nome: " << jogador.getNome()
                << " | Ping: " << jogador.getPing() << "ms" << endl;
        }
    }
};
