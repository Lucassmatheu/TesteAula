//#include <iostream>
//#include <cstdlib> // Necess�rio para rand()
//#include <ctime>   // Necess�rio para time()
//#include "Aulas.h"
//#include <string>
//
//struct Equipamento {
//    std::string nome;
//    std::string tipo;
//    int ataque;
//    int defesa;
//};
//
//struct Jogador {
//    std::string nome;
//    Equipamento* inventario;
//    int tamanhoInventario;
//    int qtdEquipamentos;
//};
//
//void mostrarInventario(Jogador* jogadores, int nJogadores) {
//    std::cout << "\n===== INVENT�RIO =====\n";
//    if (nJogadores == 0) {
//        std::cout << "Invent�rio vazio.\n";
//        return;
//    }
//    for (int i = 0; i < nJogadores; i++) {
//        std::cout << "Jogador " << (i + 1) << ": " << jogadores[i].nome << "\n";
//        std::cout << "Equipamentos:\n";
//        for (int j = 0; j < jogadores[i].qtdEquipamentos; j++) {
//            std::cout << " - " << jogadores[i].inventario[j].nome
//                << ", Tipo: " << jogadores[i].inventario[j].tipo
//                << ", Ataque: " << jogadores[i].inventario[j].ataque
//                << ", Defesa: " << jogadores[i].inventario[j].defesa << "\n";
//        }
//    }
//    std::cout << "=======================\n";
//}
//void BatalhaEntreJoadores(Jogador* jogadores, int njogadores) 
//{
//    if (njogadores < 2) 
//    {
//        std::cout << "N�o h� jogadores suficientes para uma batalha.\n";
//        return;
//    }
//    std::cout << "Escolha o �ndice dos dois jogadores para batalhar:\n";
//    for (int i = 0; i < njogadores; i++) {
//        std::cout << "[" << i << "] " << jogadores[i].nome << "\n";
//    }
//    int idx1, idx2;
//    std::cout << "Digite o �ndice do primeiro jogador: ";
//    std::cin >> idx1;
//    std::cout << "Digite o �ndice do segundo jogador: ";
//    std::cin >> idx2;
//
//    if (idx1 < 0 || idx1 >= njogadores || idx2 < 0 || idx2 >= njogadores || idx1 == idx2) {
//        std::cout << "�ndices inv�lidos ou iguais. Tente novamente.\n";
//        return;
//    }
//
//    std::cout << "Batalha entre " << jogadores[idx1].nome << " e " << jogadores[idx2].nome << "!\n";
//
//    // Mostrar invent�rio do primeiro jogador
//    std::cout << "\nInvent�rio de " << jogadores[idx1].nome << ":\n";
//    for (int i = 0; i < jogadores[idx1].qtdEquipamentos; i++) {
//        std::cout << "[" << i << "] " << jogadores[idx1].inventario[i].nome
//            << " (Tipo: " << jogadores[idx1].inventario[i].tipo
//            << ", Ataque: " << jogadores[idx1].inventario[i].ataque
//            << ", Defesa: " << jogadores[idx1].inventario[i].defesa << ")\n";
//    }
//    int eq1;
//    std::cout << "Escolha o �ndice do equipamento para " << jogadores[idx1].nome << ": ";
//    std::cin >> eq1;
//    if (eq1 < 0 || eq1 >= jogadores[idx1].qtdEquipamentos) {
//        std::cout << "�ndice de equipamento inv�lido!\n";
//        return;
//    }
//
//    // Mostrar invent�rio do segundo jogador
//    std::cout << "\nInvent�rio de " << jogadores[idx2].nome << ":\n";
//    for (int i = 0; i < jogadores[idx2].qtdEquipamentos; i++) {
//        std::cout << "[" << i << "] " << jogadores[idx2].inventario[i].nome
//            << " (Tipo: " << jogadores[idx2].inventario[i].tipo
//            << ", Ataque: " << jogadores[idx2].inventario[i].ataque
//            << ", Defesa: " << jogadores[idx2].inventario[i].defesa << ")\n";
//    }
//    int eq2;
//    std::cout << "Escolha o �ndice do equipamento para " << jogadores[idx2].nome << ": ";
//    std::cin >> eq2;
//    if (eq2 < 0 || eq2 >= jogadores[idx2].qtdEquipamentos) {
//        std::cout << "�ndice de equipamento inv�lido!\n";
//        return;
//    }
//
//    // Inicializa o gerador de n�meros aleat�rios
//    std::srand(static_cast<unsigned int>(std::time(nullptr)));
//
//    int bonus1 = std::rand() % 11;
//    int bonus2 = std::rand() % 11;
//
//    int ataqueTotal1 = jogadores[idx1].inventario[eq1].ataque + bonus1;
//    int ataqueTotal2 = jogadores[idx2].inventario[eq2].ataque + bonus2;
//
//    int resultado1 = ataqueTotal1 - jogadores[idx2].inventario[eq2].defesa;
//    int resultado2 = ataqueTotal2 - jogadores[idx1].inventario[eq1].defesa;
//
//    std::cout << "\n" << jogadores[idx1].nome << " usou " << jogadores[idx1].inventario[eq1].nome
//              << " (Ataque: " << jogadores[idx1].inventario[eq1].ataque << " + b�nus " << bonus1
//              << " = " << ataqueTotal1 << ") contra defesa " << jogadores[idx2].inventario[eq2].defesa << "\n";
//    std::cout << jogadores[idx2].nome << " usou " << jogadores[idx2].inventario[eq2].nome
//              << " (Ataque: " << jogadores[idx2].inventario[eq2].ataque << " + b�nus " << bonus2
//              << " = " << ataqueTotal2 << ") contra defesa " << jogadores[idx1].inventario[eq1].defesa << "\n";
//
//    std::cout << "\nResultado final:\n";
//    if (resultado1 > resultado2) {
//        std::cout << jogadores[idx1].nome << " venceu a batalha!\n";
//    } else if (resultado2 > resultado1) {
//        std::cout << jogadores[idx2].nome << " venceu a batalha!\n";
//    } else {
//        std::cout << "Empate!\n";
//    }
//}
//void menu() 
//{
//	int opcao;
//    std::cout << "===== MENU =====\n";
//    std::cout << "[1] Batalha entre Jogadores\n";
//    std::cout << "[2] Mostrar Invent�rio\n";
//    std::cout << "[3] Sair\n";
//	std::cout << "Escolha uma op��o: ";
//	std::cin >> opcao;
//    std::cin.ignore(); // Limpa o buffer de entrada
//    switch (opcao) {
//        case 1: {
//            int nJogadores;
//            std::cout << "Quantos jogadores est�o participando da batalha? ";
//            std::cin >> nJogadores;
//            Jogador* jogadores = new Jogador[nJogadores];
//            for (int i = 0; i < nJogadores; i++) {
//                std::cout << "Digite o nome do jogador " << (i + 1) << ": ";
//                std::getline(std::cin, jogadores[i].nome);
//                jogadores[i].tamanhoInventario = 5; // Exemplo de tamanho fixo
//                jogadores[i].qtdEquipamentos = 0;
//                jogadores[i].inventario = new Equipamento[jogadores[i].tamanhoInventario];
//            }
//            BatalhaEntreJoadores(jogadores, nJogadores);
//            for (int i = 0; i < nJogadores; i++) {
//                delete[] jogadores[i].inventario;
//            }
//            delete[] jogadores;
//            break;
//        }
//        case 2: {
//            Jogador* jogadores = new Jogador[10]; // Exemplo de aloca��o
//            mostrarInventario(jogadores, 10);
//            delete[] jogadores;
//            break;
//        }
//        case 3:
//            std::cout << "Saindo do menu...\n";
//            break;s
//        default:
//            std::cout << "Op��o inv�lida! Tente novamente.\n";
//	}
//}