#include <iostream>
#include <array>
#include "Aulas.h"

/*Para receb um vetor em uma fun��o, � necess�rio passar o tipo do vetor, o nome do vetor e o tamanho do vetor
* Exemplo: void mostrarArray(int vetor[], int tamanho)
* Dentro da fun��o � poss�vel percorrer o vetor normalmente com um la�o de repeti��o
* Exemplo: for(int i = 0; i < tamanho; i++) { std::cout << vetor[i] << " "; }
*/
void mostrarArray(int vetor[], int tamanho) 
{
	for (int i = 0; i < tamanho; i++) 
	{
		std::cout << vetor[i] << " ";
	}
	std::cout << std::endl;
}
void PreencherArray() 
{
	int vetor[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	/*Para enviar um vetor bastar olocar o tipo nome do vetor */
	mostrarArray(vetor, 10);
	/* sezeof devolver o numero em byrtes do tamanho de uma variavel ou tipo 
	logo sizeof(vetor) vai devolver o numermo de elementos do vetor multiplicado 
	pelo tamanho do seu tipo pos s�o gastos 4bytes po int neste valor
	e como s�o 10 elementos o vetor 4bytes 
	mas precisamos saber o tamanho!
	Basta dividir pelo tipo do vetor */
	int tamanhoVetor = sizeof(vetor) / sizeof(vetor[0]);
	/* Agora  ser�o 40bytes / 4 bytes = 10 e teremos tamanho do vetor */
	std::cout << "Tamanho do vetor: " << tamanhoVetor << std::endl;
	/*std::cout << "\n Tamanmho de float: "<< sizeof(float);
	std::cout << "\n Tamanho de um int" << sizeof(int);*/
	tamanhoVetor = std::size(vetor); //  a prtir da vers�o C++17 voc� pode usar std::size para obter o tamanho do vetor


}


