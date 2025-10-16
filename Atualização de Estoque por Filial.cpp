#include <iostream>
#include <string>
using namespace std;

const int Max_Produto = 15;
const int Num_Filiais = 3;

int buscarIndice(const string nomes[], int total, const string& nomeProduto) {
    for (int i = 0; i < total; ++i) {
        if (nomes[i] == nomeProduto) return i;
    }
    return -1;
}

void cadastrarProduto(string nomes[], int totais[], int estoqueFilial[][Num_Filiais], int& total) {
    if (total >= Max_Produto) {
        cout << "Limite de produtos atingido!\n";
        return;
    }

    string nomeProduto;
    cout << "Nome do produto: ";
    cin >> nomeProduto;

    if (buscarIndice(nomes, total, nomeProduto) != -1) {
        cout << "Produto já cadastrado!\n";
        return;
    }

    nomes[total] = nomeProduto;
    totais[total] = 0;
    
	// Solicita o estoque para cada filial
	// Inicializa o estoque de cada filial para o produto atual
    
    for (int j = 0; j < Num_Filiais; ++j) {
        cout << "Estoque da Filial " << (j + 1) << ": ";
		// Lê a quantidade em estoque para a filial j
        cin >> estoqueFilial[total][j];
		// Atualiza o total do produto somando o estoque da filial j
		// total do produto = total do produto + estoque da filial j
        totais[total] += estoqueFilial[total][j];
    }

    cout << "Produto cadastrado com sucesso!\n";
    ++total;
}

void mostrarProdutos(const string nomes[], const int totais[], int estoqueFilial[][Num_Filiais], int total) {
    for (int i = 0; i < total; ++i) {
        cout << "\nProduto: " << nomes[i] << "\n";
        for (int j = 0; j < Num_Filiais; ++j) {
            cout << "  Filial " << (j + 1) << ": " << estoqueFilial[i][j] << "\n";
        }
        cout << "  Total em estoque: " << totais[i] << "\n";
    }
}

void atualizarEstoque(string nomes[], int totais[], int estoqueFilial[][Num_Filiais], int total) {
    string nomeProduto;
    cout << "Nome do produto para atualizar: ";
    cin >> nomeProduto;

    int indice = buscarIndice(nomes, total, nomeProduto);
    if (indice == -1) {
        cout << "Produto não encontrado!\n";
        return;
    }

    int filial;
    cout << "Número da filial (1 a 3): ";
    cin >> filial;

    if (filial < 1 || filial > Num_Filiais) {
        cout << "Filial inválida.\n";
        return;
    }

    int novaQuantidade;
    cout << "Nova quantidade para a filial " << filial << ": ";
    cin >> novaQuantidade;

    // Atualiza o total corretamente
    totais[indice] -= estoqueFilial[indice][filial - 1];
    estoqueFilial[indice][filial - 1] = novaQuantidade;
    totais[indice] += novaQuantidade;

    cout << "Estoque atualizado com sucesso!\n";
}

void menuEstoque() {
    string nomes[Max_Produto];
    int totais[Max_Produto];
    int estoqueFilial[Max_Produto][Num_Filiais] = { 0 };
    int total = 0;

    int opcao;
    do {
        cout << "\n===== MENU ESTOQUE =====\n";
        cout << "1. Cadastrar produto\n";
        cout << "2. Mostrar produtos\n";
        cout << "3. Atualizar estoque por filial\n";
        cout << "4. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
        case 1:
            cadastrarProduto(nomes, totais, estoqueFilial, total);
            break;
        case 2:
            mostrarProdutos(nomes, totais, estoqueFilial, total);
            break;
        case 3:
            atualizarEstoque(nomes, totais, estoqueFilial, total);
            break;
        case 4:
            cout << "Encerrando o programa.\n";
            break;
        default:
            cout << "Opção inválida!\n";
        }
    } while (opcao != 4);
}

void estoque() {
    menuEstoque();
    return;
}
