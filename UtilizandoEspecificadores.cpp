#include <iostream>  
#include "Aulas.h"  
#include <locale.h>  

static void especificadores()
{  
  setlocale(LC_ALL, "Portuguese"); 
  int numeroInteiro (12);
  float numeroReal (34.56);
  char caractere ('c');
  std::string texto("Texto de exemplo");
  // string e uma cadeia de caracteres, ou seja, uma sequência de caracteres.
  bool verdadeiro(true);
  bool falso(false);
  std::printf("O valor inteiro é: %d\n", numeroInteiro);
  //%d indica que você quer que seja colocado na string:
  std::printf("O valor inteiro é: %d\n", numeroInteiro);
  //"O valor inteiro = %d" o valore da variavel numeroInteiro

 
  
  // Especificadores de tipo  
  // Os especificadores de tipo são usados para definir o tamanho e a representação dos tipos de dados.  
  // Os principais especificadores de tipo são:  
  // short: inteiro curto (2 bytes)  
  // int: inteiro (4 bytes)  
  // long: inteiro longo (4 bytes)  
  // long long: inteiro muito longo (8 bytes)  
  // float: ponto flutuante (4 bytes)  
  // double: ponto flutuante duplo (8 bytes)  
  // long double: ponto flutuante muito longo (10 bytes)  
  // short numeroCurto = 32767; // 2 bytes  
  // int numeroInteiro = 2147483647; // 4 bytes  
  // long numeroLongo = 9223372036854775807; // 8 bytes  
  // long long numeroMuitoLongo = 9223372036854775807; // 8 bytes  
  // float numeroPontoFlutuante = 3.14f; // 4 bytes  
  // double numeroPontoFlutuanteDuplo = 3.14159265358979323846; // 8 bytes  
  // long double numeroPontoFlutuanteMuitoLongo = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647093844609550582231725359408128481117450284102701938521105559644622948954930381964428810975665933446128475648233786783165271201909145648566923460348610454326648213393607260249141273724587006606315588174881520920962829254091715364367892590360011330530548820466521384146951941511609433057270365759591953092186117381932611793105118548074462379962749567351885752724891227938183011949128831426076896280457;  
  // 16 bytes  
}