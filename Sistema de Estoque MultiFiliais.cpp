#include <iostream>
#include <string>
using namespace std;

const int produtosMaximos = 5;

// Busca produto pelo nome
static int buscarIndice(const string nomes[], int total, const string& nomeProduto) {
// Retorna o índice do produto se encontrado, caso contrário retorna -1
//para inteiro i = 0; i < total; ++i
//		se nomes[i] == nomeProduto
//			retorna i
//retorna -1
    for (int i = 0; i < total; ++i) {
        if (nomes[i] == nomeProduto) return i;
    }
    return -1;
}

// Cadastrar produto
static void cadastrarProduto(string nomes[], int totais[], int& total, int estoqueFilial[][3]) {
    if (total >= produtosMaximos) {
        cout << "Limite maximo de produtos atingido.\n";
        return;
    }

    string nomeProduto;
    cout << "Digite o nome do produto: ";
    cin >> nomeProduto;

    if (buscarIndice(nomes, total, nomeProduto) != -1) {
        cout << "Produto ja cadastrado.\n";
        return;
    }

    int soma = 0;
    cout << "Digite a quantidade em estoque para cada filial (3 filiais):\n";
    for (int j = 0; j < 3; ++j) {
        int quantidade;
        cout << "Filial " << j + 1 << ": ";
        cin >> quantidade;
        estoqueFilial[total][j] = quantidade;
        soma += quantidade;
    }

    nomes[total] = nomeProduto;
    totais[total] = soma;
    ++total;

    cout << "Produto cadastrado com sucesso! Total em estoque: " << soma << endl;
}

// Mostrar produtos
static void MostrarProdutosFiliais(string nomes[], int totais[], int total, int estoqueFilial[][3]) {
    
    for (int i = 0; i < total; i++) {
        cout << "Produto: " << nomes[i] << endl;
        cout << "Estoque nas filiais:\n";
        for (int j = 0; j < 3; ++j) {
            cout << "  Filial " << j + 1 << ": " << estoqueFilial[i][j] << endl;
        }
        cout << "  Total: " << totais[i] << endl;
    }
}

// Verificar unidades disponíveis
static void unidadesDisponiveis(string nomes[], int totais[], int total) {
    string nomeProduto;
    cout << "Digite o nome do produto para verificar unidades disponiveis: ";
    cin >> nomeProduto;

    int indice = buscarIndice(nomes, total, nomeProduto);
    if (indice != -1) {
        cout << "Produto encontrado: " << nomes[indice] << ", Total em estoque: " << totais[indice] << endl;
    }
    else {
        cout << "Produto nao encontrado." << endl;
    }
}

// Produto com mais estoque
static void ProdutoComMaisEstoque(string nomes[], int totais[], int total) {
    int maxEstoque = -1;
    int indiceMax = -1;

    for (int i = 0; i < total; ++i) {
        if (totais[i] > maxEstoque) {
            maxEstoque = totais[i];
            indiceMax = i;
        }
    }

    if (indiceMax != -1) {
        cout << "Produto com mais estoque: " << nomes[indiceMax] << " com " << maxEstoque << " unidades." << endl;
    }
    else {
        cout << "Nenhum produto cadastrado." << endl;
    }
}

// Buscar produtos
static void BucarProdutos(string nomes[], int totais[], int total) {
    string nomeProduto;
    cout << "Digite o nome do produto para buscar: ";
    cin >> nomeProduto;

    int indice = buscarIndice(nomes, total, nomeProduto);
    if (indice != -1) {
        cout << "Produto encontrado: " << nomes[indice] << ", Total em estoque: " << totais[indice] << endl;
    }
    else {
        cout << "Produto nao encontrado." << endl;
    }
}

// Menu principal
void MenuEstoque() {
    string nomes[produtosMaximos];
    int totais[produtosMaximos];
    int estoqueFilial[produtosMaximos][3];
    int total = 0;

    int opcao;
    do {
        cout << "\nMenu de Estoque MultiFiliais:\n";
        cout << "1. Cadastrar Produto\n";
        cout << "2. Mostrar Produtos e Estoque por Filial\n";
        cout << "3. Verificar Unidades Disponiveis de um Produto\n";
        cout << "4. Produto com Maior Estoque\n";
        cout << "5. Buscar Produto por Nome\n";
        cout << "6. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
        case 1:
            cadastrarProduto(nomes, totais, total, estoqueFilial);
            break;
        case 2:
            MostrarProdutosFiliais(nomes, totais, total, estoqueFilial);
            break;
        case 3:
            unidadesDisponiveis(nomes, totais, total);
            break;
        case 4:
            ProdutoComMaisEstoque(nomes, totais, total);
            break;
        case 5:
            BucarProdutos(nomes, totais, total);
            break;
        case 6:
            cout << "Saindo do programa.\n";
            break;
        default:
            cout << "Opcao invalida. Tente novamente.\n";
        }
    } while (opcao != 6);
}

// Função main para rodar
int main() {
    MenuEstoque();
    return 0;
}
