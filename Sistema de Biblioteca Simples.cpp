#include <iostream>
#include <string>
using namespace std;

const int MAX_LIVROS = 10;

class Livro {
private:
    string titulo;
    string autor;
    int ano;
    bool disponivel;

public:
    Livro(string t, string a, int y) {
        titulo = t;
        autor = a;
        ano = y;
        disponivel = true;
    }

    void exibirInformacoes() {
        cout << "Titulo: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "Ano: " << ano << endl;
        cout << "Disponivel: " << (disponivel ? "Sim" : "Nao") << endl;
    }

    string getTitulo() {
        return titulo;
    }

    bool estaDisponivel() {
        return disponivel;
    }

    void emprestar() {
        disponivel = false;
    }

    void devolver() {
        disponivel = true;
    }
};

class Biblioteca {
private:
    Livro* livros[MAX_LIVROS];
    int totalLivros;

public:
    Biblioteca() {
        totalLivros = 0;
    }

    void adicionarLivro(Livro* livro) {
        if (totalLivros < MAX_LIVROS) {
            livros[totalLivros] = livro;
            totalLivros++;
            cout << "Livro adicionado com sucesso!\n";
        }
        else {
            cout << "Limite de livros atingido!\n";
        }
    }

    void listarLivros() {
        if (totalLivros == 0) {
            cout << "Nenhum livro cadastrado.\n";
            return;
        }

        cout << "\nLista de Livros:\n";
        for (int i = 0; i < totalLivros; i++) {
            cout << "\nLivro " << i + 1 << ":\n";
            livros[i]->exibirInformacoes();
        }
    }

    void procurarLivro(string titulo) {
        for (int i = 0; i < totalLivros; i++) {
            if (livros[i]->getTitulo() == titulo) {
                cout << "Livro encontrado:\n";
                livros[i]->exibirInformacoes();

                int opcao;
                cout << "Deseja emprestar este livro? (1-Sim / 2-Nao): ";
                cin >> opcao;

                if (opcao == 1 && livros[i]->estaDisponivel()) {
                    livros[i]->emprestar();
                    cout << "Livro emprestado com sucesso.\n";
                }
                else if (opcao == 1) {
                    cout << "Livro ja emprestado.\n";
                }

                return;
            }
        }
        cout << "Livro nao encontrado.\n";
    }
};

void BibliotecaSimples() {
    Biblioteca biblioteca;
    int opcao;

    do {
        cout << "\n===== Menu Biblioteca =====\n";
        cout << "1. Adicionar Livro\n";
        cout << "2. Listar Livros\n";
        cout << "3. Procurar Livro\n";
        cout << "4. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        if (opcao == 1) {
            string titulo, autor;
            int ano;
            cout << "Titulo: ";
            cin.ignore();
            getline(cin, titulo);
            cout << "Autor: ";
            getline(cin, autor);
            cout << "Ano: ";
            cin >> ano;

            Livro* novoLivro = new Livro(titulo, autor, ano);
            biblioteca.adicionarLivro(novoLivro);
        }
        else if (opcao == 2) {
            biblioteca.listarLivros();
        }
        else if (opcao == 3) {
            string tituloBusca;
            cout << "Digite o titulo do livro: ";
            cin.ignore();
            getline(cin, tituloBusca);
            biblioteca.procurarLivro(tituloBusca);
        }
        else if (opcao == 4) {
            cout << "Saindo do sistema...\n";
        }
        else {
            cout << "Opcao invalida.\n";
        }

    } while (opcao != 4);

    return;
}
