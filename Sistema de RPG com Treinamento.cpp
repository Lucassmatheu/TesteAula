#include <iostream>
#include <string>

// Função para cadastrar o personagem
void cadastrarPersonagem(std::string& nome, std::string& classe, int& nivel, int& energia, int& experiencia) {
    std::cout << "=== Cadastro de Personagem ===\n";
    std::cout << "Nome: ";
    std::cin >> nome;
    std::cout << "Classe (Guerreiro / Mago / Arqueiro): ";
    std::cin >> classe;
    std::cout << "Nivel (1 a 10): ";
    std::cin >> nivel;
    std::cout << "Energia (0 a 100): ";
    std::cin >> energia;
    experiencia = 0;

    if (nivel < 1 || nivel > 10) {
        std::cout << "Nivel invalido! Definido como 1 por padrão.\n";
        nivel = 1;
    }
    if (energia < 0 || energia > 100) {
        std::cout << "Energia invalida! Definida como 100 por padrão.\n";
        energia = 100;
    }

    std::cout << "Cadastro concluído com sucesso!\n\n";
}

// Função para treinar o personagem
void treinarPersonagem(int& energia, int& experiencia) {
    int opcaoTreino;
    do {
        std::cout << "\n=== Menu de Treinamento ===\n";
        std::cout << "[1] Treinar Força (custa 10 energia, +15 XP)\n";
        std::cout << "[2] Treinar Agilidade (custa 5 energia, +10 XP)\n";
        std::cout << "[3] Descansar (+20 energia, até 100)\n";
        std::cout << "[4] Sair do Treinamento\n";
        std::cin >> opcaoTreino;

        switch (opcaoTreino) {
        case 1:
            if (energia >= 10) {
                energia -= 10;
                experiencia += 15;
                std::cout << "Você treinou Força!\n";
            }
            else {
                std::cout << "Energia insuficiente!\n";
            }
            break;
        case 2:
            if (energia >= 5) {
                energia -= 5;
                experiencia += 10;
                std::cout << "Você treinou Agilidade!\n";
            }
            else {
                std::cout << "Energia insuficiente!\n";
            }
            break;
        case 3:
            energia += 20;
            if (energia > 100) energia = 100;
            std::cout << "Você descansou. Energia restaurada!\n";
            break;
        case 4:
            std::cout << "Saindo do treinamento...\n";
            break;
        default:
            std::cout << "Opção inválida.\n";
            break;
        }

        std::cout << "Energia Atual: " << energia << ", Experiência Atual: " << experiencia << "\n";

    } while (opcaoTreino != 4);
}

// Função para mostrar o status do personagem
void mostrarStatus(const std::string& nome, const std::string& classe, int nivel, int energia, int experiencia) {
    std::cout << "\n=== Status do Personagem ===\n";
    std::cout << "Nome: " << nome << "\n";
    std::cout << "Classe: " << classe << "\n";
    std::cout << "Nível: " << nivel << "\n";
    std::cout << "Energia: " << energia << "\n";
    std::cout << "Experiência: " << experiencia << "\n";

    std::string poder = (experiencia >= 50) ? "FORTE" : "FRACO";
    std::cout << "Você é considerado: " << poder << "\n\n";
}

// Função de Batalha
void batalhar(int& energia, int& experiencia) {
    int energiaInimigo = 40;
    int acao;
    std::cout << "\n=== Início da Batalha! ===\n";

    do {
        std::cout << "\n[1] Atacar (10 energia, -15 vida inimigo)\n";
        std::cout << "[2] Defender (+5 energia)\n";
        std::cout << "[3] Fugir\n";
        std::cout << "[4] Sair da Batalha\n";
        std::cin >> acao;

        switch (acao) {
        case 1:
            if (energia >= 10) {
                energia -= 10;
                energiaInimigo -= 15;
                experiencia += 10;
                std::cout << "Você atacou o inimigo! Energia do inimigo: " << energiaInimigo << "\n";
            }
            else {
                std::cout << "Energia insuficiente para atacar!\n";
            }
            break;
        case 2:
            energia += 5;
            if (energia > 100) energia = 100;
            std::cout << "Você se defendeu. Energia atual: " << energia << "\n";
            break;
        case 3:
            std::cout << "Você fugiu da batalha!\n";
            return;
        case 4:
            std::cout << "Saindo da batalha...\n";
            return;
        default:
            std::cout << "Opção inválida!\n";
            break;
        }

        if (energiaInimigo <= 0) {
            std::cout << "Parabéns! Você venceu o inimigo!\n";
            return;
        }
        if (energia <= 0) {
            std::cout << "Você ficou sem energia! Precisa descansar.\n";
            return;
        }
    } while (true);
}

// Menu Principal
void menuPrincipal() {
    std::string nome, classe;
    int nivel = 1, energia = 100, experiencia = 0;
    int opcao;

    do {
        std::cout << "\n=== Menu Principal ===\n";
        std::cout << "[1] Cadastrar Personagem\n";
        std::cout << "[2] Treinar Personagem\n";
        std::cout << "[3] Batalhar\n";
        std::cout << "[4] Ver Status\n";
        std::cout << "[5] Sair do Jogo\n";
        std::cin >> opcao;

        switch (opcao) {
        case 1:
            cadastrarPersonagem(nome, classe, nivel, energia, experiencia);
            break;
        case 2:
            treinarPersonagem(energia, experiencia);
            break;
        case 3:
            batalhar(energia, experiencia);
            break;
        case 4:
            mostrarStatus(nome, classe, nivel, energia, experiencia);
            break;
        case 5:
            std::cout << "Saindo do jogo...\n";
            return;
        default:
            std::cout << "Opção inválida. Tente novamente.\n";
            break;
        }
    } while (opcao != 5);
}

