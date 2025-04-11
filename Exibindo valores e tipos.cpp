#include <iostream>  
#include "Aulas.h"  

void ExibindoValoresETipos()  
{  
  short valorShort (32000);  
  int menos (-150);  
  long valorLong (1000000); 
  float valorFloat (3.14); 
  double valorDouble(6.2831);
  char caractere('X');
  std::printf("O tamanho de short �: %zu bytes\n", sizeof(valorShort));
  std::printf("O tamanho de int �: %zu bytes\n", sizeof(menos));
  std::printf("O tamanho de long �: %zu bytes\n", sizeof(valorLong));
  std::printf("O tamanho de float �: %zu bytes\n", sizeof(valorFloat));
  std::printf("O tamanho de double �: %zu bytes\n", sizeof(valorDouble));
  std::printf("O tamanho de char �: %zu bytes\n", sizeof(caractere));



}