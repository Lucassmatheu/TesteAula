#include <iostream>

void MediaAluno() 
{
	/*
Este programa calcula a média de 3 notas digitadas pelo usuário.

Passos:
1. Lê o nome do aluno
2. Lê as 3 notas
3. Calcula a média
4. Usa operador ternário para determinar se o aluno está "Aprovado" ou "Reprovado"
5. Exibe o nome, resultado e (opcionalmente) a média

Exemplo:
Entrada: 8, 7, 9 → Média: 8.0 → Resultado: Aprovado
*/

float nota1, nota2, nota3, media;
std::string resultado, Nome;
std::cout << "Digite seu nome do alunos: ";
std::cin >> Nome; 
std::cout << "Digite a primeira nota: ";
std::cin >> nota1;
std::cout << "Digite a segunda nota: ";
std::cin >> nota2;
std::cout << "Digite a terceira nota: ";
std::cin >> nota3;

media = (nota1 + nota2 + nota3) / 3;
resultado = (media >= 7) ? "Aprovado" : "Reprovado";
std::cout << "Nome do aluno " << Nome <<"Reultado:"<< resultado << std::endl;

}