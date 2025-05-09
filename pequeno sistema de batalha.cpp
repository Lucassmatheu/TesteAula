#include<iostream>
#include "Aulas.h"


static void executarBatalha(int& energiaJogador, int& energiaInimigo);

void Login(std::string nome, int nivel, int energia, bool acesso = false)
{
  std::cout << "Digite seu nome: ";
  std::cin >> nome;
  std::cout << "Digite seu nivel: ";
  std::cin >> nivel;
  std::cout << "Digite sua energia: ";
  std::cin >> energia;

  if (nome == "Guerreiro" && nivel >= 10 && energia >= 10) 
  {
      acesso = true;
      std::cout << "Acesso permitido\n";

      int energiaJogador = energia;
      int energiaInimigo = 40; 
      std::cout << "Energia do jogador: " << energiaJogador << "\n";
      executarBatalha(energiaJogador, energiaInimigo);
  }
  else
  {
      std::cout << "Acesso negado\n";
  }
}

static void executarBatalha(int& energiaJogador, int& energiaInimigo)
{ 
  int acao;
  do 
  {
      std::cout << "Qual seria Ação desejada [1] Atacar \n[2] Defender \n[3] Fugir\n[4] Sair ";
      std::cin >> acao;
      switch (acao)
      {
      case 1:
          if (energiaJogador >= 10) {
              std::cout << "Você atacou o inimigo!\n";
              energiaInimigo -= 15;
              if (energiaInimigo <= 0)
              {
                  energiaInimigo = 0;
                  std::cout << "Inimigo derrotado!\n";
              }
              std::cout << "Energia do inimigo: " << energiaInimigo << "\n";
          }
          else
          {
              std::cout << "Energia insuficiente para atacar!\n";
          }
          break;
      case 2:
          if (energiaJogador >= 5) {
              std::cout << "Você se defendeu!\n";
              energiaJogador += 5;
              std::cout << "Energia do jogador: " << energiaJogador << "\n";
              if (energiaJogador > 100) 
              {
                  energiaJogador = 100; 
              }
          }
          else
          {
              std::cout << "Energia insuficiente para defender!\n";
          }
          break;
      case 3:
          if (energiaJogador >= 8) {
              std::cout << "Você fugiu da batalha!\n";
              energiaJogador -= 5;
              std::cout << "Energia do jogador: " << energiaJogador << "\n";
          }
          else
          {
              std::cout << "Energia insuficiente para fugir!\n";
          }
          break;
      case 4:
          std::cout << "Saindo do jogo...\n";
          break;
      default:
          std::cout << "Opção inválida. Tente novamente.\n";
          break;
      }
  } while ((acao != 3 && acao != 4) && energiaInimigo > 0 && energiaJogador > 0);
}

void JogoPricipal() {
   std::string nome;
   int nivel = 0, energia = 0;
   Login(nome, nivel, energia);
}