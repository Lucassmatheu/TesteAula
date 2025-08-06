#include <iostream>
#include "Aulas.h"

/*Prot�tiposdde fun��es
Recebe um array por refer�ncia atraves de um ponteiro ou seja a variavel 
*Array ir� receber um endere�o de memoria que ser� enviado para et� fun��o */ 
void DuplicaVetor(int* Array, int tamanho);

/* Est� fun��o tamb�m recebe um array via Poteiro
* mas tambem retorna um ponteiro que neste caso de ser 
* um ponteiro para int. logo ser� capaz de devover um ponteio
* para int ou seja um endere�o de mem�ria que ser� o endere�o do
* array invertido. Na realidade vai retornar o endere�o do primeiro elemento
* do array.
* 
*/
int *InvertdoVetor(int* Array, int tamanho);

/*Irar mostrar vetor recebido via ponteiro */
void MostrarVetor(int* Array, int tamanho);

// Fun��o que n�o recebe nada e n�o retorna nada
void ArrayInvertido() 
{
	int numeros[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int tamanho = sizeof(numeros) / sizeof(int); // Calcula o tamanho do array
	/*Chamar a fun��o e passa o vetor numeos para ela 
	o endere�o do primeiro eleemnto do vetor ser� enviado para arrays */
	MostrarVetor(numeros, tamanho);
	DuplicaVetor(numeros, tamanho);
	MostrarVetor(numeros, tamanho);
	/* Aqui mostra o vetor e recebe o retorno da fun��o InvertdoVetor
		e este retorno ser� o endere�o do primeiro elemento do vetor invertido
	*/
		
	MostrarVetor(InvertdoVetor(numeros, tamanho), tamanho);



}

void DuplicaVetor(int* Array, int tamanho)
{
	/*Fun��o percorre o vetor e duplica os valores  do vetor */
	for (int i = 0; i < tamanho; i++) 
	{
		Array[i] = 2 * Array[i]; // Duplicando cada elemento do vetor
	}
}

/*esta fun��o receber um array( na realidade receber o endere�o do primeiro elemnto do array)
e devolve um array invertido*/
int* InvertdoVetor(int* Array, int tamanho)
{
	/*/ para inverter o vetor iremos usar um vetor auxiliar
		ele precisa ser statico  pois  sen�o ao sair da fun��o ele iria 
		desaparecer da memoria, e n�o conseguiria ser enviado como retorno da fun�ao 
		ou seja o endere�o do primeiro elemento do vetor auxiliar seria perdido
		na mem�ria.
		Por isso usamos o static, para que o vetor auxiliar permane�a na mem�ria
		*/
	int j = 0;
	static int vetorInvertido[10]; // Array est�tico para armazenar o vetor invertido 

	/* Para conseguir um vetor com valoires invertidos, precisamos percorrer o vetor original */
	    for (int i = tamanho - 1; i >= 0; i--)
        {
			/* j vai de 0 at� 9, ou seja, 
			 o vetor invertido vai de
				vetorInvertido[j]0 a 9 = Array [i] vai de 9 at� 0
				vetorInvertido[0] = Array[9]
				vetorInvertido[i] = Array[8]
				vetorInvertido[2] = Array[7]
				vetorInvertido[3] = Array[6]
				vetorInvertido[4] = Array[5]
				vetorInvertido[5] = Array[4]
				vetorInvertido[6] = Array[3]
				vetorInvertido[7] = Array[2]
				vetorInvertido[8] = Array[1]
				vetorInvertido[9] = Array[0]*/
            vetorInvertido[j] = Array[i];
            j++;
        }
      /* Outra forma de fazer o mesmo
	   * for (int i = 0; i < tamanho; i++)
	   * {
	   *    vetorInvertido[i] = Array[tamanho - 1 - i];
	   * }
	   */

	return &vetorInvertido[0]; // Retorna o endere�o do primeiro elemento do vetor invertido
	
}

void MostrarVetor(int* Array, int tamanho)
{
	std::cout << "Vetor: ";
	for (int i = 0; i < tamanho; i++) 
	{
		std::cout << Array[i] << " "; // Mostra cada elemento do vetor
	}

	std::cout << std::endl;
	
}
void menuArray(){
	std::cout << "===== MENU =====\n";
	std::cout << "[1] Array Invertido\n";
	std::cout << "[2] Sair\n";
	std::cout << "Escolha uma op��o: ";
	int opcao;
	std::cin >> opcao;
	switch (opcao) 
	{
	case 1:
		ArrayInvertido();
		break;
	case 2:
		std::cout << "Saindo...\n";
		break;
	default:
		std::cout << "Op��o inv�lida!\n";
		break;
	}
}
